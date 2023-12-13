#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
	int screen_width = 120;
	int screen_height = 30;
	int total = screen_width * screen_height;

	wchar_t* screen = new wchar_t[total]{};//Don't forget to initialize.
			
	//Display a * at end of buffer.
	//screen[((screen_width-1) * screen_height) + screen_height-1] = L' ';

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	while (true)
	{
		//Draw Stats & Border.
		for (int i{}; i < screen_width; i++)
		{
			screen[i] = L'_';
			screen[screen_width * 2 + i] = L'_';
		}

		//Display Frame.
		WriteConsoleOutputCharacter(hConsole, screen, total, {0,0}, &dwBytesWritten);
	}
	//There should be delete[] screen here but it never gets called due to infinite while loop.
}