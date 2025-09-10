class Timeline {
    constructor(
            id,
            stackEl, 
            data, 
            min, max, 
            detailsContainerId, 
            main_lifecycle, 
            density, 
            rank = -1) {
        this.id = id;
        this.rank = rank;

        this.min = min;
        this.max = max;

        this.updateVisibleItems = throttle(this.updateVisibleItems.bind(this), 100);

        this.labels = Object.keys(data);
        this.values = Object.values(data);
        const groupLabel = this.labels.pop();
        const groupsList = this.values.pop();

        this.worker = new Worker("workers/timeline_worker.js");

        this.__create_container(stackEl);

        this.__create_timeline(groupLabel, groupsList, density, main_lifecycle);

        this.__create_worker()

        this.__timeMarkerId = "time_marker_id";
        this.__markerFirstTime = null;

        this.detailsContainerId = detailsContainerId;

    }

    __get_path() {
        return this.labels.map((label, i) => {
            const value = this.values[i];
            if (label === "Domain") {
                return value;
            } else {
                return `${label} ${value}`
            }
        });
    }

    __create_worker() {
        this.worker.postMessage({ action: 'init', extension_string_array: EXT_STRINGS });

        this.worker.onmessage = (e) => {  
            if (e.data.toAdd) {
                this.visibleItems.add(e.data.toAdd);
            } 
            if (e.data.toRemove) {
                this.visibleItems.remove(e.data.toRemove);
            } 
            if (e.data.toUpdate) {
                this.visibleItems.update(e.data.toUpdate);
            }
        };

    }

    __create_timeline(groupLabel, groupsList, density, main_lifecycle) {
        const groups = new vis.DataSet()
        for (const groupId of groupsList) {
            const prefix = (groupId === groupsList[groupsList.length - 1]) ? '└─ ' : '├─ ';
            groups.add({ id: groupId, content: prefix + groupLabel + " " + groupId });
        }
        
        this.visibleItems = new vis.DataSet([
            {
                id: "init",
                content: "Constructor",
                type: "background",
                start: this.min,
                end: main_lifecycle[0],
            }, {
                id: "fini",
                content: "Destructor",
                type: "background",
                start: main_lifecycle[1],
                end: this.max,
            }
        ]);

        const timeline = new vis.Timeline(this.timelineDOM, this.visibleItems, groups, {
            min: this.min,
            max: this.max,
            start:0,
            end: 1e8,
            stack: false,
            showCurrentTime: false,
            showMajorLabels: false,
            showMinorLabels: false,
            horizontalScroll: false,
            verticalScroll: false,
            zoomKey: "ctrlKey",
            align: 'center',
            margin: { item: 10, axis: 5 },
            zoomMin: 5,
            groupHeightMode: 'fixed',
            format: { minorLabels: function(date, scale, step) { return convertTime(date.toDate().getTime()) } },
            template: function (item) {
                const str = item.content || "";
                return str.length > 30 ? str.substring(0, 30) + "..." : str;
            },
            tooltip: {
                followMouse: true,
                template: trace => {
                    let tooltip = `<div>`;
                    if (trace.dispatched_event) {
                    tooltip += `<strong>Dispatch</strong><br>` +
                                `<strong>Event Dispatched:</strong> ${truncate(trace.dispatched_event)} (${trace.cid})<br>` +
                                `<strong>Dispatch Time:</strong> ${convertTime(trace.start)}`;
                    } else {
                    tooltip += `<strong>${truncate(trace.content)}</strong><br>` +
                                `<strong>ID:</strong> ${trace.id}<br>` +
                                `<strong>CID:</strong> ${trace.cid}<br>` +
                                `<strong>Duration:</strong> ${convertTime(trace.dur, true)}<br>`;
                    }
                    tooltip += "</div>";
                    return tooltip;
                }
            },
        })

        this.timeline = timeline;
        
        // Fire when double click on an item
        // Focus on it
        timeline.on('doubleClick', (props) => {
            if (props.what === 'item') {
                const selectedItem = this.visibleItems.get(props.item);
                if (selectedItem) {
                    timeline.focus(selectedItem.id);
                }
            }
        });


        timeline.on('select', (props) => {
            if (props.items.length > 0) {
                if (props.event.srcEvent.ctrlKey) {
                    this.onSelect(props.items[0], false);
                } else {
                    this.onSelect(props.items[0], true);
                }
            }
        });

        let downPos = null;

        function mouseHasMoved(e) {
            if (!downPos) return false;
            const dx = e.clientX - downPos.x;
            const dy = e.clientY - downPos.y;
            const moved = Math.sqrt(dx * dx + dy * dy);
            downPos = null;
            return moved < 3;
        }

        timeline.on('mouseDown', (props) => {
            const e = props.event;
            downPos = { x: e.clientX, y: e.clientY };
        });

        timeline.on('mouseUp', (props) => {
            if (mouseHasMoved(props.event) && props.what == 'background') {
                this.unselectExcept(null);
                this.clearHighlights();
                this.clearTraceDetails();
            }
        });

        this.canvas.addEventListener("mousedown", e => {
            downPos = { x: e.clientX, y: e.clientY };
        });
        
        this.canvas.addEventListener("mouseup", e => {
            if (mouseHasMoved(e)) {
                const rect = this.canvas.getBoundingClientRect();
                const x = e.clientX - rect.left;
                const clickedTime = this.min + (x / this.canvas.offsetWidth) * (this.max - this.min);
                const { start, end } = this.getWindow();
                const half = (end - start) / 2;
                this.forceMoveWindow(clickedTime - half, clickedTime + half, true);
            }
        });


        let wasVisible = this.timelineDOM.offsetParent !== null;
        const mutationObserver = new MutationObserver(() => {
            const isVisible = this.timelineDOM.offsetParent !== null;

            // Only redraw when visibility flips from hidden → visible
            if (!wasVisible && isVisible) {
                this.timeline.redraw();
            }

            wasVisible = isVisible;
        });
        mutationObserver.observe(document.body, {
            attributes: true,
            subtree: true,
            attributeFilter: ["style", "class"]
        });

        this.preview = new Preview(
            this.canvas, 
            density, 
            this.min, this.max,
            this.getWindow()
        );
    }


    __create_container(stackEl) {
        const container = document.createElement('div');
        stackEl.appendChild(container);

        const label = document.createElement('div');
        label.className = 'timeline-label';
        label.innerHTML = '<div class="col-left">' +
                            '<span class="drag-handle">☰</span>' +
                            '<span class="collapse-arrow"></span>' +
                            '<span class="label">N/A</span>' +
                          '</div>' +
                          '<div class="col-right">' + 
                            '<canvas class="preview-canvas"></canvas>'+
                          '</div>'
        container.appendChild(label);

        const timelineEl = document.createElement('div');
        timelineEl.className = 'timeline';
        container.appendChild(timelineEl);

        this.containerDOM = container;
        this.labelDOM     = container.querySelector('.label');
        this.timelineDOM  = container.querySelector('.timeline');
        this.canvas       = container.querySelector('.preview-canvas');

        const collapseArrow = container.querySelector('.collapse-arrow');
        collapseArrow.addEventListener('click', () => {
            this.toggleCollapse();
        });
        this.container = container;
    }


    updateTimeMarker(currTime) {
        const firstTime = this.__markerFirstTime;
        let [start, end] = firstTime < currTime ? [firstTime, currTime] : [currTime, firstTime];

        // Skip if no interval
        if (start.getTime() === end.getTime()) return;

        const items = this.timeline.itemsData;
        const existing = items.get(this.__timeMarkerId);

        const data = {
            id: this.__timeMarkerId,
            content: `${convertTime(end - start)}`,
            start,
            end,
            type: "background"
        }
        // Only update if values actually changed
        if (existing &&
            (existing.start.getTime() !== start.getTime() || existing.end.getTime() !== end.getTime())
        ) {
            items.update(data);
        } else if (!existing) {
            items.add(data);
        }
    };

    updateLabel(lastPath, isLast = false) {
        const path = this.__get_path();

        const parts = [];
                        
        let parentChanged = false;
        path.forEach((element, i) => {
            const oldElement = lastPath[i];
            if (i === 0) {
                if (element !== oldElement) {
                    parts.push(element + (this.rank >= 0 ? ` (rank ${this.rank})` : ''));
                    parentChanged = true;
                }
            } else {
                if (element !== oldElement || parentChanged) {
                    parts.push(`${"&nbsp;&nbsp;".repeat(i)}└─ ${element}`);
                    parentChanged = true;
                }
            }
        });

        this.labelDOM.innerHTML = parts.join("<br>");
        this.timeline.setOptions({showMinorLabels: isLast});

        return path
    }


    toggleCollapse() {
        this.containerDOM.classList.toggle('collapsed');
        this.timelineDOM.style.display = this.isVisible() ? 'block' : 'none';
    }

    isVisible() {
        return this.containerDOM.classList.contains('collapsed') ? false : true;
    }

    onRightClickDown(props) {
        this.timeline.itemsData.remove(this.__timeMarkerId);
        
        if (props && props.time) {
            this.__markerFirstTime = props.time;
        }
    }

    onRightClickMove(props) {
        if (props && props.time) {
            this.updateTimeMarker(props.time);
        }
    }

    onRightClickUp(props) {
        this.onRightClickMove(props);
    }


    showDispatches(toggle) {
        this.worker.postMessage({action: 'showDispatch', toggle});
        this.updateVisibleItems();
    }


    updateVisibleItems(start, end) {
        if (start === undefined || end === undefined) {
            ({start, end} = this.getWindow());
        }
        const margin = end - start;
        start = start - margin;
        end = end + margin;
        this.worker.postMessage({ action: 'updateVisibleItems', range: {start, end} });
    }

    unsetHighlights() {
        this.worker.postMessage({ action: "clearHighlightItems" });
    }

    setHighlights(id, cid) {
        this.worker.postMessage({ action: "highlightItems", id, cid });
    }

    unselect() {
        this.timeline.setSelection(null);
    }


    clearHighlights() {
        const target = this.manager ? this.manager : [this];
        target.forEach(tl => {
            tl.unsetHighlights();
        });
    }

    highlightItems(id, cid) {
        const target = this.manager ? this.manager : [this];
        target.forEach((tl) => {
            if (tl.rank === this.rank) {
                tl.setHighlights( id, cid );
            }
        });
    }
    
    unselectExcept(timeline) {
        const target = this.manager ? this.manager : [this];
        target.forEach((tl) => {
            if (timeline !== tl.timeline) {
                tl.unselect()
            }
        });
    }

    forceMoveWindow(start, end, animation =  false) {
        this.timeline.emit('rangechange', {
            start: start, 
            end: end, 
            byUser: true,
            animation: animation
        });
        this.timeline.emit('rangechanged', {
            start: start, 
            end: end, 
            byUser: true
        });
    }

    getWindow() {
        const window = this.timeline.getWindow();
        return {
            start: window.start.getTime(),
            end: window.end.getTime()
        }
    }

    syncWindow(start, end, animation = false) {
        this.timeline.setWindow(start, end, { animation: animation });
        if (this.preview) this.preview.renderPreviewHighlight({start, end});
    }

    moveWindow(pct) {
        const { start, end } = this.getWindow();
        const val = (end - start) * pct;
        this.syncWindow(start - val, end - val, true)
    }

    zoomWindow(value) {
        const sliderMax = 200;
        const maxUnzoom = this.max;
        const zoomValue = parseInt(value, 10);
        const visibleRange = maxUnzoom - ((zoomValue / sliderMax) * maxUnzoom);
        const { start, end } = this.getWindow();
        const center = (start + end) / 2;
        this.syncWindow(center - visibleRange / 2, center + visibleRange / 2)
    }

    gotoWindow(start) {
        this.forceMoveWindow(start, start + 1e8, true)
    }

    onSelect(id, isCtrlKeyPushed) {
        this.unselectExcept(this.timeline)
        this.clearHighlights();
        const selectedItem  = this.visibleItems.get(id)
        if (selectedItem) {
            if (isCtrlKeyPushed) this.highlightItems(selectedItem.id, null);
            else this.highlightItems(null, selectedItem.cid);
            this.showTraceDetails(selectedItem);
        }
    };


    clearTraceDetails() {
        document.getElementById(this.detailsContainerId).innerHTML = 'Click on a trace to view details here.';
    };


    showTraceDetails(trace) {
        const traceInfo = document.getElementById(this.detailsContainerId);
        traceInfo.innerHTML = "";
        
        const args = trace.args;
        const lcol = [];
        const rcol = [];
        
        const append = (details, field, value) => details.push(`<tr><td>${escapeHTML(field)}:</td> <td>${escapeHTML(value)}</td></tr>`);
        const is_dispatch_point = trace.dispatched_event;

        const domain = this.values[1].trim();
        if (is_dispatch_point) {
            append(lcol, "Name",             "Dispatch");
            append(lcol, "Event Dispatched", `${trace.dispatched_event} (${trace.cid})`);
            append(lcol, "Dispatch Time",    convertTime(trace.start));
        } else {
            append(lcol, "Name",       trace.content);
            append(lcol, "ID",         trace.id);
            append(lcol, "CID",        trace.cid);
            append(lcol, "Source",     trace.loc);
            append(lcol, "Duration",   convertTime(trace.dur, true));
            append(lcol, "Start Time", convertTime(trace.start));
            append(lcol, "End Time",   convertTime(trace.end));

            if (domain === "Kernel Dispatch") {
                append(lcol, "Dispatch Time",          convertTime(args.dispatch_time));
                append(rcol, "GPU ID",                 this.values[0]);
                append(rcol, "Queue ID",               trace.group);
                append(rcol, "Block Dimension",        `[${Object.values(args.wrg).join(", ")}]`);
                append(rcol, "Grid Dimension",         `[${Object.values(args.grd).join(", ")}]`);
                append(rcol, "Private Segment Size",   args.private_segment_size);
                append(rcol, "Group Segment Size",     args.group_segment_size);
                append(rcol, "Kernel Handle",          args.kernel_object);
                append(rcol, "Kernel Arg Addr",        args.kernarg_address);
                append(rcol, "Completion Signal",      args.sig);

            } else if (domain === "Memory Transfer") {
                append(rcol, "GPU ID",             this.values[0]);
                append(rcol, "SDMA Engine ID",     trace.group);
                append(rcol, "Source",             args.src);
                append(rcol, "Destination",        args.dst);
                append(rcol, "Size transferred",   convertBytes(args.size));
                append(rcol, "Completion Signal",  args.sig);

            } else if (domain === "Barrier AND" || domain === "Barrier OR") {
                append(lcol, "Dispatch Time",      convertTime(args.dispatch_time));
                append(rcol, "GPU ID",             this.values[0]);
                append(rcol, "Queue ID",           trace.group);
                append(rcol, "Dependent Signals",  `[${Object.values(args.dep_signal).join(", ")}]`);
                append(rcol, "Completion Signal",  args.sig);

            } else {
                append(lcol, "Process ID",         this.values[0]);
                append(lcol, "Thread ID",          trace.group);
                rcol.push(`<tr><td>Function Arguments:</td> <td>${printArgs(args.args)}</td></tr>`);
            }
        }
        traceInfo.innerHTML = `<div class="two-column"><div class="scrollable-tab"><table>${lcol.join("\n")}</table></div><div class="scrollable-tab"><table>${rcol.join("\n")}</table></div></div>`;
    }


    setManager(manager) {
        this.manager = manager;
    }

    setOnRangeChange(callback) {
        this.timeline.on('rangechange', callback);
    }


    setOnRangeChanged(callback) {
        this.timeline.on('rangechanged', callback);
    }


    loadData(data, loadId, start, end) {
        if (!data) return;
        this.worker.postMessage({ action: "loadItems", loadId, data, start, end});
    }

    unloadData(loadId) {
        this.worker.postMessage({ action: "unloadItems", loadId });
    }
}