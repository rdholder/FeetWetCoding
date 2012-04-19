// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S01.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawDotsSoln::runExercise()
{
    // Things drawn later get drawn on top of things drawn earlier!

    // USAGE: fwcLine(xStart, yStart, xEnd, yEnd, color, linewidth);
    // USAGE: fwcCircle(x, y, radius, color, linewidth, solid);
    // USAGE: fwcRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter: you can use it or leave it out.)

    fwcRectangle(0, 0, 400, 400, BLACK, 1, true);

    fwcRectangle(100, 200, 1, 1, RED, 1);
    fwcLine(200, 200, 200, 201, GREEN, 1);
    fwcCircle(300, 200, 1, BLUE, 1, true);

}
