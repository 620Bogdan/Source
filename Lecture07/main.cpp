#include <iostream>
using namespace std;

////////////////////////////////////////////////////
int* Poiskzero(int** matrica, int column, int line, int* zeros) {
    int* zeroli = (int*)malloc(line * sizeof(int)); // Запрашиваем память для нулевых столбцов
    *zeros = 0;// Счетчик найденных столбцов, содержащих нули
    //Проверка на наличие нулей в матрице
    for (int j = 0; j < line; j++) {
        for (int i = 0; i < column; i++) {
            if (matrica[i][j] == 0) {
                zeroli[*zeros] = j; // Сохраняем номер столбца
                (*zeros)++;
                break;
            }
        }
    }
    // Уменьшение матрицы
    if (*zeros > 0) {
        zeroli = (int*)realloc(zeroli, (*zeros) * sizeof(int));
    }
    // Освобождаем память
    else {
        free(zeroli);
        zeroli = nullptr;
    }
    return zeroli;
}
//////////////////////////////////////////////////////////
void NoZero(int**& matrica, int columns, int lines, int* zeroli, int zeros, int& n) {
    // Если нет нклей, то ничего не делаем
    if (zeros == 0) {
        return;
    }
    // Сдвигаем столбцы после удаления 0
    n = lines - zeros;
    for (int i = 0; i < zeros; i++) {
        int x = zeroli[i] - i;
        for (int line = x; line < lines - 1; line++) {
            for (int column = 0; column < columns; column++) {
                matrica[column][line] = matrica[column][line + 1];
            }
        }
    }
    // Уменьшаем строки
    for (int x = 0; x < columns;  x++) {
        matrica[x] = (int*)realloc(matrica[x], n * sizeof(int));
    }

}
/////////////////////////////////////////////////////
int main() {
    //Создаем матрицу по условию
    int** matrica = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; i++) {
        matrica[i] = (int*)malloc(2 * sizeof(int));
    }
    ////////////////////////////////////////////////
    //Вводим элементы матрицы, a и b > 0. Если условие не выполняется, то мы просим повторить ввод еще раз, только на этот раз правильно
    int a;
    int b;
    int c;
    int d;
    do {
        cout << "введите элемент матрицы [0][0]: ";
        cin >> a;
        if (a < 0){
            cout << "Кажется вы ввели отрицательное число, попробуйте заного, только в этот раз введите положительное" <<endl;
        }
    } while (a < 0);
    do {
        cout << "введите элемент матрицы [0][1]: ";
        cin >> b;
        if (b < 0) {
            cout << "Кажется вы ввели отрицательное число, попробуйте заного, только в этот раз введите положительное" << endl;
        }
    } while (b < 0);
    cout << "введите элемент матрицы [1][0]: ";
    cin >> c;
    cout << "введите элемент матрицы [1][1]: ";
    cin >> d;
    ///////////////////////////////////////////////
    // Присваиваем значения матрице
    matrica[0][0] = a;
    matrica[0][1] = b;
    matrica[1][0] = c;
    matrica[1][1] = d;
    //////////////////////////////////////////////
    // Увеличиваем её по в зависимости от  а и b
    int down = 2 + a;
    int right = 2 + b;
/////////////////////////////////////////////////
    //Увеличиваем строки и столбцы
    matrica = (int**)realloc(matrica, down * sizeof(int*));
    for (int i = 0; i < down; i++) {
        if (i < 2) {
            matrica[i] = (int*)realloc(matrica[i], right * sizeof(int));
        }
        else {
            matrica[i] = (int*)malloc(right * sizeof(int));
        }
    }
 ////////////////////////////////////////////////////////
    // Заполнение новых ячеек матрицы
    for (int i = 0; i < down; i++) {
        for (int j = 0; j < right; j++) {
            if (i < 2 && j < 2) {
                continue;
            }
            matrica[i][j] = (i - 1) * c + (j - 1) * d;//Формула из условия, для заполнения новых ячеек
        }
    }
    //////////////////////////////////////////////////////
    //Показываем матрицу, которую мы вводили в начале
    cout << "Начальная матрица(до преобразований): " <<endl;
    for (int i = 0; i < down; i++) {
        for (int j = 0; j < right; j++) {
            cout << matrica[i][j] << "  ";
        }
        cout << endl;
    }
///////////////////////////////////////////////////////////
    //Поиск нулей в новой матрице, удаление их, если они есть.
    int zeros;
    int* zeroli = Poiskzero(matrica, down, right, &zeros);
    if (zeros > 0) {
        // Cтолбцы с нулями в конец
        int n;
        NoZero(matrica, down, right, zeroli, zeros, n);
        cout << "Готовая матрица (после удаления нулей): " <<endl;
        for (int i = 0; i < down; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrica[i][j] << "  ";
            }
            cout <<endl;
        }
    }
    else {
        cout << "В матрице нет столбцов с нулями, удалять нечего!!!" <<endl;
    }
///////////////////////////////////////////////
    //Освобождение ненужной памяти.
    if (zeroli != nullptr) {
        free(zeroli);
    }
    for (int i = 0; i < down; i++){
        free(matrica[i]);
    }
    free(matrica);
}
////////////////////////////////////////////
/*
 // ПУНКТ 2
int main(){
    double a, b;
    cout << "Введите a: ";
    cin >> a;
    cout << "А теперь введите b: ";
    cin >> b;

    double* pa = new double(a);
    double* pb = new double(b);

    *pa *= 3;


    // Замена a и b:
    double zam = *pa;
    *pa = *pb;
    *pb = zam;
    
    cout << "Результат действий: a = " << *pa << "  b = " << *pb << "\n";
    // Удаляем ненужные переменные:
    delete pa;
    delete pb;

    return 0;
}
*/