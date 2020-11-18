#pragma comment(lib,"ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable:4996)
int main()
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);

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

	SOCKET connection = socket(AF_INET,SOCK_STREAM,NULL);
	if (connect(connection,(SOCKADDR*)&addr,sizeof(addr)) != 0)
	{
		std::cout << "Error: failed connect to server.\n";
		return 1;
	}
	std::cout << "Connected\n";
	char msg[256];
	system("pause");
	recv(connection,msg,sizeof(msg),NULL);
	std::cout << msg << std::endl;

	return 0;
}