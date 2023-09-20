import QtQuick 2.15

Item {
    id: sessionScreen

    property int swatchHeight: 100
    property int swatchMargin: 40
    property int swatchSpacing: 10

    Rectangle {
        id: sessionBackground

        property string bgColor: "#ABABFF"

        color: bgColor
        anchors.fill: parent
    }

    Component.onCompleted: {
        let component = Qt.createComponent("Swatch.qml");

        let swatchBarLength = Window.width - 2 * swatchMargin;
        let totalSpacingLength = (appManager.swatches - 1) * swatchSpacing;
        let swatchWidth = (swatchBarLength - totalSpacingLength)/appManager.swatches;

        for(let i = 0; i < appManager.swatches; ++i)
        {
            let swatch = component.createObject(sessionBackground);
            swatch.x_pos = swatchMargin + (swatchWidth + swatchSpacing) * i;
            swatch.y_pos = 400;
            swatch.squareColor = colorHandler.colorSelections[i];
            swatch.squareWidth = swatchWidth;
            swatch.value = i;
        }
    }

    Swatch {
        id: target

        property string targetColor: "#AFBFCC"

        width: 250
        height: 250
        color: targetColor

        anchors {
            top: parent.top
            topMargin: 80
            horizontalCenter: parent.horizontalCenter
        }
    }
}
