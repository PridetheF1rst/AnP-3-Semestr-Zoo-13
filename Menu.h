#ifndef MENU_H
#define MENU_H
#pragma once
#include <iostream>
#include <string>
#include <setjmp.h>

using namespace std;

int menu(string menuElems[], int size, const char* inf);//меню

int menu_category(string menuElems[], int size, const char* inf, jmp_buf env);//

#endif