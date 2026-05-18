#include <iostream>   // ввод-вывод (cout, cin)
#include <fstream>    // работа с файлами
#include <cstring>    // функции работы с C-строками (strlen, strcpy, strcmp)
#include <cctype>     // функции проверки символов (не обяз. но оставлено)

using namespace std;  // чтобы не писать std::

// -----------------------------
// максимальные размеры массивов
// -----------------------------
const int MAX_TEXT = 10000; // максимум текста (не всегда используется)
const int MAX_WORDS = 1000; // максимум слов
const int MAX_LEN = 100;    // максимум длины слова

// -----------------------------
// проверка: русская буква
// -----------------------------
bool isRussianLetter(char c)
{
    unsigned char uc = (unsigned char)c; // перевод в unsigned для кодов 128–255

    // диапазон кириллицы в Windows-1251
    return (uc >= 192 && uc <= 255) || uc == 168 || uc == 184;
}

// -----------------------------
// проверка английской буквы
// -----------------------------
bool isEnglishLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||   // заглавные
        (c >= 'a' && c <= 'z');     // строчные
}

// -----------------------------
// общий признак буквы
// -----------------------------
bool isLetter(char c)
{
    return isRussianLetter(c) || isEnglishLetter(c);
}

// -----------------------------
// проверка цифры
// -----------------------------
bool isDigitChar(char c)
{
    return c >= '0' && c <= '9';
}

// -----------------------------
// проверка гласной буквы (русские)
// -----------------------------
bool isVowel(char c)
{
    char vowels[] =
    {
        'а','е','ё','и','о','у',
        'ъ','ы','ь','э','ю','я',
        'А','Е','Ё','И','О','У',
        'Ъ','Ы','Ь','Э','Ю','Я'
    };

    // перебор массива гласных
    for (int i = 0; i < 24; i++)
    {
        if (c == vowels[i]) // если совпало
            return true;    // это гласная
    }

    return false; // иначе нет
}

// -----------------------------
// перевод в нижний регистр
// -----------------------------
char toLowerRus(char c)
{
    if (c >= 'A' && c <= 'Z') // английские заглавные
        return c + 32;        // перевод в строчные

    // русские заглавные Windows-1251
    if ((unsigned char)c >= 192 && (unsigned char)c <= 223)
        return c + 32;

    if ((unsigned char)c == 168) // Ё → ё
        return 184;

    return c; // если не буква — вернуть как есть
}

// -----------------------------
// перевод в верхний регистр
// -----------------------------
char toUpperRus(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;

    if ((unsigned char)c >= 224 && (unsigned char)c <= 255)
        return c - 32;

    if ((unsigned char)c == 184)
        return 168;

    return c;
}

// =============================
// ПУНКТ 0 — таблица кодов
// =============================
void task0()
{
    cout << "=== Английский алфавит ===\n";

    // английские заглавные буквы
    for (char c = 'A'; c <= 'Z'; c++)
        cout << c << " : " << (int)c << endl;

    // английские строчные
    for (char c = 'a'; c <= 'z'; c++)
        cout << c << " : " << (int)c << endl;

    cout << "\n=== Цифры ===\n";

    // цифры 0–9
    for (char c = '0'; c <= '9'; c++)
        cout << c << " : " << (int)c << endl;

    cout << "\n=== Знаки ===\n";

    // набор знаков пунктуации
    char signs[] = {
        '.', ',', '!', '?',
        ':', ';', '-', '(', ')',
        '[', ']', '{', '}',
        '"', '\''
    };

    // вывод кодов знаков
    for (int i = 0; i < 14; i++)
        cout << signs[i] << " : " << (int)signs[i] << endl;

    cout << "\n=== Русские буквы ===\n";

    // диапазон Windows-1251 кириллицы
    for (int i = 192; i <= 255; i++)
    {
        char c = (char)i;
        cout << c << " : " << i << endl;
    }

    // отдельно Ё и ё
    cout << "Ё : 168\n";
    cout << "ё : 184\n";
}

