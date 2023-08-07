import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Item {
        id: rootItem


        property var component
        property var instance

        Component.onCompleted: {
            component = Qt.createComponent("file:///C:/Qt/6.4.0/mingw_64/qml/QtQuick/plugins.qmltypes", Component.PreferSynchronous);
            console.log("component: " + component)
            if (component.status === Component.Ready)
                finishCreation();
            else
                component.statusChanged.connect(finishCreation);

            instance = component.createObject(rootItem);
            console.log("instance: " + instance)
        }

        function finishCreation() {
            if (component.status === Component.Ready) {
                instance = component.createObject(rootItem);
                console.log("instance: " + instance)

                if (instance === null) {
                    // Error Handling
                    console.log("Error creating object");
                }

            } else if (component.status === Component.Error) {
                // Error Handling
                console.log("Error loading component:", component.errorString());
            }
        }

    }
}
