#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "account.h"
#include "accountmodel.h"
#include "oauth.h"
#include "stdio.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<AccountModel>("pl.polsl.sailfishauth", 1, 0, "AccountModel");
    qmlRegisterUncreatableType<Account>("pl.polsl.sailfishauth", 1, 0, "Account", "Use AccountModel::createAccount() to create a new account");
    qmlRegisterType<Account>("pl.polsl.sailfishauth", 1, 0, "Account");
    return SailfishApp::main(argc, argv);
}

