// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S05.h>
extern bool Gsoln;

int WhileLoop2Soln::runExercise()
{
    Gsoln = true;

    int x=0, y=0;
    int verticalstep=10, horizontalstep=15;

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(0, 200, 200, y, BLUE, 1);
    }

    y=0;

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(400, 200, 200, y, RED, 1);
    }

    return 0;

}
