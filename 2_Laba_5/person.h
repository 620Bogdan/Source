#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QWidget>
#include <QRegularExpression>
#include <QDebug>
#include "date.h"



class Person {
protected:
    QString firstName_; // Имя
    QString lastName_; // Фамилия
    Date birthDate_;// Дата рождения

    DateFormat format_ = DateFormat::Russian; // Формат вывода даты (по умолчанию русский)


    bool isValidName(const QString& s) const {   // Проверка корректности имени (допустимы русские или английские буквы, первая заглавная)
        if (s.isEmpty()) return false;

        QRegularExpression reRus("^[А-ЯЁ][а-яё]{0,49}$");
        QRegularExpression reEng("^[A-Z][a-z]{0,49}$");

        return reRus.match(s).hasMatch() || reEng.match(s).hasMatch();
    }

public:
    Person() : birthDate_() {}
    virtual ~Person() {} //деструктор

    void setFormat(DateFormat f) { format_ = f; } // Установка формата даты для вывода

    virtual QString getFullName() const {  //Метод получения полного имени
        return QString("%1 %2").arg(lastName_).arg(firstName_);
    }

    virtual void craft(QWidget* parent_ = nullptr) = 0;

    virtual QString getFormattedBirthDate() const { // Получение отформатированной даты рождения
        return birthDate_.toString(format_);
    }
    // Установка даты рождения
    void setBirthDate(const Date& date_) { birthDate_ = date_; }

      // Установка имени с проверкой
    bool setFirstName(const QString& name_) {
        if (isValidName(name_)) {
            firstName_ = name_;
            return true;
        }
        return false;
    }

    // Установка фамилии с проверкой
    bool setLastName(const QString& name_) {
        if (isValidName(name_)) {
            lastName_ = name_;
            return true;
        }
        return false;
    }
};

#endif
