
/*
 * Get options array for the timeline instance.
 * See "https://visjs.github.io/vis-timeline/docs/timeline/" for more details.
 */
const options = {
    onInitialDrawComplete: function () {
        window.timeline.redraw();
    },
    start: 0,
    end:   1e8,
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
