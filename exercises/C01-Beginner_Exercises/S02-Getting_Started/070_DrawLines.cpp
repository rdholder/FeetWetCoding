// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawLines::runExercise()
{
    // USAGE: fwcLine(xStart, yStart, xEnd, yEnd, color, linewidth);
    fwcLine(0, 200, 400,   0, BLUE, 1);
    fwcLine(0, 200, 400, 200, RED, 5);
    fwcLine(0, 200, 400, 400, BLACK, 10);
}
