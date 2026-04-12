#pragma once

#include "Person.h"

// Наследник
class AmP : public Person {
private:
    std::string secondName; // второе имя

public:
    AmP(std::string f, std::string s, std::string l, Date d);

    void print() const override;
    std::string getInfo() const override;
};
