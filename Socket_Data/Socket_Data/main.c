#include <stdio.h>
#include"Socket.h"
#include <string.h>
char buffer[4096] = { 0 };
void main()
{
	Socket_Client_Init("54.192.22.61", 80);
	Send("GET /v1/bpi/currentprice.json HTTP/1.1\r\nHost: api.coindesk.com\r\n\r\n");
	Recv(buffer, sizeof(buffer));
	printf(" Data : %s\r\n", buffer);
	const char* Substr="\"rate_float\":";
	char* Start_Pos=strstr(buffer, Substr);
	if (Start_Pos != NULL)
	{
		Start_Pos += strlen(Substr);
		char Bitcoin_Gia[20] = { 0 };
		int index = 0;
		while (Start_Pos[index] != '}')
		{
			Bitcoin_Gia[index] = Start_Pos[index];
			index++;
		}
		printf("\nGia Bitcoin la: %s\r\n", Bitcoin_Gia);



	}
	else
		printf("\nKhong co thong tin gia Bitcoin\r\n");
	

}
