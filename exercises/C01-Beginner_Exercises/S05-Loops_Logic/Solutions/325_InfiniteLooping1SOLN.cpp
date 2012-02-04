// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S05.h>
extern bool Gsoln;

int InfiniteLooping1Soln::runExercise()
{
    Gsoln = true;

    int x=20, y=20;
    int verticalstep=30;

    while ( y < 400 )
    {
        DrawText("y must exceed 400 for this loop to end!", x, y, BLUE, 10);
        y += verticalstep;  // when this line was commented out, y stayed 20 forever!

    }

    return 0;
}
