#include "ModelPlayer.h"
void ModelPlayer::setInfo(string name, string pass, int id)
{
	this->userName = name;
	this->passWord = pass;
	this->id = id;
}
void ModelPlayer::setUserName(string name)
{
	this->userName = name;
}
void ModelPlayer::setPassWord(string pass)
{
	this->passWord = pass;
}
string ModelPlayer::getUserName()
{
	return userName;
}
string ModelPlayer::getPassWord()
{
	return passWord;
}
int ModelPlayer::getID()
{
	return id;
}