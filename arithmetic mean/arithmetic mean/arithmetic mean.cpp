#include <iostream>
using namespace std;

// Функция для вычисления среднего арифметического элементов массива
double average(const int arr[], int size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);

    double avg = average(arr, size);

    cout << "Среднее арифметическое элементов массива: " << avg << endl;

    return 0;
}