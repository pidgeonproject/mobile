//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#ifndef WINDOW_H
#define WINDOW_H
#define ROOT 0

#include <QMainWindow>
#include <QHash>

namespace Ui
{
    class Window;
}

namespace pidgeon
{
    class ChatBox;
    // channels
    class Items;

    class Window : public QMainWindow
    {
            Q_OBJECT
        public:
            static Window * MainWindow;

            explicit Window(QWidget *parent = 0);
            ~Window();
            void SwitchChat(int id);
            void SwitchChat(ChatBox *chat);
            ChatBox *CurrentWindow;
            ChatBox *Root;

        private slots:
            void on_actionServers_channels_triggered();
            void on_actionExit_triggered();
            void on_actionSystem_window_triggered();

        private:
            QHash<int, ChatBox*> Chats;
            unsigned int LastChat;
            Ui::Window *ui;
    };
}

#endif // WINDOW_H
