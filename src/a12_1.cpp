/**
 * @author Lucas Street
 * @date 11/19/16
 * CS 10, Dave Harden
 * Assignment 12.1 - a12_1.cpp
 */

#include <iostream>

using namespace std;

class fraction {
    public:
        void set(int numerator, int denominator);

        bool isEqualTo(const fraction &other);

        void print();

        fraction addedTo(const fraction &other);

        fraction subtract(const fraction &other);

        fraction multipliedBy(const fraction &other);

        fraction dividedBy(const fraction &other);

    private:
        int numerator, denominator;
};






void fraction::set(int numeratorToSet, int denominatorToSet) {
    numerator = numeratorToSet;
    denominator = denominatorToSet;
}






bool fraction::isEqualTo(const fraction &other) {
    return (numerator * other.denominator) == (denominator * other.numerator);
}






void fraction::print() {
    cout << numerator << "/" << denominator;
}






fraction fraction::addedTo(const fraction &other) {
    fraction result;
    int comDenominator = denominator * other.denominator;
    int numeratorSum = (numerator * other.denominator) + (other.numerator * denominator);
    result.set(numeratorSum, comDenominator);
    return result;
}






fraction fraction::subtract(const fraction &other) {
    fraction negated;
    negated.set(-other.numerator, other.denominator);
    return addedTo(negated);
}






fraction fraction::multipliedBy(const fraction &other) {
    fraction result;
    result.set(numerator * other.numerator, denominator * other.denominator);
    return result;
}






fraction fraction::dividedBy(const fraction &other) {
    fraction reciprocal;
    reciprocal.set(other.denominator, other.numerator);
    return multipliedBy(reciprocal);
}






int main() {
    fraction f1;
    fraction f2;
    fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)) {
        cout << "The two fractions are equal." << endl;
    } else {
        cout << "The two fractions are not equal." << endl;
    }
}

// Output
/*
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two fractions are not equal.
*/
