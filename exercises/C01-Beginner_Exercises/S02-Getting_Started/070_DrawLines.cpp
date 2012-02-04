// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int DrawLines::runExercise()
{
    Gsoln = false;

    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    DrawLine(0, 200, 400,   0, BLUE, 1);
    DrawLine(0, 200, 400, 200, RED, 5);
    DrawLine(0, 200, 400, 400, BLACK, 10);


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    DrawLinesSoln *solution = new DrawLinesSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}
