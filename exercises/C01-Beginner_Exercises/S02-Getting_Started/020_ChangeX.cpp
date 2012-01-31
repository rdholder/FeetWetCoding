// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/020_ChangeX.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int ChangeX::runExercise()
{
    Gsoln = false;

    // USAGE: DrawText("Text.", x, y, color, fontsize);

    // CHANGE 10 TO 300
    DrawText("change x", 10, 150, BLUE, 15);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    ChangeXSoln *solution = new ChangeXSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
