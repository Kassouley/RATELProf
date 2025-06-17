function openTab(evt, tabName) {
    openTabAux(evt.currentTarget, tabName);
}

function openTabAux(activeButton, tabName) {
    const tabButtons = document.querySelectorAll('.tabs button');
    tabButtons.forEach(button => button.classList.remove('active'));
    activeButton.classList.add('active');

    const tabContents = document.querySelectorAll('.tab-content');
    tabContents.forEach(content => content.style.display = 'none');
    const activeTab = document.getElementById(tabName);
    if (activeTab) {
        activeTab.style.display = 'block';
    }
}