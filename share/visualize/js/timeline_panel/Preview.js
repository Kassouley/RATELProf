class Preview {
    constructor(canvas, density, min, max, default_range = null) {
        this.canvas = canvas;
        this.density = density;
        this.min = min;
        this.max = max;
        this.range = default_range;

        this._setupObservers();
    }

    // Create preview into the offscreen canvas
    createItemsPreview() {
        const c = this.canvas;
        const w = c.width  = c.offsetWidth;
        const h = c.height = c.offsetHeight;
        const ctx = c.getContext('2d');

        ctx.clearRect(0, 0, w, h);

        if (!w || !h) return; // skip if size not ready

        const maxWeighted = Math.max(...this.density, 0.00001);

        for (let x = 0; x < w; x++) {
            // Map x (canvas pixel) to density index
            const idx = Math.floor((x / w) * this.density.length);
            const val = this.density[idx] || 0;

            const barHeight = (val / maxWeighted) * h;
            const intensity = Math.floor((val / maxWeighted) * 255);
            ctx.fillStyle = `rgb(0,0,${intensity})`;
            ctx.fillRect(x, h - barHeight, 1, barHeight);
        }

        this.previewImage = ctx.getImageData(0, 0, w, h);
    }

    // Draw the offscreen canvas to the visible canvas and overlay highlight
    renderPreviewHighlight(range = this.range) {
        if (!range) return;
        if (!this.previewImage) return;

        const c = this.canvas;
        const ctx = c.getContext('2d');
        const h = c.height = c.offsetHeight;
        const w = c.width  = c.offsetWidth;
        if (!w || !h) return;

        ctx.putImageData(this.previewImage, 0, 0);

        const totalRange = this.max - this.min;
        if (totalRange <= 0) return;

        const viewStart = range.start - this.min;
        const viewEnd = range.end - this.min;

        const x1 = (viewStart / totalRange) * w;
        const x2 = (viewEnd / totalRange) * w;

        ctx.fillStyle = 'rgba(255,165,0,0.3)';
        ctx.fillRect(x1, 0, x2 - x1, h);
        this.range = range;
    }


    _setupObservers() {
        let wasVisible = this.canvas.offsetParent !== null; // initial state

        this._mutationObserver = new MutationObserver(() => {
            const isVisible = this.canvas.offsetParent !== null;

            // Only redraw when visibility flips from hidden → visible
            if (!wasVisible && isVisible) {
                this.createItemsPreview();
                this.renderPreviewHighlight();
            }
            wasVisible = isVisible;
        });

        this._mutationObserver.observe(document.body, {
            attributes: true,
            subtree: true,
            attributeFilter: ["style", "class"]
        });

        // ResizeObserver for container size
        this._resizeObserver = new ResizeObserver(() => {
            if (this.canvas.offsetParent !== null) {
                this.createItemsPreview();
                this.renderPreviewHighlight();
            }
        });
        this._resizeObserver.observe(this.canvas);
    }
}
