function prettyPrint(obj, indentLevel = 0) {
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
              html += prettyPrint(field.value[subfield], indentLevel + 1);
            }
          });
          html += `</div>`;
        } else if (typeof field.value === 'object') {
          html += `{<div class="indent">`;
          html += prettyPrint(field.value, indentLevel + 1); 
          html += `</div>}</div>`;
        } else {
          html += `<span class="value">${field.value}</span></div>`;
        }
      } else {
        html += `<div class="${indentClass}"><span class="key">${key}</span> = {<div class="indent">`;
        html += prettyPrint(field, indentLevel + 1); 
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
    const minStart = lifecycle_table.init_start; 
    const maxEnd   = lifecycle_table.fini_stop;
    return {
        start: minStart,
        end: minStart + 100000,
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
        groupTemplate: function (group) {
          if (!group) return;
          var container = document.createElement("div");
          if (group.treeLevel == 1) {
              var infoIcon      = document.createElement("img");
              infoIcon.src      = "assets/icons/information.png";
              infoIcon.style.paddingRight = "5px";
              container.appendChild(infoIcon);
          }
          
          var label = document.createElement("span");
          label.innerHTML = group.content;
          container.appendChild(label);  

          return container;
        },
        // loadingScreenTemplate: () => `<div style="display:flex;justify-content:center;align-items:center;height:100%;font-family:Arial,sans-serif;font-size:1.2rem;color:#333;background:#f0f0f0;text-align:center;padding:2rem;border-radius:8px;">Loading ...</div>`,
        // onTimeout: {
        //     timeoutMs: 100,
        //     callback: callback => {
        //         const didUserCancel = confirm(
        //             "Too many items loaded! Would you like to continue rendering (this might take a while)?"
        //         );
        //         callback(didUserCancel);
        //     }
        // },
        stack: false,
        min: minStart,
        max: maxEnd,
        groupHeightMode: 'fixed',
        orientation: "both",
        margin: { item: 10, axis: 5 },
        zoomMin: 5
    };
}


function createTimeline(items, groups, container) {
    const options = getTimelineOptions();
    const sortedItems    = items.sort((a, b) => a.start - b.start);
    const itemsDataSet   = new vis.DataSet(sortedItems);
    const groupsDataSet  = new vis.DataSet(groups);


    const offset = 1000;
    let lastRange = {
        start: options.start,
        end:   options.end
    };

    const visibleItems = new vis.DataView(itemsDataSet, {
        filter: function (item) {
            return item.is_visible;
        }
    });
    
    container.innerHTML = "";
    const timeline = new vis.Timeline(container, visibleItems, groupsDataSet, options);

    function binarySearch(items, end) {
        let low = 0, high = items.length;
        while (low < high) {
            const mid = Math.floor((low + high) / 2);
            if (items[mid].start < end) low = mid + 1;
            else high = mid;
        }
        return low - 1;
    }

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
        // rendered even if they go out of the range.
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
                append(rcol, "Function Arguments", prettyPrint(args.args));
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

    const move = percentage => {
        const range = timeline.getWindow();
        const interval = range.end - range.start;
        timeline.setWindow({
            start: range.start.valueOf() - interval * percentage,
            end: range.end.valueOf() - interval * percentage
        });
    };


    const onSelectTraceAux = (id, isCtrlKeyPushed) => {
        const selectedItem = itemsDataSet.get(id);
        if (selectedItem) {
            if (isCtrlKeyPushed) highlightTraces(item => item.cid === selectedItem.id);
            else highlightTraces(item => item.id === selectedItem.cid);
            showTraceDetails(selectedItem);
        }
    };


    // Attach navigation and event handlers
    document.getElementById("zoomIn").onclick = () => timeline.zoomIn(0.3);
    document.getElementById("zoomOut").onclick = () => timeline.zoomOut(0.3);

    document.getElementById("moveLeft").onclick = () => move(0.3);
    document.getElementById("moveRight").onclick = () => move(-0.3);

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

    timeline.on('contextmenu', function (properties) {
        properties.event.preventDefault();
    });

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

    timeline.on('mouseMove', function (properties) {
        if (isRightMouseDown && properties.time) {
            updateTimeMarker(properties.time);
        }
    });

    timeline.on('mouseUp', function (properties) {
        if (isRightMouseDown && properties.time) {
            updateTimeMarker(properties.time);
        }
        isRightMouseDown = false;
    });


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