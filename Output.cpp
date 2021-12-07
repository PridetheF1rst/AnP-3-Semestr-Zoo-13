#include <iostream>
#include <conio.h>
#include "zoo.h"
#include "Processing.h"
#include "Output.h"

/*�������� ������*/
void see_the_information(zoo* beg)
{
	if (!beg) { cout << "���������� ����������� !" << endl;  return; }
	else
	{
		int key;
		zoo* temp = beg;//��������� �� ������ ������
		start:
		cout << "������ �������� ��������:" << endl;
		header();
		while (temp)//���� ������ �� ��������
		{
			print_on_the_screen(*temp);
			if (temp->next && temp->next->id % print == 1)//���� �������� ������� - 14 , 
			{
				cout << endl;
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
						while (i < print)
						{
							temp = temp->prev;
							i++;
						}
					}
					else temp = beg;
					break;
				}
				default:
					break;
				}
				system("cls");
				cout << "������ �������� ��������:" << endl;
				header();
			}
			else temp = temp->next;
		}
		cout << endl;
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