// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S01.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawEllipsesSoln::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcEllipse(x, y, width, height, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcEllipse(200, 100, 300, 50, BLUE, 1, true);
    fwcEllipse(200, 200, 300, 30, RED, 5);
    fwcEllipse(200, 300, 300, 10, BLACK, 1);
}
