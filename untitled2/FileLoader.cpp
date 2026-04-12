#include "FileLoader.h"
#include "RuP.h"
#include "AmP.h"
#include <fstream>   // работа с файлами
#include <sstream>   // разбор строки

// Загрузка людей из файла
std::vector<Person*> loadFromFile(const std::string& filename) {
    std::vector<Person*> people; // вектор указателей

    std::ifstream file(filename); // открываем файл

    std::string line;

    // читаем файл построчно
    while (getline(file, line)) {

        std::stringstream ss(line); // поток для разбора строки
        std::string token;

        std::vector<std::string> data;

        // разбиваем строку по запятой
        while (getline(ss, token, ',')) {
            data.push_back(token);
        }

        // защита от неправильных строк
        if (data.size() < 7) continue;

        // код типа (1 или 2)
        int code = std::stoi(data[0]);

        // создаём дату
        Date d;
        d.day = std::stoi(data[4]);
        d.month = std::stoi(data[5]);
        d.year = std::stoi(data[6]);

        // создаём объект нужного класса
        if (code == 1) {
            // RuP: Фамилия Имя Отчество
            people.push_back(new RuP(
                data[2], // имя
                data[1], // фамилия
                data[3], // отчество
                d
                ));
        }
        else if (code == 2) {
            // AmP: Имя ВтороеИмя Фамилия
            people.push_back(new AmP(
                data[1], // имя
                data[2], // второе имя
                data[3], // фамилия
                d
                ));
        }
    }

    return people; // возвращаем список
}

// Очистка памяти
void clearPeople(std::vector<Person*>& people) {
    for (auto p : people) // проходим по всем указателям
        delete p;         // удаляем объект

    people.clear();       // очищаем вектор
}
