#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для инициализации квадратной матрицы типа int
void initializeMatrix(int matrix[][3], int size)
{
    cout << "Введите элементы матрицы типа int:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// Функция для инициализации квадратной матрицы типа double
void initializeMatrix(double matrix[][3], int size)
{
    cout << "Введите элементы матрицы типа double:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// Функция для инициализации квадратной матрицы типа char
void initializeMatrix(char matrix[][3], int size)
{
    cout << "Введите элементы матрицы типа char:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// Функция для вывода матрицы на экран
template <typename T>
void printMatrix(const T matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// Функция для определения максимального и минимального элемента на главной диагонали матрицы
template <typename T>
void findMinMaxOnDiagonal(const T matrix[][3], int size)
{
    T max = matrix[0][0];
    T min = matrix[0][0];

    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] > max)
        {
            max = matrix[i][i];
        }
        if (matrix[i][i] < min)
        {
            min = matrix[i][i];
        }
    }

    cout << "Максимальный элемент на главной диагонали: " << max << endl;
    cout << "Минимальный элемент на главной диагонали: " << min << endl;
}

// Функция для сортировки элементов по возрастанию отдельно для каждой строки матрицы
template <typename T>
void sortRows(T matrix[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        vector<T> row(matrix[i], matrix[i] + size);
        sort(row.begin(), row.end());
        copy(row.begin(), row.end(), matrix[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int size = 3;
    int intMatrix[size][3];
    double doubleMatrix[size][3];
    char charMatrix[size][3];

    initializeMatrix(intMatrix, size);
    printMatrix(intMatrix, size);
    findMinMaxOnDiagonal(intMatrix, size);
    sortRows(intMatrix, size);

    initializeMatrix(doubleMatrix, size);
    printMatrix(doubleMatrix, size);
    findMinMaxOnDiagonal(doubleMatrix, size);
    sortRows(doubleMatrix, size);

    initializeMatrix(charMatrix, size);
    printMatrix(charMatrix, size);
    findMinMaxOnDiagonal(charMatrix, size);
    sortRows(charMatrix, size);

    return 0;
}