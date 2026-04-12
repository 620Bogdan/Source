#include "Person.h" // подключаем заголовок

// Конструктор — присваиваем значения полям
Person::Person(std::string f, std::string l, Date d)
    : firstName(f), lastName(l), birthDate(d) {}

// Деструктор (пустой, но нужен для корректного удаления через указатель)
Person::~Person() {}
