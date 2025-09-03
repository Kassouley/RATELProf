const hashColorCache = new Map();

function hashStringToLightColor(str) {
    if (hashColorCache.has(str)) {
        return hashColorCache.get(str);
    }

    // Simple hash function to generate a color
    let hash = 0;
    for (let i = 0; i < str.length; i++) {
        hash = str.charCodeAt(i) + ((hash << 5) - hash);
    }

    // Convert hash to a light hexadecimal color
    let color = "#";
    for (let i = 0; i < 3; i++) {
        const value = (hash >> (i * 8)) & 0xFF;
        const lightValue = Math.floor(value / 2 + 127); // Keep value in 127–255
        color += ("00" + lightValue.toString(16)).slice(-2);
    }

    hashColorCache.set(str, color);
    return color;
}

const allItems = [];
const groupsIds = [];

const DENSITY_GRANULARITY = 1000;

function decodeMsgpack(bytes, extension_string_array, density, preview_data) {
    let off = 0;

    const f32buf      = new DataView(new ArrayBuffer(4));
    const f64buf      = new DataView(new ArrayBuffer(8));
    const textDecoder = new TextDecoder();
    
    function readB32() {
       return ((readB8() << 24) | (readB8() << 16) | (readB8() << 8) | readB8())
    }

    function readB16() { 
        return (readB8() << 8) | readB8()
    }

    function readB8() {
        return bytes[off++];
    }

    function readString(len) {
        const slice = bytes.subarray(off, off + len);
        off += len;
        return textDecoder.decode(slice);
    }
    
    function readArray(len) {
        const arr = new Array(len);
        for (let i = 0; i < len; i++) arr[i] = decode();
        return arr;
    }

    function readMap(len) {
        const map = {};
        for (let i = 0; i < len; i++) {
            const key = decode();
            const value = decode();
            map[key] = value;
        }
        return map;
    }

    // Ext formats
    function readExt(len) {
        const type = readB8();
        if (type == 1) {
            const string_id = decode();
            return extension_string_array[string_id];
        }
        else if (type == 2) {
            const curr_off = off;
            off += len; // skip len bytes
            let group = decode();
            let size = decode();
            const new_off = off;
            off = curr_off;

            const min = preview_data.min;
            const max = preview_data.max;

            for (let i = 0; i < size; i++) {
                const item = decode();
                item.className  = 'non-highlighted';
                item.style      = 'background-color:'+hashStringToLightColor(item.content);
                item.limitSize  = true;
                item.end        = item.start + item.dur;
                item.group      = group;
                item.subgroup   = item.subgroup || 0;

                allItems.push(item);

                const startX = Math.floor(((item.start - min) / (max - min)) * DENSITY_GRANULARITY);
                const stopX = Math.floor(((item.end - min) / (max - min)) * DENSITY_GRANULARITY);
                
                for (let x = startX; x <= stopX; x++) {
                    density[x] += item.score || 1;
                }
            }
            groupsIds.push(group);

            off = new_off;
            return
        }
        throw new Error(`Unsupported ext: ${typeof(type)} ${type}`);
    }

    function decode() {
        const byte = readB8();

        // positive fixint (0x00 - 0x7f)
        if (byte <= 0x7f) return byte;

        // negative fixint (0xe0 - 0xff)
        if (byte >= 0xe0) return byte - 0x100;

        // fixmap (0x80 - 0x8f)
        if ((byte & 0xf0) === 0x80) return readMap(byte & 0x0f);

        // fixarray (0x90 - 0x9f)
        if ((byte & 0xf0) === 0x90) return readArray(byte & 0x0f);

        // fixstr (0xa0 - 0xbf)
        if ((byte & 0xe0) === 0xa0) return readString(byte & 0x1f);

        switch (byte) {

            // map 16 (0xde)
            case (0xde): return readMap(readB16());

            // map 32 (0xdf)
            case(0xdf): return readMap(readB32());

            // array 16 (0xdc)
            case(0xdc): return readArray(readB16());

            // array 32 (0xdd)
            case(0xdd): return readArray(readB32());

            // str 8 (0xd9)
            case(0xd9): return readString(readB8());

            // str 16 (0xda)
            case(0xda): return readString(readB16());

            // str 32 (0xdb)
            case(0xdb): return readString(readB32());

            // nil (0xc0)
            case(0xc0): return null;

            // false (0xc2)
            case(0xc2): return false;

            // true (0xc3)
            case(0xc3): return true;

            // uint 8 (0xcc)
            case(0xcc): return readB8() & 0xFF;

            // uint 16 (0xcd)
            case(0xcd): return readB16() & 0xFFFF;

            // uint 32 (0xce)
            case(0xce): return readB32() >>> 0;

            // uint 64 (0xcf)
            case 0xcf: {
                const hi = readB32() >>> 0;
                const lo = readB32() >>> 0;
                const val = hi * 4294967296 + lo;

                if (val > Number.MAX_SAFE_INTEGER) {
                    throw new Error(`uint64 value (${val}) exceeds JavaScript safe integer range`);
                }

                return val;
            }

            // int 8 (0xd0)
            case(0xd0): {
                const val = readB8();
                return (val & 0x80) ? val - 0x100 : val;
            }
            // int 16 (0xd1)
            case(0xd1): {
                const val = readB16();
                return (val & 0x8000) ? val - 0x10000 : val;
            }
            // int 32 (0xd2)
            case(0xd2): {
                const val = readB32();
                return (val & 0x80000000) ? val - 0x100000000 : val;
            }
            // int 64 (0xd3)
            case(0xd3): {
                const hi = readB32() | 0;
                const lo = readB32() >>> 0;

                const val = hi * 4294967296 + lo;

                if (val > Number.MAX_SAFE_INTEGER || val < Number.MIN_SAFE_INTEGER) {
                    throw new Error(`int64 value (${val}) exceeds JavaScript safe integer range`);
                }

                return val;
            }
            // fixext 1 (0xd4)
            case(0xd4): return readExt(1);

            // fixext 2 (0xd5)
            case(0xd5): return readExt(2);

            // fixext 4 (0xd6)
            case(0xd6): return readExt(4);

            // fixext 8 (0xd7)
            case(0xd7): return readExt(8);

            // fixext 16 (0xd8)
            case(0xd8): return readExt(16);

            // ext 8 (0xc7)
            case(0xc7): return readExt(readB8());

            // ext 16 (0xc8)
            case(0xc8): return readExt(readB16());

            // ext 32 (0xc9)
            case(0xc9): return readExt(readB32());
       
            // float 32 (0xca)
            case 0xca:
                f32buf.setUint32(0, readB32());
                return f32buf.getFloat32(0);
            // float 64 (0xcb)
            case 0xcb:
                f64buf.setUint32(0, readB32());
                f64buf.setUint32(4, readB32());
                return f64buf.getFloat64(0);
        }

        throw new Error(`Unsupported byte: 0x${byte.toString(16)}`);
    }

    return decode();
}


