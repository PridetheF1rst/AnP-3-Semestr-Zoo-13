/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			Севастопольский государственный университет
				  Кафедра «Информационные системы»
			   Программа для работы с базой зоопарка
														   Текст программы
																РАЗРАБОТАЛ
													студент гр. ИC/б-20-1-о
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
Дата последней коррекции: 26.12.2021 .
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
//#include <mmsystem.h>
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
//#pragma comment (lib, "Winmm.lib")

/*Главная функция*/
int main()
{
	setlocale(LC_ALL, "rus");
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD maxWindow; // размер самого большого возможного консольного окна
	maxWindow.X = 150;
	maxWindow.Y = 35;
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };
	SMALL_RECT minWindow = { 0, 0, 0, 0 };
	SetConsoleWindowInfo(out_handle, true, &minWindow);
	SetConsoleScreenBufferSize(out_handle, maxWindow);
	SetConsoleWindowInfo(out_handle, true, &srctWindow);
	system("title Система работы с зоопарком");
	GWL_STYLE;


	start_menu();

	zoo* beg = 0,//начало и
		* end = 0;//конец равны нулю

	string filename = "", ques = "",
	hello[] = {
		"Использовать существующий файл", //0
		"Создать новый список", //1
	},
	yes_no[] = {
	"Да",
	"Нет"
	},
	add_new[]={
		"Добавить к списку",
		"Заменить список"
	},
	type[] = {
		"txt",//0
		"data" //1
	},
	menuElems[] = {
		"Создание списка", //0
		"Добавление записи", //1
		"Удаление записи", //2
		"Редактирование записи", //3
		"Сортировка списка", //4
		"Поиск записи", //5
		"Просмотр списка",//6
		"Сохранение списка в файл" ,//7
		"Чтение списка из файла" ,//8
		"Подсчёт суммы и веса употреблённых продуктов всеми видами пород животных",//9
		"Выход из программы" ,//10
	},
	delete_e[] = {
	"Удалить весь список.",
	"Удалить конкретный элемент."
	};
	int count_input = 0,count_id_del=0,count_id_change=0;
	jmp_buf menu_choice;
	cursor_off_on(FALSE);
	switch (menu(hello, sizeof(hello), "Для взаимодействия с программой необходимо использовать или создать список.\nВыберите пункт меню"))
	{
	case 0:
		cin.clear();
		system("cls");
		cursor_off_on(TRUE);
		filename = inp_filename(filename, "Введите имя файла , который хотите открыть(без расширения)");
		cursor_off_on(FALSE);
		ques = "Какое расширение у файла '" + filename + "' ?";
		switch (menu(type, sizeof(type),ques))
		{
		case 0:
			filename += ".txt";
			break;
		case 1:
			filename += ".data";
			break;
		}
		SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
		read_file(filename, &beg, &end);
		system("pause");
		break;
	case 1:
		SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
		cout << "Был создан новый список" << endl;
		beg = end = 0;
		system("pause");
		break;
	}

	do
	{
		setjmp(menu_choice);
		cursor_off_on(FALSE);
		switch (menu(menuElems, sizeof(menuElems), "\t\t\tСистема работы с зоопарком\n===============================================================================\n\tИспользуйте стрелочки для перемещения и Enter для выбора пункта меню\n==============================================================================="))
		{
		case 0:
		{
			system("cls");
			if (beg != 0)
			{
				switch (menu_category(yes_no, sizeof(yes_no), "Для создание нового списка требуется удалить старый . Вы хотите сохранить старый список ?\n Вы можете нажать ESC для выхода в меню", menu_choice))
				{
					SetConsoleTextAttribute(out_handle, (WORD)((Black << 4) | Yellow));
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
					SetConsoleTextAttribute(out_handle, (WORD)((Black << 4) | Yellow));
					write_in_file(filename, beg);
					cin.get();
					dellete_all(beg);
					beg = end = 0;
					break;
				case 1:
					SetConsoleTextAttribute(out_handle, (WORD)((Black << 4) | Yellow));
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
			SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
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
				switch (menu_category(delete_e, sizeof(delete_e), "Вы хотите удалить весь список или конкретный элемент ?\n Вы можете нажать ESC для выхода в меню",menu_choice))
				{
					case 0:
						{
					system("cls");
					switch (menu(yes_no, sizeof(yes_no), "Вы действительно хотите удалить все элементы ?"))
					{
					case 0:

						dellete_all(beg);
						SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
						cout << "Все элементы были удалены" << endl;
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
						SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
						unsigned int num = 0;
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
				unsigned int num = 0;
				cursor_off_on(TRUE);
				SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
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
			sort_by_field(beg,menu_choice);
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			search(beg,menu_choice);
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			see_the_information(beg,end);
			break;
		}
		case 7:
		{
			system("cls");
			cursor_off_on(TRUE);
			ques = "";
			if (!filename.empty()) cin.ignore();
			filename = inp_filename(filename, "Введите имя файла , который хотите сохранить(без расширения)");
			cursor_off_on(FALSE);
			ques = "В каком расширении вы хотите сохранить файл '" + filename + "' ?";
			switch (menu(type, sizeof(type), ques))
			{
				SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
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
			ques = "";
			filename = inp_filename(filename, "Введите имя файла , который хотите открыть(без расширения)");
			cursor_off_on(FALSE);
			ques = "В каком расширении вы хотите открыть файл '" + filename + "' ?";
			switch (menu(type, sizeof(type), ques))
			{
				SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
			case 0:
				filename += ".txt";
				break;
			case 1:
				filename += ".data";
				break;
			}
			if (beg)
			{
				switch (menu(add_new, sizeof(add_new), "Вы хотите добавить список из файла к текущему списку или заменить его ?"))
				{
				case 0:
					cout << "Данные будут добавлены к текущему списку." << endl;
					break;
				case 1:
					cout << "Текущий список будет заменён." << endl;
					dellete_all(beg);
					beg = end = 0;
					break;
				}
			}
			read_file(filename, &beg, &end);
			system("pause");
			break;
		}
		case 9:
		{
			SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
			system("cls");
			if (beg) processing(beg);
			else cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl;
			system("pause");
			break;
		}
		case 10:
		{
			system("cls");
			if (beg)
			{
				switch (menu(yes_no, sizeof(yes_no), "Вы хотите сохранить файл перед выходом ?"))
				{
					case 0:
					{
						cursor_off_on(TRUE);
						if (beg) { cin.ignore(); }
						ques = "";
						filename = inp_filename(filename, "Введите имя файла , который хотите сохранить(без расширения)");
						cursor_off_on(FALSE);
						ques = "В каком расширении вы хотите сохранить файл '" + filename + "' ?";
						switch (menu(type, sizeof(type), ques))
						{
							SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
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
					{
						break;
				    }
				}
			}
			SetConsoleTextAttribute(out_handle, (WORD)((White << 4) | Blue));
			cout << "До свидания" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		}
	} while (1);
}
