// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int WhileLoop3Soln::runExercise()
{
    Gsoln = true;

    int x=0, y=0;
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(200, 200, x, 400, BLUE, 1);
        DrawLine(200, 200, x, 0, RED, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(200, 200, 400, y, GREEN, 1);
        DrawLine(200, 200, 0, y, YELLOW, 1);
    }

    return 0;

}
