#ifndef SEARCH_H
#define SEARCH_H
#pragma once
#include <setjmp.h>
#include "zoo.h"

void search(zoo* beg,jmp_buf env);//����� �� �� ��������� ����
void search_cage(zoo* beg, int num_cage);//����� �� ������ ������
void search_name(zoo* beg, char* pet_name);//����� �� ������
void search_specie(zoo* beg, char* pet_specie);//����� �� ������
void search_area(zoo* beg, char* pet_are);//����� �� ������ ��������
void search_p_type(zoo* beg, char* p_type);//����� �� ���� ���������
void search_p_weight(zoo* beg, float p_weight);//����� �� ���� ��������� 
void search_p_money(zoo* beg, float sum_money);//����� �� ����� ����������� �� ��������
void search_date(zoo* beg, char* data);//����� �� ����
void search_id(zoo* beg, int id);

#endif
