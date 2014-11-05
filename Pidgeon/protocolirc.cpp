//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "protocolirc.h"
#include "network.h"
#include "items.h"
#include "chatbox.h"
#include "configuration.h"

using namespace pidgeon;

ProtocolIRC::ProtocolIRC()
{
    this->network = new Network();
    this->SystemWin = new ChatBox();
}

ProtocolIRC::~ProtocolIRC()
{
    delete this->SystemWin;
    delete this->network;
}

bool ProtocolIRC::IsConnected()
{
    return this->network->IsConnected();
}

void ProtocolIRC::Connect()
{
    //this->network->Connect();
    // let's create a new connection to irc server

}

void ProtocolIRC::Disconnect()
{
    this->network->Disconnect();
}

void ProtocolIRC::Register()
{
    // let's register this chat box as parent of root
    this->SystemWin->ParentItem = Items::List->SystemWindow;
    this->SystemWin->Item = new QStandardItem(this->Hostname);
    Items::List->db.insert(this->SystemWin->Item, this->SystemWin);
    Items::List->SystemWindow->appendRow(this->SystemWin->Item);
}
