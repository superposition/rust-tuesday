#!/usr/bin/env python3
"""Create a visual record of the completed rehearsal from checked-in evidence.

Requires reportlab (requirements-pdf.txt). All source excerpts are read from the
repository. Layout and narrative are editable here; no network or REA run needed.
"""
from pathlib import Path
from html import escape
import json
import textwrap

from reportlab.lib import colors
from reportlab.lib.styles import ParagraphStyle
from reportlab.pdfbase.pdfmetrics import stringWidth
from reportlab.pdfgen import canvas
from reportlab.platypus import Paragraph

ROOT = Path(__file__).resolve().parents[1]
EVIDENCE = ROOT / 'docs/evidence'
OUTPUT = ROOT / 'output/pdf/rust-tuesday-walkthrough.pdf'
W, H = 960, 640
M, CW = 48, 864
INK = '#202c32'
RUST = '#b84c2f'
MUTED = '#5c696e'
PAPER = '#f7f4ed'
PALE = '#e9e5dc'
TEAL = '#226a61'
WHITE = '#ffffff'
CODE = '#182a32'
LIGHT = '#edf2ef'
TOTAL = 10
REPO = 'https://github.com/superposition/rust-tuesday'
PAGE = 0

OUTPUT.parent.mkdir(parents=True, exist_ok=True)
c = canvas.Canvas(str(OUTPUT), pagesize=(W, H), pageCompression=1)
c.setTitle('Rust Tuesday - What we built and what the binary revealed')
c.setAuthor('Rust Tuesday')
c.setSubject('Visual record of a Rust and REA technical rehearsal, 15 October 2026')


def rect(x, y, w, h, fill, radius=0):
    c.setFillColor(colors.HexColor(fill))
    if radius:
        c.roundRect(x, H-y-h, w, h, radius, fill=1, stroke=0)
    else:
        c.rect(x, H-y-h, w, h, fill=1, stroke=0)


def line(x1, y1, x2, y2, color=PALE, width=1):
    c.setStrokeColor(colors.HexColor(color))
    c.setLineWidth(width)
    c.line(x1, H-y1, x2, H-y2)


def label(text, x, y, size=10, color=MUTED, font='Helvetica-Bold'):
    c.setFillColor(colors.HexColor(color))
    c.setFont(font, size)
    c.drawString(x, H-y-size, text)


def p(text, x, y, w, size=14, color=INK, bold=False, max_h=None):
    style = ParagraphStyle('p', fontName='Helvetica-Bold' if bold else 'Helvetica',
                           fontSize=size, leading=size*1.35, textColor=colors.HexColor(color))
    paragraph = Paragraph(text, style)
    _, h = paragraph.wrap(w, 1000)
    if max_h is not None and h > max_h:
        raise ValueError(f'Paragraph overflow on page {PAGE}: {text[:70]} ({h}>{max_h})')
    if y+h > H-62:
        raise ValueError(f'Paragraph runs into footer on page {PAGE}: {text[:70]}')
    paragraph.drawOn(c, x, H-y-h)
    return y+h


def code(text, x, y, w, size=11, highlights=()):
    """Native PDF text, with explicit width checks; returns bottom coordinate."""
    lines = text.rstrip().splitlines()
    leading = size*1.45
    height = 30+len(lines)*leading
    if y+height > H-62:
        raise ValueError(f'Code runs into footer on page {PAGE}')
    rect(x, y, w, height, CODE, 7)
    for i, row in enumerate(lines):
        if stringWidth(row, 'Courier', size) > w-32:
            raise ValueError(f'Code too wide on page {PAGE}: {row}')
        if i in highlights:
            rect(x+6, y+13+i*leading, w-12, leading, '#2d494d', 2)
        label(row, x+16, y+14+i*leading, size, LIGHT, 'Courier')
    return y+height


