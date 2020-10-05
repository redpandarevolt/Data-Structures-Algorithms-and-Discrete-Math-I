//
//  dragon.hpp
//  Dragon
//
//  Created by Marcela on 10/23/18.
//  Copyright © 2018 Marcela. All rights reserved.
//

#ifndef dragon_hpp
#define dragon_hpp

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;

class Dragon : Turtle {
public:
    Dragon(float initX = 0.0, float initY = 0.0, float initAngle = 0.0);
    void leftCurve(int l, float d);
    void rightCurve(int l, float d);
    
};
#endif /* dragon_hpp */
