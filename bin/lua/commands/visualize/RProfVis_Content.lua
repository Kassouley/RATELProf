local RProfVis_Content = {}

local BUCKET_PREFIX_CONTENT = [[
window.worker = new Worker(URL.createObjectURL(new Blob([`const b = atob("]]

local BUCKET_SUFFIX_CONTENT = [[
let o = 0;
const P = () => b.charCodeAt(o),
R8 = () => b.charCodeAt(o++),
R16 = () => R8() | R8() << 8,
R32 = () => (R16() | R8() << 16 | R8() << 24) >>> 0,
R64 = () => {
    const [l,h]=[R32(),R32()];
    return h >= 2097152 && console.warn("R64: value exceeds Number.MAX_SAFE_INTEGER"), h * 4294967296 + l
},
R = () => {
    const a = R8();
    if (a <= 127) return a;
    switch (a) {
        case 204: return R8();
        case 205: return R16();
        case 206: return R32();
        case 207: return R64()
    }
    throw new Error("Unsupported byte: 0x"+a.toString(16))
}, 
ntoc = (n) => {
let h = 0 | n;
h = 73244475 * (h ^ h >>> 16), h = 73244475 * (h ^ h >>> 16), h ^= h >>> 16;
return [((255 & h) >>> 1) + 128, ((h >>> 8 & 255) >>> 1) + 128, ((h >>> 16 & 255) >>> 1) + 128]
},
cb = new Uint8Array(12 * c),
pb = new Float64Array(8 * c),
fb = new Float64Array(c),
sb = new Float64Array(c),
db = new Float64Array(c),
gb = new Float64Array(c),
tb = new Float64Array(c),
ib = new Float64Array(c),
jb = new Float64Array(c);

self.onmessage = function(e) {
    const {off, th, eh} = e.data;
    const ep = (th - eh) / 2;

    let i = 0;
    const l = b.length
    while (o < l) {
        const [gid, tid] = [R(), R()];
        while (P() !== 0xc1) {
            let st = 0;
            if (P() === 0xc5) { o++; st = R(); }
            const [f, s, d, ii] = [R(), R(), R(), R()];
            let cid = 0;
            if (P() === 0xc4) { o++; cid = R(); }
            fb[i] = f;
            ib[i] = ii;
            jb[i] = cid;
            sb[i] = s;
            db[i] = d;
            gb[i] = gid;
            tb[i] = tid;

            let j = i*8;
            const y1 = off[gid][tid] + st * th + ep;
            pb[j++] = s;
            pb[j++] = y1;
            pb[j++] = s+d;
            pb[j++] = y1;
            pb[j++] = s+d;
            pb[j++] = y1+eh;
            pb[j++] = s;
            pb[j++] = y1+eh;

            j = i*12;
            const [r, g, b] = ntoc(f);
            cb[j++] = r; cb[j++] = g; cb[j++] = b;
            cb[j++] = r; cb[j++] = g; cb[j++] = b;
            cb[j++] = r; cb[j++] = g; cb[j++] = b;
            cb[j++] = r; cb[j++] = g; cb[j++] = b;

            i++;
        }
        o++;
    }
    self.postMessage({cb,pb,fb,sb,db,gb,tb,ib,jb},[cb,pb,fb,sb,db,gb,tb,ib,jb].map(x=>x.buffer));
};`], { type: 'application/javascript' })));
]]


function RProfVis_Content.write_bucket_prefix(filename)
    local f = ratelprof.fs.open_file(filename, "w")
    f:write(BUCKET_PREFIX_CONTENT)
    f:close()
end


function RProfVis_Content.write_bucket_suffix(filename, event_count)
    local f = ratelprof.fs.open_file(filename, "a")
    f:write("\");const c=", event_count, ";")
    f:write(BUCKET_SUFFIX_CONTENT)
    f:close()
end



return RProfVis_Content