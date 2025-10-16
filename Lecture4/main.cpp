/* №1
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите количество чисел в последовательности: ";
    cin >> n;

    int num; // вводимое число
    int sh = 0; //сумма всех чётных чисел
    int maxh = 0; //наибольшее чётное число
    int maxin = -1; //номер
    bool ch = false; //флаг

    for (int i = 1; i <= n; i++) {
        cout << "Введите число " << i << ": ";
        cin >> num;

        if (num % 2 == 0) {
            sh += num;
            if ((!ch) || (num > maxh)) {
                 maxh = num;
                 maxin = i;
            }
            ch = true;
        }
    }

    if (!ch) {
        cout << "В последовательности нет чётных чисел." << endl;
    }
    else {
        cout << "Сумма всех чётных чисел: " << sh << endl;
        cout << "Наибольшее чётное число: " << maxh << endl;
        cout << "Номер в последовательности: " << maxin << endl;
    }
    return 0;
}
 №2 */


#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Введите целый положительный x < 1000: ";
    cin >> x;

    x = abs(x);
        if (x == 0) {
            cout << "Подхлдящих цифр нет." << endl;
            return 0;
        }
    int min = 9;
    bool ft = false;

    while (x > 0) {
        if (((x % 10) != 0) && ((x % 10) != 7)){
            if ((x % 10) <= min) {
                min = x % 10;
                ft = true;
            }    
        }
        x /= 10;
    }
    if (ft) {
        cout << "Наименьшая цифра, отличная от 0 и 7: " << min << endl;
    }
    else {
        cout << "Подходящих цифр нет." << endl;
    }
    return 0;
}
