#include "AmP.h"
#include <iostream>

// Конструктор
AmP::AmP(std::string f, std::string s, std::string l, Date d)
    : Person(f, l, d), secondName(s) {}

// Формат: Имя ВтороеИмя Фамилия
void AmP::print() const {
    std::cout << firstName;

    // если второе имя есть
    if (!secondName.empty())
        std::cout << " " << secondName;

    std::cout << " " << lastName
              << " - " << birthDate.toString() << std::endl;
}

// Возвращаем строку
std::string AmP::getInfo() const {
    return firstName + " " + secondName + " " + lastName +
           " " + birthDate.toString();
}
