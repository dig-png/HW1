#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Проверка совпадений
pair<int, int> checkGuess(const vector<int>& secret, const vector<int>& guess) {
    int correctPosition = 0;
    int correctNumber = 0;

    vector<bool> usedSecret(4, false), usedGuess(4, false);

    // Сравнение чисел на своих местах
    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            correctPosition++;
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    // Сравнение чисел, которые присутствуют, но не на своих местах
    for (int i = 0; i < 4; i++) {
        if (!usedGuess[i]) {
            for (int j = 0; j < 4; j++) {
                if (!usedSecret[j] && guess[i] == secret[j]) {
                    correctNumber++;
                    usedSecret[j] = true;
                    break;
                }
            }
        }
    }

    return {correctPosition, correctNumber};
}

int main() {
    vector<int> secret(4);
    vector<int> guess(4);

    cout << "Первый игрок, введите комбинацию из 4 чисел от 1 до 6: ";
    for (int i = 0; i < 4; i++) {
        cin >> secret[i];
        if (secret[i] < 1 || secret[i] > 6) {
            cout << "Числа должны быть от 1 до 6. Попробуйте снова." << endl;
            i--;
        }
    }

    system("clear"); // Очистка экрана для второго игрока

    cout << "Второй игрок, у вас есть 6 попыток, чтобы угадать комбинацию!" << endl;

    for (int attempt = 1; attempt <= 6; attempt++) {
        cout << "Попытка " << attempt << ": Введите вашу комбинацию: ";
        for (int i = 0; i < 4; i++) {
            cin >> guess[i];
            if (guess[i] < 1 || guess[i] > 6) {
                cout << "Числа должны быть от 1 до 6. Попробуйте снова." << endl;
                i--;
            }
        }

        auto [correctPosition, correctNumber] = checkGuess(secret, guess);
        cout << "На своих местах: " << correctPosition << ", присутствуют, но не на своих местах: " << correctNumber << endl;

        if (correctPosition == 4) {
            cout << "Поздравляем! Второй игрок угадал комбинацию!" << endl;
            return 0;
        }
    }

    cout << "К сожалению, попытки закончились. Первый игрок выиграл!" << endl;
    return 0;
}
