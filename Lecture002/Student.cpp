#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){  //___Конструктор по умолчанию___//
    name = "";   //принимает имя
    surname = "";//принимает Фамилию
}

Student::Student(const Student& other) {  //___Конструктор копирования___//
    name = other.name;       //Копирует имя
    surname = other.surname;
    debts = other.debts;     // Копирует долги
}

Student::Student(string n, string s, vector<string> d){//___Конструктор полного заполнения___//
    name = n;    //Присваение имени
    surname = s;
    debts = d;
}

Student::~Student(){//____Деструктор____//
    debts.clear();  //Очищение долглв
    cout << "Деструктор Student вызван" << endl; //Вызов деконструктора
}

Student& Student::operator=(const Student& other){// Перегрузка оператора
    if (this != &other){// проверка
        name = other.name; //Копирование имени
        surname = other.surname;//Фамилии
        debts = other.debts;//Долгов
    }
    return *this; //Возращаем результат
}
Student Student::operator+(const Student& other){
    Student result;
    result.name = name + " и " + other.name;
    result.surname = surname + " и " + other.surname;

    // Добавляем долги первого
    for (int i = 0; i < debts.size(); i++){
        bool found = false;

        for (int j = 0; j < result.debts.size(); j++){
            if (result.debts[j] == debts[i]){
                found = true;
                break;
            }
        }

        if (!found)
            result.debts.push_back(debts[i]);
    }

    // Добавляем долги второго без повторов
    for (int i = 0; i < other.debts.size(); i++){
        bool found = false;

        for (int j = 0; j < result.debts.size(); j++){
            if (result.debts[j] == other.debts[i]){
                found = true;
                break;
            }
        }
        if (!found)
            result.debts.push_back(other.debts[i]);
    }
    return result;
}

/*Student Student::operator+(const Student& other) { //___Оператор +___//
    Student result;//Создание нового объекта
    result.name = name + " и " + other.name;  //Имя
    result.surname = surname + " и " + other.surname; //Фам.
    result.debts = debts; //Долги первого, копируем

    for (int i = 0; i < other.debts.size(); i++){
        string d = other.debts[i];
        bool found = false; //Флаг на наличие долгов 

        for (int j = 0; j < result.debts.size(); j++){//Повторы
            if (result.debts[j] == d)//Нашли, ставим метку
                found = true;
        }

        if (!found)
            result.debts.push_back(d);// Нет, добавляем
    }

    return result;//возвращение рез-та
}*/

Student& Student::operator-=(const Student& other){

    for (int i = 0; i < other.debts.size(); i++){

        for (int j = 0; j < debts.size(); ){

            if (debts[j] == other.debts[i]){
                debts.erase(debts.begin() + j);
            }
            else{
                j++;
            }
        }
    }
    name = name + " без " + other.name;
    surname = surname + " без " + other.surname;
    return *this;
}

/*Student Student::operator-=(const Student& other) {   //___Оператор -=___//
    Student result = *this; //Копирует объект на данный момент(текущий)

    for (int i = 0; i < other.debts.size(); i++){ //Проверка по долгам бездельника
        string d = other.debts[i];

        for (int j = 0; j < result.debts.size(); j++){
            if (result.debts[j] == d) {
                result.debts.erase(result.debts.begin() + j); //Удаление, при совпадении долга
                break;
            }
        }
    }

    result.name = name + " без " + other.name;
    result.surname = surname + " без " + other.surname;

    return result; // вывод результата
}*/

Student Student::operator/(const Student& other){  //___Оператор /___//
    Student result;   //Создание нового объекта
    result.name = name + " и " + other.name;  //Имя
    result.surname = surname + " и " + other.surname; //Фам.

    for (int i = 0; i < debts.size(); i++){ //Долги 1-го
        string d = debts[i];

        for (int j = 0; j < other.debts.size(); j++){ //Долги 2-го
            if (d == other.debts[j]){
                result.debts.push_back(d); //Добавляем, если удовл. условию
            }
        }
    }

    return result;  //Возвращает результат
}

string Student::getName(){  //Возвращает имя
    return name;
}
string Student::getSurname(){ //Фамилию
    return surname;
}
vector<string> Student::getDebts(){  //Долги
    return debts;
}

void Student::printInfo(){   //Вывод информации
    cout << "Имя: " << name << endl;
    cout << "Фамилия: " << surname << endl;
    cout << "Долги: ";

    for (int i = 0; i < debts.size(); i++)  //Перебор долгов
        cout << debts[i] << " ";

    cout << endl;
}