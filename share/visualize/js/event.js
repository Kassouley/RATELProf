document.addEventListener("DOMContentLoaded", () => {
    decodeB64(b64_data);
    createMainPanel();
    createTimelinePanel();
    
    setupCSVViewer("stats");
    setupCSVViewer("analyze");
});