// MumbleMove Server
//
// Copyright (C) 2020  Thomas Axelsson
//
// This file is part of MumbleMove.
//
// MumbleMove is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MumbleMove is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MumbleMove.  If not, see <https://www.gnu.org/licenses/>.
//

#include <QCoreApplication>
#include <QTimer>

#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    QTimer::singleShot(0, &server, &Server::run);

    return a.exec();
}
