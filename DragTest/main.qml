import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Item {
        anchors.fill: parent

        Rectangle {
            width: parent.width / 2
            height: parent.height

            color: "red"

            Rectangle {
                x: 100
                y: 100
                width: 200
                height: 200

                color: "blue"

                Drag.active: dragArea.drag.active
                Drag.hotSpot.x: 10
                Drag.hotSpot.y: 10

                MouseArea {
                    id: dragArea
                    anchors.fill: parent
                    drag.target: parent
                }
            }
        }

        Rectangle {
            x: parent.width / 2
            width: parent.width / 2
            height: parent.height
            color: "yellow"

            DropArea {
                anchors.fill: parent

                onEntered: {
                    console.log("entered")
                }
            }

            z: -1
        }
    }
}
