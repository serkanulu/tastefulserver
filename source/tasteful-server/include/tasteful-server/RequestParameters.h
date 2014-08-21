#pragma once

#include <QSharedPointer>

#include <tasteful-server/tasteful-server_api.h>

class QString;
class QByteArray;

namespace tastefulserver {

class QVariantAbstractTree;
class QVariantTree;
class MultiPart;

class TASTEFUL_SERVER_API RequestParameters
{
public:
    RequestParameters();

    void clear();

    QVariantTree & tree();
    const QVariantTree & tree() const;

    bool contains(const QString & key) const;
    bool containsPath(const QString & path) const;

    QVariantAbstractTree & operator[](const QString & key) const;
    QVariantAbstractTree & get(const QString & key) const;
    QVariantAbstractTree & getByPath(const QString & path) const;

    void insert(const QString & key, const QVariant & value);

    void parseUrl(const QUrl & url);
    void parseUrlEncoded(const QByteArray & urlEncodedPost);
    void parseMultiPart(const MultiPart & multiPart);

    QString toString() const;

    static RequestParameters fromUrl(const QUrl & url);
    static RequestParameters fromUrlEncoded(const QByteArray & urlEncoded);
    static RequestParameters fromMultiPart(const MultiPart & multiPart);

protected:
    void parseList(const QList<QPair<QString, QVariant>> &parameters);
    QList<QString> extractIndices(const QString & key) const;

    QSharedPointer<QVariantTree> m_params;
};

} // namespace tastefulserver