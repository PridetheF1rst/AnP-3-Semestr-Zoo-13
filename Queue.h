#ifndef QUEUE_H
#define QUEUE_H
#pragma once
#include "zoo.h"

zoo* add_first(const zoo& z);//���������� ������� �������� 
zoo* add(zoo* end, const zoo& z);//���������� ��������
zoo* dellete_id_beg(zoo* beg);//����������
zoo* dellete_id_end(zoo* beg, zoo* end);//������
zoo* dellete_id(zoo* beg, zoo* end, int num);//���
void dellete_all(zoo* beg);//��������
#endif