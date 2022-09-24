import QtQuick
import QtQuick.Controls

Item {
//    running: true
//    script: {
//        //btnDrawRect.enabled = false
//    }

    enum CanvasMode {
        Select,
        Marquee
    }

    property int canvasMode: AppFrameBehavior.CanvasMode.Select

    //default property list<Connections> conn

    function onBtnDrawRectClicked() {
        console.log("BtnDrawRectClicked")

        currentMouseHandler = marqueModeHandler
    }

    property QtObject currentMouseHandler: moveModeHandler

    function onHover(event) {
        currentMouseHandler.onHover(event)
    }

    function onPressed(event) {
        currentMouseHandler.onPressed(event)
    }

    function onMove(event) {
        currentMouseHandler.onMove(event)
    }

    function onReleased(event) {
        currentMouseHandler.onReleased(event)
    }

    QtObject {
        id: moveModeHandler

        function onHover(mouse) {

        }

        function onPressed(mouse) {
        }

        function onMove(event) {
        }

        function onReleased(event) {
        }

        function onCanceled() {

        }
    }

    QtObject {
        id: marqueModeHandler

        property bool pressed: false
        property point pressedPos

        function onHover(event) {

        }

        function onPressed(mouse: MouseEvent) {
            pressed = true
            pressedPos = Qt.point(mouse.x, mouse.y)
            canvasDragMarquee.visible = true
            canvasDragMarquee.x = mouse.x
            canvasDragMarquee.y = mouse.y
            canvasDragMarquee.width = 0
            canvasDragMarquee.height = 0
        }

        function onMove(mouse: MouseEvent) {
            //console.log("move ", mouse.x, mouse.y)
            if (pressed) {
                if (mouse.x < pressedPos.x) {
                    canvasDragMarquee.x = mouse.x
                    canvasDragMarquee.width = pressedPos.x - mouse.x
                } else {
                    canvasDragMarquee.x = pressedPos.x
                    canvasDragMarquee.width = mouse.x - pressedPos.x
                }

                if (mouse.y < pressedPos.y) {
                    canvasDragMarquee.y = mouse.y
                    canvasDragMarquee.height = pressedPos.y - mouse.y
                } else {
                    canvasDragMarquee.y = pressedPos.y
                    canvasDragMarquee.height = mouse.y - pressedPos.y
                }
            }
        }

        function onReleased(mouse: MouseEvent) {
            pressed = false
        }

        function onCanceled() {

        }
    }


}
