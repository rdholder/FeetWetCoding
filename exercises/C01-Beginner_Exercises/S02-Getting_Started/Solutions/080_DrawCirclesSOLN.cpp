// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawCirclesSoln::runExercise()
{
    // USAGE: fwcDrawCircle(x, y, radius, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcDrawCircle(200, 200, 100, RED, 10);
    fwcDrawCircle(300, 200, 50, BLACK, 1, true);
    fwcDrawCircle(100, 200, 40, BLUE, 1);
}
