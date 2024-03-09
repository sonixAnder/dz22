#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else 
    {
        return gcd(b, a % b);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int num1, num2;
    cout << "Введите два целых числа: ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);

    cout << "Наибольший общий делитель чисел " << num1 << " и " << num2 << " равен " << result << std::endl;

    return 0;
}