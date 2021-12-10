#include <iostream>
#include <conio.h>
#include "zoo.h"
#include "Processing.h"
#include "Output.h"

/*�������� ������*/
void see_the_information(zoo* beg,zoo* end)
{
	if (!beg) { cout << "���������� ����������� !" << endl;  return; }
	else
	{
		int key;
		bool go = false;
		int page,count=0;
		float page_end;
		if (end->id % print == 0) page_end = end->id / print;
		else page_end = (end->id / print) + 1;
		zoo* temp = beg;//��������� �� ������ ������
		cout << "������ �������� ��������:" << endl;
		header();
		while (!go)//���� ������ �� ��������
		{
			if (temp->next == nullptr)
			{
				if (count == 0)cout << endl << "��� �������� �� ���������� �������� ������� <-\t\t\t" << "�������� ����� " << page_end << " �� " << page_end << "\t\t\t\t\t  ��� ������ ������� Esc " << endl;
				count++;
				key = _getch();
				switch (key)
				{
				case Left:
				{
					count = 0;
					int i = 0;
					while (temp->prev->id % 13 != 0)
					{
						temp = temp->prev;
						i++;
					}
					i = 0;
					while (i < 12)
					{
						temp = temp->prev;
						i++;
					}
					system("cls");
					cout << "������ �������� ��������:" << endl;
					header();
					break;
				}
				case Esc:
					goto end;
				default:
					cin.ignore();
					break;
				}
			}
			else
			{
				print_on_the_screen(*temp);
				if (temp->next && temp->next->id % print == 1)//���� �������� ������� - 14 , 
				{
					page = temp->id / print;
					if (page == page_end ) go = true;
					else
					{
						if (page == 1) cout << endl << "\t\t\t\t\t\t\t" << "�������� ����� " << page << " �� " << page_end << "\t\t\t��� �������� �� ��������� �������� ������� ->" << endl;
						else cout << endl << "��� �������� �� ���������� �������� ������� <-\t\t\t" << "�������� ����� " << page << " �� " << page_end << "\t\t\t��� �������� �� ��������� �������� ������� ->" << endl;
						cout << endl << "\t\t\t\t\t\t\t��� ������ ������� Esc " << endl;

					}
					key = _getch();
					switch (key)
					{
					case  Right:
					{
						if (temp->next != nullptr)
						{
							temp = temp->next;
						}
						else system("pause"); break;
					}
					case Left:
					{
						if (temp->id != 13)
						{
							int i = 0;
							while (i < 2 * print - 1)
							{
								temp = temp->prev;
								i++;
							}
						}
						else temp = beg;
						break;
					}
					case Esc:
						goto end;
					default:
						break;
					}
					system("cls");
					cout << "������ �������� ��������:" << endl;
					header();
				}
				else temp = temp->next;
			}
		}
		cout << endl;
	end:
		return;
	}
}

/*��������� ��� ������*/
void header()
{
	for (int i = 0; i < 148; i++) cout << "=";
	printf("\n|%-3s|", "ID");
	printf("%-12s|", "����� ");
	printf("%-15s|", "������");
	printf("%-20s|", "������");
	printf("%-20s|", "����� ");
	printf("%-15s|", "��� ");
	printf("%-18s|", "���");
	printf("%-18s|", "��������� ");
	printf("%-17s|", "����");
	printf("\n|%-3s|", "");
	printf("%-12s|", "�������");
	printf("%-15s|", "���������");
	printf("%-20s|", "���������");
	printf("%-20s|", "��������");
	printf("%-15s|", "���������");
	printf("%-18s|", "���������");
	printf("%-18s|", "���������");
	printf("%-17s|\n", "(����.��.��)");
	for (int i = 0; i < 148; i++) cout << "=";
}

/*����� �������� �� �����*/
void print_on_the_screen(const zoo& z)
{
	printf("\n|%-3d|", z.id);
	printf("%-12d|", z.cage);
	printf("%-15s|", z.name);
	printf("%-20s|", z.specie);
	printf("%-20s|", z.area);
	printf("%-15s|", z.p_type);
	printf("%-18.2f|", z.p_weight);
	printf("%-18.2f|", z.p_money);
	printf("%-17s|\n", z.date);
	for (int i = 0; i < 148; i++) cout << "=";
}

/*��������� ��� ���������*/
void header_proccessing()
{
	for (int i = 0; i < 79; i++) cout << "=";
	printf("\n|%-30s|", "������ ���������");
	printf("%-20s|", "��� ���������");
	printf("%-25s|\n", "��������� ���������");
	for (int i = 0; i < 79; i++) cout << "=";
}

/*����� �������� ��������� �� �����*/
void print_processing(const zoo& z)
{
	printf("\n|%-30s|", z.specie);
	printf("%-20.2f|", z.p_weight);
	printf("%-25.2f|\n", z.p_money);
	for (int i = 0; i < 79; i++) cout << "=";
}

/*����� ������ ��������� ���������*/
void show_processing(zoo* beg)
{
	zoo* temp = beg;//��������� �� ������ ������
	cout << "����� � ��� ������������ ��������� ����� ������ ����� ��������(�� ��������� ������) :" << endl;
	header_proccessing();
	while (temp)//���� ������ �� ��������
	{
		print_processing(*temp);
		if (temp->next && temp->next->id % print == 1)//���� �������� ������� - 13 , 
		{
			cout << endl;
			system("pause");
			system("cls");
			cout << "����� � ��� ������������ ��������� ����� ������ ����� ��������(�� ��������� ������) :" << endl;
			header_proccessing();
		}
		temp = temp->next;//������� � ��������� ���������
	}
	cout << endl;
	printf("%-31s|", " ");
	printf("%-20s|", "��������� ���");
	printf("%-25s|\n", "��������� ���������");
	printf("%31s", " ");
	for (int i = 0; i < 48; i++) cout << "=";
	printf("\n%-31s|", " ");
	printf("%-20.2f|", count_weight(beg));
	printf("%-25.2f|\n", count_money(beg));
	printf("%31s", " ");
	for (int i = 0; i < 48; i++) cout << "=";
	cout << endl;
}