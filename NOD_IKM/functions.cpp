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
	//string str_arr = "";
	//// j - ����� �������� � �������, k - �����, i - ������ ������
	//int k = 0, i = str.size(), j = 0;
	//// �������� ������
	//int n = str.size() - sizeArr;
	//while (k < partArr)
	//{
	//	// �������� ��������� �� 9 ����, �������� � �����
	//	// ���� ��������� ��������� �������� ������ 9 ��������,��
	//	// ����� � 0-�� ������� ��� ����������
	//	if (i > 9) {
	//		i -= 9;
	//		str_arr = str.substr(i, 9);
	//	}
	//	else {
	//		str_arr = str.substr(0, i);
	//	}
	//	//str_arr = (i<9) ? str.substr(i, 9) : str.substr(n, i);
	//	//cout << str_arr << endl;
	//	arr[k] = atoi(str_arr.c_str()); // �������������� � �����  
	//	k++;
	//}

	string str_arr = ""; // ������, ������� ����� �������� � ������
	// k - ����� �������� � �������, i -������� ������� �������
	int k = 0, i = length - 9;
	while (k < part)
	{
		// �������� ��������� �� 9 ����, �������� � �����
		// ���� ��������� ��������� �������� ������ 9 ��������,��
		// ����� � 0-�� ������� ��� ����������
		if (i > 9) {
			i -= 9;
			str_arr = str.substr(i, 9);
		}
		else {
			str_arr = str.substr(0, i);
		}
		arr[k] = atoi(str_arr.c_str()); // �������������� � �����
		k++;
	}
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
			str1.insert(0, sizeStr1 - sizeStr2, '0');
			k = 1; // ������ ����� ������
		}
		else if (sizeStr1 < sizeStr2) {
			str2.insert(0, sizeStr2 - sizeStr1, '0');
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
			int* num1 = new int[size * 9];
			int* num2 = new int[size * 9];
			int* otvetArr = new int[size * 9];

			//� ����� ������� ������ � ������� ����������� �� 9 ���� � ����� �����
			str_to_array(num1, str1, size, part);
			str_to_array(num2, str2, size, part);
			
			if (k == 1) { // ���� ������ ������
				//cout << "1 ������" << endl;
				raznost(num1, num2, otvetArr, part); //�������� �� ������� ������
				
				str1 = ""; //�������� ������ ������, ����� ������������ � �� ��������
				for (int i = part - 1; i >= 0; i--) // �������������� �������� � ������ ������
				{
					if (i != 0) {
						str1 += to_str(otvetArr[i]); // ������� � ����� � ����������� �����
					}
					else {
						str1 += to_string(otvetArr[i]); // �� ��������� ���� � ������
					}
				}
			}
			else if (k == 2) { // ���� ������ ������
				//cout << "2 ������" << endl;
				raznost(num2, num1, otvetArr, part); // �������� �� ������� ������
				
				str2 = "";// �������� ������ ������
				for (int i = part - 1; i >= 0; i--) // �������������� �������� �� ������ ������
				{
					if (i != 0) {
						str2 += to_str(otvetArr[i]);
					}
					else {
						str2 += to_string(otvetArr[i]);
					}
				}
			}

			delete[] num1, num2, otvetArr;
		}
		//cout << "str1: " << str1 << endl;
		//cout << "str2: " << str2 << endl;
		
	}

}

void raznost(int* arr1, int* arr2, int* otvet, int part) { // ��������
	for (int i = 0; i < part; i++) {
		otvet[i] = arr1[i] - arr2[i];
		if (otvet[i] < 0) { //��������
			otvet[i] += 1000000000;
			arr1[i + 1]--;
		}
	}
}

string to_str(long int m) // ��������� ���� �� 9 ����
{
	string s = to_string(m);
	s.insert(0, 9 - s.length(), '0');
	return s;
}