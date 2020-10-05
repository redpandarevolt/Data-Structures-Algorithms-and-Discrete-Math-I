// a Rational object holds one Rational number, one fraction
#include "rat.h"

//----------------------- Rational ------------------------------------
// default constructor:  parameters are numerator and denominator respectively
// if the number is negative, the negative is always stored in the numerator
Rational::Rational(int nn, int dd) {
    numerator = nn;
    denominator = dd;
    
    numerator = dd < 0 ? -nn : nn;
    denominator = dd < 0 ? -dd : dd;
    
    reduce();
}
//-----------------Operator + add--------------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::operator+(const Rational& a)const {
    Rational t;
    
    t.numerator = a.numerator * denominator + a.denominator * numerator;
    t.denominator = a.denominator * denominator;
    t.reduce();
    
    return t;
}

//--------------------------operator- subtract-----------------------------------
// subtraction of 2 Rationals, current object and parameter

Rational Rational::operator-(const Rational& s)const {
    Rational t;
    
    t.numerator = s.denominator * numerator - denominator * s.numerator;
    t.denominator = s.denominator * denominator;
    t.reduce();
    
    return t;
}

//----------------------Operator *------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::operator*(const Rational &m) const{
    Rational t;
    
    t.numerator = m.numerator * numerator;
    t.denominator = m.denominator * denominator;
    t.reduce();
    
    return t;
}

//------------------------operator / divide----------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero crashes
Rational Rational::operator/(const Rational& v) const{
    Rational t;
    
    t.numerator = v.denominator * numerator;
    t.denominator = denominator * v.numerator;
    t.reduce();
    
    return t;
}

bool Rational::operator>(const Rational& r) const {
    return (float)numerator/denominator > (float)r.numerator/r.denominator;
}

bool Rational::operator<(const Rational& r)const {
    return (float)numerator/denominator < (float)r.numerator/r.denominator;
}

bool Rational::operator>=(const Rational& r)const {
    return *this == r || *this > r;
}

bool Rational::operator==(const Rational& r)const {
    return numerator==r.numerator && denominator == r.denominator;
}

bool Rational::operator<=(const Rational& r)const {
    return *this == r || *this < r;
}

bool Rational::operator!=(const Rational& r)const{
    return !(*this == r);
}

Rational& Rational::operator+=(const Rational& r) {
    numerator = numerator * r.denominator + denominator * r.numerator;
    denominator = denominator * r.denominator;
    reduce();
    return *this;
}

Rational& Rational::operator-=(const Rational& r) {
    numerator = numerator * r.denominator - denominator * r.numerator;
    denominator = denominator * r.denominator;
    reduce();
    return *this;
}




//-----------------------------add--------------------------------------
// overloaded +: addition of 2 Rationals, current object and parameter
Rational Rational::add(const Rational& a)const {
   Rational t;
   t.numerator = a.numerator * denominator + a.denominator * numerator;
   t.denominator = a.denominator * denominator;
   t.reduce();
   return t;
}

//-------------------------- subtract-----------------------------------
// subtraction of 2 Rationals, current object and parameter

Rational Rational::subtract(const Rational& s)const {
    Rational t;
    t.numerator = s.denominator * numerator - denominator * s.numerator;
    t.denominator = s.denominator * denominator;
    t.reduce();
    return t;
}

//------------------------- multiply------------------------------------
// multiplication of 2 Rationals, current object and parameter
Rational Rational::multiply(const Rational& m)const {
   Rational t;

   t.numerator = m.numerator * numerator;
   t.denominator = m.denominator * denominator;
   t.reduce();

   return t;
}

//------------------------------divide----------------------------------
// division of 2 Rationals, current object and parameter,
// division by zero crashes
Rational Rational::divide(const Rational& v)const{
   Rational t;

   t.numerator = v.denominator * numerator;
   t.denominator = denominator * v.numerator;
   t.reduce();

   return t;
}

//----------------------- printRational---------------------------------
void Rational::printRational() const {
   if (denominator == 0)
      cout << "DIVIDE BY ZERO ERROR!!!" << endl;
   else if (numerator == 0)
      cout << 0 << endl;
   else if (numerator == denominator)
       cout << 1;
   else
      cout << numerator << "/" << denominator;
}

//------------------ printRationalAsFloat ------------------------------
void Rational::printRationalAsFloat(){
    if (denominator == 0)
        cout << endl << "DIVIDE BY ZERO ERROR!!!" << endl;
    else
        cout << float(numerator) / float(denominator);
}

ostream& operator<<(ostream& output, const Rational& r){
    if (r.denominator == 0)
        cout << "DIVIDE BY ZERO ERROR!!!" << endl;
    else if (r.numerator == 0)
        cout << 0;
    else if (r.numerator == r.denominator)
        cout << 1;
    else
        cout << r.numerator << "/" << r.denominator;
    return output;
}

istream& operator>>(istream& input, Rational& r) {
    input >> r.numerator;
    input >> r.denominator;
    r.reduce();
    return input;
}

int Rational::getNumerator() {
    return numerator;
}

int Rational::getDenominator(){
    return denominator;
}

//------------------------- reduce ------------------------------------
// reduce fraction to lowest terms
void Rational::reduce() {
   int n = numerator < 0 ? -numerator : numerator;
   int d = denominator;
   int largest = n > d ? n : d;

   int gcd = 0;                                 // greatest common divisor

   for (int loop = largest; loop >= 2; loop--)
      if (numerator % loop == 0 && denominator % loop == 0) {
         gcd = loop;
         break;
      }

   if (gcd != 0) {
      numerator /= gcd;
      denominator /= gcd;
   }
}

