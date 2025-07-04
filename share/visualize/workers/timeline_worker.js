let allItems = [];
let visibleItems = [];
let visibleItemIds = new Set();

let selectedItemID = null;
let selectedItemCID = null;
let dispatches_are_shown = false;

function isHighlight(item) {
    return item.id === selectedItemCID || item.cid === selectedItemID;
}

function filterRange(items, start, end) {
    const newVisibleItems = [];
    const newVisibleItemIds = new Set();

    for (const [id, item] of items) {
        if (
            (
                (item.start >= start && item.start <= end) ||
                (item.end   >= start && item.end   <= end) ||
                (item.start <  start && item.end   >  end)
            ) &&
            !(item._event_kind === "DISPATCH" && !dispatches_are_shown)
        ) {
            item.className = isHighlight(item) ? 'highlighted' : 'non-highlighted';
            item.id = id
            newVisibleItems.push(item);
            newVisibleItemIds.add(id);
        }
    }

    return { newVisibleItems, newVisibleItemIds };
}


onmessage = (e) => {
    const action = e.data.action;

    if (action === 'init') {
        allItems = e.data.items;
        postMessage({ status: 'itemsSet' });
        
    } else if (action === 'updateVisibleItems') {
        const buf = 1e6;
        const { newVisibleItems, newVisibleItemIds } = filterRange(allItems, e.data.range.start - buf, e.data.range.end + buf);

        const toRemove = [];
        const toAdd = [];

        for (let i = 0; i < visibleItems.length; i++) {
            const item = visibleItems[i];
            if (!newVisibleItemIds.has(item.id)) {
                toRemove.push(item.id);
            }
        }

        for (let i = 0; i < newVisibleItems.length; i++) {
            const item = newVisibleItems[i];
            if (!visibleItemIds.has(item.id)) {
                toAdd.push(item);
            }
        }

        visibleItems = newVisibleItems;
        visibleItemIds = newVisibleItemIds

        postMessage({ toRemove, toAdd });

    } else if (action === 'highlightItems') {
        selectedItemID = e.data.id;
        selectedItemCID = e.data.cid;

        const toUpdate = []
        for (let i = 0; i < visibleItems.length; i++) {
            const item = visibleItems[i];
            if (isHighlight(item)) {
                item.className = 'highlighted';
                toUpdate.push(item);
            }
        }
        postMessage({ toUpdate });

    } else if (action === 'clearHighlightItems') {
        const toUpdate = []
        for (let i = 0; i < visibleItems.length; i++) {
            const item = visibleItems[i];
            if (isHighlight(item)) {
                item.className = 'non-highlighted';
                toUpdate.push(item);
            }
        }
        selectedItemID = null;
        selectedItemCID = null;
        postMessage({ toUpdate });
    } else if (action === 'showDispatch') {
        dispatches_are_shown = e.data.toggle;
    }
};