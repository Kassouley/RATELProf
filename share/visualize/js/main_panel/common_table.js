function createTable(title, id = null, rightElement = null) {
  const div = document.createElement("div");
  div.className = "summary-container";

  const table = document.createElement("table");
  if (id) table.id = id;

  const colgroup = document.createElement("colgroup");
  colgroup.innerHTML = `<col style="width: 30%;"><col style="width: 70%;">`;
  table.appendChild(colgroup);

  const thead = document.createElement("thead");
  thead.innerHTML = `
    <tr>
      <th colspan="2">
        <div style="display: flex; justify-content: space-between; align-items: center;">
          <span>${title}</span>
        </div>
      </th>
    </tr>
  `;

  if (rightElement) {
    const flexDiv = thead.querySelector("div");
    flexDiv.appendChild(rightElement);
  }

  table.appendChild(thead);

  const tbody = document.createElement("tbody");
  table.appendChild(tbody);

  div.appendChild(table);

  return { table: div, tbody };
}

function createGridItem(element) {
    const container = document.createElement("div");
    container.className = "grid-item";
    container.appendChild(element);
    return container
}

function createTableBlock(data) {
    const title = data.title;
    const rows = data.rows;

    const {table, tbody} = createTable(title);

    rows.forEach(({ label, value, tooltip }) => {
        const tr = document.createElement("tr");

        const tdLabel = document.createElement("td");
        if (tooltip) {
            tdLabel.innerHTML = `<span class="info-icon" title="${tooltip}">ⓘ</span> ${label}`;
        } else {
            tdLabel.textContent = label;
        }

        const tdValue = document.createElement("td");
        tdValue.textContent = value;

        tr.appendChild(tdLabel);
        tr.appendChild(tdValue);
        tbody.appendChild(tr);
    });

    return createGridItem(table);
}


function createMainPanel() {
    const container = document.getElementById("grid-container");

    // Add other tables
    for (const key of Object.keys(reportData)) {
        container.appendChild(createTableBlock(reportData[key]));
    }

    // Add GPU table with dropdown
    const gpuTable = createGpuTableWithDropdown();
    container.appendChild(gpuTable);
    updateGpuTable(0);
    document.getElementById("gpu-select").addEventListener("change", (e) => {
    updateGpuTable(e.target.value);
    });
}