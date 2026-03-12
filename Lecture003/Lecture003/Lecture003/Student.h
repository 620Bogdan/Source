#pragma once


#include <string>
#include <vector>

using namespace std;

struct Zayavlenie {
    string name;
    string surname;
    string type;
    string comment;
    int data;
};

class Student {

private:

    string name;
    string surname;
    string direction;
    int course;
    int group;
    int variant;
    vector<string> debts;

public:

    Student();
    Student(string n, string s, string dir, int c, int g, int v, vector<string> d);
    Student(const Student& other);
    ~Student();

    Student& operator=(const Student& other);

    Student operator+(const Student& other);
    Student& operator-=(const Student& other);
    Student operator/(const Student& other);

    string getName();
    string getSurname();
    int getCourse();
    int getGroup();

    void printInfo();

    Zayavlenie nextCourse();
    Zayavlenie changeGroup(int newGroup);
};
