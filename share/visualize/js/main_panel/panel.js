function createGridHeader(title, rightElement = null) {
  const headerDiv = document.createElement("div");
  headerDiv.className = "table-header";

  const titleSpan = document.createElement("span");
  titleSpan.textContent = title;
  headerDiv.appendChild(titleSpan);

  if (rightElement) {
    headerDiv.appendChild(rightElement);
  }

  return headerDiv
}

function createGridItem(title, rightElement, ...elements) {
    const container = document.createElement("div");
    container.className = "grid-item";
    const header = createGridHeader(title, rightElement);
    container.appendChild(header);
    elements.forEach(el => container.appendChild(el));
    return container;
}

function renderRow(table, data) {
    const { cells, tooltip, subrows = [], colspan = [], visible = false } = data;

    table.addRow(cells, {
        tooltip,
        numberSubrow: subrows.length,
        colspan,
        collapsed: !visible
    });

    subrows.forEach(sub => renderRow(table, sub));
}

function createGridTable(data, container, rightElement = null) {
    const tableDOM = document.createElement("div");
    tableDOM.className = 'scrollable-table';
    const table = new Table(tableDOM);
    data['rows'].forEach(row => renderRow(table, row));
    container.appendChild(createGridItem(data.title, rightElement, tableDOM));
}

function createMainPanel() {
    const container = document.createElement("div");
    container.id = "grid-container";

    createGridTable(REPORT_DATA["profilingSummary"], container);

    const select = document.createElement("select");

    Object.keys(CHART_DATA).forEach(name => {
        const option = document.createElement("option");
        option.value = name;
        option.textContent = name;
        select.appendChild(option);
    });
    
    const chartContainer = document.createElement("div");
    chartContainer.className = "chart-container";
    createPieChartSelect(chartContainer, select, CHART_DATA)
    container.appendChild(createGridItem("Summary Chart", select, chartContainer));

    createGridTable(REPORT_DATA["experimentInfo"], container);

    // Add GPU table with dropdown
    container.appendChild(createGpuTableWithDropdown());

    return container
}