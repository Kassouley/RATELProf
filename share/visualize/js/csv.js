const sortState = {}; // Store sort states per table type

function escapeHTML(str) {
    return str
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#39;");
}

function displayCSV(data, type) {
    const tableId = `${type}Table`;
    let html = `<table class='csvTable' id='${tableId}'><thead><tr>`;

    const headers = data[0].split(",");

    // Table headers with sorting event
    headers.forEach((col, index) => {
        html += `<th data-index="${index}" data-type="${type}" class="sortable">${col}<span class="sort-arrow" id="arrow-${type}-${index}"> ⭥</span></th>`;
    });

    html += "</tr></thead><tbody>";

    // Table rows
    html += data.slice(1).map(row => {
        const cells = row.match(/(".*?"|[^",]+)(?=\s*,|\s*$)/g)
            .map(cell => escapeHTML(cell));
        return `<tr><td>${cells.join("</td><td>")}</td></tr>`;
    }).join("");


    html += "</tbody></table>";
    return html;
}

function sortTable(col, type) {
    const table = document.getElementById(`${type}Table`);
    const tbody = table.querySelector("tbody");
    const rows = Array.from(tbody.rows);

    // Initialize sorting state if not present
    if (!sortState[type]) sortState[type] = { col: null, ascending: true };

    const state = sortState[type];

    // Toggle sorting order if sorting same column, otherwise reset to ascending
    state.ascending = state.col === col ? !state.ascending : true;
    state.col = col;

    rows.sort((rowA, rowB) => {
        const cellA = rowA.cells[col].textContent.trim();
        const cellB = rowB.cells[col].textContent.trim();

        const numA = parseFloat(cellA);
        const numB = parseFloat(cellB);

        return !isNaN(numA) && !isNaN(numB)
            ? (state.ascending ? numA - numB : numB - numA)
            : (state.ascending ? cellA.localeCompare(cellB) : cellB.localeCompare(cellA));
    });

    // Apply sorted rows using DocumentFragment for better performance
    const fragment = document.createDocumentFragment();
    rows.forEach(row => fragment.appendChild(row));
    tbody.innerHTML = "";
    tbody.appendChild(fragment);

    updateSortArrows(col, type, state.ascending);
}

function updateSortArrows(activeColumn, type, isAscending) {
    document.querySelectorAll(`#${type}Table .sort-arrow`).forEach(arrow => arrow.textContent = " ⭥");
    document.getElementById(`arrow-${type}-${activeColumn}`).textContent = isAscending ? " ⭡" : " ⭣";
}

function createCSVList(csv_data, type) {
    const listContainer = document.getElementById(`${type}List`);
    listContainer.innerHTML = csv_data.map(csv => 
        `<li data-type="${type}" data-name="${csv.name}">${csv.name}</li>`).join("");
}

function showCSVContent(csv, type) {
    sortState[type] = { col: null, ascending: true }; // Reset sorting
    const contentEl = document.getElementById(`${type}Content`);
    let data = "";
    if (csv.msg) data += `<p>${csv.msg}</p>`;
    if (csv.data.length !== 0 != 0) data += displayCSV(csv.data, type);
    if (data == "") data = "No data available this report.";
    contentEl.innerHTML = data;
}

// Event Delegation for sorting
document.addEventListener("click", event => {
    if (event.target.matches(".sortable")) {
        const col = event.target.dataset.index;
        const type = event.target.dataset.type;
        sortTable(Number(col), type);
    } else if (event.target.closest("li")) {
        // Handling CSV list click
        const listItem = event.target.closest("li");
        const type = listItem.dataset.type;
        const name = listItem.dataset.name;
        const csv = (type === "stats" ? csv_stats : csv_analyze).find(c => c.name === name);
        if (csv) showCSVContent(csv, type);
    } else if (event.target.closest("tr")) {
        handleRowClick(event.target.closest("tr"));
    }
});

function handleRowClick(row) {
    const itemsDataSet = timelineObject.itemsData;
    const itemName = row.lastElementChild.textContent.trim();
    const ids = itemsDataSet.get().filter(item => item.content === itemName).map(item => item.id);
    timelineObject.setSelection(ids, { focus: true });
}

// Initialize lists
createCSVList(csv_stats, "stats");
createCSVList(csv_analyze, "analyze");
