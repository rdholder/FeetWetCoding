// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int DrawEllipses::runExercise()
{
    Gsoln = false;

    // USAGE: DrawEllipse(x, y, width, height, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    DrawEllipse(100, 200, 10, 300, BLUE, 1);
    DrawEllipse(200, 200, 30, 300, RED, 5, true);
    DrawEllipse(300, 200, 50, 300, BLACK, 10);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    DrawEllipsesSoln *solution = new DrawEllipsesSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
