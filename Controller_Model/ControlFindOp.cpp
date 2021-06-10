#include "ControlFindOp.h"
void ControlFindOp::getUserName()
{
	this->userName = modelplayer.getUserName();
}
void ControlFindOp::requestMatch()
{
	getUserName();
	stringstream ss;
	userName = "huy"; // to demo
	ss << "{\"GOAL\":\"FindMatch\",\"USERNAME\":\"" << userName << "\"}" << endl;
	string sendBuffer = ss.str();
	//cout << sendBuffer << endl;
	client.sendToServer(sendBuffer);
}
bool ControlFindOp::receiveInfoMatch()
{
	string s = client.receiveFromServer();
	const char* json = s.c_str();
	Document d;
	d.Parse(json);
	cout << d["GOAL"].GetString() << endl;
	if ((string)d["GOAL"].GetString() == "FBFindMatch")
	{
		if ((string)d["RESULT"].GetString() == "Success")
		{   
			room = d["ROOM"].GetInt(); cout << d["ROOM"].GetInt() << endl;
			userNameOp = (string)d["USERNAMEOP"].GetString(); cout << (string)d["USERNAMEOP"].GetString() << endl;
			symbol = (string)d["SYMBOL"].GetString(); cout << (string)d["SYMBOL"].GetString() <<endl;
			return SUCCESS;
		}		
	}
	return FAIL;
}
void ControlFindOp::creatGame()
{
	ModelGame modelgame;
	modelgame.saveInfoMatch(room, userNameOp, symbol);
}