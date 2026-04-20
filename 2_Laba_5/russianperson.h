#ifndef RUSSIANPERSON_H
#define RUSSIANPERSON_H
#include "person.h"



class RussianPerson : public Person {
private:
    QString patronymic_; // Отчество

    bool isValidPatronymic(const QString& s) const { // Проверка корректности отчества
        if (s.isEmpty()) return true; // отчество может быть пустым
        QRegularExpression re("^[А-ЯЁ][а-яё]{0,49}$");
        return re.match(s).hasMatch();
    }

public:
    RussianPerson(); // конструктор по умолчанию
     // Конструктор с параметрами
    RussianPerson(const QString& lastName_, const QString& firstName_,
                  const QString& patronymic_, const Date& birthDate_);

    QString getFullName() const override;
    // Создание формы пропуска
    void craft(QWidget* parent_ = nullptr) override;
    // Установка отчества с проверкой

    bool setPatronymic(const QString& patr_);
    // Геттер для отчества
    QString getPatronymic() const { return patronymic_; }
};

#endif
