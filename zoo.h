#ifndef ZOO_H
#define ZOO_H
#pragma once

enum Keys {
	NoPressed,
	Ctrl = 17,
	Enter = 13,
	Esc = 27,
	Up = 72,
	Left = 75,
	Right = 77,
	Down = 80,
};

enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

/*��������� ������ ��� ��������� ������*/
const int n_n = 16,//������
n_s = 21,//������
n_a = 21,//�����
n_p = 16,//��� ���������
n_d = 11,//����
print = 13;//��������� ��� ���������� ��������� �� ��������

using namespace std;//������������� ������������ ���

/*���������� ����� � ��� ������������ ��������� ����� ������ ����� �������� (�� ��������� ������).*/

struct zoo //��������� � �����������
{
	unsigned int id,//�������� ���� ������� �� ������������
		cage;//����� �������
	char name[n_n],//������ ���������
		specie[n_s],//������
		area[n_a],//����� ��������
		p_type[n_p],//��� ���������
		date[n_d];// ����
	float p_weight,//��� ��������� 
		p_money;//��������� ������������ ��������� 

	struct zoo* next;//�������� �������
	struct zoo* prev;//���������� �������
};

#endif