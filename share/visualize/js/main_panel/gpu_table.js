
function createGpuTableWithDropdown() {
    // Create the select dropdown
    const select = document.createElement("select");
    select.id = "gpu-select";

    gpuDatasets.forEach((dataset, index) => {
        const nodeName = Object.keys(dataset)[0];
        const option = document.createElement("option");
        option.value = index;
        option.textContent = nodeName;
        select.appendChild(option);
    });

    const {table, _} = createTable("GPU Nodes", "gpuProps", select);

    return createGridItem(table);
}

function updateGpuTable(index) {
    const tbody = document.querySelector('#gpuProps tbody');
    tbody.innerHTML = '';

    const dataset = gpuDatasets[index];
    const nodeName = Object.keys(dataset)[0];
    const rowData = dataset[nodeName];

    for (let i = 0; i < gpuLabels.length; i++) {
        const tr = document.createElement('tr');

        const tdStatic = document.createElement('td');
        tdStatic.textContent = gpuLabels[i];
        tr.appendChild(tdStatic);

        const tdDynamic = document.createElement('td');
        tdDynamic.textContent = rowData[i];
        tr.appendChild(tdDynamic);

        tbody.appendChild(tr);
    }
}