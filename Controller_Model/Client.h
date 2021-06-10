#pragma once
#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <windowsx.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#include "ModelPlayer.h"
#include "rapidjson/document.h"
using namespace rapidjson;

#pragma comment (lib, "Ws2_32.lib")

#define IP "192.168.1.111"
#define PORT "80"
#define BUFFERLEN 100

class  Client
{
private:
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo* result = NULL, * ptr = NULL, hints;
	int iResult;
	char recvbuf[BUFFERLEN];
	int recvbuflen = BUFFERLEN;
public:
	 Client();
	~ Client();
	void connectToServer();
	void sendToServer(string);
	string receiveFromServer();
};