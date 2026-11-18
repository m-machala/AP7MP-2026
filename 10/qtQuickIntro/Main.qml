import QtQuick

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello world")
    color: "#9999FF"

    property int clickCount: 0
    property int moveInterval: 1000
    property int moveSpeedup: 10

    Text {
        text: "Score: " + mainWindow.clickCount
        font.pointSize: 20
        z: 2
    }

    Rectangle {
        id: rectangle
        x: 50
        y: 50
        height: 100
        width: 100
        radius: 10
        focus: true
        z: 1

        Text {
            text: qsTr("Click me...")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                //parent.rotation += 10
                //parent.focus = true

                var newSpeed = mainWindow.moveInterval - mainWindow.moveSpeedup

                if (newSpeed > 0) {
                    mainWindow.moveInterval = newSpeed
                }

                var maxX = mainWindow.width - parent.width
                var maxY = mainWindow.height - parent.height

                parent.x = Math.random() * maxX
                parent.y = Math.random() * maxY

                mainWindow.clickCount += 1
            }
        }

        Timer {
            id: moveTimer
            interval: mainWindow.moveInterval
            repeat: true
            running: true

            onTriggered: {
                var maxX = mainWindow.width - parent.width
                var maxY = mainWindow.height - parent.height

                parent.x = Math.random() * maxX
                parent.y = Math.random() * maxY
            }
        }

        Keys.onLeftPressed: x -= 50
        Keys.onRightPressed: x += 50
        Keys.onUpPressed: y -= 50
        Keys.onDownPressed: y += 50

        Behavior on x {
            NumberAnimation {
                easing.type: Easing.OutElastic
                duration: 1000
            }
        }

        Behavior on y {
            NumberAnimation {
                easing.type: Easing.OutElastic
                duration: 1000
            }
        }
    }

    /*Rectangle {
        id: rectangle2
        x: 50
        y: 50
        height: 100
        width: 100
        radius: 10
        focus: false

        Text {
            text: qsTr("Click me...")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                parent.rotation += 10
                parent.focus = true
            }
        }

        Keys.onLeftPressed: x -= 50
        Keys.onRightPressed: x += 50
        Keys.onUpPressed: y -= 50
        Keys.onDownPressed: y += 50
    }*/
}
