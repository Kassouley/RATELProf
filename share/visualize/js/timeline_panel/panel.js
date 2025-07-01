function createTimelinePanel() {
    try {
        const container = document.getElementById("timeline");
        const groups = concatGroups(groupsList);
        createTimeline(traces_data, groups, container);
    } catch (error) {
        alert('Error loading trace data: ' + error.message);
        console.error('Error loading trace data:', error)
    }
}