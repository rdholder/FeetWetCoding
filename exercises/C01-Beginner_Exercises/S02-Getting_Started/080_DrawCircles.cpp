// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int DrawCircles::runExercise()
{
    Gsoln = false;

    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: DrawCircle(x, y, radius, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    DrawCircle(130, 180, 80, BLUE, 1);
    DrawCircle(150, 220, 100, BLACK, 1, true);
    DrawCircle(250, 200, 200, RED, 10);

    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    DrawCirclesSoln *solution = new DrawCirclesSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}