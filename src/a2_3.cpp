/*
 * Lucas Street, 08/30
 * CS 10, Dave Harden
 * Assignment 2.3 - a2_3.cpp
 *
 * Prints out various results of playing with a person's first, middle, and last names. Manipulations include
 * substrings and lengths.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    string first, middle, last;
    cout << "Enter a name in the format First Middle Last: ";
    cin >> first >> middle >> last;

    // part 1
    cout << first << endl
         << middle << endl
         << last << endl;

    // part 2
    cout << first.substr(0, 1) << middle.substr(0, 1) << last.substr(0, 1) << endl;

    // part 3
    cout << middle.substr(0, 3) << endl;

    // part 4
    string full_name = first + " " + middle + " " + last;

    cout << full_name.substr(7, 1) << endl;

    // part 5
    cout << full_name.length() << endl;

    return 0;
}

// Output
/*
Enter a name in the format First Middle Last: Lucas Henry Street
Lucas
Henry
Street
LHS
Hen
e
18
*/
