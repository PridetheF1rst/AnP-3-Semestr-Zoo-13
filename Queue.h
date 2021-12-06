#ifndef QUEUE_H
#define QUEUE_H
#pragma once
#include "zoo.h"

zoo* add_first(const zoo& z);//добавление первого элемента 
zoo* add(zoo* end, const zoo& z);//добавление элемента
zoo* dellete_id_beg(zoo* beg);//подфункции
zoo* dellete_id_end(zoo* beg, zoo* end);//нужные
zoo* dellete_id(zoo* beg, zoo* end, int num);//для
void dellete_all(zoo* beg);//удаления
#endif