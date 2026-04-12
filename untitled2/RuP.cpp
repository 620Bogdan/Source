#include "RuP.h"
#include <iostream> // для cout

// Конструктор вызывает родительский + сохраняет отчество
RuP::RuP(std::string f, std::string l, std::string m, Date d)
    : Person(f, l, d), middleName(m) {}

// Вывод в формате: Фамилия Имя Отчество
void RuP::print() const {
    std::cout << lastName << " " << firstName;

    // если отчество есть — выводим
    if (!middleName.empty())
        std::cout << " " << middleName;

    // вывод даты
    std::cout << " - " << birthDate.toString() << std::endl;
}

// Возвращаем строку
std::string RuP::getInfo() const {
    return lastName + " " + firstName + " " + middleName +
           " " + birthDate.toString();
}