def excerpt(path, first, last, width=74):
    """Preserve source line labels and wrap long lines with an indented continuation."""
    lines = (ROOT/path).read_text().splitlines()
    result = []
    for n in range(first, last+1):
        pieces = textwrap.wrap(lines[n-1], width=width-5, replace_whitespace=False,
                               drop_whitespace=False, break_long_words=True) or ['']
        result.append(f'{n:>3}  {pieces[0]}')
        result.extend('     '+part for part in pieces[1:])
    return '\n'.join(result)


def start(kicker, title, subtitle=None):
    global PAGE
    if PAGE:
        c.showPage()
    PAGE += 1
    rect(0, 0, W, H, PAPER)
    rect(0, 0, 9, H, RUST)
    label('RUST TUESDAY', M, 26, 10, RUST)
    label(kicker.upper(), 186, 26, 10)
    label('EXECUTED REHEARSAL / 15 OCT 2026', 680, 26, 9)
    p(title, M, 65, CW, 31, bold=True, max_h=45)
    if subtitle:
        p(subtitle, M, 113, CW, 13, MUTED, max_h=38)
    line(M, H-49, W-M, H-49)
    label('superposition/rust-tuesday', M, H-34, 9, MUTED, 'Helvetica')
    c.linkURL(REPO, (M, 17, 195, 33), relative=0)
    label(f'{PAGE:02d} / {TOTAL:02d}', W-M-40, H-34, 9)


def source(text):
    label('RECORD  '+text, M, 564, 8.1, MUTED, 'Helvetica')


def arrow(x, y, length=32, color=RUST):
    line(x, y, x+length, y, color, 1.8)
    line(x+length-6, y-4, x+length, y, color, 1.8)
    line(x+length-6, y+4, x+length, y, color, 1.8)


def card(x, y, w, h, number, title, body):
    rect(x, y, w, h, WHITE, 8)
    label(number, x+18, y+15, 11, RUST)
    p(title, x+18, y+41, w-36, 18, bold=True, max_h=50)
    p(body, x+18, y+101, w-36, 13, MUTED, max_h=h-113)


manifest = json.loads((EVIDENCE/'binaries.json').read_text())
retained = json.loads((EVIDENCE/'retained-exports.json').read_text())
probes = json.loads((EVIDENCE/'behavior.json').read_text())['cases']
comparison = (EVIDENCE/'comparison.txt').read_text().splitlines()[0]
assert comparison.startswith('PASS: 225 ')

# 1: A result-first map, with a clear account of the artifact's limits.
start('The whole route', 'What we built. What the binary revealed.',
      'A visual record of the work behind the two-hour Rust Tuesday workshop.')
for x, num, title, body in [
    (48, '01 / WRITE', 'One problem,<br/>two strategies', 'Two Sum as a small CLI. Functions, traits, impl blocks and a fixed output contract.'),
    (270, '02 / COMPILE', 'Make two<br/>native binaries', 'A debug build for orientation. An optimized, stripped build for investigation.'),
    (492, '03 / INSPECT', 'Follow the<br/>machine evidence', 'REA drives Ghidra. Search, cross-references and decompilation reveal the path.'),
    (714, '04 / CHECK', 'Rebuild the<br/>behavior', 'A separate implementation is compared with the original through its CLI.')]:
    card(x, 178, 198, 228, num, title, body)
rect(48, 435, 248, 105, TEAL, 8)
p('225 / 225', 68, 447, 210, 35, WHITE, bold=True)
p('CLI comparisons agreed', 68, 497, 210, 13, WHITE)
p('This PDF shows actions already executed.', 324, 444, 580, 18, bold=True)
p('The author had seen the reference source. This is a technical rehearsal; a blind solve and a timed session with learners are still to come.', 324, 478, 570, 14, MUTED, max_h=60)
source('docs/evidence/README.md; docs/VERIFICATION.md; docs/evidence/comparison.txt')

# 2: Rust concepts attached to concrete code, without a full source dump.
start('01 / Write', 'Give the program one job.',
      'Find two distinct indices whose values add to the target. Return the earliest j, then the earliest i.')
