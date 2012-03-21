// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawCirclesSoln::runExercise()
{
    // USAGE: fwcDrawCircle(x, y, radius, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcDrawCircle(200, 200, 200, RED, 10);
    fwcDrawCircle(300, 200, 100, BLACK, 1, true);
    fwcDrawCircle(100, 200, 80, BLUE, 1);
}
