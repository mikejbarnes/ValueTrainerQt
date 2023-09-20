import QtQuick 2.15

Item {
    id: sessionScreen

    property int swatchHeight: 100
    property int swatchMargin: 40
    property int swatchSpacing: 10

    Rectangle {
        id: sessionBackground

        color: colorHandler.backgroundColor
        anchors.fill: parent
    }

    Component.onCompleted: {
        let component = Qt.createComponent("Swatch.qml");

        let swatchBarLength = Window.width - 2 * swatchMargin;
        let totalSpacingLength = (colorHandler.colorSections() - 1) * swatchSpacing;
        let swatchWidth = (swatchBarLength - totalSpacingLength)/colorHandler.colorSections();

        for(let i = 0; i < colorHandler.colorSections(); ++i)
        {
            let swatch = component.createObject(sessionBackground);
            swatch.x_pos = swatchMargin + (swatchWidth + swatchSpacing) * i;
            swatch.y_pos = 400;
            swatch.squareColor = "transparent"
            swatch.borderColor = "black"
            swatch.borderWidth = 5
            swatch.squareWidth = swatchWidth;
            swatch.value = i;
        }
    }

    Swatch {
        id: target

        width: 250
        height: 250
        color: colorHandler.targetColor

        anchors {
            top: parent.top
            topMargin: 80
            horizontalCenter: parent.horizontalCenter
        }
    }
}
