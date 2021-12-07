#include <iostream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
#include "zoo.h"
#include "Queue.h"
#include "Input.h"
#include "Output.h"
#include "Menu.h"
#include "Search.h"

HANDLE SearchHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Функция поиска , объединяющая остальные подфункции*/
void search(zoo* beg)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (beg)
	{
		int number = 0;
		char name[n_n], specie[n_s],
			area[n_a], p_type[n_p], data[n_d];
		float weight = 0, money = 0;
		strcpy(name, "");
		strcpy(specie, "");
		strcpy(area, "");
		strcpy(p_type, "");
		strcpy(data, "");

		string how_searh[] = {
			"Номер вольера",
			"Кличка животного",
			"Порода животного",
			"Ареал обитания",
			"Тип продуктов",
			"Вес продуктов (в килограммах)",
			"Стоимоисть потребляемых продуктов (в рублях)",
			"Дату"
		};

		switch (menu(how_searh, sizeof(how_searh), "По какому параметру вы хотите найти ? "))
		{
			SetConsoleTextAttribute(SearchHandle, (WORD)((Black << 4) | Yellow));
		case 0:
			system("cls");
			cursor_off_on(TRUE);
			number = inp_int(number, "Введите номер вольера :");
			search_cage(beg, number);
			break;
		case 1:
			system("cls");
			cursor_off_on(TRUE);
			inp_char(name, "Введите кличку животного :", n_n);
			search_name(beg, name);
			break;
		case 2:
			system("cls");
			cursor_off_on(TRUE);
			inp_char(specie, "Введите породу животного :", n_s);
			search_specie(beg, specie);
			break;
		case 3:
			system("cls");
			cursor_off_on(TRUE);
			inp_char(area, "Введите ареал обитания :", n_a);
			search_area(beg, area);
			break;
		case 4:
			system("cls");
			cursor_off_on(TRUE);
			inp_char(p_type, "Введите тип продуктов :", n_p);
			search_p_type(beg, p_type);
			break;
		case 5:
			system("cls");
			cursor_off_on(TRUE);
			weight = inp_float(weight, "Введите вес продуктов (в килограммах):");
			search_p_weight(beg, weight);
			break;
		case 6:
			system("cls");
			cursor_off_on(TRUE);
			money = inp_float(money, "Введите стоимость потребляемых продуктов (в рублях):");
			search_p_money(beg, money);
			break;
		case 7:
			system("cls");
			cursor_off_on(TRUE);
			inp_date(data);
			search_date(beg, data);
			break;
		}
	}
	else
	{
		cout << "Невозможно использовать функцию ! Отсутствуют элементы очереди!" << endl;
	}
	cursor_off_on(FALSE);
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}

/*Подфункции поиска*/

/*Поиск по номеру вольера*/
void search_cage(zoo* beg, int num_cage)
{
	int count = 0;
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (temp->cage == num_cage)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << num_cage << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << num_cage << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по кличке*/
void search_name(zoo* beg, char* pet_name)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (strcmp(temp->name, pet_name) == 0)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << pet_name << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << pet_name << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по породе*/
void search_specie(zoo* beg, char* pet_specie)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (strcmp(temp->specie, pet_specie) == 0)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << pet_specie << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << pet_specie << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по ареалу обитания*/
void search_area(zoo* beg, char* pet_area)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (strcmp(temp->area, pet_area) == 0)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << pet_area << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << pet_area << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по типу продуктов*/
void search_p_type(zoo* beg, char* p_type)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (strcmp(temp->p_type, p_type) == 0)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << p_type << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << p_type << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по весу*/
void search_p_weight(zoo* beg, float p_weight)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (temp->p_weight == p_weight)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << p_weight << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << p_weight << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по сумме*/
void search_p_money(zoo* beg, float sum_money)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (temp->p_money == sum_money)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << sum_money << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << sum_money << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

/*Поиск по дате*/
void search_date(zoo* beg, char* data)
{
	int count = 0;
	system("cls");
	zoo* temp = beg, * beg_s = nullptr, * end_s = nullptr;
	while (temp)
	{
		if (strcmp(temp->date, data) == 0)
		{
			if (!beg_s)
			{
				beg_s = add_first(*temp);
				beg_s->id = temp->id;
				end_s = beg_s;
			}
			else { end_s = add(end_s, *temp); end_s->id = temp->id; }
		}
		temp = temp->next;
	}
	if (!beg_s) { cout << "Информация , соответвующая запросу отсутствует !" << endl; }
	else
	{
		cout << "Информация , соответвующая запросу (" << data << "):" << endl;
		header();
		temp = beg_s;
		while (temp)
		{
			if (count != 1 && (count % print) == 1)
			{
				cout << endl;
				system("pause");
				system("cls");
				cout << "Информация , соответвующая запросу (" << data << "):" << endl;
				header();
				print_on_the_screen(*temp);
				count++;
			}
			else
			{
				count++;
				print_on_the_screen(*temp);
			}
			temp = temp->next;
		}
	}
	cout << endl;
}

void search_id(zoo* beg, int id)
{
	zoo* temp = beg;
	while (temp)
	{
		if (temp->id == id) { header(); print_on_the_screen(*temp); cout << endl; system("pause"); break; }
		else temp = temp->next;
	}
}