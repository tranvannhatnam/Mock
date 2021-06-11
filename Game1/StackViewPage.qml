import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    anchors.fill: parent
    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: "MainMenu.qml"
    }

}
