function createTracesCSV(content, fileName) {
    if (fileName === 'concurrency') {
        const traceIds = content.shift();
        content = traceIds.map((traceId, i) => {
            const trace = traceMap.get(traceId);
            return [
                trace.args.gpu_id,
                trace.args.queue_id,
                trace.id,
                trace.dur,
                content[0][i],
                trace.content
            ];
        }).sort((a, b) => a[4] - b[4]);
    } else if (fileName === 'hidden_transfers') {
        const traceIds = content.shift();
        content = traceIds.map((traceId, i) => {
            const trace = traceMap.get(traceId);
            const time_overlapped = content[0][i];
            return [
                trace.args.gpu_id,
                trace.id,
                trace.content,
                trace.args.size,
                content[0][i],
                trace.dur,
                (time_overlapped / trace.dur) * 100,
                trace.loc
            ];
        }).sort((a, b) => a[4] - b[4]);
    }
    return content;
}


function setupCSVViewer(tabId) {
    const csvData = csvDataPerTab[tabId];

    const container = document.getElementById(tabId);

    const ul = document.createElement('ul');
    ul.id = `csvList-${tabId}`;

    const div = document.createElement('div');
    div.className = 'csv-container';
    div.textContent = 'Select a CSV file to view its data.';

    container.appendChild(ul);
    container.appendChild(div);

    for (const fileName in csvData) {
        const file = csvData[fileName];
        if (file.content) {
            const content = decodeB64(file.content);
            file.headers = content.shift();
            file.unitMode = file.headers.find(h => h.includes('(B)')) ? 'size' : 'time';
            file.unitIndex = 0; // Default to the first unit scale
            file.hiddenCols = new Set();
            file.searchTerm = '';
            file.content = createTracesCSV(content, fileName)
        }
        const li = document.createElement('li');
        li.textContent = file.name;
        li.title = fileName;
        li.onclick = () => {
            const allItems = ul.querySelectorAll('li');
            allItems.forEach(item => item.classList.remove('active'));
            li.classList.add('active');
            displayData(file, div, tabId);
        };
        ul.appendChild(li);
    }
}

const unitScales = [1, 1e-3, 1e-6, 1e-9];
const unitLabels = {
    time: ['ns', 'µs', 'ms', 's'],
    size: ['B', 'KB', 'MB', 'GB']
};

function displayData(file, csvContainer, tabId) {
    csvContainer.innerHTML = '';
    if (file.msg) displayMSG(file, csvContainer);
    if (file.content) {
        const template = document.getElementById('csv-template');
        const clone = template.content.cloneNode(true);
        
        const csv = clone.querySelector('.csv-table');
        csv.id = `csvContainer-${tabId}`;

        const configPanel = clone.querySelector('.config-panel');

        // --- SEARCH BAR ---
        const searchInput = clone.querySelector('input');
        searchInput.value = file.searchTerm;
        searchInput.oninput = (e) => {
            file.searchTerm = e.target.value;
            file.currentPage = 1;
            displayCSV(file, csv);
        };

        // Config toggle button
        const toggleBtn = clone.querySelector('.config-toggle');
        toggleBtn.onclick = () => {
            configPanel.style.display = configPanel.style.display === 'none' ? '' : 'none';
        };


        // Column toggle buttons
        const toggleButtonsContainer = configPanel.querySelector('.hidden-toggle-buttons');
        const hiddenCols = file.hiddenCols;
        file.headers.forEach((header, index) => {
            const btn = document.createElement('button');
            btn.classList.add(...(hiddenCols.has(index) ? ['collapsed', 'light'] : ['expanded']));
            btn.textContent = header;
            btn.onclick = () => {
                const isCollapsed = hiddenCols.has(index);

                if (isCollapsed) {
                    hiddenCols.delete(index);
                } else {
                    hiddenCols.add(index);
                }

                // Update classes
                btn.classList.toggle('collapsed', !isCollapsed);
                btn.classList.toggle('expanded', isCollapsed);
                btn.classList.toggle('light', !isCollapsed);

                displayCSV(file, csv);
            };

            toggleButtonsContainer.appendChild(btn);
        });


        // Unit dropdown
        const unitSelect = configPanel.querySelector('.unit-select');

        unitLabels[file.unitMode].forEach((label, i) => {
            const option = document.createElement('option');
            option.textContent = label;
            option.selected = i === file.unitIndex;
            unitSelect.appendChild(option);
        });
            
        unitSelect.addEventListener('change', () => {
            file.unitIndex = parseFloat(unitSelect.selectedIndex);
            displayCSV(file, csv);
        });

        displayCSV(file, csv);
        csvContainer.appendChild(clone);
        
    }
}

