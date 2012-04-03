// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawEllipses::runExercise()
{
    // USAGE: fwcEllipse(x, y, width, height, color, linewidth, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    fwcEllipse(100, 200, 10, 300, BLUE, 1);
    fwcEllipse(200, 200, 30, 300, RED, 5, true);
    fwcEllipse(300, 200, 50, 300, BLACK, 10);
}
