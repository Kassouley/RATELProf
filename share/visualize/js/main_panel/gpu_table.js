function createGpuTableWithDropdown() {
    const tableDOM = document.createElement("div");
    tableDOM.className = 'scrollable-table';
    const table = new Table(tableDOM);

    const firstNode = Object.values(GPU_DATA)[0];
    // Build the rows once here
    GPU_LABELS.forEach((label, i) => {
        table.addRow([label, firstNode[i]])
    });

    // Create the dropdown
    const select = document.createElement("select");

    Object.entries(GPU_DATA).forEach(([key]) => {
        const option = document.createElement("option");
        option.value = key;
        option.textContent = "Node " + key;
        select.appendChild(option);
    });

    // Update table on dropdown change
    select.addEventListener("change", (e) => {
        updateGpuTable(GPU_DATA[e.target.value], table);
    });

    return createGridItem("GPU Nodes Attributes", select, tableDOM);
}

function updateGpuTable(data, table) {
    if (!data) return;
    data.forEach((item, i) => {
        table.updateRow(i, [null, item]);
    });
}
