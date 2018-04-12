/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

//#include <QtWidgets>

#include "codeeditor.h"

//![constructor]

/*Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPushButton *push1 = new QPushButton(tr("ensure"));

    codeeditor1 = new CodeEditor();
    QVBoxLayout *vb = new QVBoxLayout;
    vb->addWidget(push1);
    vb->addWidget(codeeditor1);
    vb->addWidget(edit1);
    this->setLayout(vb);
    connect(push1,SIGNAL(pressed()),this,SLOT(edit_input_string()));

}

void Widget::edit_input_string()
{
    codeeditor1->appendPlainText("->"+edit1->text());
}*/

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));//文本框显示的文本行数改变，行数显示区宽度跟着改变
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));//当在文本区滑动滚动条，行数显示区跟着变动。
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));//光标位置改变，高亮行位置改变

    updateLineNumberAreaWidth(0);//设置初始行数显示区宽度
    highlightCurrentLine();//设置高亮行初始位置
}

//![constructor]

//![extraAreaWidth]

int CodeEditor::lineNumberAreaWidth()//设置行数显示区宽度
{
    int digits = 1;
    int max = qMax(1, blockCount());//文本中文本块的值
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

    return space;
}

void CodeEditor::setCursorPos(int row, int col)
{
    //QTextEdit::document
    const QTextBlock block = QPlainTextEdit::document()->findBlockByLineNumber(row);
    if(block.isValid())
    {
        QTextCursor cursor = QPlainTextEdit::textCursor();
        cursor.setPosition(block.position()+col-1);
        setFocus();
        setTextCursor(cursor);
        ensureCursorVisible();
    }

}

//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)//更新行数显示区宽度
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0); //设置纯文本框周围的边距
}

//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]

//更新数值显示区的滚轮、位置坐标、大小、宽度
void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)//当滑动动滚动条，行数显示区跟着滚动
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

//![slotUpdateRequest]

//![resizeEvent]
//更新行显示区的位置坐标和大小
void CodeEditor::resizeEvent(QResizeEvent *e)//QPlainTextEdit 大小改变事件。纯文本框大小改变，更新行数显示区的位置坐标、宽、高。
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();  //返回内容矩形的坐标
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));//设置行数显示区的位置坐标和大小
}

//![resizeEvent]

//![cursorPositionChanged]

void CodeEditor::highlightCurrentLine() //高亮光标当前行
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;//在一个文件被选择的区域提供指定的一个字符串

        QColor lineColor = QColor(Qt::yellow).lighter(160);//高亮颜色设置

        selection.format.setBackground(lineColor);//高亮背景
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);//高亮形式
        selection.cursor = textCursor();//设置光标形式为文本光标
        selection.cursor.clearSelection();//通过将锚点位置设置为光标位置来清除当前选择
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);//立刻标记指定区域
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

//纯文本事件，将行显示区画到纯文本框中，并且当文本框中的文本行数改变，行数显示框跟着改变
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)//QPaintEvent包含画事件的事件参数
{
    QPainter painter(lineNumberArea);//在CodeEditor中画行数显示区。Qpainter 在widget和其他可以画的设备上执行低级别的画。画行数显示区
    painter.fillRect(event->rect(), Qt::lightGray);//设置行数显示区的背景色为高亮灰
//QPaintEvent.rect()返回需要去更新的矩形
//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();//QTextBlock:在一个文本文件中给文本段提供了一个容器。第一个可见的块
    int blockNumber = block.blockNumber();//块的数值
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
//blockBoundingGeometry返回文本块内容坐标的边框，
//translated(const QPoint &offset):相对于当前位置,沿着x轴的offset.x()和沿着y轴的offset.y()转化的矩形的副本
//contentoffset():返回文本内容在视觉接口盖的原点坐标
    int bottom = top + (int) blockBoundingRect(block).height();//文本块边框周围的坐标
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]//event()->rect().bottom()返回矩形的底部值
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);//将块的值转化为字符串
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
//QPainter::drawText(int x,int y,int width,int height,int flags,const QString &text,QRect *boundingRect = Q_NULLPTR)
//在给定坐标、宽、高的矩形内画指定的文本
        }

        block = block.next();//下一个文本块
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();//块周围矩形的高
        ++blockNumber;
    }
}
//![extraAreaPaintEvent_2]

