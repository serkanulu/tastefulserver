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

#include <tastefulserver/HttpHeader.h>
#include <tastefulserver/ContentType.h>

#include <QString>
#include <QList>
#include <QHash>

namespace tastefulserver {

class TASTEFULSERVER_API Part
{
public:
    Part();
    Part(const QList<HttpHeader> & headers, const QByteArray & content);

    bool hasHeader(const http::HeaderName & headerName) const;
    HttpHeader getHeader(const http::HeaderName & headerName) const;

    QList<HttpHeader> getHeaders() const;
    QByteArray getContent() const;

protected:
    QHash<QString, HttpHeader> headers;
    QByteArray content;
};

class TASTEFULSERVER_API MultiPart
{
public:
    MultiPart();
    MultiPart(const ContentType & type);

    void parse(const QByteArray & content);

    bool isFormData() const;

    QList<Part> getParts() const;

protected:
    ContentType type;
    QList<Part> parts;
};

} // namespace tastefulserver
