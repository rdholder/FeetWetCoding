// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop2Soln::runExercise()
{
    int y=0;
    int verticalstep=10;

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(0, 200, 200, y, BLUE, 1);
    }

    y=0;

    while ( y < 400 )
    {
        y += verticalstep;
        DrawLine(400, 200, 200, y, RED, 1);
    }
}
