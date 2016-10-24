/**
 * @author Lucas Street
 * @date 10/24/16
 * CS 10, Dave Harden
 * Assignment 8.1 - a8_1.cpp
 *
 * Performs three sets of a chosen number of arithmetic problems, each using a different
 * operator (addition, subtraction, and multiplication). Each problem uses randomly
 * generated operands between 0 and a given max value, and allows the user to input a
 * guess for the correct answer to each problem. The user's guess is then compared to
 * the correct answer and the result (correct/incorrect) is printed to the screen. When
 * all three sets have been completed, a report of the user's performance is displayed on
 * the screen, showing the amount and percentage of problems answered correctly for each
 * set as well as in total.
 *
 * This program makes use of variables passed by reference: setting the amount of problems
 * per set, generating the two operands, setting the max operand value, calculating the
 * correct answer for each problem, and keeping track of correctly answered problems.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

void printReport(int add_probs_correct, int sub_probs_correct, int mul_probs_correct,
                 int problems_per_set);

void getProbsPerSet(int &problems_per_set);

void doOneSet(char operation, int problems_per_set, int &current_correct);

void printHeader(char operation);

void getMaxNum(int &max_number);

void doOneProblem(char operation, int max_number, int &current_correct);

void generateOperands(int &first_operand, int &second_operand, int max_number);

void calculateCorrectAnswer(int first_operand, int second_operand, int &answer,
                            char operation);

void checkAnswer(int correct_answer, int answer, int &current_correct);

using namespace std;

const int NUM_SETS = 3, ADDITION_SET = 1, SUBTRACTION_SET = 2, MULTIPLICATION_SET = 3;






/**
 * Seed the random number generator, then perform three sets of problems: one set of
 * addition problems, one set of subtraction problems, and one set of multiplication
 * problems. The user may choose the number of problems per set. At the end of the program
 * a report is displayed of the user's performance on all sets.
 */
int main() {
    int problems_per_set, add_probs_correct, sub_probs_correct, mul_probs_correct;

    srand(static_cast<unsigned>(time(0)));
    getProbsPerSet(problems_per_set);
    doOneSet('+', problems_per_set, add_probs_correct);
    doOneSet('-', problems_per_set, sub_probs_correct);
    doOneSet('*', problems_per_set, mul_probs_correct);
    printReport(add_probs_correct, sub_probs_correct, mul_probs_correct,
                problems_per_set);
    return 0;
}






/**
 * Generates and prints a report of the user's performance on all sets of problems. The
 * percentages of addition, subtraction, and multiplication problems answered correctly
 * are all calculated, as well as the total percentage of problems answered correctly. The
 * number and percentage are displayed for each set.
 *
 * @param add_probs_correct the number of addition problems answered correctly
 * @param sub_probs_correct the number of subtraction problems answered correctly
 * @param mul_probs_correct the number of multiplication problems answered correctly
 * @param problems_per_set the amount of problems per set
 */
void printReport(int add_probs_correct, int sub_probs_correct, int mul_probs_correct,
                 int problems_per_set) {
    int total_correct = add_probs_correct + sub_probs_correct + mul_probs_correct;
    int total_problems = problems_per_set * NUM_SETS;

    // multiply by 100 to get a percentage - meaningless to extract 100 to a constant...
    double percent_add_correct = ((double) add_probs_correct / problems_per_set) * 100;
    double percent_sub_correct = ((double) sub_probs_correct / problems_per_set) * 100;
    double percent_mul_correct = ((double) mul_probs_correct / problems_per_set) * 100;
    double percent_total_correct = ((double) total_correct / total_problems) * 100;

    cout << "\nSet#1:  You got " << add_probs_correct << " correct out of "
         << problems_per_set << " for " << fixed << setprecision(1) << percent_add_correct
         << "%" << endl;
    cout << "Set#2:  You got " << sub_probs_correct << " correct out of "
         << problems_per_set << " for " << fixed << setprecision(1) << percent_sub_correct
         << "%" << endl;
    cout << "Set#3:  You got " << mul_probs_correct << " correct out of "
         << problems_per_set << " for " << fixed << setprecision(1) << percent_mul_correct
         << "%" << endl;
    cout << "Overall you got " << total_correct << " correct out of " << total_problems
         << " for " << fixed << setprecision(1) << percent_total_correct << "%" << endl;
}






/**
 * Sets the amount of problems to create for each set of problems. This runs only once at
 * the beginning of the program.
 *
 * @param problems_per_set a reference to store the amount of problems per set
 */
