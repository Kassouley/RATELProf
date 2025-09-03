function createTimelines (data, min, max, main_lifecycle) {
    const stackTimelines = [];
    const stackEl = document.getElementById('timelineStack');

    Object.entries(data).forEach(([rank, group]) => {
        group.forEach((entry, idx) => {
        stackTimelines.push(new Timeline(stackEl, stackTimelines, entry, min, max, "trace-info", main_lifecycle[rank], rank));
        });
    });

    setStackEvent(stackEl, stackTimelines);
    setDragEvent(stackEl, stackTimelines);
    setDocumentEvent(stackTimelines);
}


function setDocumentEvent(stackTimelines) {
    // Fire when the 'Show Dispatches' checkbox change
    // Show dispatches point of kernel and barrier dispatches
    document.getElementById("show-dispatch").addEventListener("change", (e) => {
         for (const tl of stackTimelines) {
            tl.showDispatches(e.target.checked)
        }
    });

    // Fire when the zoom slider change
    // Zoom in the timeline according to the slider value
    document.getElementById('zoom-slider').addEventListener('input', (e) => {
         for (const tl of stackTimelines) {
            tl.zoomWindow(e.target.value)
        }
    });


    // Fire when the '<<' button is clicked
    // Move the timeline to the left
    document.getElementById("moveLeft").onclick = () => {
         for (const tl of stackTimelines) {
            tl.moveWindow(0.3)
        }
    };

    // Fire when the '>>' button is clicked
    // Move the timeline to the right
    document.getElementById("moveRight").onclick = () => {
         for (const tl of stackTimelines) {
            tl.moveWindow(-0.3)
        }
    };

    // Fire when the 'Go to' button is clicked
    // Read the input field next to it and focus the timeline to the corresponding trace id
    document.getElementById("goto_id").onclick = () => {
        const input = document.getElementById("id_input").value.trim();
        const parts = input.split(":");
        let id = -1;
        let rank = -1;
        if (parts.length === 2) {
            id = parseInt(parts[0], 10);
            rank = parseInt(parts[1], 10);
        } else {
            id = parseInt(input, 10);
        }
        if (!isNaN(id)) {
            for (const tl of stackTimelines) {
                if (tl.rank == rank || rank == 0) tl.gotoId(id);
            }
        } else {
            alert("Please enter a valid Trace ID.");
        }
    };


    document.getElementById("goto_time").onclick = () => {
        const time = document.getElementById("time_input").value.trim()
        for (const tl of stackTimelines) {
            tl.gotoWindow(time);
        }
    };
}


function setDragEvent(stackEl, stackTimelines) {
    function updateOnDrag() {
        const containers = Array.from(stackEl.children);
        let lastPath = [];
        containers.forEach((container, i) => {
            const timelineObj = stackTimelines[container.dataset.index];
            lastPath = timelineObj.updateLabel(lastPath, i === containers.length - 1);
        });
    }

    updateOnDrag();
    
    // Drag & Drop
    let draggedTimeline = null;
    document.addEventListener('mousedown', e => {
      if (!e.target.classList.contains('drag-handle')) return;
      const container = e.target.closest('.timeline-container');
      if (container) { 
        draggedTimeline = container; 
        draggedTimeline.style.opacity = 0.5; }
    });

    document.addEventListener('mouseup', e => {
      if (draggedTimeline) { 
        draggedTimeline.style.opacity = 1; 
        draggedTimeline = null; 
        updateOnDrag(); 
      }
    });

    document.addEventListener('mousemove', e => {
      if (!draggedTimeline) return;
      const target = document.elementFromPoint(e.clientX, e.clientY)?.closest('.timeline-container');
      if (!target || target === draggedTimeline) return;
      const children = Array.from(stackEl.children);
      const draggedIndex = children.indexOf(draggedTimeline);
      const targetIndex = children.indexOf(target);
      if (draggedIndex < targetIndex) {
          stackEl.insertBefore(draggedTimeline, target.nextSibling);
      } else {
          stackEl.insertBefore(draggedTimeline, target);
      }
      updateOnDrag();
    });
}


function setStackEvent(stackEl, stackTimelines) {
    // Track right mouse state
    let isRightMouseDown = false;

    // Helper: get the first visible timeline
    function getVisibleTimeline() {
        return stackTimelines.find(t => t.isVisible()) || null;
    }

    // Helper: dispatch right-click events to all timelines
    function dispatchToTimelines(e, handler) {
    const visibleTimeline = getVisibleTimeline();
    if (!visibleTimeline) return;

    const props = visibleTimeline.timeline.getEventProperties(e);
    for (const t of stackTimelines) {
            if (typeof t[handler] === "function") {
                t[handler](props);
            }
        }
    }

    // Event listeners
    stackEl.addEventListener("mousedown", e => {
        if (e.button === 2) { // right mouse
            isRightMouseDown = true;
            dispatchToTimelines(e, "onRightClickDown");
        }
    });

    stackEl.addEventListener("mouseup", e => {
        if (isRightMouseDown) {
            dispatchToTimelines(e, "onRightClickUp");
            isRightMouseDown = false;
        }
    });

    stackEl.addEventListener("mousemove", e => {
        if (isRightMouseDown) {
            dispatchToTimelines(e, "onRightClickMove");
        }
    });

    stackEl.addEventListener("contextmenu", function (e) {
        e.preventDefault();
    });

    stackEl.addEventListener('wheel', function (e) {
        if (e.ctrlKey) {
            e.preventDefault();
        }
    }, { passive: false }); 
}