//
//  Complex.hpp
//  Complex Class holds on real number and one
//    inagineray number.
//
//  Created by Marcela on 10/11/18.
//  Copyright © 2018 Marcela. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include<iostream>
#include <stdio.h>
using namespace std;

class Complex {
    
    //input and output stream, friend gives full access to all variables.
    //friend ok for no local class definition of non-member function
    friend ostream& operator<<(ostream& output, const Complex & r);
    friend istream& operator>>(istream& input, Complex & r);
    
public:
    
    Complex(double = 0.0, double = 0.0); //default constructor
    
    double getReal();  //member functions
    double getImaginary();
    
    // operator add, subtract, multiply and divide methods
    Complex operator +(const Complex &)const;
    Complex operator -(const Complex &)const;
    Complex operator *(const Complex &)const;
    Complex operator /(const Complex &)const;
    
    //conjugate of denominator in division of complex numbers
    Complex conjugate();
    
    //boolean comparison operators
    bool operator==(const Complex &)const;
    bool operator!=(const Complex &)const;
    
    // assignement operators
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
    
private:
    
    //private variable of Complex class.
    double real;
    double imaginary;
};

#endif /* Complex_hpp */
