#include "account.h"
#include "oauth.h"
#include <QDebug>

#define SIZE_MAX UINT_MAX

Account::Account(QObject *parent) :
    QObject(parent)
{
}

Account::Account(const QUuid &id, QObject *parent) :
    QObject(parent),
    m_id(id),
    m_counter(0),
    m_pinLength(6),
    m_timeControlled(true),
    m_timeStep(30)
{
}

QUuid Account::id() const
{
    return m_id;
}

QString Account::name() const
{
    return m_name;
}

void Account::setName(const QString &name)
{
    if (m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

QString Account::secret() const
{
    return m_secret;
}

void Account::setSecret(const QString &secret)
{
    if (m_secret != secret) {
        m_secret = secret;
        emit secretChanged();
        generate();
    }
}

quint64 Account::counter() const
{
    return m_counter;
}

void Account::setTimeControlled(bool timeControlled){
    this->m_timeControlled = timeControlled;
    emit tcChanged();
}

void Account::setCounter(quint64 counter)
{
    if (m_counter != counter) {
        m_counter = counter;
        emit counterChanged();
    }
}

int Account::pinLength() const
{
    return m_pinLength;
}

int Account::timeStep() const
{
    return m_timeStep;
}

bool Account::timeControlled() const
{
    return m_timeControlled;
}

void Account::setPinLength(int pinLength)
{
    if (m_pinLength != pinLength) {
        m_pinLength = pinLength;
        emit pinLengthChanged();
        generate();
    }
}

void Account::setTimeStep(int timeStep)
{
    if (m_timeStep != timeStep) {
        m_timeStep = timeStep;
        emit timeStepChanged();
        generate();
    }
}

QString Account::otp() const
{
    return m_otp;
}

void Account::next()
{
    generate();
}

/**
 * Tokens (HOTP, TOTP) generator.
 * @brief Account::generate
 */
void Account::generate()
{
    if (m_secret.isEmpty()) {
        qWarning() << "No secret set. Cannot generate otp.";
        return;
    }

    if (m_pinLength <= 0) {
        qWarning() << "Pin length is" << m_pinLength << ". Cannot generate otp.";
        return;
    }

    qDebug() << "Generating secret" << m_name << m_secret << m_counter << m_pinLength << m_otp;
    QByteArray hexSecret = fromBase32(m_secret.toLatin1());
    qDebug() << "hexSecret" << hexSecret;
    Oauth oa = Oauth();
    if (m_timeControlled) {
        qDebug() << " <TOTP>" << m_otp;
        m_otp = oa.generateTOTP(hexSecret, m_timeStep, QString::number(m_pinLength));
    }
    else {
        qDebug() << " <HOTP>" << m_otp;
        m_otp = oa.generateHOTP(hexSecret, QString::number(m_counter), QString::number(m_pinLength));
        setCounter(m_counter+1);
    }
    qDebug() << "Generated code: " << m_otp;
    //emit otpChanged();
}

double Account::getTimeToNextBlock() {
    QDateTime local(QDateTime::currentDateTime());
    QDateTime UTC(local.toUTC());
    double secsPassed = UTC.toTime_t();
    int interval = secsPassed/m_timeStep;
    double secsToNextBlock = secsPassed - interval*m_timeStep;
    return secsToNextBlock;
}

QByteArray Account::fromBase32(const QByteArray &input)
{
    int buffer = 0;
    int bitsLeft = 0;
    int count = 0;

    QByteArray result;

    for (int i = 0; i < input.length(); ++i) {

        char ch = input.at(i);

        if (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '-') {
            continue;
        }
        buffer <<= 5;

        if (ch == '0') {
            ch = 'O';
        } else if (ch == '1') {
            ch = 'L';
        } else if (ch == '8') {
            ch = 'B';
        }

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            ch = (ch & 0x1F) - 1;
        } else if (ch >= '2' && ch <= '7') {
            ch -= '2' - 26;
        } else {
            return QByteArray();
        }

        buffer |= ch;
        bitsLeft += 5;
        if (bitsLeft >= 8) {
            result[count++] = buffer >> (bitsLeft - 8);
            bitsLeft -= 8;
        }

    }

    return result;

}
