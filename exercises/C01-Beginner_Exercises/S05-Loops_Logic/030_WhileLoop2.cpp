// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop2::runExercise()
{
    int x=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        fwcDrawLine(200, 0, x, 200, BLUE, 1);
    }

    x=0;

    while ( x < 400 )
    {
        x += horizontalstep;
        fwcDrawLine(200, 400, x, 200, RED, 1);
    }
}
