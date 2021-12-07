#include <iostream>
#include <Windows.h>
#include "zoo.h"
#include "Menu.h"
#include "Input.h"
#include "Output.h"


HANDLE ChangeHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*������� �������������*/
void change(zoo* beg, zoo* end, int id_num)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (beg != 0)
	{
		int number = 0;
		char templ_n[n_n], templ_s[n_s],
			templ_a[n_a], templ_p[n_p], data[n_d];
		float weight = 0, money = 0;
		strcpy(templ_n, "");
		strcpy(templ_s, "");
		strcpy(templ_a, "");
		strcpy(templ_p, "");
		strcpy(data, "");

		string change_menu[] = {

		"����� �������",
		"������ ���������",
		"������ ���������" ,
		"����� ��������" ,
		"��� ���������" ,
		"��� ��������� (� �����������)" ,
		"��������� ������������ ��������� (� ������)" ,
		"����"
		};

		zoo* temp = beg;
		while (temp)
		{
			if (temp->id == id_num)
			{
				switch (menu(change_menu, sizeof(change_menu), "��� �� ������ �������� ? "))
				{
					SetConsoleTextAttribute(ChangeHandle, (WORD)((Black << 4) | Yellow));
				case 0:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					number = inp_int(number, "������� ����� ������� :");
					temp->cage = number;
					system("cls");
					cout << "����� ������� ��� ������ �� " << temp->cage << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 1:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_n, "������� ������ ��������� :", n_n);
					strcpy(temp->name, templ_n);
					system("cls");
					cout << "������ ��������� ���� �������� �� " << temp->name << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 2:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_s, "������� ������ ��������� :", n_s);
					strcpy(temp->specie, templ_s);
					system("cls");
					cout << "������ ��������� ���� �������� �� " << temp->specie << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 3:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_a, "������� ����� �������� :", n_a);
					strcpy(temp->area, templ_a);
					system("cls");
					cout << "����� �������� ��� ������ �� " << temp->area << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 4:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_p, "������� ��� ��������� :", n_p);
					strcpy(temp->p_type, templ_p);
					system("cls");
					cout << "��� ��������� ��� ������ ��  " << temp->p_type << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 5:
					system("cls");
					cin.ignore();
					weight = inp_float(weight, "������� ��� ��������� (� �����������):");
					temp->p_weight = weight;
					system("cls");
					cout << "��� ������������ ��������� ��� ������ �� " << temp->p_weight << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 6:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					money = inp_float(money, "������� ��������� ������������ ��������� (� ������):");
					temp->p_money = money;
					system("cls");
					cout << "��������� ������������ ��������� ���� �������� �� " << temp->p_money << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 7:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_date(data);
					strcpy(temp->date, data);
					system("cls");
					cout << "���� ���� �������� �� " << temp->date << endl;
					cout << "����������������� ������� :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				}
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	else
	{
		cout << "���������� ������������ ������� ! ����������� �������� �������!" << endl;
	}
	cursor_off_on(FALSE);
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}