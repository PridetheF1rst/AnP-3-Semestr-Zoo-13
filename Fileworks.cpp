#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include "zoo.h"
#include "Queue.h"

HANDLE FileworksHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Чтение из файла*/
int read_file(string filename, zoo** beg, zoo** end)
{
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	string type = ".data";
	int count=0;
	if (filename.find(type) != std::string::npos) 
	{
		zoo temp;
		const char* file = filename.c_str();
		FILE* fin = fopen(file, "rb");
		if(!fin) { cout << "Файл " << filename << " не найден!" << endl; cin.get(); return 1; }
		else
		{
			while (fread(&temp.cage, sizeof(int), sizeof(temp.cage), fin))
			{
				fread(&temp.name, sizeof(char), n_n, fin);
				fread(&temp.specie, sizeof(char), n_s, fin);
				fread(&temp.area, sizeof(char), n_a, fin);
				fread(&temp.p_type, sizeof(char), n_p, fin);
				fread(&temp.date, sizeof(char), n_d, fin);
				fread(&temp.p_weight, sizeof(float), sizeof(temp.p_weight), fin);
				fread(&temp.p_money, sizeof(float), sizeof(temp.p_money), fin);
				if (*beg == 0)//если список ещё не создан
				{
					*beg = add_first(temp); *end = *beg;//создаём список
				}
				else//иначе
				{
					*end = add(*end, temp);//добавляем к концу списка
				}
				count++;
			}
		}
		fclose(fin);
	}
	else
	{
		ifstream fin(filename, ios::_Nocreate);
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
			count++;
		}
		fin.close();
	}
	cout << "Считана информация из файла " << filename << endl;
	cout << "Считано следущее количество записей :" << count << endl;
	return 0;
}

/*Запись в файл*/
int write_in_file(string filename, zoo* temp)
{
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	string type = ".data";
	if (filename.find(type) != std::string::npos)
	{
		const char* file = filename.c_str();
		FILE* fout = fopen(file, "wb");
		if (!fout) { cout << "Невозможно открыть файл " << filename << " для записи" << endl; return 1; }
		else
		{
			zoo* templ = temp;
			while (templ)
			{
				fwrite(&templ->cage, sizeof(int), sizeof(templ->cage), fout);
				fwrite(&templ->name, sizeof(char), n_n, fout);
				fwrite(&templ->specie, sizeof(char), n_s, fout);
				fwrite(&templ->area, sizeof(char), n_a, fout);
				fwrite(&templ->p_type, sizeof(char), n_p, fout);
				fwrite(&templ->date, sizeof(char), n_d, fout);
				fwrite(&templ->p_weight, sizeof(float), sizeof(templ->p_weight), fout);
				fwrite(&templ->p_money, sizeof(float), sizeof(templ->p_money), fout);
				templ = templ->next;
			}
		}
		fclose(fout);
	}
	else
	{
		ofstream fout(filename);
		if (!fout) { cout << "Невозможно открыть файл " << filename << " для записи" << endl; return 1; }//если поток 
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
		fout.close();
	}
	cout << "Данные сохранены в файле: " << filename << endl;
	return 0;
}
