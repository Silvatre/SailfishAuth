/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "account.h"
#include "oauth.h"

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).


    //QScopedPointer<QGuiApplication> app(SailfishApp::application(argc,argv));
    //QScopedPointer<QQuickView> view(SailfishApp::createView());
    //qmlRegisterUncreatableType<Account>("OAth", 1, 0, "Account", "Use AccountModel::createAccount() to create a new account");


    /*
     * Debugowanie dzialania algorytmu
     */
    while (true) {
        QString secretBase32 = "v54v7fqfqudv4mbacilyifwf7nhmzzyl";
        QByteArray array (secretBase32.toStdString().c_str());
        QByteArray secretHex = Account::fromBase32(array);

        QDateTime local(QDateTime::currentDateTime());
        QDateTime UTC(local.toUTC());
        uint secsPassed = UTC.toTime_t();
        qulonglong interval = secsPassed/30;
        QString intervalsHex = QString::number(interval, 16);
        // TODO Tutaj moze nie zapisac szesnastkowo
        Oauth oa = Oauth();
        QString output = oa.generateTOTP(secretHex, intervalsHex.toUpper(), "6", "HmacSHA1");

    }

    qmlRegisterType<Account>("pl.polsl.pum", 1, 0, "Account");

    /*
    Account data;
    view->rootContext()->setContextProperty("account", &data);
    view->setSource(SailfishApp::pathTo("qml/SailfishAuth.qml"));
    */

    /*
    QGuiApplication* app = SailfishApp::application(argc, argv);
    QQuickView* view = SailfishApp::createView();

    Account account;
    view->rootContext()->setContextProperty("account", &account);
    view->setSource(QUrl::fromLocalFile("../qml/pages/MainPage.qml"));
    view->show();
    */
    return SailfishApp::main(argc, argv);
}

