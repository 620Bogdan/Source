#include <iostream>
using namespace std;



// Поиск столбцов cодержащие 0:
int* Zero(int* m, int rows, int cols, int& count) {
    count = 0;
    int* result = nullptr;

    for (int j = 0; j < cols; j++) {
        bool hasZero = false;
        for (int i = 0; i < rows; i++) {
            if (m[i * cols + j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            // расширяем массив
            int* tmp = new int[count + 1];
            for (int k = 0; k < count; k++) tmp[k] = result[k];
            tmp[count] = j;

            delete[] result;
            result = tmp;
            count++;
        }
    }
    return result;
}

int main() {
    int rows = 2, cols = 2;

    // создаем матрицу 2x2
    int* m = new int[rows * cols];

    cout << "Введите 4 числа для матрицы 2x2:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> m[i * cols + j];

    int A, B, S, D;

    do {
        cout << "A (строк добавить): ";
        cin >> A;
        if (A < 0) cout << "Ошибка! A >= 0\n";
    } while (A < 0);

    do {
        cout << "B (столбцов добавить): ";
        cin >> B;
        if (B < 0) cout << "Ошибка! B >= 0\n";
    } while (B < 0);

    cout << "Введите S и D: ";
    cin >> S >> D;

    int oldRows = rows;
    int oldCols = cols;

    // новая матрица
    int newRows = rows + A;
    int newCols = cols + B;

    int* newM = new int[newRows * newCols];

    // копируем старые значения
    for (int i = 0; i < oldRows; i++)
        for (int j = 0; j < oldCols; j++)
            newM[i * newCols + j] = m[i * oldCols + j];

    delete[] m;

    // заполняем новые элементы
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            if (i >= oldRows || j >= oldCols)
                newM[i * newCols + j] = i * S + j * D;
        }
    }

    m = newM;
    rows = newRows;
    cols = newCols;

    // ищем столбцы с 0
    int count = 0;
    int* zeroCols = Zero(m, rows, cols, count);

    // удаляем столбцы с конца
    for (int z = count - 1; z >= 0; z--) {
        int removeCol = zeroCols[z];

        int* nm = new int[rows * (cols - 1)];

        for (int i = 0; i < rows; i++) {
            int idx = 0;
            for (int j = 0; j < cols; j++) {
                if (j == removeCol) continue;
                nm[i * (cols - 1) + idx] = m[i * cols + j];
                idx++;
            }
        }

        delete[] m;
        m = nm;
        cols--;
    }

    delete[] zeroCols;

    // вывод итоговой матрицы
    cout << "\nИтоговая матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << m[i * cols + j] << " ";
        cout << "\n";
    }

    delete[] m;
}
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