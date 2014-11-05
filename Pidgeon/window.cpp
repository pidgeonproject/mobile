//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "window.h"
#include "chatbox.h"
#include "items.h"
#include "ui_window.h"

using namespace pidgeon;

Window *Window::MainWindow = NULL;

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    MainWindow = this;
    this->ui->setupUi(this);
    this->Root = new ChatBox(this);
    this->LastChat = 0;
    this->Chats.insert(0, Root);
    this->ui->verticalLayout->addWidget(this->Root);
    this->CurrentWindow = this->Root;
    Items::List = new Items(this);
    this->Root->InsertText("Welcome to pidgeon, you can use command /server <hostname> to connect to an IRC server");
}

Window::~Window()
{
    delete this->ui;
}

void Window::SwitchChat(int id)
{
    if (this->Chats.contains(id))
        this->SwitchChat(this->Chats[id]);
}

void Window::SwitchChat(ChatBox *chat)
{
    if (!this->Chats.values().contains(chat))
    {
        // we need to insert this new chat window to list
        this->LastChat++;
        this->Chats.insert(this->LastChat, chat);
    }
    this->CurrentWindow->hide();
    this->CurrentWindow = chat;
    if (!this->CurrentWindow->LayedOut)
    {
        this->CurrentWindow->LayedOut = true;
        this->ui->verticalLayout->addWidget(this->CurrentWindow);
    }
    this->CurrentWindow->show();
}

void pidgeon::Window::on_actionServers_channels_triggered()
{
    Items::List->show();
}

void pidgeon::Window::on_actionExit_triggered()
{
    QApplication::exit();
}

void pidgeon::Window::on_actionSystem_window_triggered()
{
    this->SwitchChat(ROOT);
}
