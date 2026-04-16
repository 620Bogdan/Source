#ifndef RUP_H
#define RUP_H

#include "person.h"

class RuP : public Person {
public:
    QString patronymic;

    QString toString() const override {
        return lastName + " " + firstName + " " + patronymic + " " +
               birthDate.toString("dd.MM.yyyy");
    }

    QString craft() const override {
        return "Фамилия: " + lastName +
               "\nИмя: " + firstName +
               "\nОтчество: " + patronymic +
               "\n" + birthDate.toString("dd.MM.yyyy");
    }
};

#endif // RUP_H
