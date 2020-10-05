//
//  Complex.cpp
//  Complex
//
//  Created by Marcela on 10/11/18.
//  Copyright © 2018 Marcela. All rights reserved.
//
#include<iostream>
#include "Complex.hpp"

//Complex constructor of Complex class
//Initialization of of variables real and imaginary
Complex::Complex(double r, double i){
    real = r;
    imaginary = i;
    
    if( r == 0 && i == 0)       // data type with (0,0)
       cout << "";
    else if (r == 0 && i == 1)  // data type (0,1)
        cout << "i" << endl;
    else if (r == 0 && i < -1)  // data type (0, -7)
        cout << i << "i" << endl;
    else if (r == 0 && i == (-1)) // data type (0,-1)
        cout << "-i" << endl;
    else if (r < 0 && i == 0)   // data type (-4,0)
        cout << r <<endl;
    else if ( r > 0 && i < 0)   // data type (4 , -4)
        cout << r << i<< "i" << endl;
    else if (r < 0 && r < -1)   // data type (-4,-4)
        cout << r << i << "i" << endl;
    else
        cout << *this <<endl;   // pointer returns complex object
}

//Output Stream Operator: This handles all different cases
//of Complex Class: (0,0)  (0,1)
ostream& operator<<(ostream& output, const Complex& r){
    if (r.real == 0 && r.imaginary == 0)  // (0,0)
        cout << 0;
    else if (r.real == 0 && r.imaginary == 1)   //case (0, 1)
        cout << "i";
    else if (r.real == 0 && r.imaginary == -1)  //case (0, 1)
        cout << "-i";
    else if (r.real == 0  && r.imaginary > 0)   //case (0, 3)
        cout << r.imaginary<< "i";
    else if (r.real > 0 && r.imaginary == 0)    //case (3, 0)
        cout << r.real;
    else if (r.real > 0 && r.imaginary == 1)    //case (5, 1)
        cout << r.real<< " + i";
    else if (r.real > 0 && r.imaginary == -1)   //case (5, -1)
        cout << r.real<< " - i";
    else if (r.real > 0 && r.imaginary < 0)     //case (4, -4)
        cout << r.real <<" "<< r.imaginary << "i";
    else if (r.real < 0 && r.imaginary < 0)     //case (-4, -4)
        cout << r.real <<" "<< r.imaginary << "i";
    else
        cout << r.real << " + " << r.imaginary << "i"; //case (4, 4)
    return output;
}

//Input stream used with cin>> call to get
//an imaginary and real number from user.
istream& operator>>(istream& input, Complex& r) {
    input >> r.real;
    input >> r.imaginary;
    return input;
}
 //Accessor that returns either the real or imaginary number.
double Complex::getReal(){
    return real;
}
double Complex::getImaginary(){
    return imaginary;
}

//Method adds two complex numbers and returns the sum.
Complex Complex::operator+(const Complex& a)const{
    Complex sum;
    sum.real = (real + a.real);
    sum.imaginary = (imaginary + a.imaginary);
    return sum;
}
//Method subtracts two complex and returns the difference.
Complex Complex::operator-(const Complex& s)const{
    Complex diff;
    diff.real = (s.real -real);
    diff.imaginary = (s.imaginary - imaginary);
    return diff;
}
//Methos multiplies two complex numbers and returns the result.
Complex Complex::operator*(const Complex& m) const {
    Complex multiply;
    multiply.real = (m.real * real) - (m.imaginary * imaginary);
    multiply.imaginary = (real * m.imaginary) + (imaginary *m.real);
    return multiply;
}

//Methos divides two complex numbers by dividing each
//real and imaginary half by the denominator and
//returns a comple object (real, imaginary).
Complex Complex::operator/(const Complex& d) const {
    Complex division;
    double div = (d.real * d.real) - (d.imaginary * d.imaginary);
    if (div == 0)
    {
        cout << "Error: division by 0 not allowed" << endl;
        return *this;
    }
    division.real = (d.real * real) + (d.imaginary * imaginary);
    division.real = division.real / div;
    division.imaginary = (-real * d.imaginary) + (d.real * imaginary);
    division.imaginary = division.imaginary / div;
    return division;
}

//Operator overload allows for use of the += function.
Complex& Complex::operator+=(const Complex& r){  //looks off
    real = (real + r.real);
    imaginary = (imaginary + r.imaginary);
    return *this;
}

//Operator overload allows for use of the -= function.
Complex& Complex::operator-=(const Complex& d){
    real = (d.real - real);
    imaginary = (d.imaginary - imaginary);
    return *this;
}
//Operator overload allows for use of the *= function.
Complex& Complex::operator*=(const Complex& m){
    real = (m.real * real) - (m.imaginary * imaginary);
    imaginary = (real * m.imaginary) + (imaginary *m.real);
    return *this;
}

//Operator overload allows for use of the /= function.
//Uses the method in the add() above.
Complex& Complex::operator/=(const Complex& d){
    double div = (d.real * d.real) - (d.imaginary * d.imaginary);
    if (div == 0)
    {
        cout << "Error: division by 0 not allowed" << endl;
        return *this;
    }
    real = ((d.real * real) + (d.imaginary * imaginary));
    real = real / div;
    imaginary = (-d.imaginary * real) + (d.real * imaginary);
    imaginary = imaginary / div;
    return *this;
}

//Congjugate method takes the complex obj and
//returns the mathematical conjugate of the demoninator
//when dividing to complex numbers.
Complex Complex::conjugate(){
    return Complex(real, -imaginary);
}

//Comparator class allow for use of == returns a boolean.
bool Complex::operator==(const Complex& r)const{
    return real == r.real && imaginary == r.imaginary;
}
//Comparator class allow for use of != returns a boolean.
bool Complex::operator!=(const Complex& r)const{
    return !(real == r.real) || !(imaginary == r.imaginary);
}

