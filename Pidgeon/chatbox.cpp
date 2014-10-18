//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include <QDateTime>
#include <QScrollBar>
#include "chatbox.h"
#include "ui_chatbox.h"

QString pidgeon::ChatBox::EncodeHtml(QString input)
{
    QString encoded;
    for(int i=0;i<input.size();++i)
    {
        QChar ch = input.at(i);
        if(ch.unicode() > 255)
            encoded += QString("&#%1;").arg((int)ch.unicode());
        else
            encoded += ch;
    }
    encoded = encoded.replace("<", "&lt;");
    encoded = encoded.replace(">", "&gt;");
    return encoded;
}

pidgeon::ChatBox::ChatBox(QWidget *parent) : QFrame(parent), ui(new Ui::ChatBox)
{
    this->ui->setupUi(this);
}

pidgeon::ChatBox::~ChatBox()
{
    delete this->ui;
}

void pidgeon::ChatBox::InsertText(QString text, pidgeon::TextMode mode)
{
    QString tx = this->ui->textEdit->toHtml();
    tx += EncodeHtml(QDateTime::currentDateTime().toString());
    tx += ": ";
    tx += EncodeHtml(text);
    tx += "<br>\n";
    this->ui->textEdit->setHtml(tx);
    this->ui->textEdit->verticalScrollBar()->setSliderPosition(this->ui->textEdit->verticalScrollBar()->maximum());
}
