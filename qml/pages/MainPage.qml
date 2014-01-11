import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: mainPage

    function addAccount() {
        var dialog = pageStack.push("NewAccountDialog.qml")
    }

    SilicaListView {
        id: listView
        anchors.fill: parent
        pullDownMenu:pullDownMenu
        header: PageHeader { title: "SailfishAuth" }
        model: ListModel {
            id: pagesModel
            ListElement {
                title: "Text"
                key: "1231s2sss3ssssss"
            }
        }
        VerticalScrollDecorator {}

        delegate: ListItem {
            id: listItem
            width: listView.width
            height: Theme.itemSizeMedium
            menu: listItemContextMenu
            ListView.onRemove: animateRemoval(listItem)

            Row {
                anchors.fill: parent
                anchors.verticalCenter: parent.verticalCenter
                Column {
                    anchors.verticalCenter: parent.verticalCenter
                    Label {
                        font.pixelSize: Theme.fontSizeExtraSmall
                        text: title
                        color: highlighted ? Theme.highlightColor : Theme.primaryColor
                    }
                    Label {
                        font.bold: true
                        text: key
                        color: highlighted ? Theme.highlightColor : Theme.primaryColor
                    }
                }
                BusyIndicator {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right : parent.right
                    running: true
                    size: BusyIndicatorSize.Medium
                }
            }

            ContextMenu {
                id: listItemContextMenu
                MenuItem {
                    text: "Delete"
                    onClicked: remorseAction("Deleting", function() { pagesModel.remove(index) })
                }
                MenuItem {
                    text: "Edit"
                }
            }
        }

        PullDownMenu {
            id: pullDownMenu
            MenuItem {
                text: "Add account"
                onClicked: mainPage.addAccount()
            }
            MenuItem {
                text: "About"
                // TODO: Otwarcie strony About z wpisanym prowadzacym
            }
        }
    }

}





