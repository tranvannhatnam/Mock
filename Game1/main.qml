import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


ApplicationWindow {
    id: root
    width: 480
    height: 720
    visible: true
    title: qsTr("Hello World")

    Image {
        id: backgroundimage
        source: "backgroundimage.jpg"
        anchors.fill: parent
    }

    Loader{
        id: mainLoader
        anchors{
            top: parent.top
            right: parent.right
            left: parent.left
            bottom: parent.bottom
        }
        source: "StackViewPage.qml"
    }
}
