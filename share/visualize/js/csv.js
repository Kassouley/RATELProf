
function setupCSVViewer(tabId) {
    const csvData = csvDataPerTab[tabId];
    const container = document.getElementById(tabId);

    const ul = document.createElement('ul');
    ul.id = `csvList-${tabId}`;

    const div = document.createElement('div');
    div.id = `csvContainer-${tabId}`;
    div.className = 'csv-container';
    div.textContent = 'Select a CSV file to view its data.';

    container.appendChild(ul);
    container.appendChild(div);

    for (const fileName in csvData) {
        const file = csvData[fileName];
        const li = document.createElement('li');
        li.textContent = fileName;
        li.onclick = () => {
            const allItems = ul.querySelectorAll('li');
            allItems.forEach(item => item.classList.remove('active'));
            li.classList.add('active');
            displayData(file, div);
        };
        ul.appendChild(li);
    }
}

function displayData(file, csvContainer) {
    csvContainer.innerHTML = '';
    if (file.msg) displayMSG(file, csvContainer);
    if (file.content.length > 0) displayCSV(file, csvContainer);
}

function displayMSG(file, csvContainer) {
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
  csvContainer.appendChild(box);
}

function toggleContent(btn) {
  const content = btn.nextElementSibling;
  const isShown = content.classList.toggle('show');
  btn.textContent = isShown ? '−' : '+';
}


function displayCSV(file, csvContainer) {
    if (!file.hiddenCols) file.hiddenCols = new Set();
    const { content, sortState, hiddenCols } = file;
    const rows = content.map(row => row.match(/(".*?"|[^",]+)(?=\s*,|\s*$)/g));

    const table = document.createElement('table');

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
        csvContainer.innerHTML = '';
        displayData(file, csvContainer);
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
            displayData(file, csvContainer);
        };
        csvContainer.appendChild(btn);
    });

    csvContainer.appendChild(table);
}

document.addEventListener("click", event => {
    const statscsvContainer = document.getElementById('csvContainer-stats');
    const clickedRow = event.target.closest("tr");
    
    // Check if the click is within the stats tab table and on a row
    if (statscsvContainer?.contains(event.target) && clickedRow) {
        showPanel("timelinePanel");

        const itemsDataSet = timelineObject.itemsData;
        const itemName = clickedRow.lastElementChild.textContent.trim();
        const ids = itemsDataSet.get().filter(item => item.content === itemName).map(item => item.id);
        timelineObject.setSelection(ids, { focus: true });
    }
});