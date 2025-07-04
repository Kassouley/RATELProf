
function createTimeline(items, groups, container) {
    const groupsDataSet  = new vis.DataSet(groups);
    const visibleItems = new vis.DataSet([
        {
            id: "init",
            content: "init",
            type: "background",
            start: lifecycle_table.init_start,
            end: lifecycle_table.main_start,
        },{
            id: "main",
            content: "main",
            type: "background",
            start: lifecycle_table.main_start,
            end: lifecycle_table.main_stop,
            className: "mainBackground",
        },{
            id: "fini",
            content: "fini",
            type: "background",
            start: lifecycle_table.main_stop,
            end: lifecycle_table.fini_stop,
        }
    ]);

    container.innerHTML = "";
    const timeline = new vis.Timeline(container, visibleItems, groupsDataSet, options);

    // Worker code with diffing logic inside worker
    const worker = new Worker("workers/timeline_worker.js");

    worker.postMessage({ action: 'init', items: items });

    worker.onmessage = (e) => {
        if (e.data.status === 'itemsSet') {
            onRangeChanged();
        } 
        if (e.data.toRemove && e.data.toAdd) {
            visibleItems.remove(e.data.toRemove);
            visibleItems.update(e.data.toAdd);
        } 
        if (e.data.toUpdate) {
            visibleItems.update(e.data.toUpdate);
        }
    };

    // Throttle utility
    function throttle(fn, wait) {
        let lastTime = 0;
        let timeout = null;
        return function (...args) {
        const now = Date.now();
        if (now - lastTime >= wait) {
            lastTime = now;
            fn.apply(this, args);
        } else if (!timeout) {
            timeout = setTimeout(() => {
                lastTime = Date.now();
                timeout = null;
                fn.apply(this, args);
            }, wait - (now - lastTime));
        }
        };
    }

    const onRangeChanged = throttle(() => {
        const range = timeline.getWindow();
        worker.postMessage({
            action: 'updateVisibleItems',
            range: {
                start: range.start.getTime(),
                end: range.end.getTime()
            },
        });
    }, 100);

    timeline.on('rangechanged', onRangeChanged);



    const showTraceDetails = trace => {
        const traceInfo = document.getElementById('trace-info');
        const args = trace.args;
        const lcol = [];
        const rcol = [];
        
        const append = (details, field, value) => details.push(`<tr><td>${field}:</td> <td>${value}</td></tr>`);

        if (trace._event_kind === "DISPATCH") {
                append(lcol, "Name",             "Dispatch");
                append(lcol, "Event Dispatched", `${args.dispatched_event} (${trace.cid})`);
                append(lcol, "Dispatch Time",    convertTime(args.dispatch_time));
        } else {
                append(lcol, "Name",       trace.content);
                append(lcol, "ID",         trace.id);
                append(lcol, "CID",        trace.cid);
                append(lcol, "Duration",   convertTime(trace.dur, true));
                append(lcol, "Start Time", convertTime(trace.start));
                append(lcol, "End Time",   convertTime(trace.end));
        }
        const domainHandlers = {
            CPU: () => {
                append(lcol, "Process ID",         args.pid);
                append(lcol, "Thread ID",          args.tid);
                append(rcol, "Function Arguments", printArgs(args.args));
            },
            KERNEL: () => {
                append(lcol, "Dispatch Time",          convertTime(args.dispatch_time));
                append(rcol, "GPU Node ID",            args.gpu_id);
                append(rcol, "Queue ID",               args.queue_id);
                append(rcol, "Block Dimension",        `[${Object.values(args.wrg).join(", ")}]`);
                append(rcol, "Grid Dimension",         `[${Object.values(args.grd).join(", ")}]`);
                append(rcol, "Private Segment Size",   args.private_segment_size);
                append(rcol, "Group Segment Size",     args.group_segment_size);
                append(rcol, "Kernel Handle",          args.kernel_object);
                append(rcol, "Kernel Arg Addr",        args.kernarg_address);
                append(rcol, "Completion Signal",      args.sig);
            },
            BARRIER: () => {
                append(lcol, "Dispatch Time",      convertTime(args.dispatch_time));
                append(rcol, "GPU Node ID",        args.gpu_id);
                append(rcol, "Queue ID",           args.queue_id);
                append(rcol, "Dependent Signals",  `[${Object.values(args.dep_signal).join(", ")}]`);
                append(rcol, "Completion Signal",  args.sig);
            },
            COPY: () => {
                append(rcol, "Source",             args.src);
                append(rcol, "Destination",        args.dst);
                append(rcol, "Size transferred",   convertBytes(args.size));
                append(rcol, "SDMA Engine ID",     args.engine_id);
                append(rcol, "Completion Signal",  args.sig);
            }
        };

        if (domainHandlers[trace._event_kind]) domainHandlers[trace._event_kind]();

        traceInfo.innerHTML = '<div class="two-column">' +
                                `<div class="scrollable-tab"><table>${lcol.join("\n")}</table></div>` +
                                `<div class="scrollable-tab"><table>${rcol.join("\n")}</table></div>` +
                              '</div>';
    };


    const clearTraceDetails = () => {
        document.getElementById('trace-info').innerHTML = 'Click on a trace to view details here.';
    };


    const highlightTraces = (id, cid) => {
        worker.postMessage({action: 'highlightItems', id, cid});
    };


    const clearHighlightTraces = () => {
        worker.postMessage({action: 'clearHighlightItems'});
    };


    const onSelectTraceAux = (id, isCtrlKeyPushed) => {
        clearHighlightTraces();
        const selectedItem  = items.get(id)
        if (selectedItem) {
            if (isCtrlKeyPushed) highlightTraces(selectedItem.id, null);
            else highlightTraces(null, selectedItem.cid);
            showTraceDetails(selectedItem);
        }
    };


    // Fire when the 'Show Dispatches' checkbox change
    // Show dispatches point of kernel and barrier dispatches
    document.getElementById("show-dispatch").addEventListener("change", (e) => {
        worker.postMessage({action: 'showDispatch', toggle: e.target.checked});
        onRangeChanged();
    });

    // Fire when the zoom slider change
    // Zoom in the timeline according to the slider value
    const sliderMax = 200;
    const maxUnzoom = 1000000;
    document.getElementById('zoom-slider').addEventListener('input', (e) => {
        const zoomValue = parseInt(e.target.value, 10);
        const visibleRange = maxUnzoom - ((zoomValue / sliderMax) * maxUnzoom);
        const win = timeline.getWindow();
        const center = (win.start.valueOf() + win.end.valueOf()) / 2;
        const newStart = new Date(center - visibleRange / 2);
        const newEnd = new Date(center + visibleRange / 2);
        timeline.setWindow(newStart, newEnd)
    });


    // Helper function to move in the timeline
    const move = pct => {
        const win = timeline.getWindow();
        const interval = win.end - win.start;
        timeline.setWindow({
            start: win.start.valueOf() - interval * pct,
            end: win.end.valueOf() - interval * pct
        })
    };

    // Fire when the '<<' button is clicked
    // Move the timeline to the left
    document.getElementById("moveLeft").onclick = () => move(0.3);

    // Fire when the '>>' button is clicked
    // Move the timeline to the right
    document.getElementById("moveRight").onclick = () => move(-0.3);

    // Fire when the 'Go to' button is clicked
    // Read the input field next to it and focus the timeline to the corresponding trace id
    document.getElementById("goto_id").onclick = () => {
        const id = parseInt(document.getElementById("id_input").value.trim(), 10);
        if (!isNaN(id)) {
            const item  = items.get(id)
            if (item) {
                visibleItems.update(item);
                timeline.setSelection(id, { focus: true });
                onSelectTraceAux(id, false);
            }
        } else {
            alert("Please enter a valid Trace ID.");
        }
    };


    document.getElementById("goto_time").onclick = () => {
        const time = convertToNs(document.getElementById("time_input").value.trim());
        
        if (time) {
            const start = new Date(time);
            const end   = new Date(time + 1e8);
            timeline.setWindow(start, end);
        }
    };


    // Helper function and variable for time marker management
    let isRightMouseDown = false;
    let firstTime = null;
    let timeMarkerId = "time_marker_id";
    let tempItem = null;

    const updateTimeMarker = (currTime) => {
        let [start, end] = firstTime < currTime ? [firstTime, currTime] : [currTime, firstTime];
        let isItemExist = visibleItems.get(tempItem.id);
        if (isItemExist) {
            visibleItems.update({ 
                id: timeMarkerId, 
                is_visible: true,
                content: convertTime(end - start), 
                start, 
                end 
            });
        } else {
            if (start.getTime() !== end.getTime()) {
                tempItem.start = start;
                tempItem.end = end;
                visibleItems.add(tempItem);
            }
        }
    };

    // Fire when right click on timeline
    // Prevent default context menu to appear
    timeline.on('contextmenu', function (props) {
        props.event.preventDefault();
    });


    // Fire when user click on timeline and when it's a right click
    // Create the time marker but doesn't add it yet in the timeline
    // The time marker will be add only if user move the mouse
    timeline.on('mouseDown', function (props) {
        if (props.event.button === 2) {
            visibleItems.remove(timeMarkerId);
            if (props.what == 'background' && props.time) {
                isRightMouseDown = true;
                firstTime = props.time;
                tempItem = {
                    id: timeMarkerId,
                    type: "background"
                };
            }
        }
    });

    // Fire when mouse move in the timeline and when the right click is pressed
    // Update the time marker and add it if not present
    timeline.on('mouseMove', function (props) {
        if (isRightMouseDown && props.time) {
            updateTimeMarker(props.time);
        }
    });

    // Fire when user release click on timeline and when it was a right click
    // Update the time marker for the last time and leave it until new right click
    timeline.on('mouseUp', function (props) {
        if (isRightMouseDown && props.time) {
            updateTimeMarker(props.time);
        }
        isRightMouseDown = false;
    });

    // Fire when a user click on an item
    // If ctrl key is pressed     : highlight correlated parent trace
    // If ctrl key is not pressed : highlight correlated child traces
    timeline.on('select', function (props) {
        if (props.items.length > 0) {
            if (props.event.srcEvent.ctrlKey) {
                onSelectTraceAux(props.items[0], false);
            } else {
                onSelectTraceAux(props.items[0], true);
            }
        } else {
            clearTraceDetails();
            clearHighlightTraces();
        }
    });

    // Fire when double click on an item
    // Focus on it
    timeline.on('doubleClick', function (props) {
        if (props.what === 'item') {
            const selectedItem = items.get(props.item)
            if (selectedItem) {
                timeline.focus(selectedItem.id);
            }
        }
    });

    window.timeline = timeline;
}