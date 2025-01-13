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
string to_str(int m); // функция для добавления нулей

//Цвета
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