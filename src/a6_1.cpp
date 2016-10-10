/**
 * @author Lucas Street
 * @date 10/9/16
 * CS 10, Dave Harden
 * Assignment 6.1 - a6_1.cpp
 *
 * Draws a rocket on the screen using given parameters for the width of the rocket stages,
 * the height of each stage, and the number of stages to draw. The rocket itself is made
 * out of two base components, boxes and cones. An example rocket is shown below:
 *
 * @code
 *
 *      X
 *     X X
 *    X   X
 *   X     X
 *   XXXXXXX
 *   X     X
 *   X     X
 *   X     X
 *   X     X
 *   XXXXXXX
 *   XXXXXXX
 *   X     X
 *   X     X
 *   X     X
 *   X     X
 *   XXXXXXX
 *      X
 *     X X
 *    X   X
 *   X     X
 *
 * @endcode
 *
 * The above example is a rocket with a stage width of 7, a stage height of 6, and a total
 * of two stages.
 *
 * For 5 extra credit points:
 * If the stage width is an even number, the cones at the tip and the rear of the rocket
 * will have two 'X's rather than one, making for a more blunt shape.
 *
 * This program uses decomposed functions to draw each part of each rocket component, as
 * well as an example of passing variables by reference when fetching the dimensions of
 * the rocket.
 *
 * Note that the three functions defined at the end come from directly lesson 6 and do not
 * require documentation.
 */

#include <iostream>

void getDimensions(int &stage_height, int &stage_width, int &number_of_stages);

void drawRocket(int stage_height, int stage_width, int number_of_stages);

void drawCone(int cone_width);

void drawConeTip(int cone_height, bool cone_is_even);

void drawConeRow(int inner_spacing, int outer_spacing);

void pad(int space_count);

void drawBox(int width, int height);

void drawHorizontalLine(int numXs);

void draw2VerticalLines(int numSpaces, int numRows);

void drawOneRow(int numSpaces);

using namespace std;






int main() {
    int stage_height, stage_width, number_of_stages;

    getDimensions(stage_height, stage_width, number_of_stages);
    drawRocket(stage_height, stage_width, number_of_stages);

    return 0;
}






/**
 * Prompts for and sets the desired dimensions of a rocket. Note that the arguments
 * passed to this function will be modified.
 *
 * @param stage_height the height of each stage
 * @param stage_width the width of each stage
 * @param number_of_stages the amount of rectangular stages to draw the rocket with
 */
void getDimensions(int &stage_height, int &stage_width, int &number_of_stages) {
    cout << "Enter stage height: ";
    cin >> stage_height;
    cout << "Enter stage width: ";
    cin >> stage_width;
    cout << "Enter number of stages: ";
    cin >> number_of_stages;
}






/**
 * Draws a rocket, consisting of cones and boxes. The rocket has a top cone as its nose
 * and a bottom cone as its propulsion. The rocket may have one or more rectangular
 * stages between the top and bottom cones.
 *
 * @param stage_height the height of each stage
 * @param stage_width the width of each stage
 * @param number_of_stages the amount of rectangular stages to draw the rocket with
 */
void drawRocket(int stage_height, int stage_width, int number_of_stages) {
    drawCone(stage_width);

    for (int i = 0; i < number_of_stages; i++) {
        drawBox(stage_width, stage_height);
    }

    drawCone(stage_width);
}






/**
 * Draws a cone, using spaces to format 'X's in a triangular shape. The height of the
 * cone depends on the specified width.
 *
 * Examples:
 * @code
 *      X
 *     X X      XX
 *    X   X    X  X
 *   X     X  X    X
 * @endcode
 *
 * @param cone_width the desired width of the cone. Note that if this parameter is even,
 * the tip of the cone will be two X's wide, rather than one.
 */
void drawCone(int cone_width) {
    int cone_height = (cone_width + 1) / 2; // add one for odd widths
    bool cone_is_even = cone_width % 2 == 0;

    drawConeTip(cone_height, cone_is_even);

    int inner_spacing = 1;
    if (cone_is_even) inner_spacing++;
    int outer_spacing = cone_height - 2; // second tier = two spaces out

    for (int level = 1;
         level < cone_height; level++, outer_spacing--, inner_spacing += 2) {
        drawConeRow(inner_spacing, outer_spacing);
    }
}






/**
 * Draws the very tip of a cone: one X if the cone has an even width, and two X's if the
 * cone has an odd width.
 *
 * @param cone_height the height of the cone, used to calculate correct spacing on either
 * side of the tip
 * @param cone_is_even whether or not the cone has an even width
 */
void drawConeTip(int cone_height, bool cone_is_even) {
    pad(cone_height - 1);
    if (cone_is_even) cout << "XX";
    else cout << "X";
    pad(cone_height - 1);
    cout << endl;
}






/**
 * Output a particular row of a cone, with inner and outer padding.
 *
 * @param inner_spacing the amount of spaces between the two X's in the row
 * @param outer_spacing the amount of spaces on the outside of the row
 */
void drawConeRow(int inner_spacing, int outer_spacing) {
    pad(outer_spacing);
    cout << "X";
    pad(inner_spacing);
    cout << "X";
    pad(outer_spacing);
    cout << endl;
}






/**
 * Simply pads the output with a given number of spaces.
 *
 * @param space_count the number of spaces to pad
 */
void pad(int space_count) {
    for (int i = 0; i < space_count; i++) {
        cout << " ";
    }
}






/**
 * Draws a box, with the specified dimensions. The inner rows are padded with spaces.
 *
 * @param width the width of the box
 * @param height the height of the box
 */
void drawBox(int width, int height) {
    drawHorizontalLine(width);
    draw2VerticalLines(width - 2, height - 2);
    drawHorizontalLine(width);
}






void drawHorizontalLine(int numXs) {
    int count;

    for (count = 0; count < numXs; count++) {
        cout << "X";
    }
    cout << endl;
}






void draw2VerticalLines(int numSpaces, int numRows) {
    int rowCount;

    for (rowCount = 0; rowCount < numRows; rowCount++) {
        drawOneRow(numSpaces);
    }
}






void drawOneRow(int numSpaces) {
    int spaceCount;

    cout << "X";
    for (spaceCount = 0; spaceCount < numSpaces; spaceCount++) {
        cout << " ";
    }
    cout << "X" << endl;
}

// Output
/*
Enter stage height: 5
Enter stage width: 9
Enter number of stages: 2
    X
   X X
  X   X
 X     X
X       X
XXXXXXXXX
X       X
X       X
X       X
XXXXXXXXX
XXXXXXXXX
X       X
X       X
X       X
XXXXXXXXX
    X
   X X
  X   X
 X     X
X       X

-- restart --

Enter stage height: 5
Enter stage width: 8
Enter number of stages: 1
   XX
  X  X
 X    X
X      X
XXXXXXXX
X      X
X      X
X      X
XXXXXXXX
   XX
  X  X
 X    X
X      X
*/
