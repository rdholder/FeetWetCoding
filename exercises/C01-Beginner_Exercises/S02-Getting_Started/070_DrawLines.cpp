// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawLines::runExercise()
{
    // USAGE: fwcDrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    fwcDrawLine(0, 200, 400,   0, BLUE, 1);
    fwcDrawLine(0, 200, 400, 200, RED, 5);
    fwcDrawLine(0, 200, 400, 400, BLACK, 10);
}