void getProbsPerSet(int &problems_per_set) {
    cout << "Enter problems per set: ";
    cin >> problems_per_set;
}






/**
 * Perform a set of problems, using the specified operation to combine the two operands in
 * each problem. The number of problems in each set is also given, as well as a reference
 * to store the amount of problems answered correctly in this set.
 *
 * @param operation the operation for this problem set.
 * @param problems_per_set the number of problems in each set
 * @param current_correct the amount of problems answered correctly in this set (set to 0
 * initially, and then updated as the user answers each question)
 */
void doOneSet(char operation, int problems_per_set, int &current_correct) {
    printHeader(operation);
    int max_number;
    getMaxNum(max_number);
    current_correct = 0;
    for (int i = 0; i < problems_per_set; i++) {
        doOneProblem(operation, max_number, current_correct);
    }
}






/**
 * Depending on the operation for each problem set, a different set header is displayed.
 * Addition is set #1, subtraction is set #2, and multiplication is set #3.
 *
 * @param operation the operation of the current problem set
 */
void printHeader(char operation) {
    int set = 0;
    switch (operation) {
        case '+':
            set = ADDITION_SET;
            break;
        case '-':
            set = SUBTRACTION_SET;
            break;
        case '*':
            set = MULTIPLICATION_SET;
            break;
        default:
            break;
    }

    cout << "\nSet #" << set << endl;
    cout << "----------" << endl;
}






/**
 * Sets the maximum possible value for an operand, using the variable passed in by
 * reference.
 *
 * @param max_number the variable to hold the maximum value
 */
void getMaxNum(int &max_number) {
    cout << "What is the maximum number for this set? ";
    cin >> max_number;
}






/**
 * Perform the workflow for a single problem in a set. First, generate two operands within
 * the range 0 to a max value. Then, calculate a correct answer from those operands by
 * applying the specified operation, get an answer from the user, and finally compare the
 * answer with the previously calculated answer.
 *
 * @param operation the operation to perform on the generated operands
 * @param max_number the maximum possible value for an operand, used in generating the
 * two operands for this problem
 * @param current_correct the amount of problems correct in the current set, used when
 * checking the user's answer to this problem
 */
void doOneProblem(char operation, int max_number, int &current_correct) {
    int first_operand, second_operand, correct_answer;
    generateOperands(first_operand, second_operand, max_number);
    calculateCorrectAnswer(first_operand, second_operand, correct_answer, operation);

    int answer;
    cout << first_operand << " " << operation << " " << second_operand << " = ";
    cin >> answer;

    checkAnswer(correct_answer, answer, current_correct);
}






/**
 * Generates two random operands for a problem, assigning the results to the two arguments
 * passed into this function by reference. The operands are within the range 0 to a given
 * maximum value, inclusive.
 *
 * @param first_operand the first operand to use in the problem
 * @param second_operand the second operand to use in the problem
 * @param max_number the maximum possible value (inclusive) of an operand
 */
void generateOperands(int &first_operand, int &second_operand, int max_number) {
    first_operand = rand() % (max_number + 1);
    second_operand = rand() % (max_number + 1);
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
 * printed to the screen, and the number of problems answered correctly for this set is
 * increased by one. Otherwise, "incorrect" is printed.
 *
 * @param correct_answer the correct answer
 * @param answer the user-provided answer
 * @param current_correct the amount of problems answered correctly in the current set
 */
void checkAnswer(int correct_answer, int answer, int &current_correct) {
    if (answer == correct_answer) {
        cout << "correct" << endl;
        current_correct++;
    } else {
        cout << "incorrect" << endl;
    }
}

// Output
/*
Enter problems per set: 3

Set #1
----------
What is the maximum number for this set? 20
19 + 15 = 34
correct
7 + 20 = 27
correct
14 + 3 = -20
incorrect

Set #2
----------
What is the maximum number for this set? 20
4 - 4 = 0
correct
11 - 1 = 10
correct
3 - 10 = -7
correct

Set #3
----------
What is the maximum number for this set? 8
0 * 4 = -1
incorrect
8 * 8 = 0
incorrect
8 * 6 = 1826312821
incorrect

Set#1:  You got 2 correct out of 3 for 66.7%
Set#2:  You got 3 correct out of 3 for 100.0%
Set#3:  You got 0 correct out of 3 for 0.0%
Overall you got 5 correct out of 9 for 55.6%
*/
