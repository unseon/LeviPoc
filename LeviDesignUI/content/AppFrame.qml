

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import LeviDesignUI

Page {
    id: appFrame
    width: Constants.width
    height: Constants.height

    Item {
        id: recycles
        visible: false
    }

    AppFrameBehavior {
        id: behavior

        Connections {
            target: btnDrawRect
            onClicked: behavior.onBtnDrawRectClicked()
        }

        Connections {
            target: canvasDragLayer
            function onPressed(mouse) {
                behavior.onPressed(mouse)
            }

            function onPositionChanged(mouse) {
                behavior.onMove(mouse)
            }

            function onReleased(mouse) {
                behavior.onReleased(mouse)
            }
        }
    }

    header: TabBar {
        id: tabBar
        TabButton {
            id: tabHome
            icon.source: "images/icon_home"
            width: 50
        }

        TabButton {
            id: tabButton
            icon.source: "images/design_services"
            text: qsTr("Tab Button")
            width: 150
        }

        TabButton {
            id: tabButton1
            icon.source: "images/design_services"
            text: qsTr("Tab Button")
            width: 150
        }

        TabButton {
            id: addButton
            text: qsTr("+")
            width: 50
        }
    }

    Page {
        id: clientArea
        anchors.fill: parent
        header: Pane {
            //width: clientArea.width
            //height: 50
            padding: 0

            Row {
                anchors.fill: parent
                Button {
                    width: 50
                    icon.source: "images/icon_menu.png"
                }
                Button {
                    width: 50
                    autoExclusive: true
                    checkable: true
                    icon.source: "images/icon_move.png"
                }
                Button {
                    width: 50
                    autoExclusive: true
                    checkable: true
                    icon.source: "images/icon_frame.png"
                }
                Button {
                    id: btnDrawRect
                    width: 50
                    autoExclusive: true
                    checkable: true
                    icon.source: "images/icon_rectangle.png"
                }
                Button {
                    width: 50
                    checkable: true
                    autoExclusive: true
                    icon.source: "images/icon_hand.png"
                }
                Button {
                    width: 50
                    checkable: true
                    autoExclusive: true
                    icon.source: "images/icon_comment.png"
                }
            }
        }

        Rectangle {
            id: canvas
            color: "#f5f5f5"
            anchors.fill: parent
            property rect visibleRect: Qt.rect(0, 0, 100, 100)
        }

        MouseArea {
            id: canvasDragLayer
            anchors.fill: canvas

            hoverEnabled: true

            Rectangle {
                id: canvasDragMarquee
                color: "#dddddd"
                border.color: "blue"
                visible: false

                width: 100
                height: 100

                Item {
                    x: 0
                    y: 0

                    Rectangle {
                        border.color: "blue"
                        color: "white"
                        width: 7
                        height: 7
                        x: -4
                        y: -4
                    }
                }

                Item {
                    x: parent.width
                    y: parent.height

                    Rectangle {
                        border.color: "blue"
                        color: "white"
                        width: 7
                        height: 7
                        x: -4
                        y: -4
                    }
                }

                Item {
                    x: parent.width

                    Rectangle {
                        border.color: "blue"
                        color: "white"
                        width: 7
                        height: 7
                        x: -4
                        y: -4
                    }
                }

                Item {
                    y: parent.height

                    Rectangle {
                        border.color: "blue"
                        color: "white"
                        width: 7
                        height: 7
                        x: -4
                        y: -4
                    }
                }


            }
        }

        Rectangle {
            id: editorLayer
            color: "transparent"
            anchors.fill: parent
            visible: false

            SplitView {
                anchors.fill: parent
                Item {
                    SplitView.preferredWidth: 200
                    Pane {
                        anchors.fill: parent
                    }
                }

                Item {
                    SplitView.fillWidth: true
                }

                Item {
                    SplitView.preferredWidth: 200
                    Pane {
                        anchors.fill: parent
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/

