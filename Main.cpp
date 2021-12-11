/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			Севастопольский государственный университет
				  Кафедра «Информационные системы»
			   Программа для работы с базой зоопарка
														   Текст программы
																РАЗРАБОТАЛ
													тудент гр. ИC/б-20-1-о
															 Бугаенко Д.В.
								 2021
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Программа работает с базой данных зоопарка, которая считывается из
текстового файла. Каждая строка файла содержит запись об одном животном, для которого указывается номер вольера,кличка (16 символов),
порода животного(21 символ) , ареал обитания(21 символ) ,тип потребляемых продуктов (16 символов) ,вес потребляемых продуктов с точностью до сотых долей килограмма,
продуктов стоимость потребляемых продуктов с точностью до копеек, дата(11 символов)
Основные функции программы:
- вывод базы на экран;
- добавление записи о животном в базу;
- исправление записи о животном в базе;
- удаление записи о животном из базы;
- поиск записи о животном в базе;
- выбор записей о животных, попадающих в заданный пользователем диапазон дат.
Вариант задания 13. Утверждено 01.09.2021
Среда программирования Microsoft Visual Studio 22 Preview version 17.1.0 Preview 1.1
Дата последней коррекции: 11.12.2021 .
Версия 1.0
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <cctype>
#include <setjmp.h>
#include "zoo.h"
#include "Change.h"
#include "Fileworks.h"
#include "Input.h"
#include "Menu.h"
#include "Output.h"
#include "Processing.h"
#include "Queue.h"
#include "Search.h"
#include "Sort.h"
#include "Main_Menu.h"

