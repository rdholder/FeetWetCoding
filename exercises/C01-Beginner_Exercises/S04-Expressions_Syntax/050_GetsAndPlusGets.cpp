// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/GetsAndPlusGets.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/GetsAndPlusGets.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S04.h>
extern bool Gsoln;

int GetsAndPlusGets::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;                  // is this exercise code or solution code?

    int verticalstep=0;             // = is pronounced GETS and don't you forget!
    int a=0, x=2, y=50;             // == is pronounced EQUALS, it's twice, like a sequel

    verticalstep=y;
    a=x;
    DrawText("First sentence.", x, y, BLACK, 15);
    y = y + verticalstep;
    DrawText("Second sentence.", x, y, BLACK, 15);
    y += verticalstep;
    DrawText("Third sentence.", x, y, BLACK, 15);
    y += verticalstep;
    a += x;
    DrawText("Fourth sentence.", y, x, RED, 15);
    y += verticalstep;
    DrawText("Fifth sentence.", x, y, BLACK, 15);

    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    // Run the Soln code to show what the solution looks like:
    GetsAndPlusGetsSoln *solution = new GetsAndPlusGetsSoln();
    solution->runExercise();

    return 0;

}
