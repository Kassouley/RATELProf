class TimelineStackManager {
  constructor(min, max, stackContainerId, detailsContainerId, rangeSize = 1e9) {
    this.stackTimelines = [];
    this.stackEl = document.getElementById(stackContainerId);
    this.detailsContainerId = detailsContainerId;

    this.min = min;
    this.max = max;

    this.__isSyncing = false;

    this.rangeSize = rangeSize;
    this.loadedFiles = new Set(); // track already loaded

    // Setup all events
    this.setStackEvent();
    this.setDragEvent();
    this.setDocumentEvent();
  }

  addTimeline(id, rank, main_lifecycle, group_data, density) {
    const tl = new Timeline(
            id,
            this.stackEl,
            group_data,
            this.min, this.max,
            this.detailsContainerId,
            main_lifecycle,
            density,
            rank
          );

    tl.setManager(this);

    tl.setOnRangeChange(props => { 
      if (!props.byUser) return;
      const start = props.start instanceof Date ? props.start.getTime() : props.start;
      const end = props.end instanceof Date ? props.end.getTime() : props.end;
      this.syncWindow(start, end, props.animation);
    });


    tl.setOnRangeChanged(props => { 
      if (!props.byUser) return;
      const start = props.start instanceof Date ? props.start.getTime() : props.start;
      const end = props.end instanceof Date ? props.end.getTime() : props.end;
      this.updateVisibleWindow(start, end);
    });

    this.stackTimelines.push(tl);

    this.updateVisibleWindow(0, 1e8)

    this.updateOnDrag();
  }

  addGraph() {
    console.log("TODO");
  }


  async __loadRange(fileName, start, end) {
      // skip if already loaded
      if (this.loadedFiles.has(fileName)) return;
      this.loadedFiles.add(fileName);

      return new Promise((resolve, reject) => {
          const script = document.createElement("script");
          script.src = fileName;

          script.onload = () => {
              if (!window.b64_data) {
                  reject(new Error(`${fileName} did not define b64_data`));
                  return;
              }

              this.forEach(tl => {
                tl.loadData(window.b64_data[tl.id], fileName, start, end)
              })

              // cleanup globals
              window.b64_data = null;

              // remove <script> tag to free memory
              script.remove();

              console.log(`Load items from ${fileName}`)
              resolve();
          };

          script.onerror = () => {
              this.loadedFiles.delete(fileName);
              console.warn(`Failed to load ${fileName}, skipping.`);
              resolve(); // silently continue
          };
          document.head.appendChild(script);
      });
  }


  // load all files overlapping given [start, end]
  async loadRanges(start, end, margin = 1e8) {
      // extend the start and end by the margin
      const effectiveStart = Math.max(0, start - margin); ;
      const effectiveEnd = end + margin;

      // compute first and last file indices
      const firstIndex = Math.floor(effectiveStart / this.rangeSize) * this.rangeSize;
      const lastIndex  = Math.floor(effectiveEnd / this.rangeSize) * this.rangeSize;

      for (let t = firstIndex; t <= lastIndex; t += this.rangeSize) {
          await this.__loadRange(`.data/buckets/${t}.js`, start, end);
      }
  }

  // unload files far away from [start, end] with some margin
  unloadFarRanges(start, end, margin = this.rangeSize) {
    function extractBase(path) {
      const match = path.match(/(\d+)\.js$/);
      return match ? Number(match[1]) : null;
    }

    for (const fileName of this.loadedFiles) {
      const base = extractBase(fileName);
      const fileStart = base;
      const fileEnd = base + this.rangeSize;

      if (fileEnd < start - margin || fileStart > end + margin) {
        console.log(`Unload items from ${fileName}`)
        this.forEach(tl => {
          tl.unloadData(fileName)
        })
        this.loadedFiles.delete(fileName);
      }
    }
  }


  syncWindow(start, end, animation = false) {
    if (this.__isSyncing) return;
    this.__isSyncing = true;

    this.forEach((tl) => {
      tl.syncWindow(start, end, animation);
    });

    this.__isSyncing = false;
  }


  updateVisibleWindow(start, end) {
    if (start === undefined || end === undefined) {
        ({start, end} = this.getCurrentRange());
    }
    this.loadRanges(start, end);
    this.unloadFarRanges(start, end);

    this.forEach((tl) => {
      tl.updateVisibleItems(start, end);
    });
  }

  forEach(callback) {
    this.stackTimelines.forEach(callback);
  }

  on(type, handler, options) {
    this.stackEl.addEventListener(type, handler, options);
  }

  setDocumentEvent() {
    // Checkbox toggle for dispatches
    document.getElementById("show-dispatch").addEventListener("change", (e) => { 
        this.forEach(tl => { tl.showDispatches(e.target.checked); }); 
      });

    // Zoom slider
    document.getElementById("zoom-slider").addEventListener("input", (e) => {
      this.forEach(tl => { tl.zoomWindow(e.target.value) }); 
      this.updateVisibleWindow();
    });

    // Move left
    document.getElementById("moveLeft").onclick = () => {
      this.forEach(tl => { tl.moveWindow(0.3) });
      this.updateVisibleWindow();
    };

    // Move right
    document.getElementById("moveRight").onclick = () => {
      this.forEach(tl => { tl.moveWindow(-0.3) });
      this.updateVisibleWindow();
    };

    // Goto
    document.getElementById("goto_time").onclick = () => {
      const time = document.getElementById("time_input").value.trim();
      const start = convertToNs(time);
      if (start) {
        this.forEach(tl => { tl.gotoWindow(start) });
      }
    };
  }

  updateOnDrag() {
    const containers = Array.from(this.stackEl.children);
    let lastPath = [];

    containers.forEach((container, i) => {
      const timelineObj = this.stackTimelines.find(tl => tl.container === container);
      if (!timelineObj) return;

      lastPath = timelineObj.updateLabel(lastPath, i === containers.length - 1);
    });
  }

  setDragEvent() {
    // Drag & Drop
    let draggedTimeline = null;

    document.addEventListener("mousedown", (e) => {
      if (!e.target.classList.contains("drag-handle")) return;

      const container = Array.from(this.stackEl.children).find(c => c.contains(e.target));
      if (container) {
        draggedTimeline = container;
        draggedTimeline.style.opacity = 0.5;
      }
    });

    document.addEventListener("mouseup", () => {
      if (draggedTimeline) {
        draggedTimeline.style.opacity = 1;
        draggedTimeline = null;
        this.updateOnDrag();
      }
    });

    document.addEventListener("mousemove", (e) => {
      if (!draggedTimeline) return;

      const element = document.elementFromPoint(e.clientX, e.clientY);
      const target = Array.from(this.stackEl.children)
        .find(c => c.contains(element));

      if (!target || target === draggedTimeline) return;

      const children = Array.from(this.stackEl.children);
      const draggedIndex = children.indexOf(draggedTimeline);
      const targetIndex = children.indexOf(target);

      if (draggedIndex < targetIndex) {
        this.stackEl.insertBefore(draggedTimeline, target.nextSibling);
      } else {
        this.stackEl.insertBefore(draggedTimeline, target);
      }

      this.updateOnDrag();
    });
  }

  getVisibleTimeline() {
    return this.stackTimelines.find((t) => t.isVisible()) || null;
  };

  getCurrentRange() {
      return this.getVisibleTimeline().getWindow();
  }

  setStackEvent() {
    let isRightMouseDown = false;

    const dispatchToTimelines = (e, handler) => {
      const visibleTimeline = this.getVisibleTimeline();
      if (!visibleTimeline) return;

      const props = visibleTimeline.timeline.getEventProperties(e);
      for (const t of this.stackTimelines) {
        if (typeof t[handler] === "function") {
          t[handler](props);
        }
      }
    };

    this.on("mousedown", (e) => {
      if (e.button === 2) {
        isRightMouseDown = true;
        dispatchToTimelines(e, "onRightClickDown");
      }
    });

    this.on("mouseup", (e) => {
      if (isRightMouseDown) {
        dispatchToTimelines(e, "onRightClickUp");
        isRightMouseDown = false;
      }
    });

    this.on("mousemove", (e) => {
      if (isRightMouseDown) { 
        dispatchToTimelines(e, "onRightClickMove");
      }
    });

    this.on("contextmenu", (e) => { e.preventDefault() });
    this.on("wheel", (e) => { if (e.ctrlKey) { e.preventDefault() }}, { passive: false });
  }
}
