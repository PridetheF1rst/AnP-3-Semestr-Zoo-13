#ifndef ZOO_H
#define ZOO_H
#pragma once

enum Keys {
	NoPressed,
	Up = 72,
	Down = 80,
	Left = 75,
	Right = 77,
	Esc = 27,
	Enter = 13,
};

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

/*константы нужные для выделения памяти*/
const int n_n = 16,//кличка
n_s = 21,//порода
n_a = 21,//ареал
n_p = 16,//тип продуктов
n_d = 11,//дата
print = 13;//константа для количества элементов на странице

using namespace std;//использование пространства имён

/*Подсчитать сумму и вес употреблённых продуктов всеми видами пород животных (за указанный период).*/

struct zoo //структура с информацией
{
	int id,//ключевое поле скрытое от пользователя
		cage;//номер вольера
	char name[n_n],//кличка животного
		specie[n_s],//порода
		area[n_a],//ареал обитания
		p_type[n_p],//тип продуктов
		date[n_d];// дата
	float p_weight,//вес продуктов 
		p_money;//стоимость потребляемых продуктов 

	struct zoo* next;//следущий элемент
	struct zoo* prev;//предыдущий элемент

};

#endif