/*
 * Lucas Street, 10/3/16
 * CS 10, Dave Harden
 * Assignment 5.2 - a5_2.cpp
 *
 * Sums the squares of the numbers from 1 to a given number.
 */

#include <iostream>

using namespace std;

int main() {
    int num;
    cout << "Enter a number greater than 0 (less than 1 to quit): ";
    cin >> num;

    while (num > 0) {
        int sum = 0;
        for (int i = 1; i <= num; i++) {
            sum += i * i;
        }
        cout << "The sum of the squares from 1 to " << num << " is " << sum << endl;

        cout << "Enter a number greater than 0 (less than 1 to quit): ";
        cin >> num;
    }

    return 0;
}
// Output
/*
Enter a number greater than 0 (less than 1 to quit): 4
The sum of the squares from 1 to 4 is 30
Enter a number greater than 0 (less than 1 to quit): 1
The sum of the squares from 1 to 1 is 1
Enter a number greater than 0 (less than 1 to quit): 0
*/
