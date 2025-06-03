function printArgs(obj, indentLevel = 0) {
  let html = '';
  const indentClass = 'indent'.repeat(indentLevel);

  for (const key in obj) {
    const field = obj[key];
    if (typeof field === 'object' && field !== null) {
      if (field.type != undefined && field.value != undefined) {
        html += `<div class="${indentClass}"><span class="type">${field.type}</span> <span class="key">${key}</span> =  `;
        if (field.value["->*"]) {
          const keys = Object.keys(field.value);
          keys.forEach((subfield, index) => {
            if (index < keys.length - 1) {
              html += `<span class="value">${field.value[subfield]}</span> -> `;
            } else {
              html += printArgs(field.value[subfield], indentLevel + 1);
            }
          });
          html += `</div>`;
        } else if (typeof field.value === 'object') {
          html += `{<div class="indent">`;
          html += printArgs(field.value, indentLevel + 1); 
          html += `</div>}</div>`;
        } else {
          html += `<span class="value">${field.value}</span></div>`;
        }
      } else {
        html += `<div class="${indentClass}"><span class="key">${key}</span> = {<div class="indent">`;
        html += printArgs(field, indentLevel + 1); 
        html += `</div>}</div>`;
      }
    }
  }
  return html;
}


/*
 * Get options array for the timeline instance.
 * See "https://visjs.github.io/vis-timeline/docs/timeline/" for more details.
 */
function getTimelineOptions() {
    return {
        start: 0,
        end:   100000,
        min:   lifecycle_table.init_start,
        max:   lifecycle_table.fini_stop,
        format: {
            minorLabels: function(date, scale, step) {
				return convertTime(date.toDate().getTime())
			}
        },
        showCurrentTime: false,
        showMajorLabels: false,
        horizontalScroll: false,
        verticalScroll: false,
        zoomKey: "ctrlKey",
        align: 'center',
        tooltip: {
            followMouse: true,
            template: trace => {
              let tooltip = `<div>`;
              if (trace._event_kind === "DISPATCH") {
                tooltip += `<strong>Dispatch</strong><br>` +
                           `<strong>Event Dispatched:</strong> ${trace.args.dispatched_event} (${trace.cid})<br>` +
                           `<strong>Dispatch Time:</strong> ${convertTime(trace.args.dispatch_time)}`;
              } else {
                tooltip += `<strong>${trace.content}</strong><br>` +
                           `<strong>ID:</strong> ${trace.id}<br>` +
                           `<strong>CID:</strong> ${trace.cid}<br>` +
                           `<strong>Duration:</strong> ${convertTime(trace.dur, true)}<br>`;
              }
              tooltip += "</div>";
              return tooltip;
            }
        },
        groupEditable: { order: true },
        groupOrder: "value",
        groupOrderSwap: function (a, b, groups) {
            if (a.treeLevel === b.treeLevel && a.nestedInGroup == b.nestedInGroup) {
                var v = a.value;
                a.value = b.value;
                b.value = v;
            }
        },
        stack: false,
        groupHeightMode: 'fixed',
        orientation: "both",
        margin: { item: 10, axis: 5 },
        zoomMin: 5
    };
}


