#ifndef SORT_H
#define SORT_H
#pragma once
#include "zoo.h"

void sort_by_field(zoo* beg);//сортировка
void sort_cage(zoo* beg, int how_sort);//сортировка по номеру вольера
void sort_name(zoo* beg, int how_sort);//сортировка по кличке
void sort_specie(zoo* beg, int how_sort);//сортировка по породе
void sort_area(zoo* beg, int how_sort);//сортировка по ареалу обитания
void sort_p_type(zoo* beg, int how_sort);//сортировка по типу продуктов
void sort_p_weight(zoo* beg, int how_sort);//сортировка по весу продуктов
void sort_p_money(zoo* beg, int how_sort);//сортировка по стоимости потребляемых продуктов
void sort_date(zoo* beg, int how_sort);//сортировка по дате
void sort_replace(zoo* left, zoo* right, zoo* temp);//функция для смены местами элементов функции

#endif#pragma once