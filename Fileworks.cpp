#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "zoo.h"
#include "Queue.h"

HANDLE FileworksHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*������ �� �����*/
int read_file(string filename, zoo** beg, zoo** end)
{
	ifstream fin(filename, ios::in | ios::_Nocreate);
	if (!fin) { cout << "���� " << filename << " �� ������!" << endl; cin.get(); return 1; }//���� �� ������
	zoo d;
	while (fin.getline(d.name, n_n))//���� � ����� ���� ���������
	{//��������� ������
		fin.getline(d.specie, n_s);//��������� ������
		fin.getline(d.area, n_a);//��������� ����� ��������
		fin.getline(d.p_type, n_p);//��������� ��� ���������
		fin.getline(d.date, n_d);//��������� ����
		fin >> d.cage;//��������� ����� �������
		fin >> d.p_weight;//��������� ��� ���������
		fin >> d.p_money;//��������� ����� ����������� �� ��������
		fin.get();
		if (*beg == 0)//���� ������ ��� �� ������
		{
			*beg = add_first(d); *end = *beg;//������ ������
		}
		else//�����
		{
			*end = add(*end, d);//��������� � ����� ������
		}
	}
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	cout << "������� ���������� �� ����� " << filename << endl;
	return 0;
}

/*������ � ����*/
int write_in_file(string filename, zoo* temp)
{
	ofstream fout(filename);
	if (!fout) { cout << "�� ���� ������� ���� ��� ������" << endl; return 1; }//���� ����� 
	//������� ���������� - ������� ��������� �� ������
	while (temp)//���� ������ �� ����������
	{
		fout << temp->name << endl;//������ ������ ���������
		fout << temp->specie << endl;//������ ���� ���������
		fout << temp->area << endl;//������ ������ ��������
		fout << temp->p_type << endl;//������ ���� ���������
		fout << temp->date << endl;//������ ����
		fout << temp->cage << endl;//������ ������ �������
		fout << temp->p_weight << endl;//������ ���� ���������
		fout << temp->p_money << endl;//������ ����� ����� ����������� �� ��������
		temp = temp->next;//������� � ��������� ���������
	}
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	cout << "������ ��������� � �����: " << filename << endl;
	return 0;
}
