#include <iostream>
#include "Menu.h"
#include "zoo.h"
#include "Input.h"
#include <string>
#include <Windows.h>

using namespace std;

HANDLE main_menu_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

int main_menu()
{
	cursor_off_on(FALSE);
	string main_menu_buttons[] = { "������","� ���������","�����" };
	string about[] = { "��������� ���� ����������� ��� ������ � ����� ������ �������� � ������ �������� �������� �� ���������� '�������������� � ����������������'\n",
	"������ 1.0\n","������ ��� ��������� �� ������ ����� �� ������ https://github.com/PridetheF1rst/ZOO-AIP-3-Semestr.git"};
	start:
	switch (menu(main_menu_buttons, sizeof(main_menu_buttons), "����� ���������� � ��������� ������ � ��������� !\n================================================="))
	{
		
	case 0:
		return 0;
	case 1:
		system("cls");
		for (int i = 0; i < 3; i++) cout << about[i];
		cout << endl;
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