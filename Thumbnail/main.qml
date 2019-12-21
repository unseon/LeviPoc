import QtQuick 2.11
import QtQuick.Window 2.11


QtObject {
    property var mainWindow:
        Window {
            visible: true
            width: 640
            height: 480
            title: qsTr("Hello World")

//            Rectangle {
//                id: frame
//                anchors.fill: parent
//                color: "yellow"

//                Rectangle {
//                    id: rectangle
//                    x: 47
//                    y: 50
//                    width: 200
//                    height: 200
//                    color: "#cc3838"
//                    radius: 33
//                    border.width: 14

//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: {
//                            mainWindow.visible = false;
//                        }
//                    }
//                }
//            }
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
                id: frame
                anchors.fill: parent
                color: "yellow"

                Rectangle {
                    id: rectangle
                    x: 47
                    y: 50
                    width: 200
                    height: 200
                    color: "#cc3838"
                    radius: 33
                    border.width: 14
                }
            }





            Rectangle {
                id: capturFrame
                anchors.fill: parent

                color: "white"

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
                                    image.source = "file:" + filename + i + ".png";

                                    i++;
                                    if (i < 1) {
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

                Image {
                    id: image
                    width: parent.width / 2
                    height: parent.height / 2

                    //source: "file:capture0.png"
                }

                Rectangle {
                    id: rect
                    x: 300
                    y: 300

                    width: 60
                    height: 60

                    color: "green"
                    radius: 20

                    SequentialAnimation {
                        loops: -1
                        running: true

                        NumberAnimation {
                            target: rect
                            property: "rotation"
                            from: 0
                            to: 90

                            duration: 200
                        }


                        PauseAnimation {
                            duration: 800
                        }
                    }
                }
            }
        }
}
