/**
 * @author Lucas Street
 * @date 10/29/16
 * CS 10, Dave Harden
 * Assignment 9.1 - a9_1.cpp
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void printMonth(int year, int month_number, int start_day);

string getMonthName(int month_number);

void printHeader(string month_name);

void printDays(int year, int month_number, int start_day);

int getDaysInMonth(int year, int month_number);

bool isLeapYear(int year);






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






void printMonth(int year, int month_number, int start_day) {
    string month_name = getMonthName(month_number);
    printHeader(month_name);
    printDays(year, month_number, start_day);
    cout << endl;
}






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






void printHeader(string month_name) {
    cout << "\t   " << month_name << endl
         << " S  M  T  W  T  F  S" << endl
         << "--------------------" << endl;
}






void printDays(int year, int month_number, int start_day) {
    int start_spaces = start_day * 3; // 3 spaces padding for each day
    for (int i = 0; i < start_spaces; ++i) { cout << " "; }

    int days_in_month = getDaysInMonth(year, month_number);

    for (int day = 1; day <= days_in_month; ++day) {
        cout << setw(2) << day << " ";
    }
    cout << endl;
}






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






bool isLeapYear(int year) {
    if (year % 400 == 0) { return true; }
    if (year % 100 == 0) { return false; }
    return year % 4 == 0;
}

// Output
/*
What year do you want a calendar for? 2016
What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)? 0

         2016

       January
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       February
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29

       March
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       April
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

       May
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       June
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

       July
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       August
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       September
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

       October
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31

       November
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

       December
 S  M  T  W  T  F  S
--------------------
 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
*/
