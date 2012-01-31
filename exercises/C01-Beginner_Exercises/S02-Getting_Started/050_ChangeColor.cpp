// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/050_ChangeColor.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int ChangeColor::runExercise()
{
    Gsoln = false;

    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("color is BLUE", 50, 250, BLUE, 15);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    ChangeColorSoln *solution = new ChangeColorSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
