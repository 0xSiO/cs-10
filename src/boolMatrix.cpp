/**
 * @author Lucas Street
 * @date 12/5/16
 * CS 10, Dave Harden
 * Assignment 14.1 - boolMatrix.cpp
 *
 * A boolMatrix's elements are either true or false.
 *
 * Private data members:
 *   matrix: a two-dimensional array containing bool values
 *
 * 'matrix' is accessed to view and set matrix values for a boolMatrix instance.
 */

#include <cassert>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "boolMatrix.h"

using std::cout;
using std::endl;
using std::setw;
using std::log10; // this is used to find padding for setw






boolMatrix::boolMatrix() {
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            matrix[row][col] = false;
        }
    }
}






bool boolMatrix::get(const int &row, const int &column) const {
    assert(row >= 0 && column >= 0 && row < NUM_ROWS && column < NUM_COLS);
    return matrix[row][column];
}






void boolMatrix::set(const int &row, const int &column, const bool &value) {
    assert(row >= 0 && column >= 0 && row < NUM_ROWS && column < NUM_COLS);
    matrix[row][column] = value;
}






int boolMatrix::rowCount(const int &row) const {
    assert(row >= 0 && row < NUM_ROWS);
    int count = 0;
    for (int column = 0; column < NUM_COLS; ++column) {
        if (get(row, column)) {
            count++;
        }
    }
    return count;
}






int boolMatrix::colCount(const int &column) const {
    assert(column >= 0 && column < NUM_COLS);
    int count = 0;
    for (int row = 0; row < NUM_ROWS; ++row) {
        if (get(row, column)) {
            count++;
        }
    }
    return count;
}






int boolMatrix::totalCount() const {
    int count = 0;
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            if (get(row, col)) {
                count++;
            }
        }
    }
    return count;
}






/**
 * Count the number of 'true' values adjacent to a target value. There are usually 8
 * adjacent values, but that's optional - this function safely checks boundaries on all 8
 * locations. Each neighbor location is defined by 2 values: row and column.
 *
 * (Because arrays decay to pointers during assignment, I use a pointer on line 134 for
 * readability's sake in the boundary check.)
 *
 * @param row the row of the target value
 * @param column the column of the target value
 * @return the number of 'true' values adjacent to the target value
 */
int boolMatrix::neighborCount(const int &row, const int &column) const {
    assert(row >= 0 && row < NUM_ROWS && column >= 0 && column < NUM_COLS);
    int neighbor_locations[][2]{
            {row - 1, column - 1}, {row - 1, column}, {row - 1, column + 1},
            {row,     column - 1}, /*[target value]*/ {row,     column + 1},
            {row + 1, column - 1}, {row + 1, column}, {row + 1, column + 1}
    };
    int count = 0;
    for (int index = 0; index < 8; ++index) {
        int *location = neighbor_locations[index];
        if (location[0] >= 0 && location[1] >= 0 && location[0] < NUM_ROWS &&
            location[1] < NUM_COLS && get(location[0], location[1]))
            count++;
    }
    return count;
}






void boolMatrix::print() const {
    int left_pad = static_cast<int>(log10(static_cast<long double>(NUM_ROWS - 1))) + 1;

    // Top row column numbers
    cout << setw(left_pad) << " ";
    for (int col_number = 0; col_number < NUM_COLS; ++col_number) {
        cout << col_number;
    }
    cout << endl;

    // Rows
    for (int row_number = 0; row_number < NUM_ROWS; ++row_number) {
        cout << setw(left_pad) << row_number;
        printRow(row_number);
    }
}






/**
 * Print out a particular row of the matrix, with correct padding depending on the value
 * True values are shown as '*' and false value are shown as ' '
 *
 * @param row_number the index of the row to print
 */
void boolMatrix::printRow(const int &row_number) const {
    assert(row_number >= 0 && row_number < NUM_ROWS);
    for (int column = 0; column < NUM_COLS; ++column) {
        int value_padding = static_cast<int>(log10(static_cast<long double>(column))) + 1;
        if (get(row_number, column)) {
            cout << setw(value_padding) << "*";
        } else {
            cout << setw(value_padding) << " ";
        }
    }
    cout << endl;
}
