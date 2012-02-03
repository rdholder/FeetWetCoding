// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int WhileLoop1::runExercise()       // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;                  // is this exercise code or solution code?

    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(0, 0, x, 400, BLUE, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(0, 0, 400, y, RED, 1);
    }

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    WhileLoop1Soln *solution = new WhileLoop1Soln();
    solution->runExercise();

    return 0;

}
