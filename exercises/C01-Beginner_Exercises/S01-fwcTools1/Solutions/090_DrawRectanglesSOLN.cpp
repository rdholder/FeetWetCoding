// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S01.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawRectanglesSoln::runExercise()
{
    // USAGE: fwcRectangle(x, y, width, height, color, linewidth);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcRectangle(50, 50, 50, 50, BLACK, 1);
    fwcRectangle(150, 150, 50, 100, RED, 5, true);
    fwcRectangle(250, 250, 100, 50, BLUE, 10);
}
