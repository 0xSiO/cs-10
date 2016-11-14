/**
 * @author Lucas Street
 * @date 11/14/16
 * CS 10, Dave Harden
 * Assignment 11.1 - a11_1.cpp
 *
 * Reads a list of positive integers from the standard input, storing them in an array.
 * Any duplicate items in this list are discarded, and the array has a maximum size limit
 * indicated by MAX_SIZE. After receiving a negative integer as a signal to end the input
 * loop, the program prints the contents of the array up to the last number the user
 * entered. This program uses arrays as arguments, which are automatically passed by
 * reference. Therefore, to avoid modifying the array in the print_numbers function and
 * the in_array function, the array parameter is constant.
 */

#include <iostream>

using namespace std;

void read_numbers(int numbers_array[], int &index);

bool in_array(int number, const int numbers_array[], int size);

void print_numbers(const int numbers_array[], int size);

const int MAX_SIZE = 1000;






/**
 * Creates an array and a variable to track the current array index, reads in numbers from
 * the user, and then prints the resulting array to the screen.
 */
int main() {
    int numbers_array[MAX_SIZE];
    int count = 0;

    read_numbers(numbers_array, count);
    print_numbers(numbers_array, count);

    return 0;
}






/**
 * Reads and stores numbers from the user in the given array. If a number already exists
 * in the array, it will be ignored.
 *
 * @param numbers_array the array to store numbers in
 * @param index the index of the last number entered
 */
void read_numbers(int numbers_array[], int &index) {
    int number;
    cout << "Enter a non-negative integer (negative to quit): ";
    cin >> number;
    while (number >= 0) {
        if (!in_array(number, numbers_array, index)) {
            numbers_array[index++] = number;
        }
        cout << "Enter a non-negative integer (negative to quit): ";
        cin >> number;
    }
}






/**
 * Tests whether the given number exists in the given array up to a certain index.
 *
 * @param number the number to test
 * @param numbers_array the array to test
 * @param size the index of the last user-entered number
 * @return whether or not the number is an element of the array
 */
bool in_array(int number, const int numbers_array[], int size) {
    for (int i = 0; i < size; ++i) {
        if (numbers_array[i] == number) {
            return true;
        }
    }
    return false;
}






/**
 * Prints the contents of the given array to the screen, up to a given index.
 *
 * @param numbers_array the array to print
 * @param size the index of the last user-entered number
 */
void print_numbers(const int numbers_array[], int size) {
    cout << "You entered:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << numbers_array[i] << " ";
    }
    cout << endl;
}

// Output
/*
Enter a non-negative integer (negative to quit): 1
Enter a non-negative integer (negative to quit): 2
Enter a non-negative integer (negative to quit): 3
Enter a non-negative integer (negative to quit): 2
Enter a non-negative integer (negative to quit): 1
Enter a non-negative integer (negative to quit): 2
Enter a non-negative integer (negative to quit): 3
Enter a non-negative integer (negative to quit): 4
Enter a non-negative integer (negative to quit): 5
Enter a non-negative integer (negative to quit): 6
Enter a non-negative integer (negative to quit): -1
You entered:
1 2 3 4 5 6
*/