code('$ cargo run -- a 9 2 7 11 15\n0 1\n$ cargo run -- b 6 3 3\n0 1\n$ cargo run -- a 6 3\nnone', 48, 166, 420, 13)
p('Same contract, different implementation', 504, 171, 390, 19, bold=True)
p('<b>Mode a / BruteForce</b><br/>Try each earlier index for each j.<br/>O(n squared) time, O(1) extra space.', 504, 210, 385, 14, max_h=65)
p('<b>Mode b / HashLookup</b><br/>Remember earlier values and their first index.<br/>Expected O(n) time, O(n) extra space.', 504, 287, 385, 14, max_h=65)
code(excerpt(Path('src/lib.rs'), 5, 7), 48, 352, 864, 12)
concepts = [
    ('trait', 'PairSearch defines the shared find operation.'),
    ('impl Trait for Type', 'BruteForce and HashLookup each supply it.'),
    ('impl Request', 'parse creates a request; run borrows it.'),
    ('free function + generic', 'parse_number parses; solve<S> calls find.')]
for i, (term, meaning) in enumerate(concepts):
    x = 48+(i%2)*444
    y = 456+(i//2)*45
    label(term, x, y, 10, RUST, 'Courier-Bold')
    p(meaning, x, y+17, 414, 12, max_h=25)
source('src/lib.rs; src/main.rs; docs/evidence/behavior.json')

# 3: Actual proportional file-size bars and captured procedure counts.
start('02 / Compile', 'Build a readable warmup and a harder challenge.',
      'Both are native Mach-O ARM64 executables from Rust 1.90.0 on the prepared Mac.')
code('$ bash scripts/package-binaries.sh', 48, 164, 864, 13)
for y, name, color, count, desc in [
    (248, 'warmup', TEAL, '1,014', 'opt=0  /  debug=2  /  strip=none'),
    (366, 'challenge', RUST, '754', 'opt=3  /  debug=0  /  strip=symbols')]:
    entry = manifest['binaries'][name]
    label(name.upper(), 48, y, 11, color)
    label(desc, 48, y+22, 11, MUTED, 'Courier')
    bar_w = 570*entry['bytes']/manifest['binaries']['warmup']['bytes']
    rect(48, y+47, bar_w, 29, color, 3)
    label(f"{entry['bytes']:,} bytes", 60, y+52, 13, WHITE)
    p(count, 712, y+3, 180, 29, bold=True)
    p('Ghidra procedures', 712, y+42, 180, 12, MUTED)
reduction = 100*(1-manifest['binaries']['challenge']['bytes']/manifest['binaries']['warmup']['bytes'])
p(f'The challenge is {reduction:.1f}% smaller. Optimization changes the shape of the code.', 48, 480, 864, 19, bold=True)
p('Sizes and counts identify this run. Counts are analysis results, not a one-to-one map to Rust source functions. Exact SHA-256 identities are recorded with the binaries.', 48, 514, 864, 13, MUTED, max_h=37)
source('docs/evidence/binaries.json; warmup-overview.json; challenge-overview.json')

# 4: The real installation issue and tool boundaries.
start('03 / Prepare the analysis tools', 'Make the analysis engine work on this Mac.',
      'REA 6.5.0 + Ghidra 12.1.4 + Node 24.12.0 + OpenJDK 21.0.9.')
for x, title, body in [
    (48, 'Shell commands', 'I choose the binary and ask a specific question.'),
    (348, 'REA', 'Runs the analysis request and returns structured evidence.'),
    (648, 'Ghidra', 'Imports machine code, finds references and decompiles.')]:
    rect(x, 171, 264, 123, WHITE, 7)
    p(title, x+17, 188, 230, 19, bold=True)
    p(body, x+17, 224, 230, 13, MUTED, max_h=54)
arrow(316, 232, 27)
arrow(616, 232, 27)
label('ACTUAL OBSTACLE', 48, 325, 10, RUST)
p('The first doctor check failed.', 48, 348, 355, 23, bold=True)
p('The archive lacked a macOS ARM64 native decompiler. I built that component from the bundled source, then repeated the check.', 48, 392, 355, 14, max_h=90)
code('make -j8 ghidra_opt \\\n  ARCH_TYPE="-arch arm64" \\\n  OSDIR=mac_arm_64\n\n# after installing the built decompiler:\nbash scripts/rea.sh doctor \\\n  --provider ghidra --json', 444, 326, 468, 12)
p('Scoped doctor: healthy', 444, 496, 450, 17, TEAL, bold=True)
p('Full build directory and install steps: docs/LOCAL-TOOLS.md', 444, 525, 450, 11, MUTED)
source('docs/LOCAL-TOOLS.md; docs/evidence/doctor.json; docs/VERIFICATION.md')

# 5: Exact captured code rendered as selectable vector text.
start('04 / Inspect the warmup', 'Recognize the loop inside the pseudocode.',
      'The procedure search found BruteForce::find at 0x100005bd4. The excerpt below is captured output.')
code('bash scripts/rea.sh search "$PWD/artifacts/warmup/pair-finder" \\\n  find --kind procedures --provider ghidra --json', 48, 163, 864, 12)
code(excerpt(Path('docs/evidence/warmup-loop.c'), 77, 83, width=72), 48, 249, 570, 11.5, highlights=(0, 2, 3, 4))
p('What I can read here', 648, 253, 264, 20, bold=True)
p('<b>Compare:</b> two sign-extended 32-bit values are added and checked against the target.', 648, 292, 264, 13, max_h=75)
p('<b>Return:</b> two index slots and a success tag are written, then execution leaves.', 648, 376, 264, 13, max_h=75)
rect(48, 430, 570, 112, WHITE, 7)
p('A trait does not automatically imply a vtable.', 65, 444, 535, 18, bold=True)
p('The captured solve caller makes a direct call to the concrete BruteForce implementation. This is consistent with the generic solve&lt;S: PairSearch&gt; used in our source.', 65, 477, 533, 13, max_h=55)
p('Ghidra warns about __rustcall. These inferred C-like types are clues; they are not recovered Rust declarations.', 648, 470, 264, 12, MUTED, max_h=72)
source('docs/evidence/warmup-find.json; warmup-loop.c:77-83; warmup-caller.c')

# 6: Source and captured evidence aligned without inventing full source recovery.
start('05 / Inspect the second strategy', 'Find the missing value before inserting.',
      'HashLookup::find was located at 0x100005d84. The ordering is the important clue.')
label('RUST SOURCE / src/lib.rs', 48, 164, 10, RUST)
code(excerpt(Path('src/lib.rs'), 30, 36, width=66), 48, 189, 468, 10.5)
label('CAPTURED DECOMPILATION / key operations', 548, 164, 10, RUST)
# Select actual full lines; common namespace prefix is abbreviated for a readable panel.
hash_lines = (EVIDENCE/'warmup-hash.c').read_text().splitlines()
selected = []
for n in (66, 67, 69, 78, 79):
    raw = hash_lines[n-1].strip().replace('std::collections::hash::map::', '')
    wrapped = textwrap.wrap(raw, width=45, replace_whitespace=False, drop_whitespace=False)
    selected.append(f'{n:>2}  {wrapped[0]}')
    selected.extend('    '+part for part in wrapped[1:])
code('\n'.join(selected), 548, 189, 364, 10.3)
p('Namespace prefix omitted above; original line numbers retained.', 548, 418, 364, 10, MUTED, max_h=29)
for x, title, body in [
    (48, '1. Subtract', 'needed = target - value. This is the partner value to search for.'),
    (348, '2. Look up', 'A match returns an earlier index. This prevents an item pairing with itself.'),
    (648, '3. Insert', 'Only after a miss, remember the value. or_insert keeps the first index.')]:
    label(title, x, 470, 16, TEAL)
    p(body, x, 500, 264, 12.5, max_h=52)
source('src/lib.rs:30-36; docs/evidence/warmup-hash.c:66-79; full unabridged pseudocode is in the repository')

# 7: A visual evidence trail with addresses from the specific binary.
start('06 / Investigate the challenge', 'Follow a visible string back to the program.',
      'The optimized build is harder to read. A usage string gives us a concrete starting point.')
steps = [
    ('Search strings', 'usage: pair-find', '0x10003b370'),
    ('Follow references', 'two references', '0x100000eb0 / 0x100000fa0'),
    ('Find enclosing function', 'FUN_100000e20', 'the command-line dispatcher'),
    ('Read the mode branch', "0x61 = 'a' / 0x62 = 'b'", 'loop / hash implementation')]
for i, (title, value, detail) in enumerate(steps):
    y = 168+i*87
    rect(48, y, 38, 38, RUST, 5)
    label(str(i+1), 61, y+7, 17, WHITE)
    if i < 3:
        line(67, y+43, 67, y+81, RUST, 1.5)
    label(title, 104, y, 11, RUST)
    p(escape(value), 104, y+20, 370, 17, bold=True, max_h=25)
    label(detail, 104, y+49, 10.3, MUTED, 'Courier')
code('bash scripts/rea.sh search \\\n  "$PWD/artifacts/challenge/pair-finder" \\\n  usage: --kind strings \\\n  --provider ghidra --json\n\nbash scripts/rea.sh xrefs \\\n  "$PWD/artifacts/challenge/pair-finder" \\\n  0x10003b370 --provider ghidra --json', 510, 169, 402, 10.6)
p('Loop: 0x1000015a8', 510, 355, 402, 17, bold=True)
p('41 raw pseudocode lines. The core is still a loop, addition and comparison.', 510, 385, 402, 13, MUTED, max_h=42)
p('Hash: 0x10000160c', 510, 440, 402, 17, bold=True)
p('348 raw lines, including table machinery. Useful as an extension to the core lesson.', 510, 470, 402, 13, MUTED, max_h=42)
p('Addresses identify the recorded binary. Rediscover them after rebuilding.', 48, 536, 864, 11, RUST)
source('docs/evidence/challenge-usage.json; challenge-usage-xrefs.json; challenge-main.c; challenge-loop.json; challenge-hash.json')

# 8: A measured diagram distinguishes bytes actually retained from assumptions.
start('07 / Check an assumption', 'Stripped does not mean anonymous.',
      'nm showed only 72 entries, but Ghidra still recovered algorithm names. I checked the raw binary.')
p('The names survived inside the Mach-O export trie.', 48, 171, 864, 22, bold=True)
start_offset, end_offset = retained['export_file_range']
label(f'LC_DYLD_INFO_ONLY / export bytes [{start_offset}, {end_offset})', 48, 219, 12, MUTED, 'Courier')
rect(48, 258, 864, 45, PALE, 5)
# Scale corresponds to the actual export range, rather than the full executable.
def offset_x(offset):
    return 48+864*(offset-start_offset)/(end_offset-start_offset)
px = offset_x(retained['name_fragment_file_offsets']['BruteForce'])
rect(px-3, 252, 10, 57, RUST, 2)
label(str(start_offset), 48, 314, 10, MUTED, 'Courier')
label(str(end_offset), 859, 314, 10, MUTED, 'Courier')
line(px+2, 310, 625, 363, RUST, 1.5)
rect(514, 364, 398, 136, CODE, 8)
label('RETAINED RAW BYTES', 532, 380, 10, '#9ebbb7')
for i, name in enumerate(('BruteForce', 'rust_tuesday', 'HashLookup')):
    label(f"{name:<14} @ {retained['name_fragment_file_offsets'][name]}", 532, 408+i*23, 13, LIGHT, 'Courier')
p('What changed in the lesson', 48, 375, 415, 22, bold=True)
p('Learners should recover behavior and support it with evidence. They should not receive credit for inferring names that still exist in the file.', 48, 419, 415, 15, max_h=83)
p('The observed boundary: optimized + stripped according to Cargo; algorithm name fragments still present.', 48, 533, 864, 12, MUTED)
source('docs/evidence/retained-exports.json; docs/evidence/challenge-loop.c')

# 9: Specific probes and a correctly bounded result.
start('08 / Reconstruct and compare', 'Make the replacement pass the same probes.',
      'I wrote reconstruction/main.rs, compiled it, and compared its CLI behavior with the stripped original.')
# Build table rows from the actual captured probe records.
label('ACTUAL PROBES / mode a unless shown', 48, 165, 11, RUST)
rows = [probes[i] for i in (0, 1, 2, 5, 8, 22)]
rect(48, 193, 544, 29, INK, 4)
label('ARGUMENTS', 62, 200, 10, WHITE)
label('STDOUT', 430, 200, 10, WHITE)
label('EXIT', 539, 200, 10, WHITE)
for i, row in enumerate(rows):
    y = 227+i*37
    rect(48, y, 544, 34, WHITE if i%2==0 else PALE, 3)
    label(' '.join(row['args']), 62, y+9, 10.6, INK, 'Courier')
    label(row['stdout'].strip() or '(empty)', 430, y+9, 10.5, INK, 'Courier')
    label(str(row['exit_code']), 548, y+9, 10.5, INK, 'Courier')
rect(624, 165, 288, 167, TEAL, 8)
p('225 / 225', 644, 183, 248, 39, WHITE, bold=True)
p('comparisons agreed', 644, 240, 248, 18, WHITE, bold=True)
p('2 modes x 110 valid cases<br/>+ 5 invalid cases', 644, 278, 248, 12.5, WHITE)
p('Compared', 624, 355, 288, 19, bold=True)
p('Exit code, stdout bytes, and whether stderr was present. Error wording was not compared.', 624, 389, 288, 14, max_h=76)
p('What the result supports', 48, 478, 544, 18, bold=True)
p('Agreement on these cases. The author knew the source, and both replacement modes use loops; this does not establish a blind solve, all-input correctness or the original hash performance.', 48, 511, 844, 12.5, MUTED, max_h=40)
source('docs/evidence/behavior.json; comparison.txt; scripts/compare-binaries.py; reconstruction/main.rs')

# 10: Restartable commands and the actual deliverables, not aspirational claims.
start('09 / Replay the work', 'The repo contains the lesson and the receipts.',
      'Use the reference for preparation; give learners their own scaffold and the investigation brief.')
code('git clone https://github.com/superposition/rust-tuesday.git\ncd rust-tuesday\ncargo test --locked\ncargo run -- a 9 2 7 11 15\nbash scripts/package-binaries.sh\n\n# After docs/LOCAL-TOOLS.md setup:\nbash scripts/rea.sh analyze \\\n  "$PWD/artifacts/warmup/pair-finder" --provider ghidra --json', 48, 168, 864, 11.6)
code('rustc --edition 2021 -O reconstruction/main.rs \\\n  -o artifacts/reconstructed-pair-finder\npython3 scripts/compare-binaries.py \\\n  artifacts/challenge/pair-finder artifacts/reconstructed-pair-finder', 48, 363, 864, 11.6)
p('Ready in the repository', 48, 475, 412, 18, bold=True)
p('Two-hour plan and PDF; learner starter; reference code; tests; binary packaging; captured REA evidence; this visual walkthrough.', 48, 508, 412, 12.5, MUTED, max_h=52)
p('Next for the workshop', 500, 475, 412, 18, bold=True)
p('Run a timed learner rehearsal and repeat the setup on the event machines. Linux, Windows and Intel Mac were not exercised.', 500, 508, 412, 12.5, MUTED, max_h=52)
source('README.md; docs/WORKSHOP.md; docs/LOCAL-TOOLS.md; docs/VERIFICATION.md; evidence recorded 15 October 2026')

assert PAGE == TOTAL
c.save()
print(OUTPUT)
print(f'{PAGE} pages; render and inspect before delivery.')
