#include<iostream>
#include<memory>
#include<Windows.h>

using namespace std;

int main()
{
	int screen_width = 80;
	int screen_height = 30;
	int total = screen_width * screen_height;

	shared_ptr<wchar_t[]> screen(new wchar_t[total] {}, default_delete<wchar_t[]>());
		
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD bytes_written = 0;

	while (true)
	{
		//Draw Stats & Border.
		for (int i{}; i < screen_width; i++)
		{
			screen.get()[i] = L'_';
			screen.get()[screen_width * 2 + i] = L'_';
		}

		//Display Frame.
		WriteConsoleOutputCharacter(hConsole, screen.get(), total, {0,0}, &bytes_written);
	}
}