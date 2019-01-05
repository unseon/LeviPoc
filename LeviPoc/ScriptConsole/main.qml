import QtQuick 2.11
import QtQuick.Window 2.11

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent

        Rectangle {
            id: inputWindow
            x: 0
            y: 0
            width: 640
            height: 130
            color: "#f2f2f2"

            TextEdit {
                id: textInput
                text: qsTr("")
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                anchors.bottomMargin: 10
                anchors.topMargin: 10
                anchors.fill: parent
                font.pixelSize: 12

                focus: true

                Keys.onReturnPressed: {
                    console.log(event.modifiers);
                    if (event.modifiers & Qt.ControlModifier) {
                        console.log("onReturenPressed");
                        runCommand(textInput.text);
                    } else {

                        event.accepted = false;
                    }
                }

                function runCommand(cmd) {
                    try {
                        var result = eval(cmd);

                        textOutput.color = "black";
                        textOutput.text = cmd + "\n" + result;
                        textInput.text = "";
                    } catch (error) {
                        textOutput.color = "red";
                        textOutput.text = cmd + "\n" + error.message;
                    }
                }
            }
        }

        Rectangle {
            id: outputWindow
            x: 0
            y: 129
            width: 640
            height: 351
            color: "#8f8f8f"

            TextEdit {
                id: textOutput
                text: qsTr("")
                readOnly: true
                anchors.rightMargin: 10
                anchors.leftMargin: 10
                anchors.bottomMargin: 10
                anchors.topMargin: 10
                anchors.fill: parent
                font.pixelSize: 12
            }
        }
    }
}





/*##^## Designer {
    D{i:5;anchors_height:20;anchors_width:80;anchors_x:8;anchors_y:8}D{i:6;anchors_height:20;anchors_width:80;anchors_x:8;anchors_y:8}
D{i:1;anchors_height:200;anchors_width:200;anchors_x:0;anchors_y:0}
}
 ##^##*/
