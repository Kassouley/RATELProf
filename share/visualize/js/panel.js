document.addEventListener("DOMContentLoaded", function () {
    document.title = `RATELProf - ${HTML_TITLE}`;

    const panelManager = new PanelManager('#header', 'body');

    // Add panels dynamically
    panelManager.newPanel({
        id: 'mainPanel',
        title: 'Summary',
        container: createMainPanel()
    });

    panelManager.newPanel({
        id: 'timelinePanel',
        title: 'Timeline',
        container: createTimelineDOM()
    });

    panelManager.newPanel({
        id: 'statsPanel',
        title: 'Statistics',
        container: createCSVTab('statsPanel')
    });

    panelManager.newPanel({
        id: 'analyzePanel',
        title: 'Analyze',
        container: createCSVTab('analyzePanel')
    });


    try {
        createTimelines(TIMELINE_DATA, 0, TIMELINE_MAX, TIMELINE_LIFECYCLE);
    } catch (error) {
        alert('Error loading trace data: ' + error.message);
        console.error('Error loading trace data:', error)
    }

    TIMELINE_DATA = null;
});
