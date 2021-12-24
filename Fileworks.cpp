#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include "zoo.h"
#include "Queue.h"

HANDLE FileworksHandle = GetStdHandle(STD_OUTPUT_HANDLE);

/*������ �� �����*/
int read_file(string filename, zoo** beg, zoo** end)
{
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	string type = ".data";
	int count=0;
	if (filename.find(type) != std::string::npos) 
	{
		zoo temp;
		const char* file = filename.c_str();
		FILE* fin = fopen(file, "rb");
		if(!fin) { cout << "���� " << filename << " �� ������!" << endl; cin.get(); return 1; }
		else
		{
			while (fread(&temp.cage, sizeof(int), sizeof(temp.cage), fin))
			{
				fread(&temp.name, sizeof(char), n_n, fin);
				fread(&temp.specie, sizeof(char), n_s, fin);
				fread(&temp.area, sizeof(char), n_a, fin);
				fread(&temp.p_type, sizeof(char), n_p, fin);
				fread(&temp.date, sizeof(char), n_d, fin);
				fread(&temp.p_weight, sizeof(float), sizeof(temp.p_weight), fin);
				fread(&temp.p_money, sizeof(float), sizeof(temp.p_money), fin);
				if (*beg == 0)//���� ������ ��� �� ������
				{
					*beg = add_first(temp); *end = *beg;//������ ������
				}
				else//�����
				{
					*end = add(*end, temp);//��������� � ����� ������
				}
				count++;
			}
		}
		fclose(fin);
	}
	else
	{
		ifstream fin(filename, ios::_Nocreate);
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
			count++;
		}
		fin.close();
	}
	cout << "������� ���������� �� ����� " << filename << endl;
	cout << "������� �������� ���������� ������� :" << count << endl;
	return 0;
}

/*������ � ����*/
int write_in_file(string filename, zoo* temp)
{
	SetConsoleTextAttribute(FileworksHandle, (WORD)((White << 4) | Blue));
	string type = ".data";
	if (filename.find(type) != std::string::npos)
	{
		const char* file = filename.c_str();
		FILE* fout = fopen(file, "wb");
		if (!fout) { cout << "���������� ������� ���� " << filename << " ��� ������" << endl; return 1; }
		else
		{
			zoo* templ = temp;
			while (templ)
			{
				fwrite(&templ->cage, sizeof(int), sizeof(templ->cage), fout);
				fwrite(&templ->name, sizeof(char), n_n, fout);
				fwrite(&templ->specie, sizeof(char), n_s, fout);
				fwrite(&templ->area, sizeof(char), n_a, fout);
				fwrite(&templ->p_type, sizeof(char), n_p, fout);
				fwrite(&templ->date, sizeof(char), n_d, fout);
				fwrite(&templ->p_weight, sizeof(float), sizeof(templ->p_weight), fout);
				fwrite(&templ->p_money, sizeof(float), sizeof(templ->p_money), fout);
				templ = templ->next;
			}
		}
		fclose(fout);
	}
	else
	{
		ofstream fout(filename);
		if (!fout) { cout << "���������� ������� ���� " << filename << " ��� ������" << endl; return 1; }//���� ����� 
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
		fout.close();
	}
	cout << "������ ��������� � �����: " << filename << endl;
	return 0;
}
