import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480

    title: qsTr("Hello Levi")

    Rectangle {
        anchors.fill: parent

        color: "#E0EAE0"

        Text {
            anchors.centerIn: parent

            text: qsTr("Hello Levi")
        }
    }
}
