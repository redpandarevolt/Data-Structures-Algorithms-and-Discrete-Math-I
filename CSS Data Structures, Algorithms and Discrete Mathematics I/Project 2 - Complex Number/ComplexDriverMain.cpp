//
//  main.cpp
//  Complex
//
//  Created by Marcela on 10/11/18.
//  Copyright © 2018 Marcela. All rights reserved.
//

#include <iostream>
#include "Complex.hpp"

using namespace std;
int main( ) {
    
    Complex c1, c2( 1.2, 4.9 ), c3( 2.2, 1.0 ), c4( -7.0, 9.6 ), c5(8.1, -4.3), c6(0.0, -7.1), c7(6.4), c8(0.0, 1.0), c9(0.0, 4.1), c10(0.0, -1.0), c11;
    
    cout << "type two doubles for c11: ";
    cin >> c11;
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c6 = " << c6 << endl;
    cout << "c7 = " << c7 << endl;
    cout << "c8 = " << c8 << endl;
    cout << "c9 = " << c9 << endl;
    cout << "c10 = " << c10 << endl;
    cout << "c11 = " << c11 << endl;
    
    cout << "c1 + c2 + c3 = " << c1 + c2 + c3 << endl;
    cout << "c7 - c8 - c9 = " << c7 - c8 -c9<< endl;
    cout << "c2 * 22 = " << (c2 * 22) << endl;
    cout << "c2 * c3 = " << c2 * c3 << endl;
    cout << "c2 / c3 = " << c2 / c3 << endl;
    cout << "c2 / c1 = " << c2 / c1 << endl;
    cout << "c2 / c5 = " << c2 / c5 << endl;
    
    
    cout << "c4 == c4 is " << ( ( c4 == c4 ) ? "true" : "false" ) << endl;
    cout << "c4 != c4 is " << ( ( c4 != c4 ) ? "true" : "false" ) << endl;
    
    cout<< "Conjugate of " << c5 << " is " << c5.conjugate() << endl;
    cout<< "Real of " << c3 << " is " << c3.getReal()<<endl;
    cout<< "Imaginary of " << c4 << " is " << c4.getImaginary()<<endl;
    
    cout << "(c5 += c2) += c3 is " << ( (c5 += c2) += c3 ) << endl;
    cout << "(c5 -= c1) -= c2 is " << ( (c5 -= c1) -= c2 ) << endl;
    cout << "(c5 *= 22) *= 13 is " << ( (c5 *= 22) *= 13 ) << endl;
    cout << "(c5 *= c4) *= c4 is " << ( (c5 *= c4) *= c4 ) << endl;
    cout << "(c3 /= 2) / c3 is " << ( (c3 /= 2 ) / c3 ) << endl;
    cout << "c4 is " << c4 << endl;
    cout << "(c4 /= c1) / c1 is " << ( (c4 /= c1 ) / c1 ) << endl;
    cout << "c4 is " << c4 << endl;
};