// =============================
// ПУНКТ 1 — гласные в верхний регистр
// =============================
void task1()
{
    char str[101]; // строка до 100 символов

    cout << "Введите строку:\n";
    cin.getline(str, 101); // ввод строки

    // проход по символам строки
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isVowel(str[i])) // если гласная
        {
            str[i] = toUpperRus(str[i]); // сделать заглавной
        }
    }

    cout << "Результат:\n";
    cout << str << endl;
}

// -----------------------------
// проверка: слово заканчивается на букву
// -----------------------------
bool endsWith(char word[], char letter)
{
    int len = strlen(word); // длина слова

    if (len == 0)
        return false;

    // сравнение последнего символа
    return toLowerRus(word[len - 1]) ==
        toLowerRus(letter);
}

// -----------------------------
// проверка уникальности слова
// -----------------------------
bool isUnique(char words[][MAX_LEN], int count, char word[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(words[i], word) == 0)
            return false; // уже есть
    }

    return true;
}

// -----------------------------
// сортировка по длине (убывание)
// -----------------------------
void sortWords(char words[][MAX_LEN], int count)
{
    char temp[MAX_LEN]; // временный буфер

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            // если первое слово короче второго
            if (strlen(words[i]) < strlen(words[j]))
            {
                // меняем местами
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

// =============================
// ПУНКТ 2 — обработка файла
// =============================
void task2()
{
    ifstream finText("text.txt");   // входной текст
    ifstream finInput("input.txt"); // вход: N и буква
    ofstream fout("result.txt");    // выход

    if (!finText || !finInput)
    {
        cout << "Ошибка открытия файлов\n";
        return;
    }

    int N;        // сколько слов нужно
    char letter;  // заданная буква

    finInput >> N;      // читаем N
    finInput >> letter; // читаем букву

    char words[MAX_WORDS][MAX_LEN]; // массив слов
    int count = 0;                   // количество найденных

    char word[MAX_LEN]; // текущее слово
    int pos = 0;        // позиция в слове

    char c;

    // чтение файла посимвольно
    while (finText.get(c))
    {
        // если буква, цифра или дефис — формируем слово
        if (isLetter(c) || isDigitChar(c) || c == '-')
        {
            word[pos++] = toLowerRus(c);
        }
        else
        {
            // конец слова
            if (pos > 0)
            {
                word[pos] = '\0'; // завершение строки

                int len = strlen(word);

                // проверка последнего символа
                if (len > 0 && isLetter(word[len - 1]))
                {
                    // проверка: оканчивается на букву
                    if (endsWith(word, letter))
                    {
                        // проверка уникальности
                        if (isUnique(words, count, word))
                        {
                            strcpy(words[count], word);
                            count++;
                        }
                    }
                }

                pos = 0; // сброс слова
            }
        }
    }

    // сортировка по длине (возрастание → потом можно сортировать обратно)
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strlen(words[i]) > strlen(words[j]))
            {
                char temp[MAX_LEN];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    // берём N слов
    int resultCount = (N < count) ? N : count;

    // финальная сортировка (по убыванию длины)
    sortWords(words, resultCount);

    // запись результата
    for (int i = 0; i < resultCount; i++)
    {
        fout << words[i] << endl;
    }

    finText.close();
    finInput.close();
    fout.close();

    cout << "Готово: результат в result.txt\n";
}

// =============================
// MAIN — меню программы
// =============================
int main()
{
    setlocale(LC_ALL, "Russian"); // локаль (не всегда работает везде)

    int choice;

    cout << "0 - Таблица кодов\n";
    cout << "1 - Гласные в верхний регистр\n";
    cout << "2 - Поиск слов в файле\n";

    cin >> choice; // выбор пункта
    cin.ignore();   // очистка буфера

    if (choice == 0) task0();
    else if (choice == 1) task1();
    else if (choice == 2) task2();
    else cout << "Ошибка выбора\n";

    return 0;
}