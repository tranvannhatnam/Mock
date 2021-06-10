#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ModelGame.h"
#include "ModelPlayer.h"
#include "Client.h"
#define SUCCESS 1
#define FAIL 0

#define WIN 1
#define NORMAL 0

using namespace std;
class ControlInputMove
{
private:
	ModelGame modelgame;
	Client client;
	int x;
	int y;
	string symbol;
	bool gameResult;
public:
	bool checkInputMove(int x, int y);
	bool checkWin(int x, int y);
	void sendPlaying(int x, int y, bool gameResult, int room, string symbol);
	void saveCoordinate(int x, int y, string symbol);
	bool receivePlaying();
};