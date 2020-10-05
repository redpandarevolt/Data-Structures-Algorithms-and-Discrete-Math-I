// driver for Problem 6.7, Deitel and Deitel

#include "rat.h"

// to compile under unix: g++ rat.cpp revisedDriver.cpp

int main() {
    
    /* Testing old rat files*/
    Rational x(-2,6), y(-14,-16), z, w(4), copy(x);
    
    x.printRational(); cout << " + "; y.printRational();
    
    z = x.add(y);
    cout << " = "; z.printRational(); cout << endl;
    z.printRational();
    cout << " = "; z.printRationalAsFloat(); cout << endl << endl;
    
    cout<<"z = "<<z<<endl;
    
    x.printRational(); cout << " - "; y.printRational();
    z = x.subtract(y);
    cout << " = "; z.printRational(); cout << endl;
    z.printRational();
    cout << " = "; z.printRationalAsFloat(); cout << endl << endl;
    
    x.printRational(); cout << " * "; y.printRational();
    z = x.multiply(y);
    cout << " = "; z.printRational(); cout << endl;
    z.printRational();
    cout << " = "; z.printRationalAsFloat(); cout << endl << endl;
    
    x.printRational(); cout << " / "; y.printRational();
    z = x.divide(y);
    cout << " = "; z.printRational(); cout << endl;
    z.printRational();
    cout << " = "; z.printRationalAsFloat(); cout << endl;
    
    /* Testing additional methods defined */
    cout<<"Now test additional methods defined"<<endl;
    cout<<"getNumerator:"<<x.getNumerator()<<" getDenominator:"<<x.getDenominator()<<endl;
    
    
    cout << "The copy object looks just like its parameter, copy = " << copy<< endl;
    z = x + y;
    cout << x << " + " << y << " = " << z << endl;
    
    z = w + y;
    cout << w << " + " << y << " = " << z << endl;
    
    z = x - y;
    cout << x << " - " << y << " = " << z << endl;
    
    z = x * y;
    cout << x << " * " << y << " = " << z << endl;
    
    z = x / y;
    cout << x << " / " << y << " = " << z << endl;
    
    z = x + 5;
    cout << x << " + " << 5 << " = " << z << endl;
    
    //ERROR -- no match for operator +(int, class Rational)
    // z = 5 + x;
    
    z = Rational(5) + x;
    cout << 5 << " + " << x << " = " << z << endl;
    
    //ERROR -- no match for operator -(class Rational, class Rational)
    // z -= x;
    
    cout<< "get values for z"<<endl;
    cin>>z;
    
    cout << "z is "<< z <<endl;
    
    
    
    cout << x << " is:" << endl;
    
    cout << ((x > y) ? " > " : " not > ");
    cout << y << " according to the overloaded > operator\n";
    
    cout << ((x < y) ? " < " : " not < ");
    cout << y << " according to the overloaded < operator\n";
    
    cout << ((x >= y) ? " >= " : " not >= ");
    cout << y << " according to the overloaded >= operator\n";
    
    cout << ((x <= y) ? " <= " : " not <= ");
    cout << y << " according to the overloaded <= operator\n";
    
    cout << ((x == y) ? " == " : " not == ");
    cout << y << " according to the overloaded == operator\n";
    
    cout << ((x != y) ? " != " : " not != ");
    cout << y << " according to the overloaded != operator" << endl;
    
    cout << x << " + " << y;
    x += y;
    cout << " = the now changed " << x << endl;
    
    return 0;
}

