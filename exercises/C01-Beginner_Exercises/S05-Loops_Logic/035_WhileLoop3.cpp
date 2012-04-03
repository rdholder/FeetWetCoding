// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop3::runExercise()
{
    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        fwcLine(200, 0, x, 400, BLUE, 1);
        fwcLine(200, 400, x, 0, RED, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        fwcLine(0, 200, 400, y, GREEN, 1);
        fwcLine(400, 200, 0, y, YELLOW, 1);
    }
}
