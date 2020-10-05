//
//  sierpinski.cpp
//  Turtle
//
//  Created by Marcela on 10/18/18.
//  Copyright © 2018 Marcela. All rights reserved.
//
#include "sierpinski.hpp"


//Sierpinki Arrowhead
sierpinski::sierpinski(float initX, float initY, float initAngle):Turtle(initX, initY, initAngle){
    
}
// Left = 60 degrees
//Right = -60 degrees.

//draw a level-l left curve with dist d
//replace those three draws with right curve, turn(LEFT ),left
//curve, turn(LEFT ), and right curve of one level down. The
//following figure shows a level 2 left curve.
void sierpinski::leftCurve( int level, float d ){
    if(level == 1){
        draw(d);
        turn(60);
        draw(d);
        turn(60);
        draw(d);
    }
    else
        if(level > 1){
            rightCurve(level - 1, d);
            turn(60);
            leftCurve(level - 1, d);
            turn(60);
            rightCurve(level - 1, d);
        }
}

//draw a level-l right curve with dist d
//replace those three draws with left curve, turn (RIGHT ), right curve, turn(RIGHT )
//and left curve of one level down.
void sierpinski::rightCurve( int level, float d ){
    if(level == 1){
        draw(d);
        turn(-60);
        draw(d);
        turn(-60);
        draw(d);
    }
    
    if (level > 1){
        leftCurve(level - 1, d);
        turn(-60);
        rightCurve(level - 1, d);
        turn(-60);
        leftCurve(level - 1, d);
    }
    else
        draw (d);
} //draw a level-l right curve with dist d
