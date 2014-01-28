import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
        id: aboutPage

        SilicaFlickable {
            anchors.fill: parent
            contentWidth: parent.width
            contentHeight: col.height

            VerticalScrollDecorator {}
            Column {
                id: col
                spacing: Theme.paddingLarge
                width: parent.width
                PageHeader {
                    title: "About"
                }
                Rectangle {
                    id: authorsHeader
                    width: parent.width
                    color: Theme.highlightBackgroundColor
                    anchors.horizontalCenter: parent.horizontalCenter
                    height: Theme.itemSizeSmall
                    Label {
                        text: "Authors"
                        anchors.centerIn: parent
                    }
                }

                Item {
                width: parent.width
                height: Theme.itemSizeSmall
                //anchors.horizontalCenter: parent.horizontalCenter
                Column {
                    anchors.centerIn : parent
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        text: "Filip Kłębczyk"
                        color: Theme.primaryColor
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: Theme.fontSizeExtraSmall
                        text: "Supervisor"
                        color: Theme.primaryColor
                    }
                }
                }

                Item {
                width: parent.width
                height: Theme.itemSizeSmall
                //anchors.horizontalCenter: parent.horizontalCenter
                Column {
                    anchors.centerIn : parent
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        text: "Michał Krupiński"
                        color: Theme.primaryColor
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: Theme.fontSizeExtraSmall
                        text: "Developer"
                        color: Theme.primaryColor
                    }
                }
                }

                Item {
                width: parent.width
                height: Theme.itemSizeSmall
                Column {
                    anchors.centerIn : parent
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        text: "Michał Szmorliński"
                        color: Theme.primaryColor
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: Theme.fontSizeExtraSmall
                        text: "Developer"
                        color: Theme.primaryColor
                    }
                }
                }

                Rectangle {
                    width: parent.width
                    color: Theme.highlightBackgroundColor
                    height: Theme.itemSizeSmall
                    Label {
                        text: "Special thanks"
                        anchors.centerIn: parent
                    }
                }

                Item {
                width: parent.width
                height: Theme.itemSizeSmall
                Column {
                    anchors.centerIn : parent
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                        text: "Michael Zanetti"
                        color: Theme.primaryColor
                    }
                    Label {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: Theme.fontSizeExtraSmall
                        text: "Ubuntu Authenticator creator"
                        color: Theme.primaryColor
                    }
                }
                }
            }
        }
}
