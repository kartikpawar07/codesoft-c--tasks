#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator
    int numberToGuess = rand() % 100 + 1;  // Random number between 1 and 100
    int userGuess;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number correctly!" << endl;
        }
    } while (userGuess != numberToGuess);

    return 0;
}