#include "Header.h"
#include <iostream>

Rational::Rational (int givenNumerator, int givenDenominator) {
    Rational::setNum(givenNumerator);
    Rational::setDenom(givenDenominator);
}

void Rational::setNum (int givenNum) { Rational::numerator = givenNum; }

int Rational::getNum() { return Rational::numerator; }

void Rational::setDenom (int givenDenom) { Rational::denominator = givenDenom; }

int Rational::getDenom() { return Rational::denominator; }

void Rational::print() {
    if ((Rational::denominator == 0) && (Rational::numerator != 0))
        std::cout << "inf" << std::endl;
    else if ((Rational::denominator == 0) && (Rational::numerator == 0))
        std::cout << "nan" << std::endl;
    else
        std::cout << Rational::numerator << "/" << Rational::denominator << " = ";
}

void Rational::printFloat () {
    std::cout << (float) Rational::numerator / Rational::denominator << std::endl << std::endl;
}

int gcd (int first, int second) {
    first = abs(first);
    second = abs(second);
    int temp = (first < second) ? first : second;
    while ((second % temp != 0) || (first % temp != 0)) temp--;
    return temp;
}

void Rational::question (int r1Num, int r1Denom, int r2Num, int r2Denom, char sign) {
    std::cout << r1Num << "/" << r1Denom << " " << sign << " " << r2Num << "/" << r2Denom << " = ";
}

Rational Rational::add (const Rational & r2) {
    question(numerator, denominator, r2.numerator, r2.denominator,'+');
    if((denominator  == 0) || (r2.denominator == 0)) {
        Rational sum(numerator,0);
        return sum;
    }
    int resultNum, resultDenom;
    resultNum = (numerator * r2.denominator + r2.numerator * denominator);
    resultDenom = denominator * r2.denominator;
    if(resultNum == 0) {
        Rational sum(0,resultDenom);
        return sum;
    }
    Rational sum(resultNum / gcd(resultNum, resultDenom) , resultDenom / gcd(resultNum, resultDenom));
    return sum;
}

Rational Rational::subtract (const Rational & r2) {
    question(numerator, denominator, r2.numerator, r2.denominator, '-');
    if((denominator  == 0) || (r2.denominator == 0)) {
        Rational subt(numerator,0);
        return subt;
    }
    int resultNum, resultDenom;
    resultNum = (numerator * r2.denominator - r2.numerator * denominator);
    resultDenom = denominator * r2.denominator;
    if(resultNum == 0) {
        Rational odd(0,resultDenom);
        return odd;
    }
    Rational odd(resultNum / gcd(resultNum, resultDenom) , resultDenom / gcd(resultNum, resultDenom));
    return odd;
}

Rational Rational::multiply (const Rational & r2) {
    question(numerator, denominator, r2.numerator, r2.denominator,'*');
    if((denominator  == 0) || (r2.denominator == 0)) {
        Rational product(numerator,0);
        return product;
    }
    int resultNum, resultDenom;
    resultNum = numerator * r2.numerator;
    resultDenom = denominator * r2.denominator;
    if(resultNum == 0) {
        Rational product(0,resultDenom);
        return product;
    }
    Rational product(resultNum / gcd(resultNum, resultDenom) , resultDenom / gcd(resultNum, resultDenom));
    return product;
}

Rational Rational::divide (const Rational & r2) {
    question(numerator, denominator, r2.numerator, r2.denominator,'/');
    if ((denominator  == 0) || (r2.denominator == 0)) {
        Rational division(numerator,0);
        return division;
    }
    int resultNum, resultDenom;
    resultNum = numerator * r2.denominator;
    resultDenom = denominator * r2.numerator;
    if (resultNum == 0) {
        Rational division(0,resultDenom);
        return division;
    }
    Rational division(resultNum / gcd(resultNum, resultDenom) , resultDenom / gcd(resultNum, resultDenom));
    return division;
}

int main() {
    Rational r1(1,2);
    Rational r2(3,4);
    
    Rational add = r1.add(r2);
    add.print();
    add.printFloat();
    
    Rational subtract = r1.subtract(r2);
    subtract.print();
    subtract.printFloat();
    
    Rational multiply = r1.multiply(r2);
    multiply.print();
    multiply.printFloat();
    
    Rational divide = r1.divide(r2);
    divide.print();
    divide.printFloat();
    
    return 0;
}