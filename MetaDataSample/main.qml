import QtQuick
import QtQml

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        width: 300
        height: 400

        color: "red"


        property QtObject _meta: QtObject {
            property string id: "rectangle__1"
            property string name: "rectangle__1"
            property string typeName: "Rectangle"
        }

        property var _meta2: {

        }

        Component.onCompleted: {
            _meta2["name"] = "Rectangle___1"
        }

        Item {
            width: 500
            height: 500

            Rectangle {
                id: rect
                width: 100
                color: "yellow"
            }

            Component.onCompleted: {
                rect.height = Qt.binding(function() { return eval("this.width * 2") })
                console.log("rect.height = " + rect.height) // prints 200, not 1000
            }
        }
    }


}
