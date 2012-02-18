// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/010_WhileLoop1SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop1Soln::runExercise()
{
    int x=0, y=0;
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(0, 400, x, 0, BLUE, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(0, 400, 400, y, RED, 1);
    }
}
