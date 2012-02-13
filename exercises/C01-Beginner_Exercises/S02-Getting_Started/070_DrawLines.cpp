// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/070_DrawLines.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawLines::runExercise()
{
    // USAGE: DrawLine(xStart, yStart, xEnd, yEnd, color, thickness);
    DrawLine(0, 200, 400,   0, BLUE, 1);
    DrawLine(0, 200, 400, 200, RED, 5);
    DrawLine(0, 200, 400, 400, BLACK, 10);
}
