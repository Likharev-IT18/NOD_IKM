#include "Header.h"

bool chislo(string str) {
	string nums = "0123456789";
	char minus = '-';
	bool ch = false; // будем проверять цифра ли символ
	if ((str == "") || (str == "-") || ((str.size() >= 2 && str[0] == '0') || (str.size() >= 2 && (str[0] == '-' && str[1] == '0')))) return false;
	for (int i = 0; i < str.size(); i++) {
		ch = false;
		for (char n : nums) { // перебираем символы nums чтобы определить цифра ли у нас
			if (str[i] == n) ch = true;
		}
		if      ((i == 0) && (str[i] != minus) && (!ch)) return false; // если первый символ не минус и не цифра, то это не число
		else if ((i != 0) && (!ch))                      return false; // если символ не цифра, то это не число
	}
	return true;
}

void str_to_array(int* arr, string str, int length, int part) {
	string str_arr; // строка, которую будем заносить в массив
	int j = length;
	// выделяем подстроку из 9 цифр, двигаясь с конца
	// если последняя подстрока содержит меньше 9 символов,то
	// берем с 0-го символа все оставшиеся
	for (int i = 0; i < part; i++)
	{
		if (j > 9) {
			j -= 9;
			str_arr = str.substr(j, 9);
		}
		else {
			str_arr = str.substr(0, j);
		}
		arr[i] = atoi(str_arr.c_str());
	}
	/*for (int i = 0; i < part; i++) {
		cout << arr[i] << endl;
	}*/
}

void nod(string& str1, string& str2){
	int k = 1; // для сравнения
	int sizeStr1, sizeStr2;

	int size, part;

	while (k!=3) { // вычитаем из большего меньшее пока числа не станут равны
		sizeStr1 = str1.length();
		sizeStr2 = str2.length();
		// Добавляем нули слева к меньшей подстроке
		k = 3; // числа равны
		if (sizeStr1 > sizeStr2) {
			str2.insert(0, sizeStr1 - sizeStr2, '0');
			k = 1; // первое число больше
		}
		else if (sizeStr1 < sizeStr2) {
			str1.insert(0, sizeStr2 - sizeStr1, '0');
			k = 2; // второе число больше
		}
		else { // длины равны
			for (int i = 0; i < sizeStr1; i++) { // сравниваем с конца строк
				if (str1[i] > str2[i]) {
					k = 1;
					break;
				}
				else if (str2[i] > str1[i]) {
					k = 2;
					break;
				}
			}
		}

		//  Если числа не равны, вычитаем из большего меньшее
		if (k != 3) { 
			size = str1.length(); // итоговая длина строки
			part = (size % 9 == 0) ? (size / 9) : (size / 9 + 1); // ищем сколько частей

			//создаем динамические массивы
			int* num1 = new int[part];
			int* num2 = new int[part];
			int* otvetArr = new int[part];

			//с конца заносим строки в массивы разделенные по 9 цифр в одной части
			str_to_array(num1, str1, size, part);
			str_to_array(num2, str2, size, part);
			
			if (k == 1) { // если первое больше
				raznost(num1, num2, otvetArr, part); //вычитаем из первого второе
				
				str1 = ""; //обнуляем первую строку, чтобы перезаписать в неё разность
				str2 = "";// обнуляем вторую строку
				for (int i = part - 1; i >= 0; i--) // перезаписываем разность в первую строку
				{
					if (i == part-1) {
						if (otvetArr[i] != 0) { // если ноль, то его не нужно записывать
							str1 += to_string(otvetArr[i]); // не добавляем нули в начале
						}
						if (num2[i] != 0) {
							str2 += to_string(num2[i]); // не добавляем нули в начале
						}
					}
					else {
						str1 += to_str(otvetArr[i]); // выводим с конца с добавлением нулей
						str2 += to_str(num2[i]);
					}
				}

			}
			else if (k == 2) { // если второе больше
				raznost(num2, num1, otvetArr, part); // вычитаем из второго первое
				
				str1 = ""; //обнуляем первую строку, чтобы перезаписать в неё разность
				str2 = "";// обнуляем вторую строку
				for (int i = part - 1; i >= 0; i--) // перезаписываем разность в первую строку
				{
					if (i == part - 1) {
						if (num1[i] != 0) {
							str1 += to_string(num1[i]); // не добавляем нули в начале
						}
						if (otvetArr[i] != 0) {
							str2 += to_string(otvetArr[i]); // не добавляем нули в начале
						}
					}
					else {
						str1 += to_str(num1[i]); // выводим с конца с добавлением нулей
						str2 += to_str(otvetArr[i]);
					}
				}
			}

			delete[] num1;
			delete[] num2;
			delete[] otvetArr;
		}
		if (str1 == "1") { // проверка на 1 для небольшой оптимизации
			str2 = "1";
			break;
		}
		else if (str2 == "1") {
			str1 = "1";
			break;
		}
		//cout << "str1: " << str1 << endl;
		//cout << "str2: " << str2 << endl;
		
	}

}

void raznost(int* arr1, int* arr2, int* otvet, int part) { // разность
	for (int i = 0; i < part; i++) {
		if ((arr2[i] != 0) && (arr1[i] > arr2[i])) {
			if ((arr1[i] % arr2[i]) > 0) {
				otvet[i] = arr1[i] - (arr2[i] * (arr1[i] / arr2[i])); // будем вычитать сразу много
			}
			else if ((arr1[i] / arr2[i] > 2)) {
				otvet[i] = arr1[i] - (arr2[i] * (arr1[i] / arr2[i] - 1));
			}
			else {
				otvet[i] = arr1[i] - arr2[i];
			}
		}
		else {
			otvet[i] = arr1[i] - arr2[i];
		}
		if (otvet[i] < 0) { //занимаем
			otvet[i] += 1000000000;
			arr1[i + 1]--;
		}
	}
}

string to_str(int m) // добавляем нули до 9 цифр
{
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}