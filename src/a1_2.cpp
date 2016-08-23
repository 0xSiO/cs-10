/*
 * Lucas Street, 08/22
 * CS 10, Dave Harden
 * Assignment 1.2 - a1_2.cpp
 *
 * Converts pounds to ounces.
 */

#include <iostream>

using namespace std;

int main() {
    int pounds, ounces;

    cout << "enter pounds: ";
    cin >> pounds;
    ounces = pounds * 16;

    cout << pounds << " pounds is " << ounces << " ounces." << endl;

    return 0;
}

// Output
/*
enter pounds: 8
8 pounds is 128 ounces.
*/