let visibleItems = [];
let visibleItemIds = new Set();

let selectedItemID = null;
let selectedItemCID = null;
let dispatches_are_shown = false;

function isHighlight(item) {
    return item.id === selectedItemCID || item.cid === selectedItemID;
}

function filterRange(start, end) {
    const newVisibleItems = [];
    const newVisibleItemIds = new Set();
    for (const item of allItems) {
        if (
            (item.start >= start && item.start <= end) ||
            (item.end   >= start && item.end   <= end) ||
            (item.start <  start && item.end   >  end)
        ) {
            if (dispatches_are_shown && item.args.dispatch_time) {
                const dispatch_point = {
                    id :        `Dispatch_${item.id}`,
                    start:      item.args.dispatch_time,
                    type:       "point",
                    group:      item.group,
                    cid:        item.id,
                    dispatched_event: item.content,
                }
                dispatch_point.className = isHighlight(dispatch_point) ? 'highlighted' : 'non-highlighted';
                newVisibleItems.push(dispatch_point);
                newVisibleItemIds.add(dispatch_point.id);
            }
            item.className = isHighlight(item) ? 'highlighted' : 'non-highlighted';
            newVisibleItems.push(item);
            newVisibleItemIds.add(item.id);
        }
    }
    return { newVisibleItems, newVisibleItemIds };
}


onmessage = (e) => {
    const action = e.data.action;

    if (action === 'init') {
        const density = new Array(DENSITY_GRANULARITY).fill(0.1);
        const buffer = new Uint8Array(e.data.buffer)
        e.data.buffer = null;
        decodeMsgpack(
            new Uint8Array(buffer), 
            e.data.extension_string_array, 
            density, 
            e.data.preview_data);
        postMessage({ groupsIds, density });
        
    } else if (action === 'updateVisibleItems') {
        const buf = 1e6;
        const { newVisibleItems, newVisibleItemIds } = filterRange(e.data.range.start - buf, e.data.range.end + buf);

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

    } else if (action === 'select') {
        const id = e.data.id;
        const newItem = allItems.find(item => item.id === id);
        if (newItem && !visibleItemIds.has(id)) {
            visibleItems.push(newItem);
            visibleItemIds.add(id);
        }
        postMessage({ toSelect: newItem });
    }
};