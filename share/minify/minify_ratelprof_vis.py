import os
import sys
import subprocess
import shutil
import re


# Utility to read file content
def read_file(path):
    with open(path, "r", encoding="utf-8") as f:
        return f.read()

def write_file(path, content):
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

def replace_head_section(html_content: str) -> str:
    new_head = '''
<head>
    <meta charset="UTF-8">

    <link href="https://unpkg.com/vis-timeline@latest/styles/vis-timeline-graph2d.min.css" rel="stylesheet" type="text/css"/>
    <script src="https://unpkg.com/vis-timeline@latest/standalone/umd/vis-timeline-graph2d.min.js"></script>

    <link rel="stylesheet" href="style.css">
    <script src="script.js"></script>
</head>'''

    # Use regex to remove the current <head>...</head> block
    updated_html = re.sub(r"<head>.*?</head>", new_head, html_content, flags=re.DOTALL)
    return updated_html


def inline_web_workers(script_content):
    # Regex to match new Worker("path")
    worker_regex = r'new\s+Worker\s*\(\s*["\']([^"\']+)["\']\)'

    def replace_worker(match):
        worker_code_path = match.group(1)

        # Escape single quotes and backslashes in the worker code
        subprocess.run([MINIFY_SCRIPT, "-o", f"{TMP_DIR}/{worker_code_path}", f"{HTML_DIR}/{worker_code_path}"], check=True)
        worker_code_minified = read_file(f"{TMP_DIR}/{worker_code_path}").replace('\\', '\\\\').replace("'", "\\'")

        replacement = f"new Worker(URL.createObjectURL(new Blob(['{worker_code_minified}'],{{type:'application/javascript'}})))"
        return replacement

    # Replace all occurrences
    return re.sub(worker_regex, replace_worker, script_content)


SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Step 0: Output file from argument or default
output_file = sys.argv[1] if len(sys.argv) > 1 else "./index.min.html"

TMP_DIR = f"{SCRIPT_DIR}/tmp"
HTML_DIR = f"{SCRIPT_DIR}/../visualize"
MINIFY_SCRIPT = f"{SCRIPT_DIR}/minify"

# Step 1: Run minify commands
os.makedirs(TMP_DIR, exist_ok=True)

html_content = read_file(f"{HTML_DIR}/index.html")
html_content = replace_head_section(html_content)
write_file(f"{TMP_DIR}/index.min.html", html_content)

subprocess.run([MINIFY_SCRIPT, "--exclude='.*'", "-r", "-b", "-o", f"{TMP_DIR}/script.js", f"{HTML_DIR}/js/"], check=True)
subprocess.run([MINIFY_SCRIPT, "-r", "-b", "-o", f"{TMP_DIR}/style.css", f"{HTML_DIR}/css/"], check=True)
subprocess.run([MINIFY_SCRIPT, "-o", f"{TMP_DIR}/index.min.html", f"{TMP_DIR}/index.min.html"], check=True)

# Step 2: Read minified content
style_content       = read_file(f"{TMP_DIR}/style.css")
script_content      = read_file(f"{TMP_DIR}/script.js")
vis_style_content   = read_file(f"{HTML_DIR}/vis/vis-timeline-graph2d.min.css")
vis_script_content  = read_file(f"{HTML_DIR}/vis/vis-timeline-graph2d.min.js")
html_min_content    = read_file(f"{TMP_DIR}/index.min.html")

# Step 3: Define tags to replace
STYLE_TAG = '<link rel=stylesheet href=style.css>'
SCRIPT_TAG = '<script src=script.js></script>'

VIS_STYLE_TAG = '<link href=https://unpkg.com/vis-timeline@latest/styles/vis-timeline-graph2d.min.css rel=stylesheet>'
VIS_SCRIPT_TAG = '<script src=https://unpkg.com/vis-timeline@latest/standalone/umd/vis-timeline-graph2d.min.js></script>'

# Step 4: Define inline replacements
inline_style = f"<style>{style_content}</style>"
inline_script = f"<script>{inline_web_workers(script_content)}</script>"
vis_inline_style = f"<style>{vis_style_content}</style>"
vis_inline_script = f"<script>{vis_script_content}</script>"


# Step 5: Replace tags
html_min_content = html_min_content.replace(VIS_STYLE_TAG, vis_inline_style)
html_min_content = html_min_content.replace(VIS_SCRIPT_TAG, vis_inline_script)
html_min_content = html_min_content.replace(STYLE_TAG, inline_style)
html_min_content = html_min_content.replace(SCRIPT_TAG, inline_script)

# Step 6: Write final output
write_file(output_file, html_min_content)

# Step 7: Clean up temporary files
# shutil.rmtree(TMP_DIR, ignore_errors=True)

print(f"✅ Minification and inlining complete: {output_file}")