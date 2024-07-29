#include <iostream>
using namespace std;

int main()
{
    int firstNumber, secondNumber;
    float currentResult;
    int operation;
    char continueOperation;

    do
    {
        cout << "Enter first number: ";
        cin >> firstNumber;

        cout << "Enter second number: ";
        cin >> secondNumber;

        cout << "\nTo perform the below operation, enter the corresponding number\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cin >> operation;

        switch (operation)
        {
            case 1:
                currentResult = firstNumber + secondNumber;
                cout << "Answer: " << currentResult << endl;
                break;
            case 2:
                currentResult = firstNumber - secondNumber;
                cout << "Answer: " << currentResult << endl;
                break;
            case 3:
                currentResult = firstNumber * secondNumber;
                cout << "Answer: " << currentResult << endl;
                break;
            case 4:
                if (secondNumber != 0)
                {
                    currentResult = static_cast<float>(firstNumber) / secondNumber;
                    cout << "Answer: " << currentResult << endl;
                }
                else
                {
                    cout << "Can't divide by zero" << endl;
                }
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> continueOperation;

    } while (continueOperation == 'y' || continueOperation == 'Y');

    return 0;
}