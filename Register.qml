import QtQuick 2.13
import QtQuick.Controls 2.5
import QtQuick.Window 2.12
Window  {

    Text {
        id: text1
        x: 207
        y: 103
        text: qsTr("Username")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 207
        y: 148
        text: qsTr("Password")
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle
        x: 286
        y: 95
        width: 134
        height: 32
        color: "#a1c4fd"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#a1c4fd"
            }

            GradientStop {
                position: 1
                color: "#c2e9fb"
            }
        }

        TextField {
            id: usernameTextInput
            x: 11
            y: 10
            focus: true
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignLeft


        }
    }

    Rectangle {
        id: rectangle1
        x: 286
        y: 143
        width: 134
        height: 31
        color: "#aaffff"

        TextField {
            id: passwordTextInput
            x: 13
            y: 3
            width: 80
            height: 20
            font.pixelSize: 12

        }
    }

    Button {
        id: btnRegisterId
        x: 286
        y: 254
        width: 81
        height: 30
        text: qsTr("Đăng ký")
        onClicked: {
            if((repasswordTextInput.text==passwordTextInput.text)&&(usernameTextInput.text!="")){
                myContext.setUsername(usernameTextInput.text)
                myContext.setPassword(passwordTextInput.text)
            }
        }
    }

    Text {
        id: text3
        x: 207
        y: 189
        text: qsTr("RePassword")
        font.pixelSize: 12
    }

    Rectangle {
        id: rectangle2
        x: 286
        y: 189
        width: 134
        height: 31
        color: "#aaffff"
        TextField {
            id: repasswordTextInput
            x: 13
            y: 3
            width: 80
            height: 20
            font.pixelSize: 12
            onTextChanged: {
                if(repasswordTextInput.text!=passwordTextInput.text){
                    isMatchNotify.text="Not Match"
                }
                if(repasswordTextInput.text==passwordTextInput.text){
                    isMatchNotify.text="Match"
                }
            }
        }
    }

    Text {
        id: isMatchNotify
        x: 438
        y: 198
        font.pixelSize: 12
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:1.5;height:480;width:640}
}
##^##*/
