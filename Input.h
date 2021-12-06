#ifndef INPUT_H
#define INPUT_H
#pragma once

int inp_int(int n, const char* inf);//�������� ����� ����� ���� int 
char* inp_date(char* date);//�������� ����� ����
bool check_date(char* date);//�������� ����� ���� �� ������������
float inp_float(float temp, const char* inf);//�������� ����� ����� ���� float
char* inp_char(char* temp, const char* inf, int size);//�������� ����� ����� ���� char
string inp_filename(string temp, const char* inf);
void cursor_off_on(bool inf);
bool check_char(char* temp);
char* delete_space(char* temp, int size);
zoo input();

#endif
