// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
extern bool Gsoln;

int DrawLinesSoln::runExercise()
{
    Gsoln = true;

    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    DrawLine(200, 400,   0, 0, BLUE, 1);
    DrawLine(200, 400, 200, 0, RED, 5);
    DrawLine(200, 400, 400, 0, BLACK, 10);

    return 0;
}
