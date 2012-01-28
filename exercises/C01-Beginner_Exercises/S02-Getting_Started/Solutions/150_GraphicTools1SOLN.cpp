// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/GraphicTools1SOLN.cpp

// Chapter 00 Exercise 00 SOLutioN: Graphic Tools Intro.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int GraphicTools1Soln::runExercise()
{
    Gsoln = true;

    DrawLine(350, 50, 175,  0, GREEN, 1);
    DrawLine( 10, 10, 350, 10, YELLOW, 5);
    DrawLine(175, 50, 175,  0, RED, 2);
    DrawLine( 10, 30, 350, 30, YELLOW, 10);
    DrawLine(  0, 50, 175,  0, BLUE, 3);

    DrawCircle( 10, 100, 60, BLACK, 1, true);
    DrawCircle(100, 100, 40, GREEN, 2);
    DrawCircle(200, 100, 20, YELLOW, 3);
    DrawCircle(300, 100,  1, RED, 1);
    DrawLine(10, 100, 200, 100, PINK, 1);

    DrawEllipse( 10, 200, 60, 60, BLACK, 2, true);
    DrawEllipse(100, 200, 20, 40, GREEN, 1);
    DrawEllipse(200, 200, 70, 30, YELLOW, 5);
    DrawEllipse(300, 200,  1,  1, RED, 1);
    DrawEllipse(350, 200,  1, 30, BLUE, 1);
    DrawLine(10, 200, 200, 200, PINK, 1);

    DrawRectangle( 10, 300, 20, 20, GREEN, 1);
    DrawRectangle(100, 300, 10, 40, YELLOW, 3);
    DrawRectangle(200, 300, 30, 50, BLACK, 1, true );
    DrawRectangle(300, 300,  1,  1, RED, 1);
    DrawRectangle(350, 300,  1, 30, BLUE, 1);
    DrawLine(10, 300, 200, 300, PINK, 1);

    return 0;
}
