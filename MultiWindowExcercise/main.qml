import QtQuick 2.12
import QtQuick.Window 2.12


QtObject {
    property var win0: Window {
        visible: true
        width: 640
        height: 480
        title: qsTr("Hello World2")

        flags: Qt.ForeignWindow

        Item {
            anchors.fill: parent
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    while(true) {

                    }

                }
            }
        }
    }

    property var win1: Window {
        visible: true
        width: 640
        height: 480
        title: qsTr("Hello World1")

        Item {
            anchors.fill: parent


            Rectangle {
                anchors.centerIn: parent
                width: 100
                height: 100

                color: "red"

                NumberAnimation on rotation {
                    loops: -1
                    from: 0
                    to: 360
                    duration: 2000
                }
            }
        }
    }
}

