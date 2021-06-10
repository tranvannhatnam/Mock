#pragma once
#ifndef __MODELPLAYER_H_
#define __MODELPLAYER_H_
#include <iostream>

using namespace std;

class ModelPlayer
{
private:
	string userName;
	string passWord;
	int win_number, lose_number;
	int id;
public:
	void setInfo(string, string, int);
	void setUserName(string);
	void setPassWord(string);
	string getUserName();
	string getPassWord();
	int getID();
};
#endif // !__MODELPLAYER_H