HANDLE mainHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*Главная функция*/
int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow; // размер самого большого возможного консольного окна
	maxWindow.X = 150;
	maxWindow.Y = 45;
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(out_handle, true, &minWindow);
	SetConsoleScreenBufferSize(out_handle, maxWindow);
	SetConsoleWindowInfo(out_handle, true, &srctWindow);
	system("title Система работы с зоопарком");

	main_menu();

	zoo* beg = 0,//начало и
		* end = 0;//конец равны нулю

	string filename = "";
	string hello[] = {
		"Использовать существующий файл", //0
		"Создать новый список", //1
	},
	yes_no[] = {
	"Да",
	"Нет"
	},
		type[] = {
		"txt",//0
		"data" //1
	},
		menuElems[] = {
		"Создание списка", //0
		"Добавление элемента", //1
		"Удаление по ключевому полю", //2
		"Корректировка", //3
		"Сортировка", //4
		"Поиск (не по ключевому полю)", //5
		"Просмотр",//6
		"Сохранение в файл" ,//7
		"Чтение из файла" ,//8
		"Обработка",//9
		"Выход" ,//10
	},
	delete_e[] = {
	"Удалить весь список.",
	"Удалить конкретный элемент."
	};
	int count_input = 0,count_id_del=0,count_id_change=0;
	cursor_off_on(FALSE);
	switch (menu(hello, sizeof(hello), "Для взаимодействия с программой необходимо использовать или создать список.\nВыберите пункт меню"))
	{
	case 0:
		cin.clear();
		system("cls");
		cursor_off_on(TRUE);
		filename = inp_filename(filename, "Введите имя файла , который хотите открыть(без расширения)");
		cursor_off_on(FALSE);
		switch (menu(type, sizeof(type), "Какое расширение у файла ?"))
		{
		case 0:
			filename += ".txt";
			break;
		case 1:
			filename += ".data";
			break;
		}
		SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
		read_file(filename, &beg, &end);
		system("pause");
		break;
	case 1:
		SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
		cout << "Был создан новый список" << endl;
		beg = end = 0;
		system("pause");
		break;
	}


	do
	{
		jmp_buf start_menu ;
		setjmp(start_menu);
		cursor_off_on(FALSE);
		switch (menu(menuElems, sizeof(menuElems), "Система работы с зоопарком\n==================================\nИспользуйте стрелочки для перемещения"))
		{

		case 0:
		{
			system("cls");
			if (beg != 0)
			{
				switch (menu_category(yes_no, sizeof(yes_no), "Для создание нового списка требуется удалить старый . Вы хотите сохранить старый список ?\n Вы можете нажать ESC для выхода в меню", start_menu))
				{
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
				case 0:
					cursor_off_on(TRUE);
					cin.ignore();
					filename = inp_filename(filename, "Введите имя файла , который хотите сохранить(без расширения)");
					cursor_off_on(FALSE);
					switch (menu(type, sizeof(type), "В каком расширении вы хотите сохранить файл ?"))
					{
					case 0:
						filename += ".txt";
						break;
					case 1:
						filename += ".data";
						break;
					}
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
					write_in_file(filename, beg);
					cin.get();
					dellete_all(beg);
					beg = end = 0;
					break;
				case 1:
					SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
					dellete_all(beg);
					beg = end = 0;
					break;
				}
			}
			else
			{
				beg = end = 0;
			}
			cout << "Был создан новый список" << endl;
			system("pause");
			break;
		}
		case 1:
		{

			system("cls");
			cursor_off_on(TRUE);
			if (beg) 
			{
				if (filename != "" && count_input == 0) { cin.ignore(); count_input++; }
					end = add(end, input());
			}//если существует хотя бы один элемент- добавляем новый
			else
			{
				beg = add_first(input());//если не существует ни одного элемента - создаём первый
				end = beg;//приравниваем конец к началу
			}
			system("cls");
			cursor_off_on(FALSE);
			cout << "Вы создали следующий элемент : " << endl;
			header();
			print_on_the_screen(*end);
			cout << endl;
			system("pause");
			break;
			cin.clear();
		}
		case 2:
		{
			system("cls");
			if (!beg) { cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl; }
			else
			{
				switch (menu_category(delete_e, sizeof(delete_e), "Вы хотите удалить весь список или конкретный элемент ?\n Вы можете нажать ESC для выхода в меню",start_menu))
				{
					case 0:
						{
					system("cls");
					switch (menu(yes_no, sizeof(yes_no), "Вы действительно хотите удалить все элементы ?"))
					{
					case 0:

						dellete_all(beg);
						SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
						cout << "Все элементы были удалены" << endl;
						cin.ignore();
						cin.get();
						beg = end = 0;
						break;
					case 1:
						break;
					}
					break;
					}
					case 1:
						{
						cursor_off_on(TRUE);
						system("cls");

						SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
						int num = 0;
						if (filename != "" && count_id_del == 0) { cin.ignore(); count_id_del++; }
						num = inp_int(num, "Введите ID элемента");
						cursor_off_on(FALSE); 
						if (num<1 || num>end->id)
						{
							cout << "Невозможно выполнить удаление!" << endl;
							cout << "Введенноё ID не находится в диапазоне от " << beg->id << " до " << end->id << endl;
							break;
						}
						else
						{
							cout << "Выбранный вами элемент :" << endl;
							search_id(beg, num);
							system("cls");
							switch (menu(yes_no, sizeof(yes_no), "Вы действительно хотите удалить этот элемент ?"))
							{
							case 0:
								if (num == beg->id) { beg = dellete_id_beg(beg); }
								else
								{
									if (num == end->id) { end = dellete_id_end(beg, end); }
									else { dellete_id(beg, end, num); }
								}
								break;
							case 1:
								break;
							}
						}

						cursor_off_on(FALSE);
						break;
					}
				}
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			if (beg)
			{
				int num = 0;
				cursor_off_on(TRUE);
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
				if (filename != "" && count_id_change == 0) { cin.ignore(); count_id_change++; }
				num = inp_int(num, "Введите ID элемента");
				cursor_off_on(FALSE);
				if (num<1 || num>end->id)
				{
					cout << "Невозможно выполнить изменение!" << endl;
					cout << "Введенноё ID не находится в диапазоне от " << beg->id << " до " << end->id << endl;
				}
				else
				{
					cout << "Выбранный вами элемент :" << endl;
					search_id(beg, num);
					system("cls");
					switch (menu(yes_no, sizeof(yes_no), "Вы действительно хотите изменить этот элемент ?"))
					{
					case 0:
						change(beg, end, num);
						break;
					case 1:
						break;
					}
				}
			}
			else { cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl; }
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			sort_by_field(beg,start_menu);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			search(beg,start_menu);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			see_the_information(beg,end);
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			cursor_off_on(TRUE);
			if (beg) { cin.ignore(); }
			filename = inp_filename(filename, "Введите имя файла , который хотите сохранить(без расширения)");
			cursor_off_on(FALSE);
			switch (menu(type, sizeof(type), "В каком расширении вы хотите сохранить файл ?"))
			{
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			case 0:
				filename += ".txt";
				break;
			case 1:
				filename += ".data";
				break;
			}
			write_in_file(filename, beg);
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			cursor_off_on(TRUE);
			if (beg) { cin.ignore(); }
			filename = inp_filename(filename, "Введите имя файла , который хотите открыть(без расширения)");
			cursor_off_on(FALSE);
			switch (menu(type, sizeof(type), "В каком расширении вы хотите открыть файл ?"))
			{
				SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			case 0:
				filename += ".txt";
				break;
			case 1:
				filename += ".data";
				break;
			}
			read_file(filename, &beg, &end);
			system("pause");
			break;
		}
		case 9:
		{
			SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			system("cls");
			processing(beg);
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			if (beg)
			{
				switch (menu(yes_no, sizeof(yes_no), "Вы хотите файл перед выходом ?"))
				{
					case 0:
					{
					switch (menu(yes_no, sizeof(yes_no), "Вы хотите файл перед выходом ?"))
					{
					case 0:
					{
						cursor_off_on(TRUE);
						if (beg) { cin.ignore(); }
						filename = inp_filename(filename, "Введите имя файла , который хотите сохранить(без расширения)");
						cursor_off_on(FALSE);
						switch (menu(type, sizeof(type), "В каком расширении вы хотите сохранить файл ?"))
						{
							SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
						case 0:
							filename += ".txt";
							break;
						case 1:
							filename += ".data";
							break;
						}
						write_in_file(filename, beg);
						system("pause");
						break;
					}
					case 1:
						break;
					}
				}
					case 1:
					{
					break;
				}
				}
			}
			SetConsoleTextAttribute(mainHandle, (WORD)((Black << 4) | Yellow));
			cout << "До свидания" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		}
	} while (1);
}
