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
#include "ui_window.h"

using namespace pidgeon;

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    this->ui->setupUi(this);
    this->Root = new ChatBox(this);
    this->Chats.insert(0, Root);
    this->ui->verticalLayout->addWidget(this->Root);
    this->Root->InsertText("Welcome to pidgeon, you can use command /server <hostname> to connect to an IRC server");
}

Window::~Window()
{
    delete this->ui;
}
