import QtQuick 2.11
import QtQuick.Window 2.11


QtObject {
    property var mainWindow:
        Window {
            visible: true
            width: 640
            height: 480
            title: qsTr("Hello World")

            Item {
                id: frame
                anchors.fill: parent

                Rectangle {
                    id: rectangle
                    x: 47
                    y: 50
                    width: 200
                    height: 200
                    color: "#cc3838"
                    radius: 33
                    border.width: 14

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            mainWindow.visible = false;
                        }
                    }
                }
            }
        }

    property var captureWindow:
        Window {
            visible: true
            x: 0
            y: 0
            width: 640
            height: 480
            title: qsTr("CaptureWindow")


            Rectangle {
                id: rect
                x: 300
                y: 300

                width: 60
                height: 60

                color: "green"
                radius: 20

                NumberAnimation {
                    target: rect
                    property: "rotation"
                    from: 0
                    to: 360

                    duration: 1000
                    loops: -1
                    running: true
                }
            }


            Item {
                id: capturFrame
                anchors.fill: parent

                Rectangle {
                    x: 47
                    y: 50
                    width: 200
                    height: 200
                    color: "blue"
                    radius: 33
                    border.width: 14

                    MouseArea {
                        anchors.fill: parent

                        function captureImages(filename) {

                            var i = 0;
                            function capture() {
                                //mainWindow.visible = true;
                                frame.grabToImage(function(result){
                                    result.saveToFile(filename + i + ".png");

                                    i++;
                                    if (i < 100) {
                                        capture();
                                    }
                                });
                                //mainWindow.visible = false;
                            }

                            capture();
                        }

                        onClicked: {

                            captureImages("capture");
                        }
                    }
                }
            }
        }
}
