#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct  SE{
    string season;        // название времени года
    string month1, month2, month3;  // три месяца
    int next;           // индекс следующего сезона
};

// просмотр сезона
void Seasons(const SE& s) {
    cout << "\n " << s.season << " \n";
    cout << "Месяц 1-ый: " << s.month1 << endl;
    cout << "Месяц 2-ой: " << s.month2 << endl;
    cout << "Месяц 3-ий: " << s.month3 << endl;
    cout << "Следующий сезон:" << s.next << endl;
}

// обмен месяцев
void Replace(SE& A, int numA, SE& B, int numB) {
    string* sa, * sb;

    // выбираем месяц в сезоне А
    if (numA == 1) sa = &A.month1;
    else if (numA == 2) sa = &A.month2;
    else sa = &A.month3;

    // выбираем месяц в сезоне B
    if (numB == 1) sb = &B.month1;
    else if (numB == 2) sb = &B.month2;
    else sb = &B.month3;

    // обмен
    swap(*sa, *sb);
}

// вывод года начиная с зимы
void Year(const vector<SE>& S) {
    int ind = 0; // начинаем с зимы
    cout << "\nГод: ";
    for (int i = 0; i < 4; i++) {
        cout << S[ind].season << "["
            << S[ind].month1 << ", " << S[ind].month2 << ", " << S[ind].month3
            << "] ";
        ind = S[ind].next;
    }
    cout << endl;
}

int main() {

    // создаём 4 сезона
    vector<SE> S(4);

    S[0] = { "Зима",  "декабрь", "январь", "февраль", 1 };
    S[1] = { "Весна", "март", "апрель", "май", 2 };
    S[2] = { "Лето",  "июнь", "июль", "август", 3 };
    S[3] = { "Осень", "сентябрь", "октябрь", "ноябрь", 0 };

    while (true) {
        cout << "\n|МЕНЮ ВЫБОРА ПУНКТОВ|\n";
        cout << "Выберете один из ниже указанных пунктов:\n";
        cout << "1. Вывести весь год\n";
        cout << "2. Поменять месяцы между сезонами\n";
        cout << "010. Выход\n";

        int check;
        cout << "Ваш выбор: ";
        cin >> check;

        if (check == 010) break;


        else if (check == 2) {
            int A, aM, B, bM;
            cout << "Сезон A (0-3): "; cin >> A;
            cout << "Месяц в сезоне A (1-3): "; cin >> aM;
            cout << "Сезон B (0-3): "; cin >> B;
            cout << "Месяц в сезоне B (1-3): "; cin >> bM;

            if (A >= 0 && A < 4 && B >= 0 && B < 4 &&
                aM >= 1 && aM <= 3 && bM >= 1 && bM <= 3)
            {
                Replace(S[A], aM, S[B], bM);
                cout << "Обмен умпешно выполнен! Можете пользоваться теплыми дениками во время зимы:)!\n";
            }
            else {
                cout << "Извините, но произошла какая-то маленькая ОШИБОЧКА! Попробуйте ввести все данные корректно, как следует!\n";
            }
        }

        else if (check == 010) {
            Year(S);
        }

        else {
            cout << "Извините, но к сожалению таких пунктов нету, попробуйте ввести данные заного, корректно! У вас получится, я в вас верю!!!\n";
        }
    }

    return 0;
}