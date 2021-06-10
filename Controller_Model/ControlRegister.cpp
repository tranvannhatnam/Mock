#include "ControlRegister.h"
void ControlRegister::getAccount(string username, string pass)
{
	this->userName = username;
	this->passWord = pass;
}
bool ControlRegister::checkRuleAccount()
{
	if ((this->userName != "") && (this->passWord != ""))
	{
		return SUCCESS;
	}
	return FAIL;
}
void ControlRegister::sendAccToServer()
{
	// send acc to serrver
	stringstream ss;
	userName = "huy";
	passWord = "12345";
	ss << "{\"GOAL\":\"Register\",\"USERNAME\":\"" << userName << "\",\"PASSWORD\":\"" << passWord << "\"}" << endl;
	string sendBuffer = ss.str();
	//cout << sendBuffer << endl;
	client.sendToServer(sendBuffer);
}
bool ControlRegister::getResultCheckAcc()
{
	string s = client.receiveFromServer();
	const char* json = s.c_str();
	Document d;
	d.Parse(json);
	cout << d["GOAL"].GetString() << endl;
	if ((string)d["GOAL"].GetString() == "FBRegister")
	{
		if ((string)d["RESULT"].GetString() == "Success")
			return SUCCESS;
	}
	return FAIL;
}
void ControlRegister::saveAccModelPlayer()
{
	modelplayer.setInfo(userName, passWord, idRoom);
}