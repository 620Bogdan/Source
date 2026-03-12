#include <iostream>
#include "Student.h"
#include "Dekanat.hpp"

using namespace std;

void labOpinion() {

    cout << "Лабораторная" << endl;
    cout << "Интерес: 9/10" << endl;
    cout << "Наполненность: 10/10" << endl;
    cout << "Сложность: 8/10" << endl;

}

int main() {

    vector<string> d1 = { "Математика","Физикаа" };
    vector<string> d2 = { "Математика","Программирование" };

    Student s1("Богдан", "Иванов", "IT", 1, 101, 1, d1);
    Student s2("Никита", "Попов", "IT", 1, 102, 1, d2);

    Dekanat dek("Главная улица Деконата");

    dek.addStudent(&s1);
    dek.addStudent(&s2);

    dek.printStudents();

    Zayavlenie z1 = s1.nextCourse();
    Zayavlenie z2 = s2.changeGroup(105);

    cout << "Заявление №1: " << z1.type << " = " << z1.data << endl;
    cout << "Заявление №2: " << z2.type << " = " << z2.data << endl;

    labOpinion();

    return 0;
}