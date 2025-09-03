class PanelManager {
    constructor(headerSelector, containerSelector) {
        this.header = document.querySelector(headerSelector);
        this.container = document.querySelector(containerSelector);
        this.panels = {};
        this.activePanel = null;
    }
   
    newPanel({id, title, container}) {
        if (this.panels[id]) throw new Error(`Panel with id ${id} already exists`);

        const panel = document.createElement('div');
        panel.id = id;
        panel.className = 'tab-panel';
        panel.appendChild(container);
        this.container.appendChild(panel);


        const btn = document.createElement('button');
        btn.innerHTML = `<strong>${title}</strong>`;
        this.header.appendChild(btn);

        this.panels[id] = {
            element: panel,
            button: btn,
        };

        btn.addEventListener('click', () => this.showPanel(id));
        
        if (!this.activePanel) this.showPanel(id);
    }

    // Show a panel
    showPanel(id) {
        const newPanel = this.panels[id];
        if (!newPanel) return;

        // Hide current panel if exists
        if (this.activePanel) {
            const currPanel = this.panels[this.activePanel];
            currPanel.element.classList.remove('active');
        }

        // Show new panel
        newPanel.element.classList.add('active');
        this.activePanel = id;
    }
}
