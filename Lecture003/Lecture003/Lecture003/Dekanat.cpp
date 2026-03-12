#include "Dekanat.hpp"
#include <iostream>

using namespace std;

Dekanat::Dekanat(string addr) {
    address = addr;
}

Dekanat::~Dekanat() {
    students.clear();
}

void Dekanat::addStudent(Student* s) {

    students.push_back(s);

}

void Dekanat::removeStudent(Student* s) {

    for (int i = 0; i < students.size(); i++) {

        if (students[i] == s) {
            students.erase(students.begin() + i);
            break;
        }
    }

}

void Dekanat::printStudents() {

    cout << "Students in dekanat:" << endl;

    for (int i = 0; i < students.size(); i++) {

        students[i]->printInfo();
        cout << endl;

    }
}