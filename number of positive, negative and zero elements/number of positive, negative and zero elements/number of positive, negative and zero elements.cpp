#include <iostream>
using namespace std;

// Функция для определения количества положительных, отрицательных и нулевых элементов массива
void countNumbers(const int arr[], int size) 
{
    int positive = 0, negative = 0, zero = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] > 0) 
        {
            positive++;
        }
        else if (arr[i] < 0) 
        {
            negative++;
        }
        else 
        {
            zero++;
        }
    }

    cout << "Количество положительных элементов: " << positive << endl;
    cout << "Количество отрицательных элементов: " << negative << endl;
    cout << "Количество нулевых элементов: " << zero << endl;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int arr[] = { -2, 0, 5, -7, 0, 3, 1, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    countNumbers(arr, size);

    return 0;
}