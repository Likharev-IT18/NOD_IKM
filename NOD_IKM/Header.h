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
string to_str(long int m); // ������� ��� ���������� �����