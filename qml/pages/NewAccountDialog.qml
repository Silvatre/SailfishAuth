import QtQuick 2.0
import Sailfish.Silica 1.0
import "MainPage.qml"
Dialog {
    property string desc
    property string seed

    Column {
        spacing: 10
        anchors.fill: parent
        DialogHeader {
            acceptText: "Add account"
        }
        TextField {
            id: descField
            width: parent.width
            placeholderText: "Enter description..."
            label: "Description"
        }
        TextField {
            id: seedField
            width: parent.width
            placeholderText: "Enter seed..."
            label: "Seed"
        }
    }

    onDone: {
        if (result == DialogResult.Accepted) {
            // Zdaje sie, ze trzeba polaczyc w C++
            //MainPage.addAccount()
        }
    }

}