function displayMSG(file, csvContainer) {
    const messageDiv = document.createElement('div');
    messageDiv.className = 'message';

    // Create the button
    const btn = document.createElement('button');
    btn.classList.add('collapsed', 'light');
    btn.textContent = 'Advices';

    // Append the button to the div
    messageDiv.appendChild(btn)

    const contentBox = document.createElement('div');
    contentBox.innerHTML = file.msg || '<i>No content provided.</i>';
    contentBox.style.display = 'none'; // Initially hidden

    messageDiv.appendChild(contentBox);

    btn.onclick = function () {
        const isCollapsed = btn.classList.contains('collapsed');
        btn.classList.toggle('collapsed', !isCollapsed);
        btn.classList.toggle('expanded', isCollapsed);
        contentBox.style.display = isCollapsed ? 'block' : 'none';
    };
    csvContainer.appendChild(messageDiv);
}


function displayCSV(file, csvContainer) {
    // Clear container
    csvContainer.innerHTML = '';

    if (!file.currentPage) file.currentPage = 1;

    const { content, headers, sortState, hiddenCols } = file;
    let data = content;

    if (file.searchTerm.trim()) {
        const term = file.searchTerm.trim().toLowerCase();
        data = data.filter(row =>
            row.some(cell => String(cell).toLowerCase().includes(term))
        );
    }

    // Sort data
    if (sortState) {
        const { col, direction } = sortState;
        data.sort((a, b) => {
            const aVal = a[col];
            const bVal = b[col];

            const aStr = typeof aVal === 'string' ? aVal.trim() : aVal ?? "";
            const bStr = typeof bVal === 'string' ? bVal.trim() : bVal ?? "";

            const aNum = parseFloat(aStr);
            const bNum = parseFloat(bStr);
            let cmp;
            if (!isNaN(aNum) && !isNaN(bNum)) {
                cmp = aNum - bNum;
            } else {
                cmp = aStr.localeCompare(bStr);
            }
            return direction === 'asc' ? cmp : -cmp;
        });
    }

    // Estimate rowsPerPage based on container height
    const rowsPerPage = 100;

    // Pagination slice
    const totalRows = data.length;
    const totalPages = Math.ceil(totalRows / rowsPerPage);
    file.currentPage = Math.min(file.currentPage, totalPages);
    const start = (file.currentPage - 1) * rowsPerPage;
    const end = Math.min(start + rowsPerPage, totalRows);
    const pageData = data.slice(start, end);


    // Table structure
    const table = document.createElement('table');
    const thead = document.createElement('thead');
    const headerRow = document.createElement('tr');

    headers.forEach((header, index) => {
        if (hiddenCols.has(index)) return;
        const th = document.createElement('th');

        th.textContent = header;
        if (header.includes(`(${unitLabels[file.unitMode][0]})`)) {
            th.textContent = header.replace(/\(.*?\)/, `(${unitLabels[file.unitMode][file.unitIndex]})`);
        }
        th.classList.add('sortable');
        th.onclick = () => {
            const isSameCol = sortState?.col === index;
            const direction = isSameCol && sortState.direction === 'asc' ? 'desc' : 'asc';
            file.sortState = { col: index, direction };
            displayCSV(file, csvContainer);
        };
        if (sortState && sortState.col === index) {
            th.classList.add(sortState.direction);
        }
        headerRow.appendChild(th);
    });

    thead.appendChild(headerRow);
    table.appendChild(thead);

    const tbody = document.createElement('tbody');
    pageData.forEach(row => {
        const tr = document.createElement('tr');
        row.forEach((cell, index) => {
            if (hiddenCols.has(index)) return;
            const td = document.createElement('td');

            if (typeof cell === 'number') {
                if (headers[index].includes(`(${unitLabels[file.unitMode][0]})`)) {
                    cell = cell * unitScales[file.unitIndex];
                }

                if (headers[index].includes('(%)')) {
                    cell = cell.toFixed(2);
                } else {
                    cell = cell.toExponential(3);
                }
            }

            td.textContent = cell;
            tr.appendChild(td);
        });
        tbody.appendChild(tr);
    });

    table.appendChild(tbody);
    csvContainer.appendChild(table);

    // Pagination controls
    // // Create pagination container
    const pagination = document.createElement('div');
    pagination.className = 'pagination';

    // Helper to create buttons and spans
    const createBtn = (label, page, isCurrent = false, disabled = false) => {
        if (label === '...') {
            const span = document.createElement('span');
            span.textContent = '...';
            span.style.margin = '0 4px';
            return span;
        }
        const btn = document.createElement('button');
        btn.textContent = label;
        if (!isCurrent) btn.classList.add('light');
        btn.disabled = disabled;
        btn.style.margin = '0 2px';
        btn.onclick = () => {
            if (page < 1 || page > totalPages || page === file.currentPage) return;
            file.currentPage = page;
            displayCSV(file, csvContainer);
        };
        return btn;
    };

    const nButtonsVisible = 9;
    const halfButtonsVisible = 4;

    // Prev button
    pagination.appendChild(createBtn('Prev', file.currentPage - 1, false, file.currentPage === 1));

    if (totalPages <= nButtonsVisible) {
        // Show all pages
        for (let i = 1; i <= totalPages; i++) {
            pagination.appendChild(createBtn(i, i, i === file.currentPage));
        }
    } else {
        // More than 9 pages: show first, last, current ± neighbors, and ellipses
        const pages = [];

        // Always show first page
        pages.push(1);

        // Calculate start and end pages around current
        let start = file.currentPage - halfButtonsVisible;
        let end = file.currentPage + halfButtonsVisible;

        if (start < 2) {
            end += 2 - start;
            start = 2;
        }
        if (end > totalPages - 1) {
            start -= end - (totalPages - 1);
            end = totalPages - 1;
            if (start < 2) start = 2;
        }

        // Add "..." or page 2 if close to start
        if (start > 2) {
            pages.push('...');
        } else if (start === 2) {
            pages.push(2);
        }

        // Pages between start and end
        for (let i = start; i <= end; i++) {
            pages.push(i);
        }

        // Add "..." or page before last if close to end
        if (end < totalPages - 1) {
            pages.push('...');
        } else if (end === totalPages - 1) {
            pages.push(totalPages - 1);
        }

        // Always show last page
        pages.push(totalPages);

        // Render pages
        pages.forEach(p => {
            if (p === '...') {
                pagination.appendChild(createBtn('...'));
            } else {
                pagination.appendChild(createBtn(p, p, p === file.currentPage));
            }
        });
    }

    // Next button
    pagination.appendChild(createBtn('Next', file.currentPage + 1, false, file.currentPage === totalPages));

    csvContainer.appendChild(pagination);
}


document.addEventListener("click", event => {
    const statscsvContainer = document.getElementById('csvContainer-stats');
    const clickedRow = event.target.closest("tr");
    
    // Check if the click is within the stats tab table and on a row
    if (statscsvContainer?.contains(event.target) && clickedRow) {
        showPanel("timelinePanel");

        const itemsDataSet = window.timeline.itemsData;
        const itemName = clickedRow.lastElementChild.textContent.trim();
        const ids = itemsDataSet.get().filter(item => item.content === itemName).map(item => item.id);
        window.timeline.setSelection(ids, { focus: true });
    }
});