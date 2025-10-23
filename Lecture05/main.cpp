/*#include <iostream>
using namespace std;

int main() {
    int mas[4];
    for (int i = 0; i < 4; i++) {
        cout << "Введите " << i + 1 << "-ое число массива" << i + 1 << ": ";
        cin >> mas[i];
    }
    int n = abs(mas[0]);
    int minCifra = 9;
    if (n == 0) {
        minCifra = 0;
    }
    while (n > 0) {
        int cifra = n % 10;
        if (cifra < minCifra) {
            minCifra = cifra;
        }
        n = n / 10;
    }
    int n2 = abs(mas[4 - 1]);
    int minCifra2 = 9;
    if (n2 == 0) {
        minCifra2 = 0;
    }
    while (n2 > 0) {
        int cifra = n2 % 10;
        if (cifra < minCifra2) {
            minCifra2 = cifra;
        }
        n2 = n2 / 10;

    }
    if (minCifra == minCifra2) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (mas[i] < mas[j]) {
                    swap(mas[i], mas[j]);
                }
            }
        }
    }
    cout << "Массив: ";
    for (int i = 0; i < 4; i++) {
        cout << mas[i]<<" ";
    }
    return 0;
}*/


#include <iostream>
using namespace std;

int main() {
    const int y = 4, x = 3;// матрица
    int matrix[x][y];
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << "Введите число, которое стоит на месте " << i<< " " << j << ": "; //числа матрицы
            cin >> matrix[i][j]; //ввод числа
        }
    }
    int str = 0; //строка
    int sum = 0;// сумма элементов строчки
    bool tf = true;

    for (int i = 0; i < x; i++) {
        int summ = 0;
        for (int j = 0; j < y; j++) {
            summ += matrix[i][j];
        }

        if (tf) {
            sum = summ;
            str = i;
            tf = false;
        }
        else if (abs(summ) < abs(sum)) {
            sum = summ;
            str = i;
        }
    }
    for (int j = 0; j < y; j++) {
        matrix[str][j] = 0;
    }

    cout << "Матрица после замены всех значений в ней на 0 (" << str + 1<<"строка)";
    cout << endl;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
    
    return 0;
}