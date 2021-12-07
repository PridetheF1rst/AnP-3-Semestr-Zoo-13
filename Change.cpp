#include <iostream>
#include <Windows.h>
#include "zoo.h"
#include "Menu.h"
#include "Input.h"
#include "Output.h"


HANDLE ChangeHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Функция корректировки*/
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

		"Номер вольера",
		"Кличка животного",
		"Порода животного" ,
		"Ареал обитания" ,
		"Тип продуктов" ,
		"Вес продуктов (в килограммах)" ,
		"Стоимость потребляемых продуктов (в рублях)" ,
		"Дату"
		};

		zoo* temp = beg;
		while (temp)
		{
			if (temp->id == id_num)
			{
				switch (menu(change_menu, sizeof(change_menu), "Что вы хотите поменять ? "))
				{
					SetConsoleTextAttribute(ChangeHandle, (WORD)((Black << 4) | Yellow));
				case 0:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					number = inp_int(number, "Введите номер вольера :");
					temp->cage = number;
					system("cls");
					cout << "Номер вольера был изменён на " << temp->cage << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 1:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_n, "Введите кличку животного :", n_n);
					strcpy(temp->name, templ_n);
					system("cls");
					cout << "Кличка животного была изменена на " << temp->name << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 2:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_s, "Введите породу животного :", n_s);
					strcpy(temp->specie, templ_s);
					system("cls");
					cout << "Порода животного была изменена на " << temp->specie << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 3:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_a, "Введите ареал обитания :", n_a);
					strcpy(temp->area, templ_a);
					system("cls");
					cout << "Ареал обитания был изменён на " << temp->area << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 4:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					inp_char(templ_p, "Введите тип продуктов :", n_p);
					strcpy(temp->p_type, templ_p);
					system("cls");
					cout << "Тип продуктов был изменён на  " << temp->p_type << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 5:
					system("cls");
					cin.ignore();
					weight = inp_float(weight, "Введите вес продуктов (в килограммах):");
					temp->p_weight = weight;
					system("cls");
					cout << "Вес потребляемых продуктов был изменён на " << temp->p_weight << endl;
					cout << "Отредактированный элемент :" << endl;
					header();
					print_on_the_screen(*temp);
					break;
				case 6:
					system("cls");
					cin.ignore();
					cursor_off_on(TRUE);
					money = inp_float(money, "Введите стоимость потребляемых продуктов (в рублях):");
					temp->p_money = money;
					system("cls");
					cout << "Стоимость потребляемых продуктов была изменена на " << temp->p_money << endl;
					cout << "Отредактированный элемент :" << endl;
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
					cout << "Дата была изменена на " << temp->date << endl;
					cout << "Отредактированный элемент :" << endl;
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
		cout << "Невозможно использовать функцию ! Отсутствуют элементы очереди!" << endl;
	}
	cursor_off_on(FALSE);
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}