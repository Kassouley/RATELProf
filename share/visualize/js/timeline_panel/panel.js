function createTimelineDOM () {
    const div = document.createElement('div'); 
    div.innerHTML = `
    <div id="timelineStack"></div>
    <section id="nav">
        <table>
            <tr>
                <td class="left">
                    <div class="trace-select">
                        <div class="input-group">
                            <input id="id_input" placeholder="Trace ID"/>
                            <button id="goto_id">Go to</button>
                        </div>
                        <div class="input-group">
                            <input id="time_input" placeholder="Time (e.g. 15616, 500us, 165s 48ms)" />
                            <button id="goto_time">Go to</button>
                        </div>
                    </div>
                </td>
                <td class="center">
                    <button id="moveLeft" aria-label="Move timeline left">&laquo;</button>
                    <span>-</span>
                    <input id="zoom-slider" type="range" min="0" max="200" value="100">
                    <span>+</span>
                    <button id="moveRight" aria-label="Move timeline right">&raquo;</button>
                </td>
                <td class="right">
                    <input id="show-dispatch" type="checkbox">
                    <label for="show-dispatch"> Show dispatches</label>
                </td>
            </tr>
        </table>
    </section>
    <div id="trace-info">
        Click on a trace to view details here.
    </div>
    <div id="info-container">
        <div id="info-icon">i</div>
        <div class="tooltip">
            <strong>How to use the timeline:</strong>
            <ul>
                <li>Ctrl + Wheel up to zoom</li>
                <li>Ctrl + Wheel down to unzoom</li>
                <li>Left-click and move to navigate</li>
                <li>Click on density plot to move at clicked area</li>
                <li>Right-click and move to select an area and see its duration</li>
                <li>Click a trace to highlight it and highlight in red traces called by this trace</li>
                <li>Ctrl + Click a trace to highlight it and highlight in red who call this trace</li>
                <li>Double-click on a trace to focus on it</li>
                <li>Drag-n-Drop domain group to change their order</li>
                <li>Click on group's arrow to hide/show group</li>
            </ul>
        </div>
    </div>
    `;
    return div;
}

function createTimelineStackFromData(data, min, max, main_lifecycle) {
    const manager = new TimelineStackManager(min, max, "timelineStack", 'trace-info');

    data.forEach((data) => {
        const { timeline_id, rank, density, ...group_data } = data;

        manager.addTimeline(timeline_id, rank, main_lifecycle[rank], group_data, density);
    });

    return manager;
}
