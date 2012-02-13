// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/110_DrawElipses.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void DrawEllipses::runExercise()
{
    // USAGE: DrawEllipse(x, y, width, height, color, thickness, solid);
    // (solid is an optional parameter, you can use it or leave it out.)
    DrawEllipse(100, 200, 10, 300, BLUE, 1);
    DrawEllipse(200, 200, 30, 300, RED, 5, true);
    DrawEllipse(300, 200, 50, 300, BLACK, 10);
}
