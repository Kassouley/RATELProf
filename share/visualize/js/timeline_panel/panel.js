function showMessage(message, container) {
  container.innerHTML = `<div style="display:flex;justify-content:center;align-items:center;height:100%;font-family:Arial,sans-serif;font-size:1.2rem;color:#333;background:#f0f0f0;text-align:center;padding:2rem;border-radius:8px;">${message}</div>`;
}

function waitNextFrame() {
  return new Promise(resolve => requestAnimationFrame(() => resolve()));
}

async function createTimelinePanel() {
    try {
        const container = document.getElementById("timeline");
        createMainGroup();
        showMessage("Data decoding ...", container);
        await waitNextFrame();
        decodeB64(b64_data);
        showMessage("Groups Creation...", container);
        await waitNextFrame();
        const groups = concatGroups(groupsList);
        
        showMessage("Timeline Creation. Please wait . . .", container);
        await waitNextFrame();
        timelineObject = createTimeline(items, groups, container);
    } catch (error) {
        alert('Error loading trace data: ' + error.message);
        console.error('Error loading trace data:', error)
    }
}