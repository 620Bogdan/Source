#pragma once // защита от повторного включения

#include <string>   // строки
#include "Date.h"   // используем структуру даты

// Абстрактный базовый класс
class Person {
protected:
    std::string firstName; // имя
    std::string lastName;  // фамилия
    Date birthDate;        // дата рождения

public:
    // Конструктор (инициализация полей)
    Person(std::string f, std::string l, Date d);

    // Виртуальный деструктор (ВАЖНО для полиморфизма)
    virtual ~Person();

    // Чисто виртуальная функция (обязательна для наследников)
    virtual void print() const = 0;

    // Получение строки с информацией
    virtual std::string getInfo() const = 0;
};
