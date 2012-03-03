// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void IfThen1Soln::runExercise()
{
    int x=0, y=0;
    int horizontalstep=70, verticalstep=70;
    Color color = BLUE;

    while ( x < 400 )
    {
        while ( y < 400 )
        {
            if ( x < y) color = RED;
            if ( x > y) color = BLUE;
            if ( x == y ) color = BLACK;    // = is pronounced GETS, == is pronounced EQUALS  :-)
            DrawRectangle(x, y, 40, 40, color, 1, true);
            y += verticalstep;
        }
        y=0;
        x += horizontalstep;
    }
}