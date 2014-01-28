#include "accountmodel.h"
#include "account.h"

#include <QSettings>
#include <QStringList>
#include <QDebug>

AccountModel::AccountModel(QObject *parent) :
    QAbstractListModel(parent)
{
    QSettings settings("pl.polsl.sailfishauth", "sailfish-authenticator");
    qDebug() << "loading settings file:" << settings.fileName();
    foreach(const QString & group, settings.childGroups()) {
        qDebug() << "found group" << group << QUuid(group).toString();

        QUuid id = QUuid(group);
        bool migrateAccount = false;
        if (id.isNull()) {
            migrateAccount = true;
            id = QUuid::createUuid();
        }

        settings.beginGroup(group);
        Account *account = new Account(id, this);
        account->setName(settings.value("account").toString());
        account->setSecret(settings.value("secret").toString());
        account->setCounter(settings.value("counter").toInt());
        account->setPinLength(settings.value("pinLength").toInt());
        account->setTimeControlled(settings.value("timeControlled").toBool());
        account->setTimeStep(settings.value("timeStep").toInt());

        connect(account, SIGNAL(nameChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(secretChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(counterChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(pinLengthChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(otpChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(tcChanged()), SLOT(accountChanged()));
        connect(account, SIGNAL(timeStepChanged()), SLOT(accountChanged()));

        m_accounts.append(account);

        if (migrateAccount) {
            settings.remove("");
            storeAccount(account);
        }
        settings.endGroup();
    }
}

int AccountModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_accounts.count();
}

QVariant AccountModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case RoleName:
        return m_accounts.at(index.row())->name();
    case RoleSecret:
        return m_accounts.at(index.row())->secret();
    case RoleCounter:
        return m_accounts.at(index.row())->counter();
    case RolePinLength:
        return m_accounts.at(index.row())->pinLength();
    case RoleOtp:
        return m_accounts.at(index.row())->otp();
    case RoleTimeControlled:
        return m_accounts.at(index.row())->timeControlled();
    case RoleTimeStep:
        return m_accounts.at(index.row())->timeStep();
    }

    return QVariant();
}

Account *AccountModel::get(int index) const
{
    return m_accounts.at(index);
}

Account *AccountModel::createAccount()
{
    Account *account = new Account(QUuid::createUuid(), this);
    beginInsertRows(QModelIndex(), m_accounts.count(), m_accounts.count());
    m_accounts.append(account);
    connect(account, SIGNAL(nameChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(secretChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(counterChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(pinLengthChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(otpChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(tcChanged()), SLOT(accountChanged()));
    connect(account, SIGNAL(timeStepChanged()), SLOT(accountChanged()));

    storeAccount(account);

    endInsertRows();
    return account;
}

void AccountModel::deleteAccount(int index)
{
    beginRemoveRows(QModelIndex(), index, index);

    Account *account = m_accounts.takeAt(index);
    QSettings settings("pl.polsl.sailfishauth", "sailfish-authenticator");
    settings.beginGroup(account->id().toString());
    settings.remove("");
    settings.endGroup();

    account->deleteLater();

    endRemoveRows();
}

void AccountModel::deleteAccount(Account *account)
{
    int index = m_accounts.indexOf(account);
    deleteAccount(index);
}

QHash<int, QByteArray> AccountModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles.insert(RoleName, "name");
    roles.insert(RoleSecret, "secret");
    roles.insert(RoleCounter, "counter");
    roles.insert(RolePinLength, "pinLength");
    roles.insert(RoleOtp, "otp");
    roles.insert(RoleTimeControlled, "timeControlled");
    roles.insert(RoleTimeStep, "timeStep");
    return roles;
}

void AccountModel::generateNext(int account)
{
    m_accounts.at(account)->next();
    //emit dataChanged(index(account), index(account), QVector<int>() << RoleCounter << RoleOtp);
}

void AccountModel::generateAll()
{
    for (int i = 0; i < m_accounts.size(); i++) {
        generateNext(i);
    }
}


void AccountModel::refresh()
{
    emit beginResetModel();
    emit endResetModel();
}

void AccountModel::refresh(int index)
{
    QModelIndex modelIndex = this->index(index);
    emit dataChanged(modelIndex, modelIndex);
    //emit beginResetModel();
    //emit endResetModel();
}

bool AccountModel::isTimeControlled(int account){
    return m_accounts.at(account)->timeControlled();
}

void AccountModel::accountChanged()
{
    Account *account = qobject_cast<Account*>(sender());
    storeAccount(account);

    qDebug() << "account changed";
    int accountIndex = m_accounts.indexOf(account);
    emit dataChanged(index(accountIndex), index(accountIndex));
}

void AccountModel::storeAccount(Account *account)
{
    QSettings settings("pl.polsl.sailfishauth", "sailfish-authenticator");
    settings.beginGroup(account->id().toString());
    settings.setValue("account", account->name());
    settings.setValue("secret", account->secret());
    settings.setValue("counter", account->counter());
    settings.setValue("pinLength", account->pinLength());
    settings.setValue("timeControlled", account->timeControlled());
    settings.setValue("timeStep", account->timeStep());
    settings.endGroup();
    qDebug() << "saved to" << settings.fileName();

}
