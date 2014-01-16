import QtQuick 2.0
import Sailfish.Silica 1.0
import pl.polsl.pum 1.0

Page {
    id: mainPage

    function addAccount() {
        pagesModel.append({"title":"desc","key":"test"})
    }

    Account {
        id:acc
    }
    Label {
        id: txt
        anchors.fill: parent
        text: acc.getCurrentDateTime()
    }

    BusyIndicator {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right : parent.right
        running: true
        size: BusyIndicatorSize.Medium
    }
    /*
    SilicaListView {
        id: listView
        anchors.fill: parent
        anchors.top: txt.bottom
        pullDownMenu:pullDownMenu
        header: PageHeader { id: pageHeader
            title: "SailfishAuth" }
        model: ListModel {
            id: pagesModel
            // Testowy element
            ListElement {
                title: "Account#1"
                key: "asssd"
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

            Text { text: account.getCurrentDateTime() }

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
                id: menuItem1
                text: "Add account"
                onClicked: pageStack.push(Qt.resolvedUrl("NewAccountDialog.qml"))
            }
            MenuItem {
                text: "About"
                // TODO: Otwarcie strony About z wpisanym prowadzacym
            }
        }        
    }
*/
}





