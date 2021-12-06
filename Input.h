#ifndef INPUT_H
#define INPUT_H
#pragma once

int inp_int(int n, const char* inf);//проверка ввода полей типа int 
char* inp_date(char* date);//проверка ввода даты
bool check_date(char* date);//проверка ввода даты на правильность
float inp_float(float temp, const char* inf);//проверка ввода полей типа float
char* inp_char(char* temp, const char* inf, int size);//проверка ввода полей типа char
string inp_filename(string temp, const char* inf);
void cursor_off_on(bool inf);
bool check_char(char* temp);
char* delete_space(char* temp, int size);
zoo input();

#endif
