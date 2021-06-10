#include "Client.h"

Client::Client()
{
	
	WSADATA wsaData;
	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0)
	{
		cerr << "WSAStartup failed with error: " << iResult << endl;
		//return 1;
	}
	else 
	{
		/////////////////////////////////////////////////////////////////////
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;

		// Resolve the server address and port
		iResult = getaddrinfo(IP, PORT, &hints, &result);
		if (iResult != 0) 
		{
			cout << "getaddrinfo failed with error: " << iResult << endl;
			WSACleanup();
			//return 1;
		}
		/////////////////////////////////////////////////////////////////////////////
		// create socket
		Client::ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (ConnectSocket == INVALID_SOCKET)
		{
			cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
			WSACleanup();
		}
		else connectToServer();
	}
}
Client::~Client()
{
	closesocket(Client::ConnectSocket);
	WSACleanup();
}
void Client::connectToServer()
{
	ptr = result;
	iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		cerr << "Can't connect to server, Err #" << endl;
		closesocket(ConnectSocket);
		WSACleanup();
	}
}
string Client::receiveFromServer()
{
	// Receive until the peer closes the connection
	iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
	if (iResult > 0) // iRessult = Bytes received
	{
		recvbuf[iResult] = '\0';
		string str=recvbuf;
		cout << str << endl;
		//processReceive(str);
		return str;
	}
	else if (iResult == 0)
	{
		cout << "Connection closed" << endl;
	}
	else
	{
		cerr << "recv failed with error: " << WSAGetLastError() << endl;
	}
}
void Client::sendToServer(string str)
{
	char s[100];
	//cout << " Khoi tao clinet " << endl;
	cin >> s;
	
	//sprintf(s, "{\"demand\":\"login\",\"username\":\"this->,\"id\":12}");
	iResult = send(ConnectSocket, str.c_str(), str.size(), 0);
	if (iResult == SOCKET_ERROR) 
	{
		cerr << "send failed with error: " << WSAGetLastError() << endl;;
		closesocket(ConnectSocket);
		WSACleanup();
		//return 1;
	}
	cout << "Bytes Sent: " << iResult << endl;
}
