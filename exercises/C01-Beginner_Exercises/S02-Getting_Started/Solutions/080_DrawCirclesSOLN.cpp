// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawCirclesSoln::runExercise()
{
    // USAGE: fwcDrawCircle(x, y, radius, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)

    fwcDrawCircle(150, 220, 100, BLACK, 1, true);
    fwcDrawCircle(250, 200, 200, RED, 10);
    fwcDrawCircle(130, 180, 80, BLUE, 1);
}
