#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ModelPlayer.h"
#include "ModelGame.h"
#include "Client.h"

#define SUCCESS 1
#define FAIL 0

using namespace std;
class ControlRegister
{
private:
	string userName;
	string passWord;
	int win_number, lose_number;
	int idRoom;
	ModelPlayer modelplayer;
	Client client;
public:
	//ControlRegister();
	//~ControlRegister();
	void getAccount(string username, string pass);
	bool checkRuleAccount();
	void sendAccToServer();
	bool getResultCheckAcc();
	void saveAccModelPlayer(); // save to Client Model
};
