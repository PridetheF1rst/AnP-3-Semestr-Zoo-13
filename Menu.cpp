#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "zoo.h"
#include "Main_Menu.h"

using namespace std;

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbInfo;
COORD coord;

void GetBufferInfo(COORD* coord)
{
	GetConsoleScreenBufferInfo(consoleHandle, &csbInfo);
	coord->X = (csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1);
	coord->Y = (csbInfo.srWindow.Bottom - csbInfo.srWindow.Top + 1);
}

int menu(string menuElems[], int size, const char* inf)
{
	COORD coord1;
	GetBufferInfo(&coord);
	GetBufferInfo(&coord1);
	int pointer = 0;
	int code;

	while (true)
	{
		coord1 = coord;
		SetConsoleTextAttribute(consoleHandle, (WORD)((Black << 4) | Yellow));
		system("cls");
		cout << inf << endl;
		for (int i = 0; i < size / sizeof(menuElems[0]); i++)
		{
			SetConsoleCursorPosition(consoleHandle, coord1);
			if (pointer == i)
			{
				SetConsoleTextAttribute(consoleHandle, (WORD)((Black << 4) | Red));
				cout << "-->";
			}
			else
			{
				cout << " ";
				SetConsoleTextAttribute(consoleHandle, (WORD)((Black << 4) | Yellow));
			}
			cout << i + 1 << " - " << menuElems[i] << endl;
			coord1.Y++;
		}
		code = _getch();
		switch (code)
		{
		case  Down:
		{
			pointer++;
			if (pointer >= size / sizeof(menuElems[0]))
			{
				pointer = 0;
			}
			break;
		}
		case Up:
		{
			pointer--;
			if (pointer < 0)
			{
				pointer = size / sizeof(menuElems[0]) - 1;
			}
			break;
		}
		case Enter:
		{
			SetConsoleCursorPosition(consoleHandle, coord1);
			return pointer;
			_getch();
		}
		default:
			break;
		}
	}
	return EXIT_SUCCESS;
}