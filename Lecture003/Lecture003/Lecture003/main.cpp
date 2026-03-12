#include <iostream>
#include "Student.h"
#include "Dekanat.hpp"

using namespace std;

void labOpinion() {

    cout << "--- Оценка лабораторной ---" << endl;
    cout << "Интерес: 8/10" << endl;
    cout << "Наполненность: 7/10" << endl;
    cout << "Сложность: 6/10" << endl;

}

int main() {

    vector<string> d1 = { "Math","Physics" };
    vector<string> d2 = { "Math","Programming" };

    Student s1("Ivan", "Ivanov", "IT", 1, 101, 1, d1);
    Student s2("Petr", "Petrov", "IT", 1, 102, 1, d2);

    Dekanat dek("Main University Street");

    dek.addStudent(&s1);
    dek.addStudent(&s2);

    dek.printStudents();

    Zayavlenie z1 = s1.nextCourse();
    Zayavlenie z2 = s2.changeGroup(105);

    cout << "Заявление 1: " << z1.type << " -> " << z1.data << endl;
    cout << "Заявление 2: " << z2.type << " -> " << z2.data << endl;

    labOpinion();

    return 0;
}