// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/035_WhileLoop3SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.


#include <exercises/C01_S05.h>

void WhileLoop3Soln::runExercise()
{
    int x=0, y=0;
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(200, 200, x, 400, BLUE, 1);
        DrawLine(200, 200, x, 0, RED, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(200, 200, 400, y, GREEN, 1);
        DrawLine(200, 200, 0, y, YELLOW, 1);
    }
}
