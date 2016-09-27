/*
 * Lucas Street, 09/13
 * CS 10, Dave Harden
 * Assignment  - a4_3.cpp
 *
 * Tracks ages and food preferences of attendees at a movie theater. Displays average, max, and minimum ages along
 * with counts of age ranges and concession preferences.
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    const int EIGHTEEN = 18, NINETEEN = 19, THIRTY = 30, THIRTY_ONE = 31, FORTY = 40, FORTY_ONE = 41, SIXTY = 60;

    // Attendee stats
    int zero_to_18 = 0, nineteen_to_30 = 0, thirty_one_to_40 = 0, forty_one_to_60 = 0, over_60 = 0;
    int age, attendees = 0, min, max;
    double ages_sum = 0;

    // Food preference stats
    char food_preference;
    int popcorn = 0, soda = 0, popcorn_and_soda = 0;

    cout << "Enter age of attendee (negative number to quit): ";
    cin >> age;
    min = age;
    max = age;

    while (age >= 0) {
        cout << "Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): ";
        cin >> food_preference;

        switch (food_preference) {
            case 'p':
                popcorn++;
                break;
            case 's':
                soda++;
                break;
            case 'b':
                popcorn_and_soda++;
                break;
            default:
                break;
        }

        if (age >= 0 && age <= EIGHTEEN) {
            zero_to_18++;
        } else if (age >= NINETEEN && age <= THIRTY) {
            nineteen_to_30++;
        } else if (age >= THIRTY_ONE && age <= FORTY) {
            thirty_one_to_40++;
        } else if (age >= FORTY_ONE && age <= SIXTY) {
            forty_one_to_60++;
        } else {
            over_60++;
        }

        if (age < min) min = age;
        if (age > max) max = age;

        ages_sum += age;
        attendees++;

        cout << "Enter age of attendee (negative number to quit): ";
        cin >> age;
    }

    if (min >= 0 && max >= 0) {
        cout << endl;
        cout << "age 0  to 18: " << zero_to_18 << endl
             << "age 19 to 30: " << nineteen_to_30 << endl
             << "age 31 to 40: " << thirty_one_to_40 << endl
             << "age 41 to 60: " << forty_one_to_60 << endl
             << "over 60: " << over_60 << endl;
        cout << endl;

        cout << "food preference popcorn: " << popcorn << endl
             << "food preference soda: " << soda << endl
             << "food preference both: " << popcorn_and_soda << endl;

        printf("The average age was %.1f\n", ages_sum / attendees);
        cout << "The youngest person in attendance was " << min << endl;
        cout << "The oldest person in attendance was " << max << endl;
    }

    return 0;
}
// Output
/*
Enter age of attendee (negative number to quit): 34
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (negative number to quit): 16
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
Enter age of attendee (negative number to quit): 68
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
Enter age of attendee (negative number to quit): 53
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (negative number to quit): 39
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
Enter age of attendee (negative number to quit): 23
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (negative number to quit): 21
Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
Enter age of attendee (negative number to quit): -1

age 0  to 18: 1
age 19 to 30: 2
age 31 to 40: 2
age 41 to 60: 1
over 60: 1

food preference popcorn: 1
food preference soda: 4
food preference both: 2
The average age was 36.3
The youngest person in attendance was 16
The oldest person in attendance was 68
*/
