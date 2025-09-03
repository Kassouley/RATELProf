function createPieChartSelect(chartContainer, select, datasets) {
    // create elements
    const canvas = document.createElement("canvas");
    chartContainer.appendChild(canvas);
    let ctx = canvas.getContext("2d");

    const tooltip = document.createElement("div");
    tooltip.className = "toooltip";
    chartContainer.appendChild(tooltip);

    const legend = document.createElement("div");
    legend.className = "legend";
    chartContainer.appendChild(legend);

    // internal state
    const state = {
        labels: [],
        percentages: [],
        values: [],
        width: 0,
        height: 0,
        centerX: 0,
        centerY: 0,
        radius: 0,
        hoverIndex: -1
    };

    let currentIndex = Object.keys(CHART_DATA)[0]

    function isElementVisible(el) {
        if (!el) return false;
        const style = getComputedStyle(el);
        if (style.display === "none" || style.visibility === "hidden") return false;
        // getClientRects() is empty if the element or any ancestor is display:none
        return el.getClientRects().length > 0;
    }

    function rebuildLegend(labels) {
        legend.innerHTML = "";
        labels.forEach(label => {
            const item = document.createElement("div");
            item.className = "legend-item";
            const colorBox = document.createElement("div");
            colorBox.className = "legend-color";
            colorBox.style.backgroundColor = hashStringToLightColor(label);
            const text = document.createElement("span");
            text.textContent = label;
            item.appendChild(colorBox);
            item.appendChild(text);
            legend.appendChild(item);
        });
    }

    // compute slice index under local canvas coords (x,y)
    function getSliceIndexAt(x, y) {
        const dx = x - state.centerX;
        const dy = y - state.centerY;
        const dist = Math.sqrt(dx * dx + dy * dy);
        if (dist > state.radius + 10) return -1; // outside
        let angle = Math.atan2(dy, dx);
        if (angle < 0) angle += 2 * Math.PI;
        let start = 0;
        for (let i = 0; i < state.percentages.length; i++) {
        const sliceAngle = (state.percentages[i] / 100) * 2 * Math.PI;
        if (angle >= start && angle < start + sliceAngle) return i;
        start += sliceAngle;
        }
        return -1;
    }

    // render using current state; hoveredIndex optional
    function render(hoveredIndex = -1) {
        // ctx assumed valid
        ctx.clearRect(0, 0, state.width, state.height);
        let startAngle = 0;

        for (let i = 0; i < state.percentages.length; i++) {
        const sliceAngle = (state.percentages[i] / 100) * 2 * Math.PI;
        const explodeDist = i === hoveredIndex ? 10 : 0;
        const midAngle = startAngle + sliceAngle / 2;
        const offsetX = Math.cos(midAngle) * explodeDist;
        const offsetY = Math.sin(midAngle) * explodeDist;

        ctx.beginPath();
        ctx.moveTo(state.centerX + offsetX, state.centerY + offsetY);
        ctx.arc(state.centerX + offsetX, state.centerY + offsetY, state.radius, startAngle, startAngle + sliceAngle);
        ctx.closePath();
        ctx.fillStyle = hashStringToLightColor(state.labels[i]);
        ctx.fill();

        // labels
        ctx.fillStyle = "black";
        ctx.font = "14px Arial";
        ctx.textAlign = "center";
        ctx.textBaseline = "middle";
        const textX = state.centerX + offsetX + Math.cos(midAngle) * (state.radius / 1.5);
        const textY = state.centerY + offsetY + Math.sin(midAngle) * (state.radius / 1.5);
        ctx.fillText(`${state.percentages[i]}%`, textX, textY);

        startAngle += sliceAngle;
        }
    }

    // update sizes & state, then render
    function drawPieChart(dataset) {
        // size to container in device pixels
        const newW = chartContainer.clientWidth || Math.max(1, Math.round(chartContainer.getBoundingClientRect().width));
        const newH = chartContainer.clientHeight || Math.max(1, Math.round(chartContainer.getBoundingClientRect().height));

        // only change canvas pixel dimensions when necessary (resizing resets canvas state)
        if (canvas.width !== newW || canvas.height !== newH) {
            canvas.width = newW;
            canvas.height = newH;
            // re-get context because defaults were reset
            ctx = canvas.getContext("2d");
        }

        state.width = canvas.width;
        state.height = canvas.height;
        state.labels = Object.keys(dataset);
        state.percentages = Object.values(dataset).map(d => d.pct.toFixed(2));
        state.values = Object.values(dataset).map(d => d.val); 
        state.radius = Math.min(state.width, state.height) / 2.25;
        state.centerX = state.width / 2;
        state.centerY = state.height / 2;

        rebuildLegend(state.labels);
        state.hoverIndex = -1;
        render(-1);
    }

    // --- event handlers (attached once) ---
    function onMouseMove(e) {
        const rect = canvas.getBoundingClientRect();
        const localX = e.clientX - rect.left;
        const localY = e.clientY - rect.top;
        const hovered = getSliceIndexAt(localX, localY);

        if (hovered !== state.hoverIndex) {
        state.hoverIndex = hovered;
        render(hovered);
        }

        if (hovered !== -1) {
        tooltip.style.visibility = "visible";
        tooltip.textContent = `${state.labels[hovered]}: ${state.values[hovered]} (${state.percentages[hovered]}%)`;
        } else {
        tooltip.style.visibility = "hidden";
        }

        // position tooltip relative to chartContainer
        const containerRect = chartContainer.getBoundingClientRect();
        tooltip.style.left = Math.round(e.clientX - containerRect.left + 15) + "px";
        tooltip.style.top = Math.round(e.clientY - containerRect.top + 15) + "px";
    }

    function onMouseLeave() {
        state.hoverIndex = -1;
        tooltip.style.visibility = "hidden";
        render(-1);
    }

    canvas.addEventListener("mousemove", onMouseMove);
    canvas.addEventListener("mouseleave", onMouseLeave);

    // --- observers with coalescing ---
    let rafId = null;
    function scheduleRedraw() {
        if (rafId) return;
        rafId = requestAnimationFrame(() => {
            rafId = null;
            // only redraw if actually visible
            if (isElementVisible(canvas)) {
                drawPieChart(datasets[currentIndex]);
            }
        });
    }

    let wasVisible = isElementVisible(canvas);

    const mutationObserver = new MutationObserver(() => {
        const nowVisible = isElementVisible(canvas);
        // only react when hidden -> visible
        if (!wasVisible && nowVisible) {
            scheduleRedraw();
        }
        wasVisible = nowVisible;
    });

    // watch for attribute changes that might hide/show ancestors
    mutationObserver.observe(chartContainer, {
        attributes: true,
        subtree: true,
        attributeFilter: ["style", "class"]
    });

    // watch for size changes on the container
    const resizeObserver = new ResizeObserver(() => {
        scheduleRedraw();
    });
    resizeObserver.observe(chartContainer);

    // select change and initial draw
    select.addEventListener("change", () => {
        drawPieChart(datasets[select.value]);
    });

    // initial draw when created (if visible)
    if (isElementVisible(canvas)) {
        drawPieChart(datasets[currentIndex]);
    } else {
        // if initially hidden, still set current dataset but wait until shown
        wasVisible = false;
    }
}