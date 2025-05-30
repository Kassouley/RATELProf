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


function convertBytes(bytes) {
    if (bytes === 0) return '0 Bytes';
  
    const units = ['Bytes', 'KB', 'MB', 'GB'];
    const size = Math.floor(Math.log(bytes) / Math.log(1024));
    const formattedSize = bytes / Math.pow(1024, size);
  
    return `${formattedSize % 1 === 0 ? formattedSize.toFixed(0) : formattedSize.toFixed(2)} ${units[size]}`
}


function convertTime(time, isNanosecond = false) {
    let milliseconds, microseconds, nanoseconds, seconds, minutes;

    if (isNanosecond) {
        nanoseconds = time % 1e3;
        microseconds = Math.floor(time / 1e3) % 1e3;
        milliseconds = Math.floor(time / 1e6) % 1e3;
        seconds      = Math.floor(time / 1e9) % 60;
        minutes      = Math.floor(time / (1e9 * 60))
    } else {
        microseconds = time % 1e3;
        milliseconds = Math.floor(time / 1e3) % 1e3;
        seconds      = Math.floor(time / 1e6) % 60;
        minutes      = Math.floor(time / (1e6 * 60))
    } 

    let result = [];
    if (minutes > 0) {
        result.push(`${minutes} min`);
        if (seconds > 0) result.push(`${seconds}s`) 
    } 
    else if (seconds > 0) {
        result.push(`${seconds} s`);
        if (milliseconds > 0) result.push(`${milliseconds}ms`)
    }
    else if (milliseconds > 0) {
        result.push(`${milliseconds} ms`);
        if (microseconds > 0) result.push(`${microseconds} µs`)
    } 
    else if (microseconds > 0) {
        result.push(`${microseconds} µs`);
        if (nanoseconds > 0) result.push(`${nanoseconds} ns`)
    }
    else if (nanoseconds > 0) {
        result.push(`${nanoseconds} ns`);
    }

    return result.join(' ') 
}


