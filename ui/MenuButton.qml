import QtQuick 2.15

Rectangle {
    id: button

    property string buttonColor: "purple"
    property string buttonText: "Button"
    property int textSize: 60

    signal buttonClicked()

    radius: 5
    color: buttonColor

    Text {
        anchors.centerIn: parent
        color: "white"
        text: buttonText
        font.pixelSize: textSize
    }

    MouseArea {
        anchors.fill: parent
        onPressed: button.color = "red"
        onReleased: button.color = buttonColor
        onClicked: button.buttonClicked()
    }
}
