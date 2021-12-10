#include <iostream>
#include <Windows.h>
#include "zoo.h"
#include "Menu.h"
#include "Sort.h"

HANDLE sortHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*������� ���������� , ������������ ��������� ����������*/
void sort_by_field(zoo* beg,jmp_buf env)
{
	int how_sort;
	string _sort[] = { " �� ����������� " ," �� �������� " };
	string field[] = {
		" ����� �������",
		"������ ���������" ,
		"������" ,
		"����� ��������",
		"��� ���������" ,
		"��� ��������� (� �����������)" ,
		"���������� ������������ ��������� (� ������)" ,
		"����"
	};

	if (beg)
	{
		how_sort = menu_category(_sort, sizeof(_sort), "����� ���������� �� ������ ������� ?\n �� ������ ������ ESC ��� ������ � ����",env);
		SetConsoleTextAttribute(sortHandle, (WORD)((Black << 4) | Yellow));
		zoo* temp_1, temp_2;
		switch (menu(field, sizeof(field), "�� ������ ��������� �� ������ ������������� ? "))
		{
			SetConsoleTextAttribute(sortHandle, (WORD)((Black << 4) | Yellow));
		case 0:
			system("cls");
			sort_cage(beg, how_sort);
			break;
		case 1:
			system("cls");
			sort_name(beg, how_sort);
			break;
		case 2:
			system("cls");
			sort_specie(beg, how_sort);
			break;
		case 3:
			system("cls");
			sort_area(beg, how_sort);
			break;
		case 4:
			system("cls");
			sort_p_type(beg, how_sort);
			break;
		case 5:
			system("cls");
			sort_p_weight(beg, how_sort);
			break;
		case 6:
			system("cls");
			sort_p_money(beg, how_sort);
			break;
		case 7:
			system("cls");
			sort_date(beg, how_sort);
			break;
		}
		cout << "���������� ���� ��������� !" << endl;
	}
	else
	{
		cout << "���������� ������������ ������� ! ����������� �������� �������!" << endl;
	}
}

/*���������� ����������*/

/*����� ������� ��� ����������*/
void sort_replace(zoo* left, zoo* right, zoo* temp)
{
	temp->cage = left->cage;              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	left->cage = right->cage;             //������ � ��� ������� ������ x, ������� ������ ���
	right->cage = temp->cage;
	//����� ��  ����� ���� ��� ����������� ��� ������� ������������ ��������
	strcpy(temp->name, left->name);              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	strcpy(left->name, right->name);             //������ � ��� ������� ������ x, ������� ������ ���
	strcpy(right->name, temp->name);

	strcpy(temp->specie, left->specie);              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	strcpy(left->specie, right->specie);             //������ � ��� ������� ������ x, ������� ������ ���
	strcpy(right->specie, temp->specie);

	strcpy(temp->area, left->area);              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	strcpy(left->area, right->area);             //������ � ��� ������� ������ x, ������� ������ ���
	strcpy(right->area, temp->area);

	strcpy(temp->p_type, left->p_type);              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	strcpy(left->p_type, right->p_type);             //������ � ��� ������� ������ x, ������� ������ ���
	strcpy(right->p_type, temp->p_type);

	temp->p_weight = left->p_weight;              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	left->p_weight = right->p_weight;             //������ � ��� ������� ������ x, ������� ������ ���
	right->p_weight = temp->p_weight;

	temp->p_money = left->p_money;              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	left->p_money = right->p_money;             //������ � ��� ������� ������ x, ������� ������ ���
	right->p_money = temp->p_money;

	strcpy(temp->date, left->date);              //� ������������ ��� ���������� ��������, �� ����������� ���������� �����, �������
	strcpy(left->date, right->date);             //������ � ��� ������� ������ x, ������� ������ ���
	strcpy(right->date, temp->date);
}

/*���������� �� ������ �������*/
void sort_cage(zoo* beg, int how_sort)
{
	zoo* left = beg,* right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((left->cage) > (right->cage))
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((left->cage) < (right->cage))
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ������*/
void sort_name(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((strcmp(left->name, right->name)) > 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((strcmp(left->name, right->name)) < 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ������*/
void sort_specie(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((strcmp(left->specie, right->specie)) > 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((strcmp(left->specie, right->specie)) < 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ������ ��������*/
void sort_area(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((strcmp(left->area, right->area)) > 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((strcmp(left->area, right->area)) < 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ���� ���������*/
void sort_p_type(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((strcmp(left->p_type, right->p_type)) > 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((strcmp(left->p_type, right->p_type)) < 0)
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ���� ���������*/
void sort_p_weight(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:

				if ((left->p_weight) > (right->p_weight))
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((left->p_weight) < (right->p_weight))
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ���������� ������������ ����� �� ��������*/
void sort_p_money(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:

				if ((left->p_money) > (right->p_money))
				{
					sort_replace(left, right, temp);
				}
				break;
			case 1:
				if ((left->p_money) < (right->p_money))
				{
					sort_replace(left, right, temp);
				}
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

/*���������� �� ����*/
void sort_date(zoo* beg, int how_sort)
{
	zoo* left = beg, * right = beg->next, * temp = new zoo;

	while (left->next)
	{
		while (right)
		{
			switch (how_sort)
			{
			case 0:
				if ((strcmp(left->date, right->date)) > 0) { sort_replace(left, right, temp); }
				break;
			case 1:
				if ((strcmp(left->date, right->date)) < 0) { sort_replace(left, right, temp); }
				break;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}