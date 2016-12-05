/**
 * @author Lucas Street
 * @date 12/5/16
 * CS 10, Dave Harden
 * Assignment 14.1 - a14_1.cpp
 *
 * Client program for testing the boolMatrix class
 */

#include <cassert>
#include "boolMatrix.h"

using namespace std;






int main() {
    boolMatrix matrix;
    matrix.set(0, 5, true);
    matrix.set(10, 10, true);
    matrix.set(10, 11, true);
    assert(matrix.get(0, 5) && matrix.get(10, 10) && matrix.get(10, 11));
    assert(matrix.rowCount(10) == 2 && matrix.colCount(10) == 1 &&
           matrix.rowCount(0) == 1 && matrix.totalCount() == 3);
    assert(matrix.neighborCount(9, 10) == 2 && matrix.neighborCount(0, 0) == 0);

//    for (int i = 0; i < boolMatrix::NUM_ROWS; ++i) {
//        for (int j = 0; j < boolMatrix::NUM_COLS; ++j) {
//            matrix.set(i, j, true);
//        }
//    }

    matrix.print();

    return 0;
}
