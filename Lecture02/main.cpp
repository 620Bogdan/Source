#include <iostream>
#include <bitset>
using namespace std;
int main() {
    short A;
    short i;
    cout << "Число i: ";
    cin >> i;

    if ((i >= 8) || (i < 0)) {
        cout << "Большой i или малый " << endl;
    }

    cout << "Число А:";
    cin >> A;
    bitset<8> b2 = A;
    cout << "Двоичный вид A: " << b2.to_string()<< endl;

    bool i2 = (A >> i) & 1;
    cout << "Значение "<< i<< "-го бита: " << i2 << endl;
    cout << (1 << i);

if (i2 == 1){
    int y, z;
    cout << "Введите 1 - ое число : ";
    cin >> y;
    cout << "Введите 2 - ое число : ";
    cin >> z;
    if (y > z) {
        cout <<"Максимальное число: " << y<< endl;
    }
    else if (y < z) {
        cout << "Максимальное число: " << z << endl;
    }
    else {
        cout << "Максимальное число: " << z << endl;
    }
    A = A & ~(1 << i);
    cout << "Результат после установки iбит A в 0  " << i << "-го бита:" << endl;
    cout << A << " = " << bitset<8>(A) << endl;
}
else {
    A = ~A;
    cout << "Результат инверсии битов A:" << A << ":  " << bitset<8>(A);
}
	return 0;



int main() {
    int monthNumber;
    cout << "Введите номор месяца: ";
    cin >> monthNumber;
    switch (monthNumber) {
            
    case 1: cout << "Январь"; break;
    case 2: cout << "Февраль"; break;
    case 3: cout << "Март"; break;
    case 4: cout << "Апрель"; break;
    case 5: cout << "Май"; break;
    case 6: cout << "Июнь"; break;
    case 7: cout << "Июль"; break;
    case 8: cout << "Август"; break;
    case 9: cout << "Сентябрь"; break;
    case 10: cout << "Октябрь"; break;
    case 11: cout << "Ноябрь"; break;
    case 12: cout << "Декабрь"; break;
    default:cout << "Ошибка! Кажись, указан не существующий номер месяца.";
    }
}
