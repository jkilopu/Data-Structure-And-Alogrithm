#include <stdio.h>
#include <windows.h>
#include <conio.h>
int main()
{
	HANDLE InPut = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE OutPut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pox = {0, 0};
	char ch;

	ch = getch();
	putchar(ch);

	return 0;
}
