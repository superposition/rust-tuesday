#!/usr/bin/env python3
"""Render the workshop Markdown as a paginated, printable A4 guide."""
from pathlib import Path
from html import escape

from markdown_it import MarkdownIt
from reportlab.lib import colors
from reportlab.lib.enums import TA_LEFT
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib.pagesizes import A4
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, Preformatted, PageBreak,
    Flowable,
)

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "docs/WORKSHOP.md"
OUTPUT = ROOT / "output/pdf/rust-tuesday-workshop.pdf"
INK = colors.HexColor("#1d2830")
MUTED = colors.HexColor("#56616a")
RUST = colors.HexColor("#ba482b")
PALE = colors.HexColor("#f3f1ed")
PAGE_W, PAGE_H = A4
WIDTH = PAGE_W - 96

STYLES = {
    "body": ParagraphStyle("body", fontName="Helvetica", fontSize=10.1,
        leading=14.3, textColor=INK, spaceAfter=9),
    "h1": ParagraphStyle("h1", fontName="Helvetica-Bold", fontSize=25,
        leading=29, textColor=INK, spaceAfter=12),
    "cover": ParagraphStyle("cover", fontName="Helvetica-Bold", fontSize=42,
        leading=47, textColor=INK, spaceAfter=14),
    "h2": ParagraphStyle("h2", fontName="Helvetica-Bold", fontSize=14,
        leading=19, textColor=RUST, spaceAfter=17),
    "code": ParagraphStyle("code", fontName="Courier", fontSize=8.15,
        leading=11.6, textColor=INK, alignment=TA_LEFT),
    "item": ParagraphStyle("item", fontName="Helvetica", fontSize=10.1,
        leading=14.3, textColor=INK, leftIndent=13, firstLineIndent=-11,
        spaceAfter=6),
}

def inline(tokens):
    parts = []
    for token in tokens or []:
        if token.type == "text":
            parts.append(escape(token.content))
        elif token.type == "code_inline":
            parts.append(f'<font name="Courier" size="9">{escape(token.content)}</font>')
        elif token.type == "strong_open":
            parts.append("<b>")
        elif token.type == "strong_close":
            parts.append("</b>")
        elif token.type == "em_open":
            parts.append("<i>")
        elif token.type == "em_close":
            parts.append("</i>")
        elif token.type == "link_open":
            href = escape(token.attrGet("href"), quote=True)
            parts.append(f'<link href="{href}" color="#9d3b25"><u>')
        elif token.type == "link_close":
            parts.append("</u></link>")
        elif token.type in ("softbreak", "hardbreak"):
            parts.append(" " if token.type == "softbreak" else "<br/>")
    return "".join(parts)

class CodeBox(Flowable):
    def __init__(self, text):
        super().__init__()
        self.content = Preformatted(text.rstrip(), STYLES["code"])
        self.spaceBefore = 2
        self.spaceAfter = 12

    def wrap(self, width, height):
        self.width = width
        _, inside_height = self.content.wrap(width - 24, height)
        self.height = inside_height + 22
        # Refuse overflow rather than silently clipping a command.
        from reportlab.pdfbase.pdfmetrics import stringWidth
        for line in self.content.lines:
            if stringWidth(line, "Courier", STYLES["code"].fontSize) > width - 24:
                raise ValueError(f"Code line too wide: {line}")
        return self.width, self.height

    def draw(self):
        self.canv.setFillColor(PALE)
        self.canv.roundRect(0, 0, self.width, self.height, 5, fill=1, stroke=0)
        self.canv.setFillColor(RUST)
        self.canv.rect(0, 0, 2.3, self.height, fill=1, stroke=0)
        self.content.drawOn(self.canv, 12, 11)

def page_content(markdown, cover=False):
    tokens = MarkdownIt().parse(markdown)
    result = []
    index = 0
    list_stack = []
    item_prefix = None
    while index < len(tokens):
        token = tokens[index]
        if token.type == "heading_open":
            level = int(token.tag[1])
            style = "cover" if cover and level == 1 else ("h1" if level == 1 else "h2")
            result.append(Paragraph(inline(tokens[index + 1].children), STYLES[style]))
            index += 3
            continue
        if token.type == "bullet_list_open":
            list_stack.append(None)
        elif token.type == "ordered_list_open":
            list_stack.append(int(token.attrGet("start") or 1))
        elif token.type in ("bullet_list_close", "ordered_list_close"):
            list_stack.pop()
            result.append(Spacer(1, 3))
        elif token.type == "list_item_open":
            counter = list_stack[-1]
            item_prefix = "- " if counter is None else f"{counter}. "
            if counter is not None:
                list_stack[-1] += 1
        elif token.type == "list_item_close":
            item_prefix = None
        elif token.type == "paragraph_open":
            text = inline(tokens[index + 1].children)
            style = "item" if item_prefix is not None else "body"
            if item_prefix is not None:
                text = item_prefix + text
                item_prefix = ""
            result.append(Paragraph(text, STYLES[style]))
            index += 3
            continue
        elif token.type == "fence":
            result.append(CodeBox(token.content))
        index += 1
    return result

SECTIONS = SOURCE.read_text().split("<!-- page -->")
page_total = len(SECTIONS)

def chrome(canvas, doc):
    canvas.saveState()
    canvas.setFillColor(RUST)
    canvas.rect(0, PAGE_H - 8, PAGE_W, 8, fill=1, stroke=0)
    canvas.setFont("Helvetica-Bold", 8)
    canvas.setFillColor(MUTED)
    canvas.drawString(48, PAGE_H - 39, "RUST TUESDAY / WORKSHOP GUIDE")
    canvas.setFont("Helvetica", 8)
    canvas.drawRightString(PAGE_W - 48, PAGE_H - 39, "120 MIN / TWO SUM + REA")
    canvas.setStrokeColor(colors.HexColor("#d5d7d6"))
    canvas.line(48, 45, PAGE_W - 48, 45)
    canvas.setFillColor(MUTED)
    canvas.setFont("Helvetica", 8)
    canvas.drawString(48, 30, "superposition/rust-tuesday  |  native rehearsal verified")
    canvas.drawRightString(PAGE_W - 48, 30, f"{doc.page:02d} / {page_total:02d}")
    canvas.restoreState()

OUTPUT.parent.mkdir(parents=True, exist_ok=True)
document = SimpleDocTemplate(str(OUTPUT), pagesize=A4,
    rightMargin=48, leftMargin=48, topMargin=67, bottomMargin=62,
    title="Rust Tuesday - Build it. Strip it. Explain it.",
    author="Rust Tuesday", subject="Two-hour Rust and REA workshop")
story = []
for i, section in enumerate(SECTIONS):
    if i:
        story.append(PageBreak())
    story.extend(page_content(section, cover=(i == 0)))
document.build(story, onFirstPage=chrome, onLaterPages=chrome)
print(OUTPUT)
print(f"Expected pages: {page_total}; render and inspect before delivery.")
