#pragma once // защита от двойного подключения файла

#include <string> // для использования std::string

// Структура для хранения даты
struct Date {
    int day;   // день
    int month; // месяц
    int year;  // год

    // Метод для преобразования даты в строку
    std::string toString() const {
        // добавляем 0 если день < 10 (например 01)
        std::string d = (day < 10 ? "0" : "") + std::to_string(day);

        // добавляем 0 если месяц < 10
        std::string m = (month < 10 ? "0" : "") + std::to_string(month);

        // возвращаем строку в формате дд.мм.гггг
        return d + "." + m + "." + std::to_string(year);
    }
};
