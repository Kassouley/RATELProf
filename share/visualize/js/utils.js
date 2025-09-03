function printArgs(obj, indentLevel = 0) {
  let html = '';
  const indentClass = 'indent'.repeat(indentLevel);

  for (const key in obj) {
    const field = obj[key];
    if (typeof field === 'object' && field !== null) {
      if (field.type != undefined && field.value != undefined) {
        html += `<div class="${indentClass}"><span class="type">${field.type}</span> <span class="key">${key}</span> =  `;
        if (field.value["->*"]) {
          const keys = Object.keys(field.value);
          keys.forEach((subfield, index) => {
            if (index < keys.length - 1) {
              html += `<span class="value">${field.value[subfield]}</span> -> `;
            } else {
              html += printArgs(field.value[subfield], indentLevel + 1);
            }
          });
          html += `</div>`;
        } else if (typeof field.value === 'object') {
          html += `{<div class="indent">`;
          html += printArgs(field.value, indentLevel + 1); 
          html += `</div>}</div>`;
        } else {
          html += `<span class="value">${field.value}</span></div>`;
        }
      } else {
        html += `<div class="${indentClass}"><span class="key">${key}</span> = {<div class="indent">`;
        html += printArgs(field, indentLevel + 1); 
        html += `</div>}</div>`;
      }
    }
  }
  return html;
}

function escapeHTML(input) {
  if (typeof input !== "string") return input;
  if (!input) return "";
  return input
    .replace(/&/g, "&amp;")
    .replace(/</g, "&lt;")
    .replace(/>/g, "&gt;")
    .replace(/"/g, "&quot;")
    .replace(/'/g, "&#039;");
}


function hashStringToLightColor(str) {
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
    return color;
}


function convertBytes(bytes) {
    if (bytes === 0) return '0 Bytes';
  
    const units = ['Bytes', 'KB', 'MB', 'GB'];
    const size = Math.floor(Math.log(bytes) / Math.log(1024));
    const formattedSize = bytes / Math.pow(1024, size);
  
    return `${formattedSize % 1 === 0 ? formattedSize.toFixed(0) : formattedSize.toFixed(2)} ${units[size]}`
}


// Throttle utility
function throttle(fn, wait) {
    let lastTime = 0;
    let timeout = null;
    return function (...args) {
    const now = Date.now();
    if (now - lastTime >= wait) {
        lastTime = now;
        fn.apply(this, args);
    } else if (!timeout) {
        timeout = setTimeout(() => {
            lastTime = Date.now();
            timeout = null;
            fn.apply(this, args);
        }, wait - (now - lastTime));
    }
  };
}


function convertTime(time, isNanosecond = true) {
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
        if (seconds > 0) result.push(`${seconds} s`) 
    } 
    else if (seconds > 0) {
        result.push(`${seconds} s`);
        if (milliseconds > 0) result.push(`${milliseconds} ms`)
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

function convertToNs(input) {
      if (!input) {
        alert('Please enter a value.');
        return;
      }
      const tokens = input.split(/\s+/); // split by spaces
      let totalNs = 0;
      const regex = /^(\d+)(ns|us|ms|s)?$/i; // match exactly one token

      for (const token of tokens) {
        const match = token.match(regex);
        if (!match) {
          alert(`Invalid token: "${token}"`);
          return;
        }

        const value = Number(match[1]);
        const unit = (match[2] || 'ns').toLowerCase();

        switch (unit) {
          case 's':
            totalNs += value * 1e9;
            break;
          case 'ms':
            totalNs += value * 1e6;
            break;
          case 'us':
            totalNs += value * 1e3;
            break;
          case 'ns':
            totalNs += value;
            break;
          default:
            alert(`Unknown unit: ${unit}`);
            return;
        }
      }
      return totalNs;
    }

function truncate(str, maxLength = 30) {
    if (!str) return "";
    return str.length > maxLength ? str.substring(0, maxLength) + "..." : str;
}