#ifndef PROCESSING_H
#define PROCESSING_H
#pragma once

void processing(zoo* beg);//обработка согласно варианту
float count_money(zoo* beg_p);//Подсчёт всей суммы денег для обработки
float count_weight(zoo* beg_p);//Подсчёт всего веса для обработки
int processing_write_in_file(string filename, zoo* temp);

#endif