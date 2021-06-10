#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ModelGame.h"
#include "ModelPlayer.h"
#include "Client.h"

#define SUCCESS 1
#define FAIL 0

using namespace std;
class ControlFindOp
{
private:
	string userName;
	int room;
	string userNameOp;
	string symbol;
	ModelPlayer modelplayer;
	Client client;
		
public: 
	void getUserName();
	void requestMatch();
	bool receiveInfoMatch();
	void creatGame();
};