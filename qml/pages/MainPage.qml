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
            title: "Sailfish Authenticator" }
        model: accounts

        VerticalScrollDecorator {}

        delegate: ListItem {
            id: listItem
            width: accountsListView.width
            height: Theme.itemSizeMedium
            menu: listItemContextMenu

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

            IconButton {
               id: hotpRefreshIcon
               icon.source: "refresh.png"
               visible : !timeControlled
               anchors.verticalCenter: parent.verticalCenter
               anchors.right : parent.right
               scale: 0.35
               opacity: 0.9
               MouseArea {
                   anchors.fill: parent
                   onClicked:{
                       hotpRefreshIconAnimation.start();
                       accounts.generateNext(index);
                       accounts.refresh(index);
                   }
               }

               RotationAnimation on rotation {
                   id: hotpRefreshIconAnimation
                   property: "rotation"
                   target: hotpRefreshIcon
                   duration: 500
                   from: 0; to: 360
               }
            }

            ProgressCircle {
                id: progressCircle
                anchors.verticalCenter: parent.verticalCenter
                anchors.right : parent.right
                scale: 0.75
                visible: timeControlled
                onValueChanged: {
                    if(value == 0) {
                        accounts.generateNext(index);
                        accounts.refresh(index);
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
                    running: timeControlled && Qt.application.active

                    onTriggered: {
                        var secsToBlock = accounts.get(index).getTimeToNextBlock();
                        progressCircle.value = (secsToBlock/accounts.get(index).timeStep) % 1.0
                        progressLabel.text = accounts.get(index).timeStep - secsToBlock;
                    }
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
                            accounts.refresh(index);
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
                text: "Add account"
                onClicked: pageStack.push(accountDialog, {account: null})
            }
            MenuItem {
                text: "About"
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        }
    }

    Dialog {
        id: accountDialog
        property QtObject account: null
        property bool customAlgorithmOptions: account ? true : false

        onOpened: account ? (serviceComboBox.currentIndex = 1) && (algorithmComboBox.currentIndex = account.timeControlled? 1 : 0) && (hotpCounterTextField.text = account.counter): 0

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
                placeholderText: "Enter account name"
                label: "Name"
                //validator: RegExpValidator { regExp: /^[.]{3,100}$/ }
            }
            TextField {
                id: secretField
                width: parent.width
                text: accountDialog.account ? accountDialog.account.secret : ""
                placeholderText: "Enter 16 or 32 digits secret key"
                label: "Secret key"
                validator: RegExpValidator { regExp: /^[A-Za-z0-9]{16}|[A-Za-z0-9]{32}$/ }
            }

            ComboBox {
                id: serviceComboBox
                width: parent.width
                visible: accountDialog.account ? false : true
                label: "Service"
                menu: ContextMenu {
                    id: serviceContextMenu
                    MenuItem { text: "Google" }
                    MenuItem { text: "Custom" }
                }
                onValueChanged: currentIndex == 1 ? accountDialog.customAlgorithmOptions = true : accountDialog.customAlgorithmOptions = false;
            }

            ComboBox {
                id: algorithmComboBox
                width: parent.width
                visible: accountDialog.customAlgorithmOptions || accountDialog.account
                label: "Algorithm"
                currentIndex: 1
                menu: ContextMenu {
                    MenuItem { text: "HOTP" }
                    MenuItem { text: "TOTP" }
                }
            }

            TextField {
               id: hotpCounterTextField
               width: parent.width
               visible: algorithmComboBox.currentIndex == 0 && accountDialog.customAlgorithmOptions
               text: accountDialog.account ? accountDialog.account.counter : "0"
               placeholderText: "Enter counter"
               label: "Counter"
               validator: RegExpValidator { regExp: /^[\d]{1,19}$/ }
           }

            TextField {
               id: totpTimeStepTextField
               width: parent.width
               visible: algorithmComboBox.currentIndex == 1 && accountDialog.customAlgorithmOptions
               //visible: false // Zalecany jest 30sekundowy interwal
               text: accountDialog.account ? accountDialog.account.timeStep : "30"
               placeholderText: "Enter time step"
               label: "Time step"
               validator: IntValidator { bottom: 10; top: 99}
           }

            TextField {
               id: pinLengthTextField
               width: parent.width
               visible: accountDialog.customAlgorithmOptions
               text: accountDialog.account ? accountDialog.account.pinLength : "6"
               label: "Pin length"
               validator: IntValidator { bottom: 1; top: 9}
           }
        }

        onDone: {
            if (result == DialogResult.Accepted) {
                if(nameField.acceptableInput == true){
                    if(secretField.acceptableInput == true){
                        var newAccount = account;
                        if (newAccount == null) {
                            newAccount = accounts.createAccount()
                        }
                        if (serviceComboBox.value == "Google" && account == null) {
                            newAccount.name = nameField.text
                            newAccount.secret = secretField.text
                            newAccount.counter = 0;
                            newAccount.pinLength = 6;
                            newAccount.timeStep = 30;
                            newAccount.timeControlled = true;
                        }
                        else {
                            newAccount.name = nameField.text
                            newAccount.secret = secretField.text
                            newAccount.counter = parseInt(hotpCounterTextField.text)
                            newAccount.pinLength = parseInt(pinLengthTextField.text)
                            newAccount.timeStep = parseInt(totpTimeStepTextField.text)
                            if (algorithmComboBox.value == "TOTP")
                                newAccount.timeControlled = true;
                            else
                                newAccount.timeControlled = false;
                        }
                    }
                }
            }
        }

    }

}







