#include "ControlLogin.h"
void ControlLogin::getAccount(string username, string pass)
{
	this->userName = username;
	this->passWord = pass;
}
bool ControlLogin::checkRuleAccount()
{
	if ((this->userName != "") && (this->passWord != ""))
	{
		return SUCCESS;
	}
	return FAIL;
}
void ControlLogin::sendAccToServer()
{
	// send acc to serrver
	stringstream ss;
	userName = "huy";
	passWord = "12345";
	ss << "{\"GOAL\":\"Login\",\"USERNAME\":\"" << userName << "\",\"PASSWORD\":\"" << passWord << "\"}" << endl;
	string sendBuffer = ss.str();
	//cout << sendBuffer << endl;
	client.sendToServer(sendBuffer);
}
bool ControlLogin::getResultCheckAcc()
{
	string s = client.receiveFromServer();
	const char* json = s.c_str();
	Document d;
	d.Parse(json);
	cout << d["GOAL"].GetString() << endl;
	if ((string)d["GOAL"].GetString() == "FBLogin")
	{
		if ((string)d["RESULT"].GetString() == "Success")
			return TRUE;
	}
	return FALSE;
}
void ControlLogin::saveAccModelPlayer()
{
	modelplayer.setInfo(userName, passWord, id);
}