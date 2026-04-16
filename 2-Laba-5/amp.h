#ifndef AMP_H
#define AMP_H

#include "person.h"

class AmP : public Person {
public:
    QString secondName;

    QString toString() const override {
        return firstName + " " + secondName + " " + lastName + " " +
               birthDate.toString("dd.MM.yyyy");
    }

    QString craft() const override {
        return "Name: " + firstName +
               "\nSecond name: " + secondName +
               "\nLast name: " + lastName +
               "\n" + birthDate.toString("MM-dd-yyyy");
    }
};

#endif // AMP_H
