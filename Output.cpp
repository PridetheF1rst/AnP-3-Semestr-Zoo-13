#include <iostream>
#include <conio.h>
#include "zoo.h"
#include "Processing.h"
#include "Output.h"

/*Просмотр списка*/
void see_the_information(zoo* beg,zoo* end)
{
	if (!beg) { cout << "Информация отсутствует !" << endl;  return; }
	else
	{
		int key;
		bool go = false;
		int page,count=0;
		float page_end;
		if (end->id % print == 0) page_end = end->id / print;
		else page_end = (end->id / print) + 1;
		zoo* temp = beg;//указатель на начало списка
		cout << "Список животных зоопарка:" << endl;
		header();
		while (!go)//пока список не кончился
		{
			if (temp->next == nullptr)
			{
				if (count == 0)cout << endl << "Для перехода на предыдущую страницу нажмите <-\t\t\t" << "Страница номер " << page_end << " из " << page_end << "\t\t\t\t\t  Для выхода нажмите Esc " << endl;
				count++;
				key = _getch();
				switch (key)
				{
				case Left:
				{
					count = 0;
					int i = 0;
					while (temp->prev->id % 13 != 0)
					{
						temp = temp->prev;
						i++;
					}
					i = 0;
					while (i < 12)
					{
						temp = temp->prev;
						i++;
					}
					system("cls");
					cout << "Список животных зоопарка:" << endl;
					header();
					break;
				}
				case Esc:
					goto end;
				default:
					cin.ignore();
					break;
				}
			}
			else
			{
				print_on_the_screen(*temp);
				if (temp->next && temp->next->id % print == 1)//если следущий элемент - 14 , 
				{
					page = temp->id / print;
					if (page == page_end ) go = true;
					else
					{
						if (page == 1) cout << endl << "\t\t\t\t\t\t\t" << "Страница номер " << page << " из " << page_end << "\t\t\tДля перехода на следующую страницу нажмите ->" << endl;
						else cout << endl << "Для перехода на предыдущую страницу нажмите <-\t\t\t" << "Страница номер " << page << " из " << page_end << "\t\t\tДля перехода на следующую страницу нажмите ->" << endl;
						cout << endl << "\t\t\t\t\t\t\tДля выхода нажмите Esc " << endl;

					}
					key = _getch();
					switch (key)
					{
					case  Right:
					{
						if (temp->next != nullptr)
						{
							temp = temp->next;
						}
						else system("pause"); break;
					}
					case Left:
					{
						if (temp->id != 13)
						{
							int i = 0;
							while (i < 2 * print - 1)
							{
								temp = temp->prev;
								i++;
							}
						}
						else temp = beg;
						break;
					}
					case Esc:
						goto end;
					default:
						break;
					}
					system("cls");
					cout << "Список животных зоопарка:" << endl;
					header();
				}
				else temp = temp->next;
			}
		}
		cout << endl;
	end:
		return;
	}
}

/*Заголовок для списка*/
void header()
{
	for (int i = 0; i < 148; i++) cout << "=";
	printf("\n|%-3s|", "ID");
	printf("%-12s|", "Номер ");
	printf("%-15s|", "Кличка");
	printf("%-20s|", "Порода");
	printf("%-20s|", "Ареал ");
	printf("%-15s|", "Тип ");
	printf("%-18s|", "Вес");
	printf("%-18s|", "Стоимость ");
	printf("%-17s|", "Дата");
	printf("\n|%-3s|", "");
	printf("%-12s|", "вольера");
	printf("%-15s|", "животного");
	printf("%-20s|", "животного");
	printf("%-20s|", "обитания");
	printf("%-15s|", "продуктов");
	printf("%-18s|", "продуктов");
	printf("%-18s|", "продуктов");
	printf("%-17s|\n", "(ГГГГ.ММ.ДД)");
	for (int i = 0; i < 148; i++) cout << "=";
}

/*Вывод элемента на экран*/
void print_on_the_screen(const zoo& z)
{
	printf("\n|%-3d|", z.id);
	printf("%-12d|", z.cage);
	printf("%-15s|", z.name);
	printf("%-20s|", z.specie);
	printf("%-20s|", z.area);
	printf("%-15s|", z.p_type);
	printf("%-18.2f|", z.p_weight);
	printf("%-18.2f|", z.p_money);
	printf("%-17s|\n", z.date);
	for (int i = 0; i < 148; i++) cout << "=";
}

/*Заголовок для обработки*/
void header_proccessing()
{
	for (int i = 0; i < 79; i++) cout << "=";
	printf("\n|%-30s|", "Порода животного");
	printf("%-20s|", "Вес продуктов");
	printf("%-25s|\n", "Стоимость продуктов");
	for (int i = 0; i < 79; i++) cout << "=";
}

/*Вывод элемента обработки на экран*/
void print_processing(const zoo& z)
{
	printf("\n|%-30s|", z.specie);
	printf("%-20.2f|", z.p_weight);
	printf("%-25.2f|\n", z.p_money);
	for (int i = 0; i < 79; i++) cout << "=";
}

/*Вывод списка элементов обработки*/
void show_processing(zoo* beg)
{
	zoo* temp = beg;//указатель на начало списка
	cout << "Сумма и вес употреблённых продуктов всеми видами пород животных(за указанный период) :" << endl;
	header_proccessing();
	while (temp)//пока список не кончился
	{
		print_processing(*temp);
		if (temp->next && temp->next->id % print == 1)//если следущий элемент - 13 , 
		{
			cout << endl;
			system("pause");
			system("cls");
			cout << "Сумма и вес употреблённых продуктов всеми видами пород животных(за указанный период) :" << endl;
			header_proccessing();
		}
		temp = temp->next;//переход к следующей структуре
	}
	cout << endl;
	printf("%-31s|", " ");
	printf("%-20s|", "Суммарный вес");
	printf("%-25s|\n", "Суммарная стоимость");
	printf("%31s", " ");
	for (int i = 0; i < 48; i++) cout << "=";
	printf("\n%-31s|", " ");
	printf("%-20.2f|", count_weight(beg));
	printf("%-25.2f|\n", count_money(beg));
	printf("%31s", " ");
	for (int i = 0; i < 48; i++) cout << "=";
	cout << endl;
}