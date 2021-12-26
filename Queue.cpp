#include <iostream>
#include "zoo.h"
#include "Input.h"
#include "Output.h"

using namespace std;//использование пространства имён

/*Функция добавления первого элемента*/
zoo* add_first(const zoo& z)
{
	zoo* beg = new zoo;
	*beg = z;
	beg->id = 1;//ключевое поле равно единице на момент начало списка
	beg->prev = NULL;
	beg->next = 0;
	return beg;
}

/*Функция добавления в уже существующий список*/
zoo* add(zoo* end, const zoo& z)
{
	zoo* newZ = new zoo;//
	*newZ = z;
	newZ->prev = end;
	newZ->next = 0;
	end->next = newZ;
	end = newZ;
	newZ->id = newZ->prev->id + 1;//увеличение ключевого поля на единицу для новой структуры
	return end;
}

/*Удаление по ключевому полю , если id равно id начала*/
zoo* dellete_id_beg(zoo* beg)
{
	zoo* temp;
	if (!beg) { cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl; return 0; }
	else
	{
		temp = beg;
		cout << "Выполнено удаление элемента с ID = " << beg->id << endl;
		header();
		print_on_the_screen(*beg);
		cout << endl;
		while (temp)
		{
			(temp->id)--;
			temp = temp->next;
		}
		temp = beg;
		beg = beg->next;
		delete temp;
		return beg;
	}
}

/*Удаление по ключевому полю , если id равно id конца*/
zoo* dellete_id_end(zoo* beg, zoo* end)
{
	if (!beg) { cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl; return 0; }
	zoo* temp;
	temp = end->prev;
	zoo* temp_1 = end;
	temp->next = end->next;
	end = temp;
	cout << "Выполнено удаление элемента с ID = " << temp_1->id << endl;
	header();
	print_on_the_screen(*temp_1);
	cout << endl;
	delete temp_1;
	return end;
}

/*Удаление по ключевому полю*/
zoo* dellete_id(zoo* beg, zoo* end, int num)
{
	zoo* temp;
	temp = beg;
	if (!beg) { cout << "Невозможно выполнить операцию ! Очередь пуста!" << endl; return 0; }
	else
	{
		while (temp)
		{
			if (temp->next->id == num)
			{
				zoo* temp_1 = temp->next;
				temp->next = temp_1->next;
				temp_1->next->prev = temp;
				cout << "Выполнено удаление элемента с ID = " << num << endl;
				header();
				print_on_the_screen(*temp_1);
				cout << endl;
				delete temp_1;
				temp_1 = temp->next;
				while (temp_1)
				{
					(temp_1->id)--;
					temp_1 = temp_1->next;
				}
				break;
			}
			else temp = temp->next;
		}
	}
}

/*Удаление всего списка*/
void dellete_all(zoo* beg)
{
	zoo* temp = beg;
	while (temp)
	{
		zoo* temp_1 = temp->next;
		delete temp;
		temp = temp_1;
	}
}
