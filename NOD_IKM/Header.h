#pragma once

//����������� ���������
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//�������
bool chislo(string str); // �������� ������� �� �����
void nod(string& str1, string& str2); // ����� ��� ���� ����� ���������� �������
void str_to_array(int* arr, string str, int length, int part); // ������� ������ � ������
void raznost(int* arr1, int* arr2, int* otvet, int part); // ������� ���������
string to_str(int m); // ������� ��� ���������� �����

//�����
enum ConsoleColor
{
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
void SetColor(int text, int background);
void SetColor(int text, ConsoleColor background);