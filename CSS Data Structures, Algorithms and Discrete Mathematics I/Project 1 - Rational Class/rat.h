// a Rational object holds one Rational number, one fraction

#ifndef RAT_H
#define RAT_H
#include <iostream>
using namespace std;

class Rational {
friend ostream& operator<<(ostream& output, const Rational& r);
friend istream& operator>>(istream& input, Rational & r);
    
    // not fully commented
    //no return type here
public:
   Rational(int = 0, int = 1);  // default  constructor
    //allows for three different constructor types
    //second number can't be 0 because division by 0 not allowed
    //Rational r1(2, -3)    means 2/-3
    //Rational r2(1)        means 1/1=1
    //Rational r3           means 0/1 =0
//dont' to touch parameter, create new rational class to return.
    
    Rational operator+(const Rational &)const;
    Rational operator-(const Rational &)const;
    Rational operator*(const Rational &)const;
    Rational operator/(const Rational &)const;
    
    bool operator>(const Rational &)const;
    bool operator<(const Rational &)const;
    bool operator>=(const Rational &)const;
    bool operator==(const Rational &)const;
    bool operator<=(const Rational &)const;
    bool operator!=(const Rational &)const;
    
    Rational& operator+=(const Rational &);
    Rational& operator-=(const Rational &);
    //Rational& operator*=(const Rational &):
    //Rational& operator/=(const Rational &);
    
    void printRational()const;
    void printRationalAsFloat();
    int getNumerator();
    int getDenominator();
    
    Rational add(const Rational &)const;
    Rational subtract(const Rational &)const;
    Rational multiply(const Rational &)const;
    Rational divide(const Rational &)const;

private:
    int numerator;
    int denominator;
    void reduce(); // utility function, reduce to lowest terms
};

#endif

