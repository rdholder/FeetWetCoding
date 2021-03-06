// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoop5::runExercise()
{
    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int horizontalstep=70, verticalstep=70;

    while ( x < 400 )
    {
        while ( y < 400 )
        {
            fwcRectangle(x, y, 25, 25, RED, 1, true);
            y += verticalstep;
        }
        y=0;
        x += horizontalstep;
    }
}
