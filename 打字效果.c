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
		SlowPrint("~~~~~~~~~~~~~~ Hello, World. ~~~~~~~~~~~~~~\n", 10);
		printf("\n");
		Sleep(200);
		a++;
	}
	while (a != 5);
	printf("Test the end\n");
	return 0;
 }
