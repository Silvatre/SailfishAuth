import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog {

    Column {
        spacing: 10
        anchors.fill: parent
        DialogHeader {
            acceptText: "Delete"
        }
        Label {
            text: "Really delete?"
        }
        Label {
            id: fileName
        }
    }
}
