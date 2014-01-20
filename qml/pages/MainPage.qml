import QtQuick 2.0
import Sailfish.Silica 1.0
import pl.polsl.sailfishauth 1.0

Page {
    id: mainPage

    AccountModel {
        id: accounts
    }

    SilicaListView {
        id: accountsListView
        anchors.fill: parent
        pullDownMenu:pullDownMenu
        header: PageHeader { id: pageHeader
            title: "SailfishAuth" }
        model: accounts

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: listItem
            width: accountsListView.width
            height: Theme.itemSizeMedium
            menu: listItemContextMenu
            ListView.onRemove: animateRemoval(listItem)

            Column {
                anchors.verticalCenter: parent.verticalCenter
                Label {
                    font.pixelSize: Theme.fontSizeExtraSmall
                    text: name
                    color: highlighted ? Theme.highlightColor : Theme.primaryColor
                }
                Label {
                    font.bold: true
                    text: otp
                    color: highlighted ? Theme.highlightColor : Theme.primaryColor
                }
            }
            ProgressCircle {
                id: progressCircle
                anchors.verticalCenter: parent.verticalCenter
                anchors.right : parent.right
                scale: 0.75
                onValueChanged: {
                    if(value == 0) {
                        accounts.generateAll();
                        accounts.refresh();
                    }
                }
                Label {
                    id: progressLabel
                    anchors.centerIn: parent
                }
                Timer {
                    id: progressTimer
                    interval: 50
                    repeat: true

                    onTriggered: {
                        var secsToBlock = accounts.getTimeToNextBlock();
                        progressCircle.value = (secsToBlock/30) % 1.0
                        progressLabel.text = 30 - secsToBlock;
                    }
                    running: Qt.application.active
                }

            }
            Separator {
                width: parent.width
                opacity: 0.3
                color: "white"
            }
            ContextMenu {
                id: listItemContextMenu
                MenuItem {
                    id: listItemContextMenuDeleteItem
                    text: "Delete"
                    onClicked: {
                        remorseAction("Deleting", function() {
                        accounts.deleteAccount(index);
                        accounts.refresh();
                        })
                    }
                }
                MenuItem {
                    text: "Modify"
                    onClicked: pageStack.push(accountDialog, {account: accounts.get(index)})
                }
            }
        }

        PullDownMenu {
            id: pullDownMenu
            MenuItem {
                id: menuItem1
                text: "Add accounts"
                onClicked: pageStack.push(accountDialog, {account: null})
            }
            MenuItem {
                text: "About"
                // TODO: Otwarcie strony About z wpisanym prowadzacym
            }
        }        
    }

    Dialog {
        id: accountDialog
        property QtObject account: null

        Column {
            spacing: 10
            anchors.fill: parent
            DialogHeader {
                acceptText: accountDialog.account ? "Modify account" : "Add account"
            }
            TextField {
                id: nameField
                width: parent.width
                text: accountDialog.account ? accountDialog.account.name : ""
                placeholderText: "Enter name..."
                label: "Name"
            }
            TextField {
                id: secretField
                width: parent.width
                text: accountDialog.account ? accountDialog.account.secret : ""
                placeholderText: "Enter secret key..."
                label: "Secret key"
            }
        }

        onDone: {
            if (result == DialogResult.Accepted) {
                var newAccount = account;
                if (newAccount == null) {
                    newAccount = accounts.createAccount()
                }
                newAccount.name = nameField.text
                newAccount.secret = secretField.text
                newAccount.counter = 0
                newAccount.pinLength = 6

            }
        }

    }

}







