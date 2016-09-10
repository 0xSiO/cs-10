/*
 * Lucas Street, 09/10
 * CS 10, Dave Harden
 * Assignment 3.3 - a3_3.cpp
 *
 * A simple calculator using two operands and one operator. A switch statement is used to handle the different
 * cases for the operator. If the user enters an unknown operator, the calculator returns 0 by default.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double operand1, operand2;
    char operation;

    cout << "Enter a number: ";
    cin >> operand1;
    cout << "Enter an operation: ";
    cin >> operation;
    cout << "Enter a number: ";
    cin >> operand2;

    double result;

    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case 'x':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            result = 0;
            break;
    }

    cout << fixed << setprecision(2) << "Result: " << result << endl;

    return 0;
}
// Output
/*
Enter a number: 5
Enter an operation: /
Enter a number: 6
Result: 0.83
*/
