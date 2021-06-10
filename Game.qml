import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12
Window {
    width: 550
    height: 650
    visible: true
    title: qsTr("Tic tac toe")
    Rectangle{
        width: parent.width
        height: 100

        Button {
            id: button
            width: 100
            height: 60
            text: "What ever"
            onClicked: {
                myGameContext.pushbtn()
            }
        }

        TextField {
            id: textInput
            anchors.right: parent.right
            width: 80
            height: 60
            text: myGameContext.opponent
            font.pixelSize: 12
            onEditingFinished: {
                myGameContext.opponent=text
            }
        }

    }

    Rectangle{
        y:150
        width: parent.width
        height: 600
        TableView {
            anchors.fill: parent
            y: 150
            clip: true
            model:myGameContext
            delegate: Rectangle {
                implicitWidth: 50
                implicitHeight: 50
                border.color: "black"
                border.width: 1
                Text {
                    id: textId
                    text: qsTr(tableData)
                    font.pointSize: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        if (currentState==0){
                            console.log("Not your turn")
                        }
                        else{
                            if(textId.text!=""){
                                console.log("Invalid Move")
                            }
                            else {
                                tableData="O"
                            }
                        }
                    }
                }
            }
        }
    }
}
