#pragma once

#include "Person.h" // наследуемся от Person

// Класс-наследник
class RuP : public Person {
private:
    std::string middleName; // отчество

public:
    // Конструктор
    RuP(std::string f, std::string l, std::string m, Date d);

    // Переопределение виртуальных функций
    void print() const override;
    std::string getInfo() const override;
};
