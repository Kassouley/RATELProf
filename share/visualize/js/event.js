document.addEventListener("DOMContentLoaded", () => {
    createMainPanel();
    createTimelinePanel();
    
    setupCSVViewer("stats");
    setupCSVViewer("analyze");
});