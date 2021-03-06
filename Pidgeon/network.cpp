//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#include "configuration.h"
#include "network.h"

using namespace pidgeon;

Network *Network::MainNetwork = NULL;
QList<Network*> Network::Networks;

Network::Network()
{
    this->isConnected = false;
    this->Nickname = Configuration::Nickname;
    this->Ident = Configuration::Ident;
}

Network::~Network()
{

}

void Network::Connect()
{

}

void Network::Disconnect()
{

}

bool Network::IsConnected()
{
    return this->isConnected;
}
