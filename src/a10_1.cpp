/**
 * @author Lucas Street
 * @date 11/5/16
 * CS 10, Dave Harden
 * Assignment 10.1 - a10_1.cpp
 *
 * Prints out a full year of ASCII formatted calendar months. The user simply enters the
 * year and the day of the week January 1st falls on, and the program will generate months
 * with the correct amount of days per month (including 29 days for February if the given
 * year is a leap year. The process of printing the resulting year is functionally
 * decomposed, so the program uses one variable passed by reference to keep track of the
 * day of the week each month must end/begin on. An example month with correct formatting
 * looks like this:
 *
 *         January
 *   S  M  T  W  T  F  S
 *  --------------------
 *         1  2  3  4  5
 *   6  7  8  9 10 11 12
 *  13 14 15 16 17 18 19
 *  20 21 22 23 24 25 26
 *  27 28 29 30 31
 *
 * In this example, since January ends on Thursday which corresponds to a week day number
 * of 4, then February 1st will fall on week day number 5, or Friday.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printMonth(int year, int month_number, int &start_day);

string getMonthName(int month_number);

void printHeader(string month_name);

void printDays(int year, int month_number, int &start_day);

int getDaysInMonth(int year, int month_number);

bool isLeapYear(int year);


const int SATURDAY = 6;






/**
 * Ask the user for the year they want to create a calendar for and the day of the week
 * that January 1st falls on. Then print out ASCII formatted calendar months for the
 * requested year.
 */
int main() {
    int year, start_day;
    cout << "What year do you want a calendar for? ";
    cin >> year;
    cout << "What day of the week does January 1 fall on "
         << "(0 for Sunday, 1 for Monday, etc.)? ";
    cin >> start_day;

    cout << "\n\t\t " << year << "\n\n";
    for (int month = 0; month < 12; ++month) {
        printMonth(year, month, start_day);
    }

    return 0;
}






/**
 * Print out a single month in a year, grabbing the month name from the given month
 * number.
 *
 * @param year the specified year this month belongs to
 * @param month_number the number of the month (0-11) where 0=January and 11=December
 * @param start_day which day the month starts on (0-6) where 0=Sunday and 6=Saturday
 */
void printMonth(int year, int month_number, int &start_day) {
    string month_name = getMonthName(month_number);
    printHeader(month_name);
    printDays(year, month_number, start_day);
    cout << endl;
}






/**
 * Maps a month number to its corresponding month name.
 *
 * @param month_number the number of the month (0-11) where 0=January and 11=December
 * @return the name of the month that corresponds to the month number. If the month_number
 * is not in the valid range, then the empty string is returned.
 */
string getMonthName(int month_number) {
    switch (month_number) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            return ""; // not found
    }
}






/**
 * Prints out a header for each month. The width is calculated precisely that each day
 * number in the month may have at least 1 space of padding.
 *
 * @param month_name the name of the month to use when displaying the header
 */
void printHeader(string month_name) {
    cout << "\t   " << month_name << endl
         << " S  M  T  W  T  F  S" << endl
         << "--------------------" << endl;
}






/**
 * Prints out all the days in the given month. The start_day variable is used to keep
 * track of where the last month left off. Each day is printed with a width of 2 to
 * provide ample spacing, and when the day of the week is Saturday, a new line is printed
 * to format the month as one might see it on an actual calendar.
 *
 * @param year the year the month belongs to (used for calculating the days for February
 * in case it's a leap year
 * @param month_number the number of the month (0-11) where 0=January and 11=December
 * @param start_day which day the month starts on (0-6) where 0=Sunday and 6=Saturday.
 * Since this is a reference, changes to this variable persist between different month
 * printings, which lets me keep track of where the last month left off.
 */
void printDays(int year, int month_number, int &start_day) {
    int start_spaces = start_day * 3; // 3 spaces padding for each day
    for (int i = 0; i < start_spaces; ++i) { cout << " "; }

    int days_in_month = getDaysInMonth(year, month_number);

    for (int day = 1; day <= days_in_month; ++day) {
        cout << setw(2) << day << " ";

        // Use start_day to keep track of the day of the week
        if (start_day == SATURDAY) {
            cout << endl;
            start_day = 0;
        } else {
            start_day++;
        }
    }
    cout << endl;
}






/**
 * Determine the number of days in a particular month. If the year is a leap year, then
 * February gets an extra day.
 *
 * @remark This function uses switch statement fall-through to be more compact.
 *
 * @param year the year the month belongs to
 * @param month_number the number of the month (0-11) where 0=January and 11=December
 * @return the number of days in the specified month for the specified year. If the month
 * number is not in the valid range, then 0 is returned.
 */
int getDaysInMonth(int year, int month_number) {
    switch (month_number) {
        case 0:  // January
        case 2:  // March
        case 4:  // May
        case 6:  // July
        case 7:  // August
        case 9:  // October
        case 11: // December
            return 31;

        case 3:  // April
        case 5:  // June
        case 8:  // September
        case 10: // November
            return 30;

        case 1:  // Feb
            if (isLeapYear(year)) { return 29; }
            else { return 28; }

        default:
            return 0; // invalid month
    }
}






/**
 * Determines whether the given year is a leap year. A year is a leap year when it is
 * divisible by 4 but not 100 (with the exception of divisibility by 400).
 *
 * @param year the year to test for "leapness"
 * @return whether or not the year is a leap year
 */
bool isLeapYear(int year) {
    if (year % 400 == 0) { return true; }
    if (year % 100 == 0) { return false; }
    return year % 4 == 0;
}

// Output
/*
What year do you want a calendar for? 2004
What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)? 2

         2004

       January
 S  M  T  W  T  F  S
--------------------
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

       February
 S  M  T  W  T  F  S
--------------------
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29

       March
 S  M  T  W  T  F  S
--------------------
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31

       April
 S  M  T  W  T  F  S
--------------------
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30

       May
 S  M  T  W  T  F  S
--------------------
             1  2  3
 4  5  6  7  8  9 10
11 12 13 14 15 16 17
18 19 20 21 22 23 24
25 26 27 28 29 30 31


       June
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30

       July
 S  M  T  W  T  F  S
--------------------
       1  2  3  4  5
 6  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

       August
 S  M  T  W  T  F  S
--------------------
                1  2
 3  4  5  6  7  8  9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
31

       September
 S  M  T  W  T  F  S
--------------------
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30

       October
 S  M  T  W  T  F  S
--------------------
          1  2  3  4
 5  6  7  8  9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31

       November
 S  M  T  W  T  F  S
--------------------
                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30

       December
 S  M  T  W  T  F  S
--------------------
    1  2  3  4  5  6
 7  8  9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 31
*/
