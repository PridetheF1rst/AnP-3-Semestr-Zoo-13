#include <iostream>
#include <string>
#include <Windows.h>
#include "zoo.h"
#include "Input.h"

HANDLE InputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Ввод информации*/
zoo input()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	zoo z;
	z.cage = 0;
	strcpy(z.name, "");
	strcpy(z.specie, "");
	strcpy(z.area, "");
	strcpy(z.p_type, "");
	z.p_weight = 0;
	z.p_money = 0;
	strcpy(z.date, "");

	z.cage = inp_int(z.cage, "Введите номер вольера :");
	cin.ignore();
	inp_char(z.name, "Введите кличку животного :", n_n);
	inp_char(z.specie, "Введите породу животного :", n_s);
	inp_char(z.area, "Введите ареал обитания :", n_a);
	inp_char(z.p_type, "Введите тип продуктов :", n_p);
	z.p_weight = inp_float(z.p_weight, "Введите вес продуктов (в килограммах):");
	cin.ignore();
	z.p_money = inp_float(z.p_money, "Введите стоимость потребляемых продуктов (в рублях):");
	cin.ignore();
	inp_date(z.date);

	cin.clear();
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	return z;
}

/*Проверка ввода перменных типа int*/
int inp_int(int n, const char* inf)
{
	bool int_ = true;
	system("cls");
	cout << inf << endl;
	cin >> noskipws >> n;
	do
	{
		if (!cin ||n<0)
		{
			int_ = false;
			system("cls");
			cin.clear();
			cin.get();
			cout << "Похоже вы неправильно ввели информацию. Повторите попытку." << endl;
			cout << inf << endl;
			cin >> noskipws >> n;
		}
		else int_ = true;
	} while (!int_);
	return n;
}

/*Проверка ввода переменных типа char*/
char* inp_char(char* temp, const char* inf, int size)
{
	cout << inf << endl;
	cin.getline(temp,size);
	temp=delete_space(temp, size);
	while (strcmp(temp, "") == 0 || strcmp(temp, "\0") == 0||!check_char(temp))
	{
		cout << "Похоже вы неправильно ввели информацию. Повторите попытку." << endl;
		cout << inf << endl;
		cin.getline(temp, size);
	}
	return temp;
}

bool check_char(char* temp)
{ 
	int i = 0,count=0;
	while (temp[i])
	{
		if(isdigit(temp[i])||ispunct(temp[i]))count++;
		i++;
	}
	if (count == 0)return true;
	else return false;
}

char* delete_space(char* temp, int size)
{
	int i = 0;
	while (temp[i])
	{
		if (isspace(temp[0]))
			for (i = 0; i < sizeof(temp); i++)
			{
				temp[i] = temp[i + 1];
			}
		i++;
	}
	return temp;
}

/*Проверка ввода имени файла*/
string inp_filename(string temp, const char* inf)
{
	cin.clear();
	cout << inf << endl;
	cin >> noskipws >> temp;
	while (temp.empty())
	{
		cin.clear();
		cin.get();
		cout << "Похоже вы неправильно ввели имя файла. Повторите попытку." << endl;
		cout << inf << endl;
		cin >> noskipws >> temp;
	}
	return temp;
}

/*Проверка ввода переменных типа float*/
float inp_float(float temp, const char* inf)
{
	bool float_ = true;
	cin.clear();
	cout << inf << endl;
	cin >> noskipws >> temp;
	do
	{
		if (!cin ||temp<0)
		{
			float_ = false;
			cin.clear();
			cin.ignore();
			cin.get();
			cout << "Похоже вы неправильно ввели информацию. Повторите попытку." << endl;
			cout << inf << endl;
			cin >> noskipws >> temp;
		}
		else float_ = true;
	} while (!float_);
	return temp;
}

/*Проверка ввода даты*/
char* inp_date(char* date)
{
	cout << "Введите дату :" << endl;
	cout << "ГГГГ.ММ.ДД" << endl;
	cin.getline(date, n_d);
	while (strcmp(date, "") == 0 || strcmp(date, "\0") == 0 || !check_date(date))
	{
		cout << "Похоже вы неправильно ввели информацию. Повторите попытку." << endl;
		cout << "Введите дату :" << endl;
		cout << "ГГГГ.ММ.ДД" << endl;
		cin.getline(date, n_d);
	}
	return date;
}

/*Проверка правильности даты*/
bool check_date(char* date)
{
	int year = 0, month = 0, day = 0, count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (isdigit(date[i])) count++;
	}

	if (count != 4) return false;
	count = 0;

	for (int i = 0; i < 3; i++)
	{
		if (isdigit(date[i + 5])) count++;
	}

	if (count < 1 || count > 2) return false;
	count = 0;

	for (int i = 0; i < 2; i++)
	{
		if (isdigit(date[i + 8])) count++;
	}

	if (count < 1 || count >2) return false;

	year += atoi(&date[0]);
	month += atoi(&date[5]);
	day += atoi(&date[8]);

	if (year < 1900 || year>2021) return false;

	if (month < 1 || month>12) return false;

	switch (month)
	{
	case 1:
		if (day < 1 || day>31)	return false;
		break;
	case 2:
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				if (day < 1 || day>29)	return false;
			}
			else { if (day < 1 || day>28) return false; }
		}
		else
		{
			if (year % 4 == 0) { if (day < 1 || day>29)	return false; }
			else { if (day < 1 || day>28)	return false; }
		}
		break;
	case 3:
		if (day < 1 || day>31)	return false;
		break;
	case 4:
		if (day < 1 || day>30)	return false;
		break;
	case 5:
		if (day < 1 || day>31)	return false;
		break;
	case 6:
		if (day < 1 || day>30)	return false;
		break;
	case 7:
		if (day < 1 || day>31)	return false;
		break;
	case 8:
		if (day < 1 || day>31)	return false;
		break;
	case 9:
		if (day < 1 || day>30)	return false;
		break;
	case 10:
		if (day < 1 || day>31)	return false;
		break;
	case 11:
		if (day < 1 || day>30)	return false;
		break;
	case 12:
		if (day < 1 || day>31)	return false;
		break;
	}
	return true;
}

/*Фнукция отображения курсора*/
void cursor_off_on(bool inf)
{
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = inf;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}