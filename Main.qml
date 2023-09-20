import QtQuick
import QtQuick.Window

Window {
    width: 1000
    height: 600
    visible: true
    title: qsTr("Value Trainer")

    Connections {
        target: appManager
        onAskQuestion: mainLoader.source = "ui/QuestionScreen.qml"
        onShowAnswer: mainLoader.source = "ui/AnswerScreen.qml"
    }

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "ui/MenuScreen.qml"
    }
}
