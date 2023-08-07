import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item {
        anchors.fill: parent

        Rectangle {
            id: rect01
            x: 30
            y: 30
            height: 100
            width: 100

            color: "red"


            NumberAnimation {
                target: text1
                property: "scale"
                duration: 200
                easing.type: Easing.InOutQuad
                from: 1.0
                to: 2.0
                loops: -1
                running: true
            }

            Text {
                id: text1
                text: "Hello"
            }
        }

        Rectangle {
            id: rect02
            x: 230
            y: 30
            height: 100
            width: 100

            color: "yellow"

            Column {
                id: column
                Text {
                    text: "Hello01"
                }
            }
        }

        property Rectangle temp: Rectangle {
            id: temp

            width: 50
            height: 50
            color: "blue"
        }

        Component.onCompleted : {
            // replace
            //rect02["data"] = rect01["data"]

            // add
            //console.log(rect01.data[1])
            //temp.data = column.data
            //column.data.push(rect01.data[1])
            //column.data.push(temp.data[0])

            var newData = rect02.data
            rect02.data = null
            rect02.data = newData
        }
    }
}
