#!/usr/bin/env python3
"""Render annotated excerpts from the captured Ghidra output, not UI screenshots."""
from pathlib import Path
import textwrap
from PIL import Image, ImageDraw, ImageFont

ROOT = Path(__file__).resolve().parents[1]
FOLDER = ROOT / "docs/evidence"

def font(size, mono=False):
    candidates = (["/System/Library/Fonts/Menlo.ttc", "DejaVuSansMono.ttf"] if mono
                  else ["/System/Library/Fonts/Helvetica.ttc", "DejaVuSans.ttf"])
    for path in candidates:
        try:
            return ImageFont.truetype(path, size)
        except OSError:
            pass
    return ImageFont.load_default(size=size)

def excerpt(name, ranges):
    lines = (FOLDER / f"{name}.c").read_text().splitlines()
    chosen = []
    for index, (start, end) in enumerate(ranges):
        if index:
            chosen.append("      ... omitted ...")
        chosen.extend(f"{number:3d} | {lines[number-1].strip()}" for number in range(start, end+1))
    return chosen

cards = [
    ("warmup-loop", "The loop's comparison is visible", "WARMUP / 0x100005bd4",
     [(64,64),(69,69),(77,83)],
     "Two indexed loads feed a widened sum and a target comparison. The matching branch stores two indices and returns.",
     "The function's name survives in the debug binary. Ghidra warns that the Rust calling convention is unknown; its inferred parameter types are not source truth."),
    ("warmup-hash", "Lookup happens before insertion", "WARMUP / 0x100005d84",
     [(66,79)],
     "The complement is looked up first. A match returns; only the no-match path reaches entry and or_insert.",
     "This call structure supports the hash-map interpretation. A timing comparison on a few tiny inputs would not establish it."),
    ("challenge-loop", "Optimization leaves a compact loop", "CHALLENGE / 0x1000015a8",
     [(21,38)],
     "The outer index grows, the inner scan stops at that index, and a matching sum stores the earlier index first. Behavior probes agree with this reading.",
     "The stripped Mach-O still contains algorithm name fragments in its export trie. Treat stripping and loss of names as separate observations."),
]

for name, title, location, ranges, observation, limitation in cards:
    im = Image.new("RGB", (1600,1000), "#faf9f6")
    d = ImageDraw.Draw(im)
    d.rectangle((0,0,1600,12), fill="#ba482b")
    d.text((60,38), "RUST TUESDAY / REAL BINARY EVIDENCE", font=font(19), fill="#56616a")
    d.text((60,82), title, font=font(43), fill="#1d2830")
    d.text((60,141), location + "  /  REA 6.5.0 + Ghidra 12.1.4", font=font(22), fill="#ba482b")
    d.rounded_rectangle((60,190,1540,735), radius=12, fill="#202a33")
    y=214
    for line in excerpt(name,ranges):
        for part in textwrap.wrap(line, width=112, subsequent_indent="      ", replace_whitespace=False, drop_whitespace=False) or [""]:
            d.text((82,y),part,font=font(20,True),fill="#f6f3ed")
            y+=26
    assert y < 725, (name,y)
    y=760
    for label, text in [("INTERPRETATION",observation),("LIMIT",limitation)]:
        d.text((60,y),label,font=font(18),fill="#ba482b")
        for line in textwrap.wrap(text,width=109):
            d.text((265,y),line,font=font(20),fill="#1d2830")
            y+=28
        y+=12
    assert y < 964,(name,y)
    d.text((60,968),f"Annotated excerpt from {name}.c; original line numbers retained. Not a UI screenshot.",font=font(17),fill="#56616a")
    im.save(FOLDER/f"{name}.png")
    print(FOLDER/f"{name}.png")
