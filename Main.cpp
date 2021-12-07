/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			��������������� ��������������� �����������
				  ������� ��������������� ��������
			   ��������� ��� ������ � ����� ��������
														   ����� ���������
																����������
													������ ��. �C/�-20-1-�
															 �������� �.�.
								 2021
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
��������� �������� � ����� ������ ��������, ������� ����������� ��
���������� �����. ������ ������ ����� �������� ������ �� ����� ��������, ��� �������� ����������� ����� �������,������ (16 ��������),
������ ���������(21 ������) , ����� ��������(21 ������) ,��� ������������ ��������� (16 ��������) ,��� ������������ ��������� � ��������� �� ����� ����� ����������,
��������� ��������� ������������ ��������� � ��������� �� ������, ����(11 ��������)
�������� ������� ���������:
- ����� ���� �� �����;
- ���������� ������ � �������� � ����;
- ����������� ������ � �������� � ����;
- �������� ������ � �������� �� ����;
- ����� ������ � �������� � ����;
- ����� ������� � ��������, ���������� � �������� ������������� �������� ���.
������� ������� 13. ���������� 01.09.2021
����� ���������������� Microsoft Visual Studio 22 Preview version 17.1.0 Preview 1.1
���� ��������� ���������: 06.12.2021 .
������ 1.0
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <ctype.h>
#include "zoo.h"
#include "Change.h"
#include "Fileworks.h"
#include "Input.h"
#include "Menu.h"
#include "Output.h"
#include "Processing.h"
#include "Queue.h"
#include "Search.h"
#include "Sort.h"
#include "Main_Menu.h"

