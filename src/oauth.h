#ifndef OAUTH_H
#define OAUTH_H
#include <QObject>
#include <QDateTime>
#include <QUuid>
class Oauth
{
public:
    Oauth();
    QString generateTOTP(QByteArray key, QString time, QString returnDigits, QString crypto);
    QByteArray hmacSha1(QByteArray key, QByteArray baseString);
    QByteArray hexStr2Bytes(QString hex);
    QByteArray encryptToByteArray(QByteArray plaintext);
    QByteArray encryptToByteArray(const QString& plaintext);
};

#endif // OAUTH_H
