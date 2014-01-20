#include "oauth.h"
#include <QMessageAuthenticationCode>
#include <stdio.h>
Oauth::Oauth()
{
}

QString Oauth::generateTOTP(QByteArray key, QString time, QString returnDigits, QString crypto){
        bool* ok;
        int codeDigits = returnDigits.toInt(ok);
        QString result;

        // Using the counter
        // First 8 bytes are for the movingFactor
        // Compliant with base RFC 4226 (HOTP)
        while (time.length() < 16 )
            time = "0" + time;

        // Get the HEX in a Byte[]
        QByteArray msg = hexStr2Bytes(time);
        QByteArray hash = hmacSha1(key, msg);

        // put selected bytes into result int
        int offset = hash.at(hash.length() - 1) & 0xf;

        int binary =
            ((hash.at(offset) & 0x7f) << 24) |
            ((hash.at(offset + 1) & 0xff) << 16) |
            ((hash.at(offset + 2) & 0xff) << 8) |
            (hash.at(offset + 3) & 0xff);

        // int otp = binary % DIGITS_POWER[codeDigits];
        int otp = binary % 1000000;
        result = QString::number(otp, 10);
        while (result.length() < codeDigits) {
            result = "0" + result;
        }
        return result;
}

QByteArray Oauth::hmacSha1(QByteArray key, QByteArray baseString)
{
    int blockSize = 64; // HMAC-SHA-1 block size, defined in SHA-1 standard
    if (key.length() > blockSize) { // if key is longer than block size (64), reduce key length with SHA-1 compression
        key = QCryptographicHash::hash(key, QCryptographicHash::Sha1);
    }

    QByteArray innerPadding(blockSize, char(0x36)); // initialize inner padding with char "6"
    QByteArray outerPadding(blockSize, char(0x5c)); // initialize outer padding with char "\"
    // ascii characters 0x36 ("6") and 0x5c ("\") are selected because they have large
    // Hamming distance (http://en.wikipedia.org/wiki/Hamming_distance)

    for (int i = 0; i < key.length(); i++) {
        innerPadding[i] = innerPadding[i] ^ key.at(i); // XOR operation between every byte in key and innerpadding, of key length
        outerPadding[i] = outerPadding[i] ^ key.at(i); // XOR operation between every byte in key and outerpadding, of key length
    }

    // result = hash ( outerPadding CONCAT hash ( innerPadding CONCAT baseString ) ).toBase64
    QByteArray total = outerPadding;
    QByteArray part = innerPadding;
    part.append(baseString);
    total.append(QCryptographicHash::hash(part, QCryptographicHash::Sha1));
    QByteArray hashed = QCryptographicHash::hash(total, QCryptographicHash::Sha1);
    return hashed;
}

QByteArray Oauth::hexStr2Bytes(QString hex){
    QByteArray ba = hex.toLocal8Bit();
    char* pos = ba.data();
    unsigned char val[12];
    size_t count = 0;

    for(count = 0; count < sizeof(val)/sizeof(val[0]); count++) {
       sscanf(pos, "%2hhx", &val[count]);
       pos += 2 * sizeof(char);
    }
    val[ba.size()/2] = '\0';

    // Adding one byte to get the right conversion
    // Values starting with "0" can be converted
    QByteArray ret = QByteArray(reinterpret_cast<char*>(val), ba.size()/2);
    pos++;
    return ret;
}
