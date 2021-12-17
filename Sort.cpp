#include <iostream>
#include <Windows.h>
#include "zoo.h"
#include "Menu.h"
#include "Sort.h"

HANDLE sortHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Функция сортировки , объединяющая остальные подфункции*/
void sort_by_field(zoo* beg,jmp_buf env)
{
	int how_sort;
	string _sort[] = { " По возрастанию " ," По убыванию " };
	string field[] = {
		" Номер вольера",
		"Кличку животного" ,
		"Породу" ,
		"Ареал обитания",
		"Тип продуктов" ,
		"Вес продуктов (в килограммах)" ,
		"Стоимоисть потребляемых продуктов (в рублях)" ,
		"Дату"
	};

	if (beg)
	{
		how_sort = menu_category(_sort, sizeof(_sort), "Какую сортировку вы хотите выбрать ?\n Вы можете нажать ESC для выхода в меню",env);
		SetConsoleTextAttribute(sortHandle, (WORD)((White << 4) | Blue));
		zoo* temp_1, temp_2;
		switch (menu(field, sizeof(field), "По какому параметру вы хотите отсортировать ? "))
		{
			SetConsoleTextAttribute(sortHandle, (WORD)((White << 4) | Blue));
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
		cout << "Сортировка была выполнена !" << endl;
	}
	else
	{
		cout << "Невозможно использовать функцию ! Отсутствуют элементы очереди!" << endl;
	}
}

/*Подфункции сортировки*/

/*Смена местами при сортировке*/
void sort_replace(zoo* left, zoo* right, zoo* temp)
{
	temp->cage = left->cage;              
	left->cage = right->cage;             
	right->cage = temp->cage;

	strcpy(temp->name, left->name);        
	strcpy(left->name, right->name);      
	strcpy(right->name, temp->name);

	strcpy(temp->specie, left->specie);              
	strcpy(left->specie, right->specie);             
	strcpy(right->specie, temp->specie);

	strcpy(temp->area, left->area);              
	strcpy(left->area, right->area);             
	strcpy(right->area, temp->area);

	strcpy(temp->p_type, left->p_type);            
	strcpy(left->p_type, right->p_type);         
	strcpy(right->p_type, temp->p_type);

	temp->p_weight = left->p_weight;    
	left->p_weight = right->p_weight;          
	right->p_weight = temp->p_weight;

	temp->p_money = left->p_money;       
	left->p_money = right->p_money;     
	right->p_money = temp->p_money;

	strcpy(temp->date, left->date);    
	strcpy(left->date, right->date);     
	strcpy(right->date, temp->date);
}

/*Сортировка по номеру вольера*/
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

/*Сортировка по кличке*/
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

/*Сортировка по породе*/
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

/*Сортировка по ареалу обитания*/
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

/*Сортировка по типу продуктов*/
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

/*Сортировка по весу продуктов*/
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

/*Сортировка по количеству затраченнных денег на продукты*/
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

/*Сортировка по дате*/
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