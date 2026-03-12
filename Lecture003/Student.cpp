#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
    name = "";
    surname = "";
    direction = "";
    course = 1;
    group = 0;
    variant = 0;
}

Student::Student(string n, string s, string dir, int c, int g, int v, vector<string> d) {
    name = n;
    surname = s;
    direction = dir;
    course = c;
    group = g;
    variant = v;
    debts = d;
}

Student::Student(const Student& other) {
    name = other.name;
    surname = other.surname;
    direction = other.direction;
    course = other.course;
    group = other.group;
    variant = other.variant;
    debts = other.debts;
}

Student::~Student() {
    debts.clear();
}

Student& Student::operator=(const Student& other) {

    if (this != &other) {
        name = other.name;
        surname = other.surname;
        direction = other.direction;
        course = other.course;
        group = other.group;
        variant = other.variant;
        debts = other.debts;
    }

    return *this;
}

string Student::getName() {
    return name;
}

string Student::getSurname() {
    return surname;
}

int Student::getCourse() {
    return course;
}

int Student::getGroup() {
    return group;
}

void Student::printInfo() {

    cout << "Имя : " << name << endl;
    cout << "Фамилия : " << surname << endl;
    cout << "Направление: " << direction << endl;
    cout << "Курс : " << course << endl;
    cout << "Группа: " << group << endl;
    cout << "Вариант: " << variant << endl;

    cout << "Любимые ДОЛГИ: ";

    for (int i = 0; i < debts.size(); i++)
        cout << debts[i] << " ";

    cout << endl;
}

Zayavlenie Student::nextCourse() {

    Zayavlenie z;

    z.name = name;
    z.surname = surname;
    z.type = "перевод на курс выше";
    z.comment = "Прошу меня перевести на следующий курс, пожалуйста.";
    z.data = course + 1;

    return z;
}

Zayavlenie Student::changeGroup(int newGroup) {

    Zayavlenie z;

    z.name = name;
    z.surname = surname;
    z.type = "перевод в группу";
    z.comment = "Прошу перевести в другую группу";
    z.data = newGroup;

    return z;
}