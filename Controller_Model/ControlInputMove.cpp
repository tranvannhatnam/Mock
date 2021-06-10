#include "ControlInputMove.h"
bool ControlInputMove::checkInputMove(int x, int y)
{
	if (modelgame.getValue(x, y) == state::EMPTY) return TRUE;
	else FALSE;
}
bool ControlInputMove::checkWin(int x, int y)
{
	//// code nay de test
	//for(int i=2;i<=4;i++)
	//modelgame.saveData(i, i, state::X); 
	//modelgame.saveData(5, 5, state::X);
	//modelgame.coutBoard();
	//state t = state::X;
	//// end code test
	state t;
	if (symbol == "X") t = state::X;
	else if (symbol == "O") t= state::O;
	else if (symbol == "EMPTY") t= state::EMPTY;

	int arrx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
	int arry[8] = { -1, 1, -1, 1, 0, 0, 1, -1 };
	int dem = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) dem = 0;
		int a = x;
		int b = y;
		while (true)
		{
			a += arrx[i];
			b += arry[i];
			if (a < 0 || a > 19 || b < 0 || b > 19) {
				break;
			}
			if (modelgame.getValue(a, b) != t) {
				break;
			}
			else if (modelgame.getValue(a, b) == t)
				dem++;
		}
		if (dem >= 4)
		{
			return WIN;
		}
	}
	//click.XO = state::EMPTY;
	return NORMAL;
}
void ControlInputMove::sendPlaying(int x, int y, bool gameResult, int room, string symbol)
{
	stringstream ss;
	//userName = "huy"; // to demo
	ss << "{\"GOAL\":\"Play\",\"X\":" << x << ",\"Y\":" << y << ",\"GAMERESULT\":" << gameResult << ",\"ROOM\":" << room << ",\"XO\":\"" << symbol << "\"}" << endl;
	string sendBuffer = ss.str();
	//cout << sendBuffer << endl;
	client.sendToServer(sendBuffer);
}
void ControlInputMove::saveCoordinate(int x, int y, string symbol)
{
	if (symbol=="X") modelgame.saveData(x, y, state::X);
	else if (symbol == "O") modelgame.saveData(x, y, state::O);
	else if (symbol == "EMPTY") modelgame.saveData(x, y, state::EMPTY);
}
bool ControlInputMove::receivePlaying()
{
	string s = client.receiveFromServer();
	const char* json = s.c_str();
	Document d;
	d.Parse(json);
	cout << d["GOAL"].GetString() << endl;
	if ((string)d["GOAL"].GetString() == "FBPlay")
	{
			x = d["X"].GetInt(); cout << d["X"].GetInt() <<endl;
			y = d["Y"].GetInt(); cout << d["Y"].GetInt() << endl;
			symbol = (string)d["XO"].GetString(); cout << (string)d["XO"].GetString() << endl;
			gameResult = d["GAMERESULT"].GetInt(); cout << d["GAMERESULT"].GetInt() << endl;
			return SUCCESS;
	}
	return FAIL;
}