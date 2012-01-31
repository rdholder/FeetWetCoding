// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int WhileLoop4::runExercise()
{
    Gsoln = false;                  // is this exercise code or solution code?

    int x=0, y=600;                 // = is pronounced GETS, == is pronounced EQUALS
    int velocity= -45;
    int rateofchange=1;
    int horizontalstep = 12;
    char buffer [33];

    while ( x < 400 )
    {
        x += horizontalstep;
        y += velocity;
        velocity += rateofchange;
        DrawCircle(x, y, 20, RED, 1);
        DrawInt(velocity, x+10, y, BLUE, 10);
    }

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    WhileLoop4Soln *solution = new WhileLoop4Soln();
    solution->runExercise();

    return 0;

}
