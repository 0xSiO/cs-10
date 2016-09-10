/*
 * Lucas Street, 09/10
 * CS 10, Dave Harden
 * Assignment 3.1 - a3_1.cpp
 *
 * Calculates the area of a square or triangle depending on the input given. Uses an if-else structure
 * to make this choice.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char type;
    cout << "Enter the type of figure (s or t): ";
    cin >> type;

    if (type == 's') {
        double side_length;
        cout << "Enter the length of a side: ";
        cin >> side_length;
        cout << fixed << setprecision(1) << "The area is " << (side_length * side_length) << endl;
    } else if (type == 't') {
        double base, height;
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the height: ";
        cin >> height;
        cout << fixed << setprecision(1) << "The area is " << (0.5 * base * height) << endl;
    } else {
        cout << "Invalid type." << endl;
    }

    return 0;
}
// Output
/*
Enter the type of figure (s or t): s
Enter the length of a side: 8.9
The area is 79.2

Enter the type of figure (s or t): t
Enter the base: 2.3
Enter the height: 8
The area is 9.2
*/
