/**
 * @author Lucas Street
 * @date 11/28/16
 * CS 10, Dave Harden
 * Assignment 13.1 - fraction.cpp
 *
 * fraction objects are always stored in lowest terms, and never have denominators of 0.
 *
 * Private data members:
 *   numerator: an integer representing the numerator of the fraction
 *   denominator: an integer representing the denominator of the fraction
 *
 * Both the numerator and denominator are used to calculate the various arithmetic
 * operations on fractions, testing equality, and finding factors for simplification.
 */

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "fraction.h"

using namespace std;






fraction::fraction() {
    numerator = 0;
    denominator = 1;
    // 0/1 is already simplified
}






fraction::fraction(int num, int denom) {
    if (denom == 0) {
        throw std::invalid_argument("denom cannot be 0");
    }
    numerator = num;
    denominator = denom;
    simplify();
}






/**
 * If the numerator of the first fraction times the denominator of the second is
 * equal to the denominator of the first times the numerator of the second, then the
 * fractions are equal.
 *
 * @param other the other fraction object to test
 * @return a boolean indicating whether the calling fraction is equal in value to the
 * provided fraction
 */
bool fraction::isEqualTo(const fraction &other) const {
    return (numerator * other.denominator) == (denominator * other.numerator);
}






void fraction::print() const {
    cout << numerator << "/" << denominator;
}






fraction fraction::addedTo(const fraction &other) const {
    int comDenominator = denominator * other.denominator;
    int numeratorSum = (numerator * other.denominator) + (other.numerator * denominator);
    fraction result(numeratorSum, comDenominator);
    result.simplify();
    return result;
}






fraction fraction::subtract(const fraction &other) const {
    fraction negated(-other.numerator, other.denominator);
    return addedTo(negated);
}






fraction fraction::multipliedBy(const fraction &other) const {
    fraction result(numerator * other.numerator, denominator * other.denominator);
    result.simplify();
    return result;
}






fraction fraction::dividedBy(const fraction &other) const {
    fraction reciprocal(other.denominator, other.numerator);
    return multipliedBy(reciprocal);
}






void fraction::simplify() {
    int gcf = getGCF();
    numerator /= gcf;
    denominator /= gcf;
}






/**
 * This function finds the greatest common factor between the numerator and the
 * denominator of a fraction.
 *
 * @return the greatest common factor
 */
int fraction::getGCF() const {
    int factor = 1;
    int gcf = 1;

    while (abs(numerator) >= factor && abs(denominator) >= factor) {
        if (numerator % factor == 0 && denominator % factor == 0) {
            gcf = factor;
        }
        factor++;
    }

    return gcf;
}
