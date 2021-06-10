#include "ModelGame.h"

ModelGame::ModelGame()
{
	boardVector.assign(BOARD_SIZE, vector<state>(BOARD_SIZE));
}
bool ModelGame::checkValidMove(int xAxis, int yAxis, state type)
{
	if (this->boardVector.at(xAxis).at(yAxis) == state::EMPTY)
	{
		this->boardVector.at(xAxis).at(yAxis) = type;
		return true;
	}
	else
	{
		return false;
	}
}
void ModelGame::coutBoard()
{
	int dong = boardVector.size();
	for (int i = 0; i < dong; i++)
	{
		int cot = boardVector[i].size();
		for (int j = 0; j < cot; j++)
		{
			cout << (int)boardVector[i][j];
		}
		cout << endl;
	}
}
void ModelGame::resetBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < boardVector[i].size(); j++)
		{
			boardVector[i][j] = state::EMPTY;
		}
		//cout<< endl;
	}
}
void ModelGame::saveData(int x, int y, state type)
{
	boardVector[x][y] = type;
}
state ModelGame::getValue(int x, int y)
{
	switch (boardVector[x][y])
	{
		case state::EMPTY: return state::EMPTY;
		case state::O: return state::O;
		case state::X: return state::X;
		default: break;
	}
}
void ModelGame::saveInfoMatch(int idRoom, string userNameOp,string mySymbol)
{
	this->idRoom = idRoom;
	this->userNameOp = userNameOp;
	this->mySymbol = mySymbol;
}