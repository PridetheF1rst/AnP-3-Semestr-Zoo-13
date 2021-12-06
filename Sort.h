#ifndef SORT_H
#define SORT_H
#pragma once
#include "zoo.h"

void sort_by_field(zoo* beg);//����������
void sort_cage(zoo* beg, int how_sort);//���������� �� ������ �������
void sort_name(zoo* beg, int how_sort);//���������� �� ������
void sort_specie(zoo* beg, int how_sort);//���������� �� ������
void sort_area(zoo* beg, int how_sort);//���������� �� ������ ��������
void sort_p_type(zoo* beg, int how_sort);//���������� �� ���� ���������
void sort_p_weight(zoo* beg, int how_sort);//���������� �� ���� ���������
void sort_p_money(zoo* beg, int how_sort);//���������� �� ��������� ������������ ���������
void sort_date(zoo* beg, int how_sort);//���������� �� ����
void sort_replace(zoo* left, zoo* right, zoo* temp);//������� ��� ����� ������� ��������� �������

#endif#pragma once