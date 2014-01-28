#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H

#include <QAbstractListModel>

class Account;

class AccountModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        RoleName,
        RoleSecret,
        RoleCounter,
        RolePinLength,
        RoleOtp,
        RoleTimeControlled,
        RoleTimeStep
    };

    explicit AccountModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE Account *get(int index) const;
    Q_INVOKABLE Account *createAccount();
    Q_INVOKABLE void deleteAccount(int index);
    Q_INVOKABLE void deleteAccount(Account *account);


public slots:
    void generateNext(int account);
    void generateAll();
    void refresh();
    void refresh(int index);
    bool isTimeControlled(int account);

private slots:
    void accountChanged();
    void storeAccount(Account *account);

private:
    QList<Account*> m_accounts;
};

#endif // ACCOUNTMODEL_H
