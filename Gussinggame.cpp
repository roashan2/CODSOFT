
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void provideClue(int actualNumber, int userGuess, int attemptCount);

int main() {
    int userGuess = 0, attemptCount = 0;
    srand(time(0));
    int actualNumber = rand() % 100 + 1;
     

    while (userGuess != actualNumber) {
        cout << "Enter your guessing number: ";
        cin >> userGuess;

        if (userGuess != actualNumber) {
            provideClue(actualNumber, userGuess, attemptCount);
            attemptCount++;
        }
    }

    if (userGuess == actualNumber) {
        cout << "\n🎉 GUESSING MATCHED WITH ORIGINAL VALUE ✅";
    }

    return 0;
}

void provideClue(int actualNumber, int userGuess, int attemptCount) {
    int difference;
    float rem;

    userGuess > actualNumber ? cout << "Your guessing is too high" : cout << "Your guessing is too low";
    cout << "\n";

    if (attemptCount == 1) {
        rem = userGuess / 10;
        if (rem != 0) {
            cout << "Clue 🧩: [It is a double-digit number]" << endl;
        } else {
            cout << "Clue 🧩: [It is a single-digit number]" << endl;
        }
    }

    if ((actualNumber % 2 == 0) && (attemptCount >= 2)) {
        cout << "Clue 🧩: [The number is a multiple of two]" << endl;
    } else if ((actualNumber % 2 != 0) && (attemptCount >= 2)) {
        cout << "Clue 🧩: [The number is odd]" << endl;
    }

    if ((attemptCount >= 3) && (actualNumber % 2 == 0) && (actualNumber <= 50)) {
        cout << "Clue 🧩: [The number is between 1 and 50 and a multiple of two]" << endl;
    } else if ((attemptCount >= 3) && (actualNumber % 2 != 0) && (actualNumber <= 50)) {
        cout << "Clue 🧩: [The number is between 1 and 50 and odd]" << endl;
    } else if ((attemptCount >= 3) && (actualNumber % 2 == 0) && (actualNumber >= 50)) {
        cout << "Clue 🧩: [The number is between 50 and 100 and a multiple of two]" << endl;
    } else if ((attemptCount >= 3) && (actualNumber % 2 != 0) && (actualNumber >= 50)) {
        cout << "Clue 🧩: [The number is between 50 and 100 and odd]" << endl;
    }

    if (attemptCount >= 5) {
        difference = actualNumber - userGuess;
        cout << "Clue 🧩: [Your guess is off by " << abs(difference) << " digits]" << endl;
    }
}
