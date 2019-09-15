import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    Item {
        anchors.fill: parent

        Rectangle {
            id: rect
            width: 50
            height: 50
            color: "red"
            anchors.centerIn: parent

            AnimationController {
                animation:
                    NumberAnimation {
                    target: rect
                    property: "rotation"
                    from: 0
                    to: 360
                    //duration: 200
                    easing.type: Easing.InOutQuad
                }

                progress: 0.1
            }
        }
    }
}
