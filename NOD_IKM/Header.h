#pragma once

//Подключение библиотек
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

//функции
bool chislo(string str); // проверка введено ли число
void nod(string& str1, string& str2); // поиск нод двух чисел алгоритмом евклида
void str_to_array(int* arr, string str, int length, int part); // перевод строки в массив
void raznost(int* arr1, int* arr2, int* otvet, int part); // функция вычитания
string to_str(long int m); // функция для добавления нулей