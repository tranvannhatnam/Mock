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
        height: 223
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
            Rectangle {
                id: passwordsubmitRectangle
                width: userNameRectangle.width
                height: userNameRectangle.height

                border.color: "#000080"
                Text {
                    anchors.centerIn: passwordsubmitRectangle
                    text: qsTr("Submit Password")
                }
            }
            Button{
                width: 100
                id: buttonLogin
                text: "Register"
                onClicked: {
                    if ((passwordTextFieldID.text == passwordsubmitTextFieldID.text) && (passwordTextFieldID.text != "") )
                    {
                        RegisterMenucontroller.setPasswordRegister ( passwordsubmitTextFieldID.text)
                        RegisterMenucontroller.setPasswordRegister ( passwordsubmitTextFieldID.text)
                        console.log(userNameTextFieldID.text)
                        console.log(passwordsubmitTextFieldID.text)

                    }
                    else
                    {
                        text1.color= "#dc143c"
                    }
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
                //                echoMode: TextField.Password
            }
            TextField{
                width: 200
                id: passwordsubmitTextFieldID
                //                echoMode: TextField.Password
            }
            Text {
                id: text1
                width: 200
                color: Qt.rgba(0,0,0,0)
                text: qsTr("Password doesn't match")
                font.pixelSize: 16
            }
        }
    }
}
