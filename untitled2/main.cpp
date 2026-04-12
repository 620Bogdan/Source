#include <iostream>
#include <vector>
#include "FileLoader.h"

int main() {

    // Загружаем людей из файла
    std::vector<Person*> people = loadFromFile("data.txt");

    std::cout << "===== Список =====\n";

    // Вывод всех объектов (полиморфизм)
    for (size_t i = 0; i < people.size(); i++) {
        std::cout << i + 1 << ". ";
        people[i]->print(); // вызывается нужная версия print()
    }

    // Выбор пользователя (имитация двойного клика)
    int choice;
    std::cout << "\nВыберите номер: ";
    std::cin >> choice;

    // Проверка корректности
    if (choice > 0 && choice <= people.size()) {

        std::cout << "\n=== Информация ===\n";

        // вывод полной информации
        std::cout << people[choice - 1]->getInfo() << std::endl;

        char action;
        std::cout << "\nПечать (p) / Отмена (c): ";
        std::cin >> action;

        // если "печать" — удаляем
        if (action == 'p') {
            delete people[choice - 1]; // удаляем объект
            people.erase(people.begin() + choice - 1); // убираем из списка
            std::cout << "Удалено.\n";
        }
    }

    // очищаем память
    clearPeople(people);

    return 0;
}
