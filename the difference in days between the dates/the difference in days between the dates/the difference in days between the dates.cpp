#include <iostream>
using namespace std;

//определение, является ли год високосным
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//вычисление разности в днях между двумя датами
int differenceInDays(int day1, int month1, int year1, int day2, int month2, int year2)
{
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = 0;

    // Добавляем дни за полные года между датами
    for (int year = year1 + 1; year < year2; year++)
    {
        days += isLeapYear(year) ? 366 : 365;
    }

    // Добавляем дни до конца года для первой даты
    for (int month = month1 + 1; month <= 12; month++)
    {
        days += daysInMonth[month];
        if (month == 2 && isLeapYear(year1))
        {
            days++;
        }
    }
    days += daysInMonth[month1] - day1;

    // Добавляем дни с начала года для второй даты
    for (int month = 1; month < month2; month++)
    {
        days += daysInMonth[month];
        if (month == 2 && isLeapYear(year2))
        {
            days++;
        }
    }
    days += day2;

    return days;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    int day1 = 5, month1 = 3, year1 = 2022;
    int day2 = 15, month2 = 3, year2 = 2022;

    int daysDifference = differenceInDays(day1, month1, year1, day2, month2, year2);

    cout << "Разность в днях между " << day1 << "." << month1 << "." << year1 << " и "
        << day2 << "." << month2 << "." << year2 << " составляет " << daysDifference << " дней." << endl;

    return 0;
}