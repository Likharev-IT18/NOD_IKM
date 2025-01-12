#include "Header.h"

int main()
{
    //меняем кодировку
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    setlocale(LC_ALL, "Ru");

    string m = "", n = "", p = "";
    int kolvo_null = 0; // будем считать количество нулей
    cout << "\t\tНахождение НОД трёх чисел" << endl;
    
    bool ch_norm = true; // будем требовать ввод пока введено не число
    while (true) {
        //   Записываем 3 числа в строки
        //первое число
        do {
            ch_norm = true;
            cout << "Число 1:";
            getline(cin, m);
            if (!chislo(m)) {
                ch_norm = false;
                cout << "Неправильный ввод числа." << endl;
            }
        } while (!ch_norm);
        if (m == "0") kolvo_null++;
        //второе число
        do {
            ch_norm = true;
            cout << "Число 2:";
            getline(cin, n);
            if (!chislo(n)) {
                ch_norm = false;
                cout << "Неправильный ввод числа." << endl;
            }
        } while (!ch_norm);
        if (n == "0") kolvo_null++;
        //третье число
        do {
            ch_norm = true;

            cout << "Число 3:";
            getline(cin, p);

            if (!chislo(p)) {
                ch_norm = false;
                cout << "Неправильный ввод числа." << endl;
            }
        } while (!ch_norm);
        if (p == "0") kolvo_null++;

        if (kolvo_null > 0) { // если есть хотябы 1 ноль то ответ сразу 0
            cout << "Ответ: 0" << endl; 
        }
        else {
            int sizeM, sizeN, sizeP;
            int partM, partN, partP;

            //ищем размеры строк и убираем минусы
            if (m[0] == '-') {
                sizeM = m.size() - 1;
                m = m.substr(1, sizeM);
            }
            else sizeM = m.size();
            if (n[0] == '-') {
                sizeN = n.size() - 1;
                n = n.substr(1, sizeN);
            }
            else sizeN = n.size();
            if (p[0] == '-') {
                sizeP = p.size() - 1;
                p = p.substr(1, sizeP);
            }
            else sizeP = p.size();
            
            ////ищем сколько частей будет в массивах
            //partM = m.size() % 9 == 0 ? m.size() / 9 : m.size() / 9 + 1;
            //partN = n.size() % 9 == 0 ? n.size() / 9 : n.size() / 9 + 1;
            //partP = p.size() % 9 == 0 ? p.size() / 9 : p.size() / 9 + 1;
            //
            ////Создаем динамические массивы
            //int* arrayM = new int[partM*9];
            //int* arrayN = new int[partN*9];
            //int* arrayP = new int[partP*9];
            
            //Заполняем массивы
            //str_to_array(m, arrayM, sizeM, partM);
            //str_to_array(n, arrayN, sizeN, partN);
            //str_to_array(p, arrayP, sizeP, partP);

            // Ищем нод первых двух чисел
            nod(m, n);
            // Ищем нод ответа предыдущего нода и третьего числа
            nod(n, p);

            cout << "Ответ:" << p << endl;

        }
    }
}