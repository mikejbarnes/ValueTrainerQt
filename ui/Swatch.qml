import QtQuick 2.15

Rectangle {
    id: swatch

    property int x_pos
    property int y_pos
    property int squareWidth
    property string squareColor
    property string borderColor
    property int borderWidth
    property int value

    x: x_pos
    y: y_pos
    color: squareColor
    width: squareWidth
    height: 100
    radius: 5
    border.color: borderColor
    border.width: borderWidth

    MouseArea {
        anchors.fill: parent
        onPressed: swatch.color = "purple"
        onReleased: swatch.color = squareColor
        onClicked: appManager.answerSelected(value)
    }
}

