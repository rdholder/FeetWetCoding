// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.
// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/060_ChangeFont.cpp

// Open (double-click) the README.html file to access the documentation.

#include <setup.h>
#include <exercises/C01_S02.h>
extern bool Gsoln;

int DrawDotsSoln::runExercise()
{
    Gsoln = true;

    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    // USAGE: DrawCircle(x, y, radius, color, thickness, solid);
    // USAGE: DrawRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)
    DrawLine(200, 100, 200, 100, BLACK, 1);
    DrawCircle(150, 250, 1, BLUE, 1);
    DrawRectangle(250, 250, 1, 1, RED, 1);

    return 0;
}
