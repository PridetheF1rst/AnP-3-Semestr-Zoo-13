#include <iostream>
#include "Menu.h"
#include "zoo.h"
#include "Input.h"
#include <string>
#include <Windows.h>
#include "Main_Menu.h"

using namespace std;

HANDLE main_menu_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

int main_menu()
{
	cursor_off_on(FALSE);
	string main_menu_buttons[] = { "������","� ���������","�����" };
	string about[] = { "��������� ���� ����������� ��� ������ � ����� ������ �������� � ������ �������� �������� �� ���������� '�������������� � ����������������'\n",
	"������ ��� ��������� �� ������ ����� �� ������ https://github.com/PridetheF1rst/AnP-3-Semestr-Zoo-13.git \n","\t\t\t\t������ 1.0"};
	start:
	switch (menu(main_menu_buttons, sizeof(main_menu_buttons), "����� ���������� � ��������� ������ � ��������� !\n================================================="))
	{
		
	case 0:
		return 0;
	case 1:
		system("cls");
		for (int i = 0; i < 3; i++)
		{
			goto_x_y(5+i*17, 15+i);
			cout << about[i];
		}
		cout << endl;
		goto_x_y(50, 19);
		system("pause");
		goto start;
	case 2:
		system("cls");
		SetConsoleTextAttribute(main_menu_Handle, (WORD)((Black << 4) | Yellow));
		cout << "�� ��������" << endl;
		system("pause");
		exit(0);
	}
}

void goto_x_y(short x, short y)
{
	SetConsoleCursorPosition(main_menu_Handle,{ x, y });
}