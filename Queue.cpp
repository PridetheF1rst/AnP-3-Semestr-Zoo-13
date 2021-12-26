#include <iostream>
#include "zoo.h"
#include "Input.h"
#include "Output.h"

using namespace std;//������������� ������������ ���

/*������� ���������� ������� ��������*/
zoo* add_first(const zoo& z)
{
	zoo* beg = new zoo;
	*beg = z;
	beg->id = 1;//�������� ���� ����� ������� �� ������ ������ ������
	beg->prev = NULL;
	beg->next = 0;
	return beg;
}

/*������� ���������� � ��� ������������ ������*/
zoo* add(zoo* end, const zoo& z)
{
	zoo* newZ = new zoo;//
	*newZ = z;
	newZ->prev = end;
	newZ->next = 0;
	end->next = newZ;
	end = newZ;
	newZ->id = newZ->prev->id + 1;//���������� ��������� ���� �� ������� ��� ����� ���������
	return end;
}

/*�������� �� ��������� ���� , ���� id ����� id ������*/
zoo* dellete_id_beg(zoo* beg)
{
	zoo* temp;
	if (!beg) { cout << "���������� ��������� �������� ! ������� �����!" << endl; return 0; }
	else
	{
		temp = beg;
		cout << "��������� �������� �������� � ID = " << beg->id << endl;
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

/*�������� �� ��������� ���� , ���� id ����� id �����*/
zoo* dellete_id_end(zoo* beg, zoo* end)
{
	if (!beg) { cout << "���������� ��������� �������� ! ������� �����!" << endl; return 0; }
	zoo* temp;
	temp = end->prev;
	zoo* temp_1 = end;
	temp->next = end->next;
	end = temp;
	cout << "��������� �������� �������� � ID = " << temp_1->id << endl;
	header();
	print_on_the_screen(*temp_1);
	cout << endl;
	delete temp_1;
	return end;
}

/*�������� �� ��������� ����*/
zoo* dellete_id(zoo* beg, zoo* end, int num)
{
	zoo* temp;
	temp = beg;
	if (!beg) { cout << "���������� ��������� �������� ! ������� �����!" << endl; return 0; }
	else
	{
		while (temp)
		{
			if (temp->next->id == num)
			{
				zoo* temp_1 = temp->next;
				temp->next = temp_1->next;
				temp_1->next->prev = temp;
				cout << "��������� �������� �������� � ID = " << num << endl;
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

/*�������� ����� ������*/
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
