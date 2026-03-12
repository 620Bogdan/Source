#pragma once


#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class Dekanat {

private:

    string address;
    vector<Student*> students;

public:

    Dekanat(string addr);
    ~Dekanat();

    Dekanat(const Dekanat&) = delete;

    void addStudent(Student* s);
    void removeStudent(Student* s);

    void printStudents();
};
