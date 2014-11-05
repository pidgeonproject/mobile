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
#include "commands.h"
#include "chatbox.h"
#include "configuration.h"
#include "network.h"
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
    this->ui->textEdit->setHtml("");
    this->LayedOut = false;
    this->ParentItem = NULL;
    this->Item = NULL;
    // this is a workaround until qt can handle this we need the text to start a bottom, but valign
    // is clearly not working for some reason
    this->TextBuffer = "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>"\
                         "<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>";
}

pidgeon::ChatBox::~ChatBox()
{
    delete this->ui;
}

void pidgeon::ChatBox::InsertText(QString text, pidgeon::TextMode mode)
{
    //QString tx = this->ui->textEdit->toHtml();
    QString color;
    switch (mode)
    {
        // both user and channel have same color
        case TextMode_User:
        case TextMode_Channel:
            color = "#FFFFFF";
            break;
        case TextMode_System:
            color = "#91EB65";
            break;
    }
    this->TextBuffer += "<font color=\"" + color + "\">";
    this->TextBuffer += EncodeHtml(QDateTime::currentDateTime().toString());
    this->TextBuffer += ": ";
    this->TextBuffer += EncodeHtml(text);
    this->TextBuffer += "</font>\n";
    this->TextBuffer += "<br>\n";
    QString html = "<html><head></head><body><table height='100%' width='100%'><tr><td valign='bottom'>";
    html += this->TextBuffer;
    html += "</td></tr></table></body></html>";
    this->ui->textEdit->setHtml(html);
    this->ui->textEdit->verticalScrollBar()->setSliderPosition(this->ui->textEdit->verticalScrollBar()->maximum());
}

void pidgeon::ChatBox::ProcessInput(QString text)
{
    QString double_pr = Configuration::CommandPrefix + Configuration::CommandPrefix;
    if (text.startsWith(Configuration::CommandPrefix) && !text.startsWith(double_pr))
    {
        QString command = text.mid(1);
        QString parameters;
        if (command.contains(" "))
        {
            int x = command.indexOf(" ");
            parameters = command.mid(x + 1);
            command = command.mid(0, x);
        }
        if (command == "server")
        {
            if (parameters.isEmpty())
                goto missing;
            Commands::Server(parameters);
            return;
        }
        this->InsertText("Invalid command: " + command);
        return;
        missing:
            this->InsertText("Missing parameter");
            return;
    }
    else if (text.startsWith(double_pr))
        text = text.mid(1);
    if (!Network::MainNetwork || !Network::MainNetwork->IsConnected())
    {
        this->InsertText("Not connected");
        return;
    }
}

void pidgeon::ChatBox::on_lineEdit_returnPressed()
{
    this->ProcessInput(QString(this->ui->lineEdit->text()));
    this->ui->lineEdit->clear();
}
