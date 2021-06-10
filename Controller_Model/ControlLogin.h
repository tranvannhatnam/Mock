#pragma once
#include <iostream>
#include "ModelPlayer.h"
#include "Client.h"
#include <string>
#include <sstream>

#define SUCCESS 1
#define FAIL 0
using namespace std;
class ControlLogin
{
private:
	string userName;
	string passWord;
	int win_number, lose_number;
	int id;
	ModelPlayer modelplayer;
	Client client;
public:
	void getAccount(string username, string pass);
	bool checkRuleAccount();
	void sendAccToServer();
	bool getResultCheckAcc();
	void saveAccModelPlayer(); // save to Client Model
};