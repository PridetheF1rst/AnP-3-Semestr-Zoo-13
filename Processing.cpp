#include <iostream>
#include <fstream>
#include <Windows.h>
#include "zoo.h"
#include "Input.h"
#include "Queue.h"
#include "Processing.h"
#include "Output.h"
#include "Menu.h"

HANDLE ProcessingHandle = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

/*Подсчёт сумму и вес употреблённых продуктов всеми видами пород животных (за указанный период)*/
void processing(zoo* beg)
{
	zoo* temp = beg;
	zoo* beg_p = nullptr, * end_p = nullptr;
	char time1[n_d] = "", time2[n_d] = "";
	string filename_processing;
	system("cls");
	cursor_off_on(TRUE);
	cin.ignore();
	cout << "Введите дату начала" << endl;
	inp_date(time1);
	cout << "Введите дату окончания" << endl;
	inp_date(time2);
	while (strcmp(time1, time2) > 0)
	{
		system("cls");
		cout << "Неверно введена дата! Дата окончания не может быть раньше даты начала !" << endl;
		cout << "Введите дату начала" << endl;
		inp_date(time1);
		cout << "Введите дату окончания" << endl;
		inp_date(time2);
	}
	system("cls");
	cursor_off_on(FALSE);
	cout << "Дата начала :";
	printf(time1, n_d);
	cout << endl << "Дата окончания :";
	printf(time2, n_d);
	cout << endl;
	while (temp)
	{
		if (((strcmp(temp->date, time1) > 0) || strcmp(temp->date, time1) == 0) && ((strcmp(temp->date, time2) < 0) || strcmp(temp->date, time2) == 0))
		{
			if (!beg_p)
			{
				beg_p = add_first(*temp);
				end_p = beg_p;
			}
			else
			{
				int c = 0;
				zoo* temp1 = beg_p;

				while (temp1)
				{
					if (strcmp(temp->specie, temp1->specie) == 0)
					{
						temp1->p_money += temp->p_money;
						temp1->p_weight += temp->p_weight;
						c = 1;
						break;
					}
					temp1 = temp1->next;
				}
				if (c == 0)
				{
					end_p = add(end_p, *temp);
				}
			}
		}
		temp = temp->next;
	}
	if (beg_p)
	{
		show_processing(beg_p);
		cursor_off_on(TRUE);
		filename_processing = inp_filename(filename_processing, "Введите имя файла , который хотите сохранить(без расширения)");
		cursor_off_on(FALSE);
		string type[] = {
			"txt",//0
			"data" //1
		};
		switch (menu(type, sizeof(type), "В каком расширении вы хотите сохранить файл ?"))
		{
		case 0:
			filename_processing += ".txt";
			break;
		case 1:
			filename_processing += ".data";
			break;
		}
		SetConsoleTextAttribute(ProcessingHandle, (WORD)((Black << 4) | Yellow));
		processing_write_in_file(filename_processing, beg_p);
	}
	else cout << "Не найдены элементы списка , которые могут соответствовать указанному периоду!" << endl;
}
/*Подсчёт всей суммы денег для обработки*/
float count_money(zoo* beg_p)
{
	zoo* temp = beg_p;
	float count = 0;
	while (temp)
	{
		count += temp->p_money;
		temp = temp->next;
	}
	return count;
}

/*Подсчёт всего веса для обработки*/
float count_weight(zoo* beg_p)
{
	zoo* temp = beg_p;
	float count = 0;
	while (temp)
	{
		count += temp->p_weight;
		temp = temp->next;
	}
	return count;
}

/*Запись данных обработки в файл*/
int processing_write_in_file(string filename, zoo* temp)
{
	float money = 0, weight = 0;
	ofstream fout(filename);
	if (!fout) { cout << "Не могу открыть файл для записи" << endl; return 1; }//если поток 
	//открыть невозможно - вывести сообщение об ошибке
	while (temp)//пока список не закончился
	{
		fout << temp->specie << endl;//запись вида животного
		fout << temp->date << endl;//запись даты
		fout << temp->p_weight << endl;//запись веса продуктов
		weight += temp->p_weight;//подсчёт всей массы
		fout << temp->p_money << endl;//запись суммы денег потраченных на продукты
		money += temp->p_money;//подсчёт всей суммы денег
		temp = temp->next;//переход к следующей структуре
	}
	fout << endl;
	fout << weight << endl;//запись всей массы
	fout << money << endl;//запись всей суммы денег
	cout << "Результаты обработки сохранены в файле: " << filename << endl;
	return 0;
}
