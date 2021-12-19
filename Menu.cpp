#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <csetjmp>
#include "zoo.h"
#include "Input.h"

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

void goto_x_y(short x, short y)
{
	SetConsoleCursorPosition(consoleHandle, { x, y });
}

int menu(string menuElems[], int size, string inf)
{
	COORD coord1;
	GetBufferInfo(&coord);
	GetBufferInfo(&coord1);
	int pointer = 0;
	int code;

	while (true)
	{
		coord1 = coord;
		SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Blue));
		system("cls");
		cout << inf << endl;
		for (int i = 0; i < size / sizeof(menuElems[0]); i++)
		{
			if (pointer == i)
			{
				SetConsoleTextAttribute(consoleHandle, (WORD)((White  << 4) | Black));
				cout << "-->";
			}
			else
			{
				cout << " ";
				SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Blue));
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

int menu_category(string menuElems[], int size, string inf,jmp_buf env)
{
	COORD coord1;
	GetBufferInfo(&coord);
	GetBufferInfo(&coord1);
	int pointer = 0;
	int code;

	while (true)
	{
		coord1 = coord;
		SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Blue));
		system("cls");
		cout << inf << endl;
		for (int i = 0; i < size / sizeof(menuElems[0]); i++)
		{
			SetConsoleCursorPosition(consoleHandle, coord1);
			if (pointer == i)
			{
				SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Black));
				cout << "-->";
			}
			else
			{
				SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Blue));
			}
			cout<< i + 1 << " - " << menuElems[i] << endl;
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
		case Esc:
		{
			longjmp(env,0);
		}
		default:
			break;
		}
	}
	return EXIT_SUCCESS;
}

int start_menu()
{
	cursor_off_on(FALSE);
	string main_menu_buttons[] = { "Начать","О программе","Выход" };
	string about[] = { "Программа была разработана для работы с базой данных зоопарка в рамках третьего семестра по дисциплине 'Алгоритмизация и Программирование'\n",
	"Полный код программы вы можете найти по ссылке https://github.com/PridetheF1rst/AnP-3-Semestr-Zoo-13.git \n","\t\t\t\tВерсия 1.0" };
start:
	switch (menu(main_menu_buttons, sizeof(main_menu_buttons), "Добро пожаловать в программу работы с зоопарком !\n================================================="))
	{
	case 0:
		return 0;
	case 1:
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			goto_x_y(5 + i * 17, 15 + i);
			cout << about[i];
		}
		cout << endl;
		goto_x_y(50, 19);
		system("pause");
		goto start;
	case 2:
		system("cls");
		SetConsoleTextAttribute(consoleHandle, (WORD)((White << 4) | Blue));
		cout << "До свидания" << endl;
		system("pause");
		exit(0);
	}
}
