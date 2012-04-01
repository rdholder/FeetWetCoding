// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawLinesSoln::runExercise()
{
    // USAGE: fwcDrawLine(xStart, yStart, xEnd, yEnd, color, linewidth);

    fwcDrawLine(200, 400,   0, 0, BLUE, 1);
    fwcDrawLine(200, 400, 200, 0, RED, 5);
    fwcDrawLine(200, 400, 400, 0, BLACK, 10);
}
