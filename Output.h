#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once
#include "zoo.h"

void print_on_the_screen(const zoo& z);//просмотр элемента  
void see_the_information(zoo* beg);//просмотр всей информации
void header();//заголовок
void header_proccessing();//заголовок для обработки
void print_processing(const zoo& z);//Вывод элемента обработки на экран
void show_processing(zoo* beg);//Вывод списка элементов обработки

#endif