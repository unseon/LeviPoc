import QtQuick 2.0

Item {
    id: root
    width: 400
    height: 300

    Rectangle {
        id: rect
        anchors.fill: parent
        color: "red"

        radius: 20
    }


    PropertyAnimation {
        id: anim
        //running: true
        target: rect
        property: "color"
        duration: 2000
        to: "blue"
        easing.type: Easing.InOutQuad
    }

    Component.onCompleted: {
        anim.start();
    }
}
