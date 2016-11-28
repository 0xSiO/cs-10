/**
 * @author Lucas Street
 * @date 11/28/16
 * CS 10, Dave Harden
 * Assignment 13.1 - fraction.h
 *
 * A fraction stores a quotient of two numbers in the form NUMERATOR/DENOMINATOR.
 * fractions may be added, subtracted, multiplied, and divided by each other.
 *
 * fraction();
 * @pre none
 * @post the constructed fraction has a value of 0/1
 *
 * fraction(int num, int denom);
 * @pre num and denom are integers; denom is not 0
 * @post the constructed fraction has a value of num/denom, simplified to smallest terms
 *
 * bool isEqualTo(const fraction &other) const;
 * @pre the argument is a valid fraction
 * @post the value returned is either true or false
 *
 * void print() const;
 * @pre the calling object is a valid fraction
 * @post no parameter or data member changes
 *
 * fraction addedTo(const fraction &other) const;
 * @pre the calling object and the argument are valid fractions
 * @post the value returned is a fraction with a value equal to the sum of the calling
 * fraction and the argument
 *
 * fraction subtract(const fraction &other) const;
 * @pre the calling object and the argument are valid fractions
 * @post the value returned is a fraction with a value equal to the difference between
 * the calling fraction and the argument
 *
 * fraction multipliedBy(const fraction &other) const;
 * @pre the calling object and the argument are valid fractions
 * @post the value returned is a fraction with a value equal to the product of the calling
 * fraction and the argument
 *
 * fraction dividedBy(const fraction &other) const;
 * @pre the calling object and the argument are valid fractions
 * @post the value returned is a fraction with a value equal to the quotient of the
 * calling fraction and the argument
 */

#ifndef CS10_FRACTION_H
#define CS10_FRACTION_H

class fraction {
    public:
        fraction();

        fraction(int num, int denom);

        bool isEqualTo(const fraction &other) const;

        void print() const;

        fraction addedTo(const fraction &other) const;

        fraction subtract(const fraction &other) const;

        fraction multipliedBy(const fraction &other) const;

        fraction dividedBy(const fraction &other) const;

    private:
        int numerator, denominator;

        void simplify();

        int getGCF() const;
};

#endif //CS10_FRACTION_H
