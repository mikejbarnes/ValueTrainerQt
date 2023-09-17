import QtQuick 2.15

Rectangle {
    property string checkedColor: "red"
    property string unCheckedColor: "transparent"

    signal buttonClicked()

    width: 50
    height: 50
    border.width: 5
    border.color: checkedColor
    color: "transparent"
    radius: 5

    Rectangle {
        id: center

        property bool checked: true

        width: 30
        height: 30
        radius: 5

        color: checkedColor

        anchors {
            centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log(center.checked);
                if(center.checked) {
                    center.checked = false;
                    center.color = unCheckedColor;
                } else {
                    center.checked = true;
                    center.color = checkedColor;
                }

                buttonClicked();
            }
        }
    }
}