HANDLE mainHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*������� �������*/
int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow; // ������ ������ �������� ���������� ����������� ����
	maxWindow.X = 150;
	maxWindow.Y = 45;
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(out_handle, true, &minWindow);
	SetConsoleScreenBufferSize(out_handle, maxWindow);
	SetConsoleWindowInfo(out_handle, true, &srctWindow);
	system("title ������� ������ � ���������");

	main_menu();


	zoo* beg = 0,//������ �
		* end = 0;//����� ����� ����


	string filename = "";
	string hello[] = {
		"������������ ������������ ����", //0
		"������� ����� ������", //1
	},
	yes_no[] = {
	"��",
	"���"
	},
		type[] = {
		"txt",//0
		"data" //1
	},
		menuElems[] = {
		"�������� ������", //0
		"���������� ��������", //1
		"�������� �� ��������� ����", //2
		"�������������", //3
		"����������", //4
		"����� (�� �� ��������� ����)", //5
		"��������",//6
		"���������� � ����" ,//7
		"������ �� �����" ,//8
		"���������",//9
		"�����" ,//10
	},
	delete_e[] = {
	"������� ���� ������.",
	"������� ���������� �������."
	};
	cursor_off_on(FALSE);
	switch (menu(hello, sizeof(hello), "��� �������������� � ���������� ���������� ������������ ��� ������� ������.\n�������� ����� ����"))
	{
	case 0:
		cin.clear();
		system("cls");
		cursor_off_on(TRUE);
		filename = inp_filename(filename, "������� ��� ����� , ������� ������ �������(��� ����������)");
		cursor_off_on(FALSE);
		switch (menu(type, sizeof(type), "����� ���������� � ����� ?"))
		{
		case 0:
			filename += ".txt";
			break;
		case 1:
			filename += ".data";
			break;
		}
		SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
		read_file(filename, &beg, &end);
		system("pause");
		break;
	case 1:
		SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
		cout << "��� ������ ����� ������" << endl;
		beg = end = 0;
		system("pause");
		break;
	}


	do
	{
		start_menu:
		cursor_off_on(FALSE);
		switch (menu(menuElems, sizeof(menuElems), "������� ������ � ���������\n==================================\n����������� ��������� ��� �����������"))
		{

		case 0:
		{
			system("cls");
			if (beg != 0)
			{
				switch (menu(yes_no, sizeof(yes_no), "��� �������� ������ ������ ��������� ������� ������ . �� ������ ��������� ������ ������ ?"))
				{
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
				case 0:
					cursor_off_on(TRUE);
					cin.ignore();
					filename = inp_filename(filename, "������� ��� ����� , ������� ������ ���������(��� ����������)");
					cursor_off_on(FALSE);
					switch (menu(type, sizeof(type), "� ����� ���������� �� ������ ��������� ���� ?"))
					{
					case 0:
						filename += ".txt";
						break;
					case 1:
						filename += ".data";
						break;
					}
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
					write_in_file(filename, beg);
					cin.get();
					dellete_all(beg);
					beg = end = 0;
					break;
				case 1:
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
					dellete_all(beg);
					beg = end = 0;
					break;
				}
			}
			else
			{
				beg = end = 0;
			}
			cout << "��� ������ ����� ������" << endl;
			system("pause");
			break;
		}
		case 1:
		{

			system("cls");
			cursor_off_on(TRUE);
			if (beg) { end = add(end, input()); }//���� ���������� ���� �� ���� �������- ��������� �����
			else
			{
				beg = add_first(input());//���� �� ���������� �� ������ �������� - ������ ������
				end = beg;//������������ ����� � ������
			}
			system("cls");
			cursor_off_on(FALSE);
			cout << "�� ������� ��������� ������� : " << endl;
			header();
			print_on_the_screen(*end);
			cout << endl;
			system("pause");
			break;
			cin.clear();
		}
		case 2:
		{
			system("cls");
			if (!beg) { cout << "���������� ��������� �������� ! ������� �����!" << endl; }
			else
			{
				switch (menu(delete_e, sizeof(delete_e), "�� ������ ������� ���� ������ ��� ���������� ������� ?"))
				{
					case 0:
						{
					system("cls");
					switch (menu(yes_no, sizeof(yes_no), "�� ������������� ������ ������� ��� �������� ?"))
					{
					case 0:

						dellete_all(beg);
						SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
						cout << "��� �������� ���� �������" << endl;
						cin.ignore();
						cin.get();
						beg = end = 0;
						break;
					case 1:
						break;
					}
					break;
					}
					case 1:
						{
						cursor_off_on(TRUE);
						system("cls");

						SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
						int num = 0;
						cin.clear();
						num = inp_int(num, "������� ID ��������");
						cursor_off_on(FALSE);
						if (num<1 || num>end->id)
						{
							cout << "���������� ��������� ��������!" << endl;
							cout << "�������� ID �� ��������� � ��������� �� " << beg->id << " �� " << end->id << endl;
							break;
						}
						else
						{
							cout << "��������� ���� ������� :" << endl;
							search_id(beg, num);
							system("cls");
							switch (menu(yes_no, sizeof(yes_no), "�� ������������� ������ ������� ���� ������� ?"))
							{
							case 0:
								if (num == beg->id) { beg = dellete_id_beg(beg); }
								else
								{
									if (num == end->id) { end = dellete_id_end(beg, end); }
									else { dellete_id(beg, end, num); }
								}
								break;
							case 1:
								break;
							}
						}

						cursor_off_on(FALSE);
						break;
					}
				}
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (beg)
			{
				int num = 0;
				cursor_off_on(TRUE);
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
				num = inp_int(num, "������� ID ��������");
				cursor_off_on(FALSE);
				if (num<1 || num>end->id)
				{
					cout << "���������� ��������� ���������!" << endl;
					cout << "�������� ID �� ��������� � ��������� �� " << beg->id << " �� " << end->id << endl;
				}
				else change(beg, end, num);
			}
			else { cout << "���������� ��������� �������� ! ������� �����!" << endl; }
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			sort_by_field(beg);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			search(beg);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			see_the_information(beg);
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			cursor_off_on(TRUE);
			if (beg) { cin.ignore(); }
			filename = inp_filename(filename, "������� ��� ����� , ������� ������ ���������(��� ����������)");
			cursor_off_on(FALSE);
			switch (menu(type, sizeof(type), "� ����� ���������� �� ������ ��������� ���� ?"))
			{
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			case 0:
				filename += ".txt";
				break;
			case 1:
				filename += ".data";
				break;
			}
			write_in_file(filename, beg);
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			cursor_off_on(TRUE);
			if (beg) { cin.ignore(); }
			filename = inp_filename(filename, "������� ��� ����� , ������� ������ �������(��� ����������)");
			cursor_off_on(FALSE);
			switch (menu(type, sizeof(type), "� ����� ���������� �� ������ ������� ���� ?"))
			{
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			case 0:
				filename += ".txt";
				break;
			case 1:
				filename += ".data";
				break;
			}
			read_file(filename, &beg, &end);
			system("pause");
			break;
		}
		case 9:
		{
			SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			system("cls");
			processing(beg);
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			switch (menu(yes_no, sizeof(yes_no), "�� ������ ���� ����� ������� ?"))
			{
			case 0:
				cursor_off_on(TRUE);
				if (beg) { cin.ignore(); }
				filename = inp_filename(filename, "������� ��� ����� , ������� ������ ���������(��� ����������)");
				cursor_off_on(FALSE);
				switch (menu(type, sizeof(type), "� ����� ���������� �� ������ ��������� ���� ?"))
				{
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
				case 0:
					filename += ".txt";
					break;
				case 1:
					filename += ".data";
					break;
				}
				write_in_file(filename, beg);
				system("pause");
				break;
			case 1:
				break;
			}
			SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			cout << "�� ��������" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		}
	} while (1);
}
