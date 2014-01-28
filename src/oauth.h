#ifndef OAUTH_H
#define OAUTH_H
#include <QObject>
#include <QDateTime>
#include <QUuid>
class Oauth
{
public:
    Oauth();
    QString generateHOTP(QByteArray key, QString counter, QString returnDigits);
    QString generateTOTP(QByteArray key, int timeStep, QString returnDigits);
    QByteArray hmacSha1(QByteArray key, QByteArray baseString);
    QByteArray hexStr2Bytes(QString hex);
    QByteArray encryptToByteArray(QByteArray plaintext);
    QByteArray encryptToByteArray(const QString& plaintext);
};

#endif // OAUTH_H
