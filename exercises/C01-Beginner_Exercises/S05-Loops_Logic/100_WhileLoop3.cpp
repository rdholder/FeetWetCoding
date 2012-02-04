// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S05.h>
extern bool Gsoln;

int WhileLoop3::runExercise()
{
    Gsoln = false;                  // is this exercise code or solution code?

    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(200, 0, x, 400, BLUE, 1);
        DrawLine(200, 400, x, 0, RED, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(0, 200, 400, y, GREEN, 1);
        DrawLine(400, 200, 0, y, YELLOW, 1);
    }

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    WhileLoop3Soln *solution = new WhileLoop3Soln();
    solution->runExercise();

    return 0;

}
