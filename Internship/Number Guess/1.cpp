#include<iostream>
#include <cstdlib>
#include <ctime>

int main() {
    using namespace std;
    srand(time(0));
    int randomNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high! Try again." <<endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." <<endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." <<endl;
        }
    }while (guess != randomNumber);

    return 0;
}