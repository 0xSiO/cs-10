/*
 * Lucas Street, 08/30
 * CS 10, Dave Harden
 * Assignment 2.2 - a2_2.cpp
 *
 * Converts a temperature value given in Celsius to a value in Fahrenheit.
 */

#include <iostream>

using namespace std;

int main() {

    int celsius;
    cout << "enter degrees Celsius: ";
    cin >> celsius;

    // Use a double value for accuracy, celsius will be auto promoted to double in this expression
    double fahrenheit = (9.0 / 5.0) * celsius + 32;

    // Cast fahrenheit back to int for nice printing
    cout << celsius << " degrees Celsius is " << (int) fahrenheit << " degrees Fahrenheit.";

    return 0;
}

// Output
/*
enter degrees Celsius: 100
100 degrees Celsius is 212 degrees Fahrenheit.
*/
