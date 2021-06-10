import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3


Item {
    Column{
        anchors.centerIn: parent
        spacing: 50
        Button{
            text: "Play Game"
            id: playButton
            background: Rectangle{
                color: "#ffffff"
                border.color: "#000080"
            }

            width: 160
            height: 70
            font.pixelSize: 20           
            onClicked: stackView.push("PlayMenu.qml")
        }
        Button{
            text: "Register game"
            id: registerButton
            background: Rectangle{
                color: "#ffffff"
                border.color: "#000080"
            }
            width: playButton.width
            height: playButton.height
            font.pixelSize: 20

            onClicked: stackView.push("RegisterMenu.qml")

        }
        Button{
            text: "Exit Game"
            id: exitButton
            background: Rectangle{
                color: "#ffffff"
                border.color: "#000080"
            }
            width: playButton.width
            height: playButton.height
            font.pixelSize: 20

            onClicked: Qt.quit()
        }
    }

}
