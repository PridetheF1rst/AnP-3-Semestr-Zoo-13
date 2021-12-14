#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "zoo.h"
#include "Queue.h"

HANDLE FileworksHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Чтение из файла*/
int read_file(string filename, zoo** beg, zoo** end)
{
	ifstream fin(filename, ios::in | ios::_Nocreate);
	if (!fin) { cout << "Файл " << filename << " не найден!" << endl; cin.get(); return 1; }//файл не найден
	zoo d;
	while (fin.getline(d.name, n_n))//пока в файле есть структуры
	{//считываем кличку
		fin.getline(d.specie, n_s);//считываем породу
		fin.getline(d.area, n_a);//считываем среду обитания
		fin.getline(d.p_type, n_p);//считываем тип продуктов
		fin.getline(d.date, n_d);//считываем дату
		fin >> d.cage;//считываем номер вольера
		fin >> d.p_weight;//считываем вес продуктов
		fin >> d.p_money;//считываем сумму потраченную на продукты
		fin.get();
		if (*beg == 0)//если список ещё не создан
		{
			*beg = add_first(d); *end = *beg;//создаём список
		}
		else//иначе
		{
			*end = add(*end, d);//добавляем к концу списка
		}
	}
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	cout << "Считана информация из файла " << filename << endl;
	return 0;
}

/*Запись в файл*/
int write_in_file(string filename, zoo* temp)
{
	ofstream fout(filename);
	if (!fout) { cout << "Не могу открыть файл для записи" << endl; return 1; }//если поток 
	//открыть невозможно - вывести сообщение об ошибке
	while (temp)//пока список не закончился
	{
		fout << temp->name << endl;//запись клички животного
		fout << temp->specie << endl;//запись вида животного
		fout << temp->area << endl;//запись ареала обитания
		fout << temp->p_type << endl;//запись типа продуктов
		fout << temp->date << endl;//запись даты
		fout << temp->cage << endl;//запись номера вольера
		fout << temp->p_weight << endl;//запись веса продуктов
		fout << temp->p_money << endl;//запись суммы денег потраченных на продукты
		temp = temp->next;//переход к следующей структуре
	}
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	cout << "Данные сохранены в файле: " << filename << endl;
	return 0;
}
