import QtQuick 2.15
import QtQuick.Controls

Item {
    id: menuScreen

    Rectangle {
        anchors.fill: parent
        color: "#124500"
    }

    CheckButton {
        id: backgroundCheck

        onButtonClicked: colorHandler.backgroundIsRandom

        anchors {
            left: parent.left
            leftMargin: 20
            top: parent.top
            topMargin: 50
        }
    }

    Text {
        id: backgroundLabel

        color: "white"
        font.pixelSize: 40
        text: "Randomize Background Color"
        horizontalAlignment: Text.AlignLeft

        anchors {
            left: backgroundCheck.right
            leftMargin: 20
            verticalCenter: backgroundCheck.verticalCenter
        }
    }

    CheckButton {
        id: saturationCheck

        onButtonClicked: colorHandler.saturationIsRandom();

        anchors {
            left: parent.left
            leftMargin: 20
            top: backgroundLabel.bottom
            topMargin: 20
        }
    }

    Text {
        id: saturationLabel

        text: "Saturation"
        color: "white"
        font.pixelSize: 40

        anchors {
            left: saturationCheck.right
            leftMargin: 20
            verticalCenter: saturationCheck.verticalCenter
        }
    }

    RangeSlider {
        id: saturationSlider

        property int start: 0
        property int end: 100
        property int step: 10
        property int handleSize: 30

        first.onValueChanged: colorHandler.onSaturationMinChanged(first.value)
        second.onValueChanged: colorHandler.onSaturationMaxChanged(second.value)

        width: 400
        height: 100

        from: start
        to: end
        stepSize: step
        snapMode: RangeSlider.SnapAlways

        anchors {
            left: saturationLabel.right
            leftMargin: 50
            verticalCenter: saturationLabel.verticalCenter
        }

        first.value: start
        first.handle: Rectangle {
            implicitWidth: saturationSlider.handleSize
            implicitHeight: saturationSlider.handleSize
            radius: 50
            x: saturationSlider.first.visualPosition * saturationSlider.availableWidth
            y: saturationSlider.topPadding + saturationSlider.availableHeight / 2 - height / 2
        }

        second.value: end
        second.handle: Rectangle {
            implicitWidth: saturationSlider.handleSize
            implicitHeight: saturationSlider.handleSize
            radius: 50
            x: saturationSlider.second.visualPosition * saturationSlider.availableWidth
            y: saturationSlider.topPadding + saturationSlider.availableHeight / 2 - height / 2
        }

    }

    Text {
        id: sliderValue

        text: Math.round(saturationSlider.first.value) + "-" + Math.round(saturationSlider.second.value) + " %"
        color: "white"
        font.pixelSize: 50

        anchors {
            left: saturationSlider.right
            leftMargin: 50
            verticalCenter: saturationLabel.verticalCenter
        }
    }

    CheckButton {
        id: hueCheck

        onButtonClicked: colorHandler.hueIsRandom()

        anchors {
            left: parent.left
            leftMargin: 20
            top: saturationCheck.bottom
            topMargin: 20
        }
    }

    Text {
        id: hueLabel

        color: "white"
        font.pixelSize: 40
        text: "Randomize Hue"
        horizontalAlignment: Text.AlignLeft

        anchors {
            left: hueCheck.right
            leftMargin: 20
            verticalCenter: hueCheck.verticalCenter
        }
    }

    Text {
        id: sectionsLabel

        text: "Sections"
        color: "white"
        font.pixelSize: 40

        anchors {
            left: hueCheck.right
            leftMargin: 20
            top: hueCheck.bottom
            topMargin: 20
        }
    }

    Slider {
        id: sectionsSlider

        property int start: 5
        property int end: 17
        property int step: 2
        property int handleSize: 30

        value: colorHandler.colorSections()
        onValueChanged: colorHandler.setColorSections(sectionsSlider.value)

        width: 400
        height: 100

        from: start
        to: end
        stepSize: step
        snapMode: Slider.SnapAlways

        handle:
            Rectangle {
                x: sectionsSlider.visualPosition * sectionsSlider.availableWidth
                y: sectionsSlider.topPadding + sectionsSlider.availableHeight / 2 - height / 2
                implicitWidth: sectionsSlider.handleSize
                implicitHeight: sectionsSlider.handleSize
                radius: 50
            }

        anchors {
            left: sectionsLabel.right
            leftMargin: 50
            verticalCenter: sectionsLabel.verticalCenter
        }
    }

    Text {
        id: sectionsValue

        color: "white"
        font.pixelSize: 40
        text: sectionsSlider.value
        horizontalAlignment: Text.AlignLeft

        anchors {
            left: sectionsSlider.right
            leftMargin: 20
            verticalCenter: sectionsSlider.verticalCenter
        }
    }

    Text {
        id: roundsLabel

        text: "Rounds per Session"
        color: "white"
        font.pixelSize: 40

        anchors {
            left: hueCheck.right
            leftMargin: 20
            top: sectionsLabel.bottom
            topMargin: 20
        }
    }

    Slider {
        id: roundsSlider

        property int start: 10
        property int end: 50
        property int step: 5
        property int handleSize: 30

        value: appManager.roundsPerSession()
        onValueChanged: appManager.setRoundsPerSession(roundsSlider.value)

        width: 400
        height: 100

        from: start
        to: end
        stepSize: step
        snapMode: Slider.SnapAlways

        handle:
            Rectangle {
                x: roundsSlider.visualPosition * roundsSlider.availableWidth
                y: roundsSlider.topPadding + roundsSlider.availableHeight / 2 - height / 2
                implicitWidth: roundsSlider.handleSize
                implicitHeight: roundsSlider.handleSize
                radius: 50
            }

        anchors {
            left: roundsLabel.right
            leftMargin: 50
            verticalCenter: roundsLabel.verticalCenter
        }
    }

    Text {
        id: roundsValue

        color: "white"
        font.pixelSize: 40
        text: roundsSlider.value
        horizontalAlignment: Text.AlignLeft

        anchors {
            left: roundsSlider.right
            leftMargin: 20
            verticalCenter: roundsSlider.verticalCenter
        }
    }

    MenuButton {
        width: 400
        height: 150

        anchors {
            right: parent.right
            rightMargin: 40
            bottom: parent.bottom
            bottomMargin: 40
        }

        buttonColor: "pink"
        buttonText: "Start Session"
        onButtonClicked: appManager.prepareQuestion()
    }

}
