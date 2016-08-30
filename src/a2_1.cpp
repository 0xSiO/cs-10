/*
 * Lucas Street, 08/30
 * CS 10, Dave Harden
 * Assignment 2.1 - a2_1.cpp
 *
 * Splits an amount of money, entered in cents, into quarters, dimes, nickels, and pennies. Uses integer division
 * and the modulo operator to do so.
 */

#include <iostream>

using namespace std;

int main() {
    // Constants for breaking into each coin value
    const int QUARTER_VAL = 25;
    const int DIME_VAL = 10;
    const int NICKEL_VAL = 5;

    int cents;
    cout << "enter number of cents: ";
    cin >> cents;

    int pennies, nickels, dimes, quarters;

    // Use integer division to get a truncated value, then use modulo operator to get the remainder
    quarters = cents / QUARTER_VAL;
    cents %= QUARTER_VAL;
    dimes = cents / DIME_VAL;
    cents %= DIME_VAL;
    nickels = cents / NICKEL_VAL;
    cents %= NICKEL_VAL;
    pennies = cents;

    cout << "pennies: " << pennies << endl;
    cout << "nickels: " << nickels << endl;
    cout << "dimes: " << dimes << endl;
    cout << "quarters: " << quarters << endl;

    return 0;
}

// Output
/*
enter number of cents: 89
pennies: 4
nickels: 0
dimes: 1
quarters: 3
*/
