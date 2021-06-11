import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Window 2.3



Item {
    Button{
        id: backButton
        text: "Back"
        onClicked: stackView.pop()
    }

    Row {
        id: row
        anchors.centerIn: parent
        width: 341
        height: 101
        spacing: 20
        Column{
            id: column1
            spacing: 20
            Rectangle {
                id: userNameRectangle
                width: 120
                height: 40
                border.color: "#000080"
                Text {
                    anchors.centerIn: userNameRectangle
                    text: qsTr("User Name")
                }
            }
            Rectangle {
                id: passwordRectangle
                width: userNameRectangle.width
                height: userNameRectangle.height

                border.color: "#000080"
                Text {
                    anchors.centerIn: passwordRectangle
                    text: qsTr("Password")

                }
            }
            Button{
                width: 100
                id: buttonLogin
                text: "Login"
                background: Rectangle{
                    color: "#ffffff"
                    border.color: "#000080"
                }
                onClicked: {
                    Playmenucontroler.username = userNameTextFieldID.text
                    Playmenucontroler.password = passwordTextFieldID.text
                    console.log(userNameTextFieldID.text)
                    console.log(passwordTextFieldID.text)       
                }
            }
        }
        Column{
            id: column2
            spacing: 20
            TextField{
                width: 200
                id: userNameTextFieldID
            }
            TextField{
                width: 200
                id: passwordTextFieldID
                echoMode: TextField.Password
            }
        }

    }

}

