/*
 * Lucas Street, 10/3/16
 * CS 10, Dave Harden
 * Assignment 5.1 - a5_1.cpp
 *
 * Counts a given amount of numbers, and keeps track of the first and last '7' entered.
 */

#include <iostream>

using namespace std;

const int SEVEN = 7, NONE = -1;

int main() {
    int times;
    cout << "How many numbers will be entered? ";
    cin >> times;

    int first_seven_pos = NONE, last_seven_pos = NONE;

    int num;
    for (int i = 1; i <= times; i++) {
        cout << "Enter num: ";
        cin >> num;
        if (num == SEVEN) {
            if (first_seven_pos == NONE) {
                // first seven
                first_seven_pos = i;
            }
            last_seven_pos = i;
        }
    }

    if (first_seven_pos == NONE) {
        cout << "Sorry, no 7's were entered." << endl;
    } else {
        cout << "The first 7 was in position " << first_seven_pos << endl;
        cout << "The last 7 was in position " << last_seven_pos << endl;
    }

    return 0;
}
