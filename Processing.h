#ifndef PROCESSING_H
#define PROCESSING_H
#pragma once

void processing(zoo* beg);//��������� �������� ��������
float count_money(zoo* beg_p);//������� ���� ����� ����� ��� ���������
float count_weight(zoo* beg_p);//������� ����� ���� ��� ���������
int processing_write_in_file(string filename, zoo* temp);

#endif