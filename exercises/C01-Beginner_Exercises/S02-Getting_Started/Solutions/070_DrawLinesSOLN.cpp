// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawLinesSoln::runExercise()
{
    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);

    DrawLine(200, 400,   0, 0, BLUE, 1);
    DrawLine(200, 400, 200, 0, RED, 5);
    DrawLine(200, 400, 400, 0, BLACK, 10);
}
