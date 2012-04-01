// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void WhileLoop5Soln::runExercise()
{
    int x=100, y=100;
    int horizontalstep=30, verticalstep=30;

    while ( x < 280 )
    {
        while ( y < 280 )
        {
            fwcDrawRectangle(x, y, 25, 25, DARKBLUE, 1, true);
            y += verticalstep;
        }
        y=100;
        x += horizontalstep;
    }
}
