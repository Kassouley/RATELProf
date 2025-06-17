
function setupCSVViewer(tabId) {
    const csvData = csvDataPerTab[tabId];
    const listEl = document.getElementById(`csvList-${tabId}`);
    const tableContainer = document.getElementById(`tableContainer-${tabId}`);

    for (const fileName in csvData) {
        const file = csvData[fileName];
        const li = document.createElement('li');
        li.textContent = fileName;
        li.onclick = () => displayData(file, tableContainer);
        listEl.appendChild(li);
    }
}

function displayData(file, tableContainer) {
    tableContainer.innerHTML = '';
    if (file.msg) displayMSG(file, tableContainer);
    if (file.content.length > 0) displayCSV(file, tableContainer);
}

function displayMSG(file, tableContainer) {
  const box = document.createElement('div');
  box.className = 'box';

  const toggleBtn = document.createElement('div');
  toggleBtn.className = 'toggle-btn';
  toggleBtn.textContent = '+';
  toggleBtn.onclick = function () {
    toggleContent(this);
  };

  const labelText = document.createTextNode(' Advices');

  const contentBox = document.createElement('div');
  contentBox.className = 'content-box';

  const paragraph = document.createElement('div');
  paragraph.innerHTML = file.msg || '<i>No content provided.</i>';

  contentBox.appendChild(paragraph);
  box.appendChild(toggleBtn);
  box.appendChild(labelText);
  box.appendChild(contentBox);
  tableContainer.appendChild(box);
}

function toggleContent(btn) {
  const content = btn.nextElementSibling;
  const isShown = content.classList.toggle('show');
  btn.textContent = isShown ? '−' : '+';
}


function displayCSV(file, tableContainer) {
    if (!file.hiddenCols) file.hiddenCols = new Set();
    const { content, sortState, hiddenCols } = file;
    const rows = content.map(row => row.match(/(".*?"|[^",]+)(?=\s*,|\s*$)/g));

    const table = document.createElement('table');
    table.className = 'csvTable';

    const thead = document.createElement('thead');
    const headerRow = document.createElement('tr');

    rows[0].forEach((header, index) => {
    if (hiddenCols.has(index)) return;
    const th = document.createElement('th');
    th.textContent = header;
    th.classList.add('sortable');
    th.onclick = () => {
        const isSameCol = sortState?.col === index;
        const direction = isSameCol && sortState.direction === 'asc' ? 'desc' : 'asc';
        file.sortState = { col: index, direction };
        tableContainer.innerHTML = '';
        displayData(file, tableContainer);
    };
    if (sortState && sortState.col === index) {
        th.classList.add(sortState.direction);
    }
    headerRow.appendChild(th);
    });

    thead.appendChild(headerRow);
    table.appendChild(thead);

    const tbody = document.createElement('tbody');
    let dataRows = rows.slice(1);

    if (sortState) {
    const { col, direction } = sortState;
    dataRows.sort((a, b) => {
        const aText = a[col]?.trim() ?? "";
        const bText = b[col]?.trim() ?? "";
        const aNum = parseFloat(aText);
        const bNum = parseFloat(bText);
        let cmp;
        if (!isNaN(aNum) && !isNaN(bNum)) {
        cmp = aNum - bNum;
        } else {
        cmp = aText.localeCompare(bText);
        }
        return direction === 'asc' ? cmp : -cmp;
    });
    }

    dataRows.forEach(row => {
    const tr = document.createElement('tr');
        row.forEach((cell, index) => {
            if (hiddenCols.has(index)) return;
            const td = document.createElement('td');
            td.textContent = cell;
            tr.appendChild(td);
        });
        tbody.appendChild(tr);
    });

    table.appendChild(tbody);

    // Column toggle buttons
    rows[0].forEach((header, index) => {
    const btn = document.createElement('button');
    btn.textContent = `${hiddenCols.has(index) ? '[+]' : '[-]'} ${header}`;
    btn.className = hiddenCols.has(index) ? ' hidden' : '';
    btn.onclick = () => {
        if (hiddenCols.has(index)) hiddenCols.delete(index);
        else hiddenCols.add(index);
        displayData(file, tableContainer);
    };
    tableContainer.appendChild(btn);
    });

    tableContainer.appendChild(table);
}

// Setup CSV Viewers for each tab
setupCSVViewer("stats");
setupCSVViewer("analyze");

document.addEventListener("click", event => {
    const statsTableContainer = document.getElementById('tableContainer-stats');
    const clickedRow = event.target.closest("tr");
    
    // Check if the click is within the stats tab table and on a row
    if (statsTableContainer?.contains(event.target) && clickedRow) {
        // Open tab1
        openTabAux(document.querySelector('#btn-tab-tl'), "tab1");

        const itemsDataSet = timelineObject.itemsData;
        const itemName = clickedRow.lastElementChild.textContent.trim();
        const ids = itemsDataSet.get().filter(item => item.content === itemName).map(item => item.id);
        timelineObject.setSelection(ids, { focus: true });
    }
});