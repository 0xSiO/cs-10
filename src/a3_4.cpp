/*
 * Lucas Street, 09/10
 * CS 10, Dave Harden
 * Assignment 3.4 - a3_4.cpp
 *
 * Calculates the gross and net cost of a telephone call from San Francisco to Miami, FL in 1995, given the start
 * time of the call and the length of the call in minutes.
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double REGULAR_RATE = 0.4, FEDERAL_TAX = 1.04, LONG_CALL_DISCOUNT = 0.85, LATE_OR_EARLY_DISCOUNT = 0.5,
            ONE_HOUR = 60, SIX_PM = 1800, EIGHT_AM = 800;

    double start_time, call_length;

    cout << "Enter start time: ";
    cin >> start_time;
    cout << "Enter length of call in minutes: ";
    cin >> call_length;

    // calculate with regular rate first
    double cost = call_length * REGULAR_RATE;
    cout << fixed << setprecision(2) << "gross cost: $" << cost << endl;

    // late/early call discount
    if (start_time >= SIX_PM || start_time < EIGHT_AM) {
        cost *= LATE_OR_EARLY_DISCOUNT;
    }

    // long call discount
    if (call_length > ONE_HOUR) {
        cost *= LONG_CALL_DISCOUNT;
    }

    // apply tax
    cost *= FEDERAL_TAX;

    cout << fixed << setprecision(2) << "net cost: $" << cost << endl;

    return 0;
}
// Output
/*
Enter start time: 2322
Enter length of call in minutes: 67
gross cost: $26.80
net cost: $11.85

Enter start time: 759
Enter length of call in minutes: 10
gross cost: $4.00
net cost: $2.08

Enter start time: 1300
Enter length of call in minutes: 100
gross cost: $40.00
net cost: $35.36

Enter start time: 1300
Enter length of call in minutes: 10
gross cost: $4.00
net cost: $4.16
*/
