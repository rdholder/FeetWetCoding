// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void WhileLoop1Soln::runExercise()
{
    int x=0, y=0;
    int verticalstep=10, horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        fwcLine(0, 400, x, 0, BLUE, 1);
    }

    while ( y < 400 )
    {
        y += verticalstep;
        fwcLine(0, 400, 400, y, RED, 1);
    }
}
