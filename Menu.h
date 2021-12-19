#ifndef MENU_H
#define MENU_H
#pragma once
#include <iostream>
#include <string>
#include <setjmp.h>

using namespace std;

int menu(string menuElems[], int size, string inf);//меню

int menu_category(string menuElems[], int size, string inf, jmp_buf env);//

int start_menu();

void goto_x_y(short x, short y);

#endif