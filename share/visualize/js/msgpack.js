function decodeB64(b64) {
    const bin = atob(b64);
    let off = 0;
    
    const float32Buffer = new DataView(new ArrayBuffer(4));
    const float64Buffer = new DataView(new ArrayBuffer(8));
    
    function readByte32() {
       return ((readByte8() << 24) | (readByte8() << 16) | (readByte8() << 8) | readByte8());
    }

    function readByte16() { 
        return (readByte8() << 8) | readByte8();
    }

    function readByte8() {
        return bin.charCodeAt(off++);
    }

    /*
    function readString(len) {
        const str = bin.slice(off, off + len);
        off += len;
        return new TextDecoder().decode(Uint8Array.from(str, c => c.charCodeAt(0)));
    }
    */

    function readArray(len) {
        const arr = [];
        for (let i = 0; i < len; i++) arr.push(decode());
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
        const type = readByte8();
        if (type == 1) {
            const string_id = decode();
            return extension_string_array[string_id];
        }
        else if (type == 2) {
            let domain_id = decode();
            let size = decode();
            
            for (let i = 0; i < size; i++) {
                const item = decode();

                item.className  = 'non-highlighted';
                item.style      = 'background-color:'+hashStringToLightColor(item.content);
                item.limitSize  = true;
                item.end        = item.start + Math.ceil(item.dur/1000);
                item.group      = get_group_id(item, domain_id);
                
                if (item.start < 1000000) item.is_visible = true;

                items.push(item);
            }
            return
        }
        throw new Error(`Unsupported ext: ${typeof(type)} ${type}`);
    }

    function decode() {
        const byte = readByte8();

        // positive fixint (0x00 - 0x7f)
        if (byte <= 0x7f) return byte;

        // negative fixint (0xe0 - 0xff)
        if (byte >= 0xe0) return byte - 0x100;

        // fixmap (0x80 - 0x8f)
        if ((byte & 0xf0) === 0x80) return readMap(byte & 0x0f);

        // fixarray (0x90 - 0x9f)
        if ((byte & 0xf0) === 0x90) return readArray(byte & 0x0f);

        // fixstr (0xa0 - 0xbf)
        // if ((byte & 0xe0) === 0xa0) return readString(byte & 0x1f);

        switch (byte) {

            // map 16 (0xde)
            case (0xde): return readMap(readByte16());

            // map 32 (0xdf)
            case(0xdf): return readMap(readByte32());

            // array 16 (0xdc)
            case(0xdc): return readArray(readByte16());

            // array 32 (0xdd)
            case(0xdd): return readArray(readByte32());

            /*
            // str 8 (0xd9)
            case(0xd9): return readString(readByte8());

            // str 16 (0xda)
            case(0xda): return readString(readByte16());

            // str 32 (0xdb)
            case(0xdb): return readString(readByte32());
            */

            // nil (0xc0)
            case(0xc0): return null;

            // false (0xc2)
            case(0xc2): return false;

            // true (0xc3)
            case(0xc3): return true;

            // uint 8 (0xcc)
            case(0xcc): return readByte8()  & 0xFF;

            // uint 16 (0xcd)
            case(0xcd): return readByte16() & 0xFFFF;

            // uint 32 (0xce)
            case(0xce): return readByte32() >>> 0;

            // uint 64 (0xcf)
            case 0xcf: {
                const hi = readByte32() >>> 0;
                const lo = readByte32() >>> 0;
                const val = hi * 4294967296 + lo;

                if (val > Number.MAX_SAFE_INTEGER) {
                    throw new Error("uint64 value exceeds JavaScript safe integer range");
                }

                return val;
            }

            // int 8 (0xd0)
            case(0xd0): {
                const val = readByte8();
                return (val & 0x80) ? val - 0x100 : val;
            }
            // int 16 (0xd1)
            case(0xd1): {
                const val = readByte16();
                return (val & 0x8000) ? val - 0x10000 : val;
            }
            // int 32 (0xd2)
            case(0xd2): {
                const val = readByte32();
                return (val & 0x80000000) ? val - 0x100000000 : val;
            }
            // int 64 (0xd3)
            case(0xd3): {
                const hi = readByte32();
                const lo = readByte32();
                const val = (hi << 32n) | lo;
                return (high & 0x80000000) ? val - (1n << 64n) : val;
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
            case(0xc7): return readExt(readByte8());

            // ext 16 (0xc8)
            case(0xc8): return readExt(readByte16());

            // ext 32 (0xc9)
            case(0xc9): return readExt(readByte32());
       
            // float 32 (0xca)
            case 0xca:
                float32Buffer.setUint32(0, readByte32());
                return float32Buffer.getFloat32(0);
            // float 64 (0xcb)
            case 0xcb:
                float64Buffer.setUint32(0, readByte32());
                float64Buffer.setUint32(4, readByte32());
                return float64Buffer.getFloat64(0);
        }

        throw new Error(`Unsupported byte: 0x${byte.toString(16)}`);
    }

    return decode();
}