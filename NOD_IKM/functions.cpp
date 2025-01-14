#include "Header.h"

bool chislo(string str) {
	string nums = "0123456789";
	char minus = '-';
	bool ch = false; // ����� ��������� ����� �� ������
	if ((str == "") || (str == "-") || ((str.size() >= 2 && str[0] == '0') || (str.size() >= 2 && (str[0] == '-' && str[1] == '0')))) return false;
	for (int i = 0; i < str.size(); i++) {
		ch = false;
		for (char n : nums) { // ���������� ������� nums ����� ���������� ����� �� � ���
			if (str[i] == n) ch = true;
		}
		if      ((i == 0) && (str[i] != minus) && (!ch)) return false; // ���� ������ ������ �� ����� � �� �����, �� ��� �� �����
		else if ((i != 0) && (!ch))                      return false; // ���� ������ �� �����, �� ��� �� �����
	}
	return true;
}

void str_to_array(int* arr, string str, int length, int part) {
	string str_arr; // ������, ������� ����� �������� � ������
	int j = length;
	// �������� ��������� �� 9 ����, �������� � �����
	// ���� ��������� ��������� �������� ������ 9 ��������,��
	// ����� � 0-�� ������� ��� ����������
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
	int k = 1; // ��� ���������
	int sizeStr1, sizeStr2;

	int size, part;

	while (k!=3) { // �������� �� �������� ������� ���� ����� �� ������ �����
		sizeStr1 = str1.length();
		sizeStr2 = str2.length();
		// ��������� ���� ����� � ������� ���������
		k = 3; // ����� �����
		if (sizeStr1 > sizeStr2) {
			str2.insert(0, sizeStr1 - sizeStr2, '0');
			k = 1; // ������ ����� ������
		}
		else if (sizeStr1 < sizeStr2) {
			str1.insert(0, sizeStr2 - sizeStr1, '0');
			k = 2; // ������ ����� ������
		}
		else { // ����� �����
			for (int i = 0; i < sizeStr1; i++) { // ���������� � ����� �����
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

		//  ���� ����� �� �����, �������� �� �������� �������
		if (k != 3) { 
			size = str1.length(); // �������� ����� ������
			part = (size % 9 == 0) ? (size / 9) : (size / 9 + 1); // ���� ������� ������

			//������� ������������ �������
			int* num1 = new int[part];
			int* num2 = new int[part];
			int* otvetArr = new int[part];

			//� ����� ������� ������ � ������� ����������� �� 9 ���� � ����� �����
			str_to_array(num1, str1, size, part);
			str_to_array(num2, str2, size, part);
			
			if (k == 1) { // ���� ������ ������
				raznost(num1, num2, otvetArr, part); //�������� �� ������� ������
				
				str1 = ""; //�������� ������ ������, ����� ������������ � �� ��������
				str2 = "";// �������� ������ ������
				for (int i = part - 1; i >= 0; i--) // �������������� �������� � ������ ������
				{
					if (i == part-1) {
						if (otvetArr[i] != 0) { // ���� ����, �� ��� �� ����� ����������
							str1 += to_string(otvetArr[i]); // �� ��������� ���� � ������
						}
						if (num2[i] != 0) {
							str2 += to_string(num2[i]); // �� ��������� ���� � ������
						}
					}
					else {
						str1 += to_str(otvetArr[i]); // ������� � ����� � ����������� �����
						str2 += to_str(num2[i]);
					}
				}

			}
			else if (k == 2) { // ���� ������ ������
				raznost(num2, num1, otvetArr, part); // �������� �� ������� ������
				
				str1 = ""; //�������� ������ ������, ����� ������������ � �� ��������
				str2 = "";// �������� ������ ������
				for (int i = part - 1; i >= 0; i--) // �������������� �������� � ������ ������
				{
					if (i == part - 1) {
						if (num1[i] != 0) {
							str1 += to_string(num1[i]); // �� ��������� ���� � ������
						}
						if (otvetArr[i] != 0) {
							str2 += to_string(otvetArr[i]); // �� ��������� ���� � ������
						}
					}
					else {
						str1 += to_str(num1[i]); // ������� � ����� � ����������� �����
						str2 += to_str(otvetArr[i]);
					}
				}
			}

			delete[] num1;
			delete[] num2;
			delete[] otvetArr;
		}
		if (str1 == "1") { // �������� �� 1 ��� ��������� �����������
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

void raznost(int* arr1, int* arr2, int* otvet, int part) { // ��������
	for (int i = 0; i < part; i++) {
		if ((arr2[i] != 0) && (arr1[i] > arr2[i])) {
			if ((arr1[i] % arr2[i]) > 0) {
				otvet[i] = arr1[i] - (arr2[i] * (arr1[i] / arr2[i])); // ����� �������� ����� �����
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
		if (otvet[i] < 0) { //��������
			otvet[i] += 1000000000;
			arr1[i + 1]--;
		}
	}
}

string to_str(int m) // ��������� ���� �� 9 ����
{
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}