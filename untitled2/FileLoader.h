#pragma once

#include <vector>   // для vector
#include <string>   // строки
#include "Person.h"

// Функция загрузки данных из файла
std::vector<Person*> loadFromFile(const std::string& filename);

// Очистка памяти
void clearPeople(std::vector<Person*>& people);
