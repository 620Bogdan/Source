#include <iostream>
using namespace std;


int function(int a, int b) {
    cout << "исп. функция суммы 2х чисел" << endl;
    return a + 2 * b + 3;
}


int function(int a, int b, int c) {
    cout << "исп. функция суммы 3х чисел" << endl;
    int su1 = a + b;
    int su2 = a + c;
    int su3 = b + c;
    int msu = su1;
    if (su2 > msu) {
        msu = su2;
    }
    if (su3 > msu) {
        msu = su3;
    }
    return msu;
}

void L1(int a, int b) {
    float c, s;
    c = pow(((a * a) + (b * b)), 0.5);
    s = (a + b + c);
    cout << "Гипотинуза: " << c << " float" << endl;
    cout << "Площадь: " << s << " float" << endl;
    cout << "float : " << sizeof(float) * 8 << "байт, " << numeric_limits<float>::lowest() << " " << numeric_limits<float>::max() << endl;
}


int main() {
    int choice;
    cout << "Выберите пункт(1 или 2):" << endl;
    cout << "Введите номер пункта: ";
    cin >> choice;


    if (choice == 1) {
        int a, b, c;
        cout << "Введите три целых числа (если число = 0, то можно считать, что его нет):" << endl;
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "c = ";
        cin >> c;


        // Считаем количество ненулевых чисел
        int count = 0;
        if (a != 0) {
            count++;
        }
        if (b != 0) {
            count++;
        }
        if (c != 0) {
            count++;
        }
        int result = 0;


        if (count == 0) {
            cout << "Ошибка: чисел нет!" << endl;
            return 0;
        }


        else if (count == 1) {
            cout << "исп. функция для 1го числа" << endl;
            if (a != 0) {
                result = a;
            }
            else if (b != 0) {
                result = b;
            }
            else {
                result = c;
            }
        }


        else if (count == 2) {
            int x[2], i = 0;
            if (a != 0) {
                x[i++] = a;
            }
            if (b != 0) {
                x[i++] = b;
            }
            if (c != 0) {
                x[i++] = c;
            }
            result = function(x[0], x[1]);
        }


        else if (count == 3) {
            result = function(a, b, c);
        }

        cout << "Полученный результат: " << result << endl;
    }
    else if (choice == 2) {
        cout << "Введите введите два значения катетов" << endl;
        int a, b;
        cin >> a;
        cin >> b;
        L1(a, b);
    }
    else {
        cout << "Неправильно введенное число, попробуйте ввести число заного." << endl;
    }
    return 0;
}