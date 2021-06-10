#include <iostream>
#include <string>
#include "ControlLogin.h"
#include "ControlRegister.h"
#include "ControlFindOp.h"
#include "ControlInputMove.h"
//#include "Client.h"
//#include "rapidjson/document.h"

using namespace std;
//using namespace rapidjson;
int main()
{
	ControlInputMove c;
	/*Client client;
	client.connectToServer();*/
	//while (1)
	//{
	//	c.sendPlaying(10,11,0,100,"X");
	//	if (c.receivePlaying()) cout << "dang nhap Thanh cong" << endl;
	//	else cout << "dang nhap khong thanh cong" << endl;
	//}
	if (c.checkWin(6, 6)==WIN)
	{
		cout << "cc" << endl;
	}
	else
	{
		cout << "lose" << endl;
	}
	return 0;
}