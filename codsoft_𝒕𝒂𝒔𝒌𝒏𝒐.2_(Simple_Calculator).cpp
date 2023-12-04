#include <iostream>
#include <cstdlib>
using namespace std;

class calculator
{
private:
    double a, b;

public:
    void set_values(double x, double y)
    {
        a = x;
        b = y;
    }

    double add()
    {
        return (a + b);
    }

    double sub()
    {
        return (a - b);
    }

    double mul()
    {
        return a * b;
    }

    double div()
    {
        if (b != 0)
        {
            return (a / b);
        }
        else
        {
            cout << "Division by zero is not allowed." << endl;
        }
    }
};

int main()
{
    char choice;
    do
    {
        double num1, num2;
        int oper;
        cout << "\t\t\t\t__________________________________\t\t\t\t" << endl;
        cout << "\t\t\t\t|                                |\t\t\t\t" << endl;
        cout << "\t\t\t\t|       SIMPLE  CALCULATOR       |\t\t\t\t" << endl;
        cout << "\t\t\t\t|________________________________|\t\t\t\t" << endl;
        cout<<endl;
        cout << "   Welcome to Simple Calculator! Press enter to continue...";
        cin.get();
        system("cls");
        cout << endl;
        cout << endl;
        cout << "Enter first number : " << endl;
        cin >> num1;
        cout << "Enter second number : " << endl;
        cin >> num2;
        cout << endl;
        cout << "Select operation:\n"
             << "[1] Addition \n[2] Subtraction \n[3] Multiplication \n[4] Division\n"
             << "Choose a number:" << endl;
        cin >> oper;

        calculator calc;
        calc.set_values(num1, num2);

        switch (oper)
        {
        case 1:
            cout << "Result = " << calc.add() << endl;
            break;

        case 2:
            cout << "Result = " << calc.sub() << endl;
            break;

        case 3:
            cout << "Result = " << calc.mul() << endl;
            break;

        case 4:
            cout << "Result = " << calc.div() << endl;
            break;

        default:
            cout << "Invalid selection"<<endl;
            break;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting the calculator program. Thank You!" << endl;

    return 0;
}
