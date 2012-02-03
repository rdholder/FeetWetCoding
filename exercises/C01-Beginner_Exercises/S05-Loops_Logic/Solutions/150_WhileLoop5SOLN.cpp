// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int WhileLoop5Soln::runExercise()
{
    Gsoln = true;

    int x=100, y=100;
    int horizontalstep=30, verticalstep=30;

    while ( x < 280 )
    {
        while ( y < 280 )
        {
            DrawRectangle(x, y, 25, 25, RED, 1, true);
            y += verticalstep;
        }
        y=100;
        x += horizontalstep;
    }

    return 0;
}