function createTimeline(items, groups, container) {
    const options        = getTimelineOptions();
    const sortedItems    = items.sort((a, b) => a.start - b.start);
    const itemsDataSet   = new vis.DataSet(sortedItems);
    const groupsDataSet  = new vis.DataSet(groups);

    let dispatches_are_shown = false;

    const visibleItems = new vis.DataView(itemsDataSet, {
        filter: function (item) {
            if (item._event_kind == "DISPATCH" && !dispatches_are_shown) return false;
            return item.is_visible;
        }
    });

    container.innerHTML = "";
    const timeline = new vis.Timeline(container, visibleItems, groupsDataSet, options);

    // Helper function for adding visible item in timeline
    const offset = 1000;
    let lastRange = {
        start: options.start,
        end:   options.end
    };

    const binarySearch = (items, end) => {
        let low = 0, high = items.length;
        while (low < high) {
            const mid = Math.floor((low + high) / 2);
            if (items[mid].start < end) low = mid + 1;
            else high = mid;
        }
        return low - 1;
    };

    // Fire when range changed more than 1000 unit of time
    // Update visible item in timeline
    timeline.on('rangechanged', function (props) {
        const newStart = props.start.getTime();
        const newEnd = props.end.getTime();

        if (Math.abs(newStart - lastRange.start) < 1000 && Math.abs(newEnd - lastRange.end) < 1000) return;

        lastRange.start = newStart;
        lastRange.end   = newEnd;

        const rangeStart = newStart - offset;
        const rangeEnd   = newEnd   + offset;

        const lastIndex = binarySearch(sortedItems, rangeEnd);

        // In this version, items are rendered only if they are visible in the current range and stay
        // rendered even if they went out of the range.
        const updates = [];

        for (let i = lastIndex; i >= 0; i--) {
            const item = sortedItems[i];
            const itemEnd = item.end ? item.end : item.start;
            if (itemEnd < rangeStart) break;

            const shouldBeVisible = itemEnd >= rangeStart && item.start <= rangeEnd;

            if (item.is_visible !== shouldBeVisible) {
                item.is_visible = shouldBeVisible;
                updates.push({ id: item.id, is_visible: item.is_visible });
            }
        }

        if (updates.length > 0) {
            itemsDataSet.update(updates);
        }
    });


    const showTraceDetails = trace => {
        const traceInfo = document.getElementById('trace-info');
        const args = trace.args;
        const lcol = [];
        const rcol = [];
        
        const append = (details, field, value) => details.push(`<tr><th>${field}:</th> <td>${value}</td></tr>`);

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
            MEMORY: () => {
                append(rcol, "Source",             args.src);
                append(rcol, "Destination",        args.dst);
                append(rcol, "Size transferred",   convertBytes(args.size));
                append(rcol, "SDMA Engine ID",     args.engine_id);
                append(rcol, "Completion Signal",  args.sig);
            }
        };

        if (domainHandlers[trace._event_kind]) domainHandlers[trace._event_kind]();

        traceInfo.innerHTML = '<table class="two-column"><tr><td>' +
                                `<div class="scrollable-column"><table class="column">${lcol.join("\n")}</table></div>` +
                                `</td><td><div class="scrollable-column"><table class="column">${rcol.join("\n")}</table></div>` +
                              '</td></tr></table>';
    };


    const clearTraceDetails = () => {
        document.getElementById('trace-info').innerHTML = 'Click on a trace to view details here.';
    };

    const highlightedOriginalItems = [];

    const clearHighlightTraces = () => {
        if (highlightedOriginalItems.length) {
            itemsDataSet.update(highlightedOriginalItems);
            highlightedOriginalItems.length = 0; // Reset array
        }
    };

    const highlightTraces = (filterFun) => {
        clearHighlightTraces();

        const matchingItems = itemsDataSet.get().filter(filterFun);
        if (matchingItems.length === 0) return;

        highlightedOriginalItems.push(...matchingItems);
        
        const highlightedItems = matchingItems.map(item => ({
            id: item.id,
            className: 'highlighted'
        }));
        itemsDataSet.update(highlightedItems);
    };



    const onSelectTraceAux = (id, isCtrlKeyPushed) => {
        const selectedItem = itemsDataSet.get(id);
        if (selectedItem) {
            if (isCtrlKeyPushed) highlightTraces(item => item.cid === selectedItem.id);
            else highlightTraces(item => item.id === selectedItem.cid);
            showTraceDetails(selectedItem);
        }
    };


    // Fire when the 'Show Dispatches' checkbox change
    // Show dispatches point of kernel and barrier dispatches
    document.getElementById("show-dispatch").addEventListener("change", (e) => {
        dispatches_are_shown = e.target.checked;
        visibleItems.refresh();
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
    document.getElementById("goto").onclick = () => {
        const id = parseInt(document.getElementById("id_input").value.trim(), 10);
        if (!isNaN(id)) {
            itemsDataSet.updateOnly({id:id, is_visible: true});
            timeline.setSelection(id, { focus: true });
            onSelectTraceAux(id, false);
        } else {
            alert("Please enter a valid Trace ID.");
        }
    };


    // Helper function and variable for time marker management
    let isRightMouseDown = false;
    let firstTime = null;
    let timeMarkerId = "time_marker_id";
    let tempItem = null;

    const updateTimeMarker = (currTime) => {
        let [start, end] = firstTime < currTime ? [firstTime, currTime] : [currTime, firstTime];
        let isItemExist = itemsDataSet.get(tempItem.id);
        if (isItemExist) {
            itemsDataSet.update({ 
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
                itemsDataSet.add(tempItem);
            }
        }
    };

    // Fire when right click on timeline
    // Prevent default context menu to appear
    timeline.on('contextmenu', function (properties) {
        properties.event.preventDefault();
    });


    // Fire when user click on timeline and when it's a right click
    // Create the time marker but doesn't add it yet in the timeline
    // The time marker will be add only if user move the mouse
    timeline.on('mouseDown', function (properties) {
        if (properties.event.button === 2) {
            itemsDataSet.remove(timeMarkerId);
            if (properties.what == 'background' && properties.time) {
                isRightMouseDown = true;
                firstTime = properties.time;
                tempItem = {
                    id: timeMarkerId,
                    type: "background"
                };
            }
        }
    });

    // Fire when mouse move in the timeline and when the right click is pressed
    // Update the time marker and add it if not present
    timeline.on('mouseMove', function (properties) {
        if (isRightMouseDown && properties.time) {
            updateTimeMarker(properties.time);
        }
    });

    // Fire when user release click on timeline and when it was a right click
    // Update the time marker for the last time and leave it until new right click
    timeline.on('mouseUp', function (properties) {
        if (isRightMouseDown && properties.time) {
            updateTimeMarker(properties.time);
        }
        isRightMouseDown = false;
    });

    // Fire when a user click on an item
    // If ctrl key is pressed     : highlight correlated parent trace
    // If ctrl key is not pressed : highlight correlated child traces
    timeline.on('select', function (properties) {
        if (properties.items.length > 0) {
            if (properties.event.srcEvent.ctrlKey) {
                onSelectTraceAux(properties.items[0], false);
            } else {
                onSelectTraceAux(properties.items[0], true);
            }
        } else {
            clearTraceDetails();
            clearHighlightTraces();
        }
    });

    // Fire when double click on an item
    // Focus on it
    timeline.on('doubleClick', function (properties) {
        if (properties.what === 'item') {
            const selectedItem = itemsDataSet.get(properties.item);
            if (selectedItem) {
                timeline.focus(selectedItem.id);
            }
        }
    });

    return timeline;
}