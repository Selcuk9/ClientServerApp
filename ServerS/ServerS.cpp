#pragma comment(lib,"Ws2_32.lib")

#include <winsock2.h>
#include <iostream>


#pragma warning(disable:4996)
int main(int argc, char* argv[])
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2,1);
	
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeOfaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
 

	SOCKET sListen = socket(AF_INET,SOCK_STREAM,NULL);
	bind(sListen,(SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeOfaddr);

	if (newConnection == 0)
	{
		std::cout << "Error #2\n";
	}
	else {
		std::cout << "Client Connected!\n";
		char msg[256] = "Hello. it's my first network program!";
		send(newConnection,msg,sizeof(addr),NULL);
	}

	system("pause");

	return 0;

}


