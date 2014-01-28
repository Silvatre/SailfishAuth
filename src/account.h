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
    Q_PROPERTY(int timeStep READ timeStep WRITE setTimeStep NOTIFY timeStepChanged)
    Q_PROPERTY(QString otp READ otp NOTIFY otpChanged)
    Q_PROPERTY(bool timeControlled READ timeControlled WRITE setTimeControlled NOTIFY tcChanged)

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

    int timeStep() const;
    void setTimeStep(int pinLength);

    QString otp() const;

    static QByteArray fromBase32(const QByteArray &input);

    bool timeControlled() const;
    void setTimeControlled(bool timeControlled);

signals:
    void nameChanged();
    void secretChanged();
    void counterChanged();
    void pinLengthChanged();
    void otpChanged();
    void tcChanged();
    void timeStepChanged();

public slots:
    void next();
    double getTimeToNextBlock();

private:
    void generate();

private:
    QUuid m_id;
    QString m_name;
    QString m_secret;
    quint64 m_counter;
    int m_pinLength;
    int m_timeStep;
    QString m_otp;
    bool m_timeControlled;
};

#endif // ACCOUNT_H
