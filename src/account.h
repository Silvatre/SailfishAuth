#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QObject>
#include <QDateTime>
#include <QUuid>

class Account : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString secret READ secret WRITE setSecret NOTIFY secretChanged)
    Q_PROPERTY(quint64 counter READ counter WRITE setCounter NOTIFY counterChanged)
    Q_PROPERTY(int pinLength READ pinLength WRITE setPinLength NOTIFY pinLengthChanged)
    Q_PROPERTY(QString otp READ otp NOTIFY otpChanged)

public:
    explicit Account(QObject *parent = 0);

    explicit Account(const QUuid &id, QObject *parent = 0);

    QUuid id() const;

    QString name() const;
    void setName(const QString &name);

    QString secret() const;
    void setSecret(const QString &secret);

    quint64 counter() const;
    void setCounter(quint64 counter);

    int pinLength() const;
    void setPinLength(int pinLength);

    QString otp() const;

signals:
    void nameChanged();
    void secretChanged();
    void counterChanged();
    void pinLengthChanged();
    void otpChanged();

public slots:
    void next();

private:
    void generate();

    static QByteArray fromBase32(const QByteArray &input);

private:
    QUuid m_id;
    QString m_name;
    QString m_secret;
    quint64 m_counter;
    int m_pinLength;
    QString m_otp;
};

#endif // ACCOUNT_H
