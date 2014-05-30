/**
 * (C) LGPL-3
 *
 * Tasteful Server <https://github.com/scheibel/tasteful-server>
 *
 * Copyright: 2012-2014 Lux, Scheibel
 * Authors:
 *     Roland Lux <rollux2000@googlemail.com>
 *     Willy Scheibel <willyscheibel@gmx.de>
 *
 * This file is part of Tasteful Server.
 *
 * Tasteful Server is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Tasteful Server is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Tasteful Server.  If not, see <http://www.gnu.org/licenses/>.
 **/

#pragma once

#include <tastefulserver/tastefulserver_api.h>

#include <tastefulserver/AbstractSocket.h>
#include <tastefulserver/HttpRequestParser.h>
#include <tastefulserver/http.h>

namespace tastefulserver {

class HttpSocketHandler;

class TASTEFULSERVER_API HttpSocket : public AbstractSocket
{
public:
    HttpSocket(HttpSocketHandler * handler);

    void send(const HttpResponse & response);

    void disconnect();
protected:
    virtual void receiveData(const QByteArray & data) override;

    HttpSocketHandler * m_handler;
    HttpRequestParser m_parser;
    HttpRequest m_request;

    virtual void addConnectionInfo(HttpRequest & request);

    virtual QAbstractSocket * createSocket(qintptr socketDescriptor) override;

protected slots:
    void badRequest();
};

} // namespace tastefulserver
