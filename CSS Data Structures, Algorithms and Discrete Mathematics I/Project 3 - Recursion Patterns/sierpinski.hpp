//
//  sierpinski.hpp
//  Turtle
//
//  Created by Marcela on 10/18/18.
//  Copyright © 2018 Marcela. All rights reserved.
//

// sierpinski Class
#ifndef SIERPINSKI_H
#define SIERPINSKI_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class sierpinski : Turtle {
public:
    sierpinski( float initX=0.0, float initY=0.0, float initAngle=0.0 );
    void leftCurve( int level, float d );  //draw a level-l left curve with dist d
    void rightCurve( int level, float d ); //draw a level-l right curve with dist d
};
#endif
