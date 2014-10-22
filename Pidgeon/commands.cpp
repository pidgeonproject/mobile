//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "commands.h"
#include "window.h"
#include "chatbox.h"

using namespace pidgeon;

void Commands::Server(QString params)
{
    int port = 6667;
    QString server = params;
    if (server.contains(" "))
    {
        port = params.mid(params.indexOf(" ") + 1).toInt();
        server = server.mid(0, server.indexOf(" "));
    }
    Window::MainWindow->CurrentWindow->InsertText("Connecting to " + server + " using port " + QString::number(port));
}
