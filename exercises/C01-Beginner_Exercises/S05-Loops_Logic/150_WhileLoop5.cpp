// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int WhileLoop5::runExercise()
{
    Gsoln = false;                  // is this exercise code or solution code?

    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int horizontalstep=70, verticalstep=70;

    while ( x < 400 )
    {
        while ( y < 600 )
        {
            DrawRectangle(x, y, 25, 25, RED, 1, true);
            y += verticalstep;
        }
        y=0;
        x += horizontalstep;
    }

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    WhileLoop5Soln *solution = new WhileLoop5Soln();
    solution->runExercise();

    return 0;
}
