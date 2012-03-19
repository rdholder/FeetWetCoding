// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop1::runExercise()
{
    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        fwcDrawLine(0, 0, x, 400, BLUE, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        fwcDrawLine(0, 0, 400, y, RED, 1);
    }
}
