// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int DrawEllipsesSoln::runExercise()
{
    Gsoln = true;

    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: DrawEllipse(x, y, width, height, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    DrawEllipse(200, 100, 300, 50, BLUE, 1, true);
    DrawEllipse(200, 200, 300, 30, RED, 5);
    DrawEllipse(200, 300, 300, 10, BLACK, 1);

    return 0;
}
