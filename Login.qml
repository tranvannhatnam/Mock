import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
Window {
    visible: true
    title: qsTr("Login")
    width: 600
    height: 480
    property string name: ""
    property string password: ""

    Button {
        id: btnLogin
        x: 190
        y: 248
        width: 100
        height: 60
        text: "Đăng nhập"
        onClicked: {
            myLoginContext.setName(name)
            myLoginContext.setName(password)
        }
    }

    TextField {
        id: txtUsername
        x: 254
        y: 66
        anchors.right: parent.right
        width: 175
        height: 60
        text: ""
        font.pixelSize: 12
        anchors.rightMargin: 171
        onEditingFinished: {
            if (txtUsername.text==""){
                usernameMessage.text="Username can't be empty"
            }
            else{
                usernameMessage.text=""
                name=txtUsername.text
            }
        }
    }

    TextField {
        id: txtPassword
        x: 254
        y: 153
        width: 175
        height: 60
        text: ""
        anchors.right: parent.right
        font.pixelSize: 12
        anchors.rightMargin: 171
        onEditingFinished: {
            if (txtPassword.text==""){
                passwordMessage.text="Password can't be empty"
            }
            else{
                passwordMessage.text=""
                password=txtPassword.text
            }
        }
    }

    Text {
        id: text1
        x: 119
        y: 89
        text: qsTr("Username")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 126
        y: 164
        text: qsTr("Password")
        font.pixelSize: 12
    }

    Button {
        id: btnRegister
        x: 366
        y: 248
        width: 100
        height: 60
        text: "Đăng ký"
        onClicked: {
            myLoginContext.gotoRegister()
        }
    }

    Text {
        id: usernameMessage
        x: 473
        y: 89
        font.pixelSize: 12
    }

    Text {
        id: passwordMessage
        x: 473
        y: 176
        font.pixelSize: 12
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.5;height:480;width:640}D{i:3}D{i:6}
}
##^##*/
