class Table {
    constructor(container, options = {}) {
        const { id = "", subgroupPadding = 36 } = options;
        this.subgroupPadding = subgroupPadding;
        this.groupCounter = 1;
        this.pendingGroup = [];

        this.table = document.createElement("table");

        if (id) this.table.id = id;

        this.tbody = document.createElement("tbody");
        this.table.appendChild(this.tbody);
        container.appendChild(this.table);
    }

    addRow(cells, props = {}) {
        const { 
            colspan = [], 
            tooltip = null, 
            numberSubrow = 0, 
            collapsed = false, 
            onClick = null } = props;

        const tr = document.createElement("tr");
        tr.style.backgroundColor = ""
        let groupId = null;
        let depth = 0;

        // Handle subrow for pending group
        if (this.pendingGroup.length) {
            const current = this.pendingGroup.at(-1);
            groupId = current.groupId;
            depth = current.depth;
            tr.classList.add(`group-${groupId}`);
            tr.style.display = current.collapsed ? "none" : "table-row";

            if (--current.count <= 0) this.pendingGroup.pop();
        }

        // Handle new group
        if (numberSubrow > 0) {
            groupId = this.groupCounter++;
            tr.dataset.group = groupId;
            if (!collapsed) tr.classList.add("expanded");
            this.pendingGroup.push({ count: numberSubrow, groupId, collapsed, depth: this.pendingGroup.length + 1 });
        }

        // Click handler
        if (typeof onClick === "function") {
            tr.style.cursor = "pointer";
            tr.addEventListener("click", e => {
                if (!e.target.closest(".info-icon")) onClick(tr, e);
            });
        }

        // Build cells
        cells.forEach((content, idx) => {
            const td = document.createElement("td");
            td.colSpan = colspan[idx] || 1;
            td.style.paddingLeft = `${this.subgroupPadding * depth}px`;

            if (idx === 0) {
                const fragment = document.createDocumentFragment();
                const placeholder = document.createElement("span");
                placeholder.style.display = "inline-block";
                placeholder.style.width = "1em";
                placeholder.style.marginRight = "8px";

                if (numberSubrow > 0) placeholder.appendChild(this.__getCollapseArrow(tr, collapsed, groupId));

                fragment.appendChild(placeholder);

                if (tooltip) {
                    const tooltipSpan = document.createElement("span");
                    tooltipSpan.className = "info-icon";
                    tooltipSpan.title = tooltip;
                    tooltipSpan.textContent = "ⓘ";
                    fragment.append(tooltipSpan, document.createTextNode(" "));
                }

                fragment.appendChild(document.createTextNode(content));
                td.appendChild(fragment);
            } else td.textContent = content;

                tr.appendChild(td);
        });

        this.tbody.appendChild(tr);
        this.__applyAlternateColors();
    }

    forEachRow(callback) {
        Array.from(this.tbody.rows).forEach(callback);
    }

    updateRow(rowIndex, newValues) {
        const tr = this.tbody.rows[rowIndex];
        if (!tr) return;

        newValues.forEach((val, idx) => {
            if (val === null || val === undefined) return;

            const td = tr.cells[idx];
            if (!td) return;

            if (idx === 0) {
                const textNode = Array.from(td.childNodes).reverse().find(n => n.nodeType === Node.TEXT_NODE);
                if (textNode) textNode.textContent = val;
                else td.appendChild(document.createTextNode(val));
            } else td.textContent = val;
        });
    }

    __applyAlternateColors() {
        Array.from(this.tbody.rows)
            .filter(r => r.style.display !== "none")
            .forEach((r, i) => {
                r.classList.remove("even", "odd");
                r.classList.add(i % 2 === 0 ? "even" : "odd");
            });
    }

    __getCollapseArrow(tr, collapsed, groupId) {
        const arrow = document.createElement("span");
        Object.assign(arrow.style, {
            cursor: "pointer",
            display: "inline-block",
            width: "1em",
            userSelect: "none",
            transform: collapsed ? "" : "rotate(90deg)",
            marginLeft: "4px",
        });
        arrow.textContent = "▶";

        arrow.addEventListener("click", e => {
            e.stopPropagation();
            const groupRows = this.tbody.querySelectorAll(`.group-${groupId}`);
            const isVisible = groupRows[0].style.display !== "none";
            groupRows.forEach(r => r.style.display = isVisible ? "none" : "table-row");
            arrow.style.transform = isVisible ? "" : "rotate(90deg)";
            tr.classList.toggle("expanded", !isVisible);
            this.__applyAlternateColors();
        });

        return arrow;
    }
}