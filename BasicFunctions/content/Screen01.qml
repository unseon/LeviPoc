/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 2.15
import QtQuick.Controls 2.15
import BasicFunctions 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Button {
        checked: false
        checkable: true
        text: checked ? "delete" : "inserted"
        anchors.centerIn: parent

        onClicked: {
            if (checked) {
                row.children = recycled.children

                var a = []
                a.push(row.children[1])
                a.push(row.children[0])

                row.children = a


            } else {

//                console.log(row.children.push(null))
//                console.log(Object.keys(row.children))
//                row.children[0].parent = recycled


            }
        }
    }


    Row {
        id: row
        Rectangle {
            color: "red"
            width: 100
            height: 100
            radius: 20
        }
        Rectangle {
            color: "blue"
            width: 100
            height: 100
            radius: 20
        }

    }

    Item {
        id: recycled
        visible: false
    }
}
