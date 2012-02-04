// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/030_ChangeY.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int ChangeY::runExercise()
{
    Gsoln = false;

    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("change y", 50, 50, BLUE, 15);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    ChangeYSoln *solution = new ChangeYSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
