#include <stdio.h>
#include <windows.h>

void SlowPrint(char* string, int sleeptime)
{
	int i = 0;
	while(string[i] != '\0')
	{
		printf("%c",string[i]);
		Sleep(sleeptime);
		i++;
	}
 } 
 int main()
 {   
 	int a = 0;
	do
	{
		SlowPrint("~~~~~~~~~~~~~~ Hello, World. ~~~~~~~~~~~~~~\n", 30);
		printf("\n");
		Sleep(2);
		a++;
	}
	while (a != 5);
	
	return 0;
 }
