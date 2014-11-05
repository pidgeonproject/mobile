//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU Lesser General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU Lesser General Public License for more details.

// Copyright (c) Petr Bena 2014

#ifndef PROTOCOLIRC_H
#define PROTOCOLIRC_H

#include "protocol.h"
#include <QString>

namespace pidgeon
{
    class ChatBox;
    class Network;
    class ProtocolIRC : Protocol
    {
        public:
            ProtocolIRC();
            ~ProtocolIRC();
            bool IsConnected();
            void Connect();
            void Disconnect();
            void Register();
            //! Port we use to connect to the irc server
            int Port;
            ChatBox *SystemWin;
            QString Hostname;

        private:
            Network *network;
    };
}

#endif // PROTOCOLIRC_H
