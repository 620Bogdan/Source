#include <string>
#include <vector>
using namespace std;

class Student{ //Класс Student


private:

    string name;            //Имя
    string surname;         //Фамилия
    vector<string> debts;  //Долги!!!😭

public:

    Student();//Конструктор по умолчанию
    Student(const Student& other);//Конструктор копирования
    Student(string n, string s, vector<string> d);//Конструктор заполнения
    ~Student();//Деструктор

    Student& operator=(const Student& other);//оператор присваивание


    Student operator+(const Student& other);//Оператор +
    Student& operator-=(const Student& other);//Оператор -=
    Student operator/(const Student& other);//Оператор /

    string getName();//Геттер имени(ниже также)
    string getSurname();
    vector<string> getDebts();

    void printInfo();//Вывод всей нужной информации..

};