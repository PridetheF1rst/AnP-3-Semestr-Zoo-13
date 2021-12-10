#ifndef SEARCH_H
#define SEARCH_H
#pragma once
#include <setjmp.h>
#include "zoo.h"

void search(zoo* beg,jmp_buf env);//поиск не по ключевому полю
void search_cage(zoo* beg, int num_cage);//поиск по номеру клетки
void search_name(zoo* beg, char* pet_name);//поиск по кличке
void search_specie(zoo* beg, char* pet_specie);//поиск по породе
void search_area(zoo* beg, char* pet_are);//поиск по ареалу обитания
void search_p_type(zoo* beg, char* p_type);//поиск по типу продуктов
void search_p_weight(zoo* beg, float p_weight);//поиск по весу продуктов 
void search_p_money(zoo* beg, float sum_money);//поиск по сумме потраченной на продукты
void search_date(zoo* beg, char* data);//поиск по дате
void search_id(zoo* beg, int id);

#endif
