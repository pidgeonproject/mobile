//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#ifndef CHATBOX_H
#define CHATBOX_H

#include <QString>
#include <QFrame>

namespace Ui
{
    class ChatBox;
}

namespace pidgeon
{
    enum TextMode
    {
        TextMode_Channel,
        TextMode_User,
        TextMode_System
    };

    class ChatBox : public QFrame
    {
            Q_OBJECT
        public:
            static QString EncodeHtml(QString input);

            explicit ChatBox(QWidget *parent = 0);
            ~ChatBox();
            void InsertText(QString text, TextMode mode = TextMode_System);
            void ProcessInput(QString text);
            bool LayedOut;

        private slots:
            void on_lineEdit_returnPressed();

        private:
            QString TextBuffer;
            Ui::ChatBox *ui;
    };
}

#endif // CHATBOX_H
