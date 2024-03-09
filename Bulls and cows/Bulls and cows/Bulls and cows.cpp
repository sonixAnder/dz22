#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int checkBullsAndCows(string secretNumber, string guess, int index, int bulls, int cows)
{
    if (index == secretNumber.length())
    {
        cout << "Быков: " << bulls << ", коров: " << cows << endl;

        if (bulls == 4)
        {
            return true;
        }

        return false;
    }

    if (secretNumber[index] == guess[index])
    {
        return checkBullsAndCows(secretNumber, guess, index + 1, bulls + 1, cows);
    }

    for (int i = 0; i < secretNumber.length(); i++)
    {
        if (secretNumber[i] == guess[index])
        {
            return checkBullsAndCows(secretNumber, guess, index + 1, bulls, cows + 1);
        }
    }

    return checkBullsAndCows(secretNumber, guess, index + 1, bulls, cows);
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    string secretNumber = to_string(1000 + rand() % 9000);

    cout << "Добро пожаловать в игру 'Быки и коровы'!\n";
    cout << "Компьютер загадал четырёхзначное число. Попробуйте угадать его.\n";

    int attempts = 0;
    bool guessed = false;

    while (!guessed)
    {
        string guess;
        cout << "Введите вашу догадку: ";
        cin >> guess;

        if (guess.length() != 4)
        {
            cout << "Пожалуйста, введите четырёхзначное число.\n";
            continue;
        }

        attempts++;

        guessed = checkBullsAndCows(secretNumber, guess, 0, 0, 0);
    }

    cout << "Поздравляем! Вы угадали число. Количество попыток: " << attempts << endl;

    return 0;
}