/**
 * @author Lucas Street
 * @date 12/5/16
 * CS 10, Dave Harden
 * Assignment 14.1 - boolMatrix.h
 *
 * A boolMatrix stores a two-dimensional array of boolean values. A client may read and
 * write to the values in the array, print the matrix, and count 'true' values in rows,
 * columns, or the whole array.
 *
 * Additionally, a client may count 'true' values for array elements adjacent to a
 * specified location. An illustration of this is shown below, where 't' represents a true
 * value and 'f' represents a false value:
 *   [t][t][f]
 *   [f][f][t]  <-- A subset of the two-dimensional array; shape may vary with location
 *   [f][f][t]
 * Counting the neighbors of the center element above would return 4, since there are
 * four 'true' values adjacent to the center element. This function also works when the
 * target element is located in a corner or side of the matrix.
 *
 * boolMatrix();
 * @pre none
 * @post the constructed boolMatrix's elements are all false, and the two-dimensional
 * array has dimensions of NUM_ROWS by NUM_COLS
 *
 * bool get(int row, int column) const;
 * @pre 0 <= row < NUM_ROWS and 0 <= column < NUM_COLS
 * @post the returned value is equal to the value at matrix[row, column]
 *
 * void set(int row, int column, bool value);
 * @pre 0 <= row < NUM_ROWS and 0 <= column < NUM_COLS, value is either true or false
 * @post the value at matrix[row, column] is now equal to the given value
 *
 * int rowCount(int row) const;
 * @pre 0 <= row < NUM_ROWS
 * @post the returned value is equal to the number of 'true' values in the given row
 *
 * int colCount(int column) const;
 * @pre 0 <= column < NUM_COLS
 * @post the returned value is equal to the number of 'true' values in the given column
 *
 * int totalCount() const;
 * @pre matrix is properly initialized
 * @post the returned value is equal to the number of 'true' values in the entire matrix
 *
 * int neighborCount(int row, int column) const;
 * @pre 0 <= row < NUM_ROWS and 0 <= column < NUM_COLS
 * @post the returned value is equal to the number of 'true' values adjacent to the
 * element at matrix[row][column]
 *
 * void print() const;
 * @pre matrix is properly initialized
 * @post a formatted representation of matrix is printed to standard output
 */

#ifndef CS10_BOOLMATRIX_H
#define CS10_BOOLMATRIX_H

class boolMatrix {
    public:
        static const int NUM_ROWS = 20;
        static const int NUM_COLS = 20;
        boolMatrix();
        bool get(const int &row, const int &column) const;
        void set(const int &row, const int &column, const bool &value);
        int rowCount(const int &row) const;
        int colCount(const int &column) const;
        int totalCount() const;
        int neighborCount(const int &row, const int &column) const;
        void print() const;
    private:
        bool matrix[NUM_ROWS][NUM_COLS];
        void printRow(const int &row_number) const;
};

#endif //CS10_BOOLMATRIX_H
