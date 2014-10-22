//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#ifndef NETWORK_H
#define NETWORK_H

#include <QString>
#include <QList>
#include "protocol.h"

namespace pidgeon
{
    class Network
    {
        public:
            static Network *MainNetwork;
            static QList<Network*> Networks;
            Network();
            ~Network();
            void Connect();
            void Disconnect();
            bool IsConnected();
            QString Name;
            QString Nickname;
            QString Ident;
            QString Hostname;
        private:
            bool isConnected;
    };
}

#endif // NETWORK_H
