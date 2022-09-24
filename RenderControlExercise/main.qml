import QtQuick 2.12
Item {
    width: 400
    height: 400
    Rectangle {
        anchors.fill: parent
        color: "red"


        Rectangle {
            id: blue
            width: 50
            height: 50
            color: "blue"
            anchors.verticalCenter: parent.verticalCenter
        }
    }


    NumberAnimation {
        running: true

        target: blue
        property: "x"
        duration: 2000
        to: 300
        easing.type: Easing.InOutQuad
    }
}
