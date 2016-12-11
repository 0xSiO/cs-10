/**
 * @author Lucas Street
 * @date 12/11/16
 * CS 10, Dave Harden
 * Assignment 15.1 - a15.cpp
 *
 * Simulates the game of life using a boolMatrix from assignment 14. The game is a
 * computer simulation of the life and death events in a population of single-cell
 * organisms. Each position in a two-dimensional grid (Petri dish) can support one cell.
 * The program determines whether each position will be able to support life in the next
 * generation using a set of specific rules depending on the amount of live cells adjacent
 * to each cell. The user can specify the number of generations to cycle through and the
 * resulting grid is displayed along with some statistics at the end of the program.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "boolMatrix.h"

using namespace std;

void load_live_cells(const string &file_name, boolMatrix &grid);

boolMatrix next_generation(const boolMatrix &grid);

bool will_cell_live(int row, int column, const boolMatrix &grid);

void display_stats(const boolMatrix &grid);






/**
 * Populates a grid with true values given by the coordinates in life.txt, then runs a
 * user-provided number of generations on the grid, then displays the grid and some stats.
 */
int main() {
    boolMatrix grid;
    load_live_cells("life.txt", grid);

    int generations;
    cout << "Enter number of generations: ";
    cin >> generations;
    cout << endl;

    for (int i = 0; i < generations; ++i) {
        grid = next_generation(grid);
    }

    display_stats(grid);
    return 0;
}






/**
 * Loads X-Y coordinate pairs from a given file and sets all cells matching those
 * coordinates to 'true' in the given grid.
 *
 * @param file_name the file to read coordinates from
 * @param grid the grid to populate with data
 */
void load_live_cells(const string &file_name, boolMatrix &grid) {
    ifstream data_file(file_name);
    assert(data_file);
    int x, y;
    data_file >> x >> y;
    while (data_file) {
        grid.set(x, y, true);
        data_file >> x >> y;
    }
    data_file.close();
}






/**
 * Generates a new grid that represents the next generation of the given grid. Each cell
 * in the given grid is tested to see whether it will live, and the results are returned
 * as a new boolMatrix.
 *
 * @param grid the grid to create a new generation from
 * @return a boolMatrix representing 1 generation past the given grid
 */
boolMatrix next_generation(const boolMatrix &grid) {
    boolMatrix new_grid;
    for (int row = 0; row < boolMatrix::NUM_ROWS; ++row) {
        for (int column = 0; column < boolMatrix::NUM_COLS; ++column) {
            bool state = will_cell_live(row, column, grid);
            new_grid.set(row, column, state);
        }
    }
    return new_grid;
}






/**
 * Tests a cell in a boolMatrix to see whether or not that cell will live. The rules for
 * determining life or death are as follows:
 *   If alive:
 *     if the cell has 2 or 3 live neighbors, the cell will live.
 *     else, it will die.
 *   If dead:
 *     if the cell has 3 live neighbors, the cell will come to life.
 *     else, it will stay dead.
 *
 * These tests are simplified as one conditional expression in the return statement of the
 * function.
 *
 * @param row the row of the cell to test
 * @param column the column of the cell to test
 * @param grid the boolMatrix that the cell is located in
 * @return whether or not the target cell will live in the next generation of the grid
 */
bool will_cell_live(int row, int column, const boolMatrix &grid) {
    bool currently_alive = grid.get(row, column);
    int living_neighbors = grid.neighborCount(row, column);
    return living_neighbors == 3 || (living_neighbors == 2 && currently_alive);
}






/**
 * Displays the given grid and some stats about the number of living cells in row 10,
 * column 10, and in the entire grid.
 *
 * @param grid the boolMatrix to display stats for
 */
void display_stats(const boolMatrix &grid) {
    grid.print();
    cout << "Total alive in row 10 = " << grid.rowCount(10) << endl;
    cout << "Total alive in col 10 = " << grid.colCount(10) << endl;
    cout << "Total alive = " << grid.totalCount() << endl;
}

// Output
/*
Enter number of generations: 5

  01234567890123456789
 0
 1         *        *
 2       *   * ***  *
 3       *   **** *
 4      *  * *    **
 5    *  *   *****  *
 6 ** *     *    *** *
 7    * ***       *  *
 8               ****
 9 *         ******
10* *          *
11   *  *      **   *
12**    ****       ***
13  *         *** ** *
14      *  *   *   ***
15 **   ***      ** **
16      *         * **
17
18
19
Total alive in row 10 = 3
Total alive in col 10 = 1
Total alive = 95

Enter number of generations: 8

  0123456789012345678901
 0
 1         **     *
 2         * *   ** *
 3       **        *
 4    **** * *   **
 5    **  * ** ** *
 6   *      ***
 7    **  *  * *
 8     ***   * *
 9 **        *  *
10* **        *   * **
11* ** ** **  * * *
12*   *   *** *       *
13* *        ***  * *
14 *      ***  **   *
15        *     *      *
16     * *      *  ** *
17      *         *
18
19
20
Total alive in row 10 = 7
Total alive in col 10 = 5
Total alive = 94
*/
