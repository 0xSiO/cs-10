/**
 * @author Lucas Street
 * @date 10/17/16
 * CS 10, Dave Harden
 * Assignment 7.1 - a7_1.cpp
 *
 * Performs three sets of five arithmetic problems, each using a different operator. Each
 * problem uses randomly generated operands between 0 and 100 and allows the user to input
 * a guess for the correct answer to each problem. The user's guess is then compared to
 * the correct answer and the result is printed to the screen. This program makes use of
 * variables passed by reference, such as when generating the two operands, as well as in
 * calculating the correct answer to each problem. Currently the only operations available
 * are addition, subtraction, and multiplication.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

void doOneSet(char operation);

void doOneProblem(char operation, int max_number, int current_correct);

void generateOperands(int first_operand, int second_operand, int max_number);

void calculateCorrectAnswer(int first_operand, int second_operand, int &answer,
                            char operation);

void checkAnswer(int correct_answer, int answer, int &current_correct);

using namespace std;

const int PROBLEMS_PER_SET = 5;






/**
 * Seed the random number generator, then perform three sets of 5 problems: one set of
 * addition problems, one set of subtraction problems, and one set of multiplication
 * problems.
 */
int main() {
    srand(static_cast<unsigned>(time(0)));
    doOneSet('+');
    doOneSet('-');
    doOneSet('*');
    return 0;
}






/**
 * Perform a set of problems, using the specified operation to combine the two operands in
 * each problem. The number of problems in each set is PROBLEMS_PER_SET.
 *
 * @param operation the operation for this problem set.
 */
void doOneSet(char operation) {
    for (int i = 0; i < PROBLEMS_PER_SET; i++) {
        doOneProblem(operation, 0, 0);
    }
}






/**
 * Perform the workflow for a single problem in a set. First, generate two operands. Then,
 * calculate a correct answer from those operands by applying the specified operation,
 * get an answer from the user, and finally compare the answer with the previously
 * calculated answer.
 *
 * @param operation the operation to perform on the generated operands
 */
void doOneProblem(char operation, int i, int i) {
    int first_operand, second_operand, correct_answer;
    generateOperands(first_operand, second_operand, 0);
    calculateCorrectAnswer(first_operand, second_operand, correct_answer, operation);

    int answer;
    cout << first_operand << " " << operation << " " << second_operand << " = ";
    cin >> answer;

    checkAnswer(correct_answer, answer, <#initializer#>);
}






/**
 * Generates two random operands for a problem, assigning the results to the two arguments
 * passed into this function by reference.
 *
 * @param first_operand the first operand to use in the problem
 * @param second_operand the second operand to use in the problem
 */
void generateOperands(int first_operand, int second_operand, int i) {
    first_operand = rand() % 101; // will turn 101 into variable on next assignment
    second_operand = rand() % 101;
}






/**
 * Calculates the correct answer for a problem given the two operands, a reference to the
 * correct answer variable, and the operation to use on the operands. Using a switch
 * statement on the operation, the calculation is performed one of a few ways and the
 * result is assigned to correct_answer.
 *
 * @param first_operand the first operand to use in the calculation
 * @param second_operand the second operand to use in the calculation
 * @param correct_answer a reference to the correct answer variable
 * @param operation the operation to use on the two operands
 */
void calculateCorrectAnswer(int first_operand, int second_operand, int &correct_answer,
                            char operation) {
    switch (operation) {
        case '+':
            correct_answer = first_operand + second_operand;
            break;
        case '-':
            correct_answer = first_operand - second_operand;
            break;
        case '*':
            correct_answer = first_operand * second_operand;
            break;
        default:
            cout << "invalid operation" << endl;
            break;
    }
}






/**
 * Compares the user-provided answer with the correct answer. If they match, "correct" is
 * printed to the screen. Otherwise, "incorrect" is printed.
 *
 * @param correct_answer the correct answer
 * @param answer the user-provided answer
 */
void checkAnswer(int correct_answer, int answer, int &i) {
    if (answer == correct_answer) {
        cout << "correct" << endl;
    } else {
        cout << "incorrect" << endl;
    }
}

// Output
/*
24 + 27 = 51
correct
96 + 63 = 159
correct
41 + 11 = 52
correct
10 + 57 = 67
correct
62 + 49 = 1
incorrect
77 - 62 = 15
correct
57 - 8 = 49
correct
28 - 19 = 0
incorrect
21 - 35 = -16
incorrect
75 - 64 = 11
correct
38 * 18 = 684
correct
91 * 96 = 8736
correct
15 * 81 = 0
incorrect
92 * 26 = 2392
correct
0 * 27 = 0
correct
*/
