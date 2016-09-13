/*
 * Lucas Street, 09/13
 * CS 10, Dave Harden
 * Assignment 4.2 - a4_2.cpp
 *
 * Converts pounds to ounces, except this time the program continues using a value-based loop where the user
 * enters a negative number to exit.
 */

#include <iostream>

using namespace std;

int main() {
    int pounds, ounces;

    cout << "enter pounds (negative number to exit): ";
    cin >> pounds;

    while (pounds > 0) {
        ounces = pounds * 16;

        cout << pounds << " pounds is " << ounces << " ounces." << endl;

        cout << "enter pounds (negative number to exit): ";
        cin >> pounds;
    }

    return 0;
}
// Output
/*
enter pounds (negative number to exit): 10
10 pounds is 160 ounces.
enter pounds (negative number to exit): 4
4 pounds is 64 ounces.
enter pounds (negative number to exit): -2
*/
