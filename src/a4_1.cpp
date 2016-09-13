/*
 * Lucas Street, 09/13
 * CS 10, Dave Harden
 * Assignment 4.1 - a4_1.cpp
 *
 * Converts pounds to ounces, except this time the program continues using a question-based loop until the user
 * wants to quit.
 */

#include <iostream>

using namespace std;

int main() {
    char response;
    int pounds, ounces;

    cout << "Would you like to convert pounds to ounces? (y/n) ";
    cin >> response;

    while (response == 'y') {
        cout << "enter pounds: ";
        cin >> pounds;
        ounces = pounds * 16;

        cout << pounds << " pounds is " << ounces << " ounces." << endl;

        cout << "Would you like to convert pounds to ounces? (y/n) ";
        cin >> response;
    }

    return 0;
}
// Output
/*
Would you like to convert pounds to ounces? (y/n) y
enter pounds: 1
1 pounds is 16 ounces.
Would you like to convert pounds to ounces? (y/n) y
enter pounds: 34
34 pounds is 544 ounces.
Would you like to convert pounds to ounces? (y/n) n
*/
