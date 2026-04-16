#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>

class Person {
public:
    QString lastName;
    QString firstName;
    QDate birthDate;

    virtual QString toString() const = 0;
    virtual QString craft() const = 0;

    virtual ~Person() {}
};

#endif // PERSON_H
