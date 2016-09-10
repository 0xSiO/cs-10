/*
 * Lucas Street, 09/10
 * CS 10, Dave Harden
 * Assignment 3.2 - a3_2.cpp
 *
 * Outputs the educational level of a student given the number of years spent in school. Uses an if-else structure
 * with ranges of grade levels to find the correct response.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    const int FIRST_GRADE = 1, SIXTH_GRADE = 6, SEVENTH_GRADE = 7, EIGHTH_GRADE = 8, NINTH_GRADE = 9, TWELFTH_GRADE = 12;

    int years;
    cout << "Enter years of school: ";
    cin >> years;

    string result;

    if (years == 0) {
        result = "no school";
    } else if (years >= FIRST_GRADE && years <= SIXTH_GRADE) {
        result = "elementary school";
    } else if (years >= SEVENTH_GRADE && years <= EIGHTH_GRADE) {
        result = "middle school";
    } else if (years >= NINTH_GRADE && years <= TWELFTH_GRADE) {
        result = "high school";
    } else if (years > TWELFTH_GRADE) {
        result = "college";
    } else {
        result = "years of school must be a non-negative integer";
    }

    cout << result << endl;

    return 0;
}
// Output
/*
Enter years of school: 16
college
*/
