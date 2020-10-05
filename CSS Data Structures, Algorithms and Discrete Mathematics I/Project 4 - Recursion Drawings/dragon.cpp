//
//  dragon.cpp
//  Dragon
//
//  Created by Marcela on 10/23/18.
//  Copyright © 2018 Marcela. All rights reserved.
//

#include "dragon.hpp"

const int RIGHT = -90;
const int LEFT = 90;

Dragon::Dragon(float initX, float initY, float initAngle): Turtle(initX, initY, initAngle){
}

void Dragon::rightCurve(int level, float d){
    if(level > 0)
    {
        turn(RIGHT);
        leftCurve(level - 1, d);
        turn(RIGHT);
        rightCurve(level - 1, d);
    }
    else
        draw(d);
}

void Dragon::leftCurve(int level, float d){
    if(level > 0)
    {
        leftCurve(level -1, d);
        turn(LEFT);
        rightCurve(level -1, d);
        turn(LEFT);
    }
    else
        draw(d);
}
