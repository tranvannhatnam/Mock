#pragma once
#ifndef __MODELGAME_H_
#define __MODELGAME_H_

#include <iostream>
#include <vector>

using namespace std;
#define BOARD_SIZE 20

enum class state
{
	EMPTY=0, 
	X,
	O
};
class ModelGame
{
private:
	int idRoom;
	string userNameOp;
	string mySymbol;
	vector<vector<state>> boardVector;
public:
	ModelGame();
	void coutBoard();
	bool checkValidMove(int xAxis, int yAxis, state type);
	state getValue(int x, int y);
	void resetBoard();
	void saveData(int x, int y, state type);
	void saveInfoMatch(int idRoom, string userNameOp, string mySymbol);
};
#endif // !__MODELGAME_H