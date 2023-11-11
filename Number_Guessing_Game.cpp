#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int random_num = rand() % 100 + 1;

    int user_input, attempts=0;
    char again;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have a number between 1 and 100. Can you guess what it is?" << endl;
    
while (true) {
        cout << "Enter your guess: ";
        cin >> user_input;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        attempts++;

        if (user_input < random_num) {
            cout << "Too low! Try again." << endl;
        } else if (user_input > random_num) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << user_input << " in " << attempts << " attempts." << endl;
            break;
        }
    }

    return 0;
}