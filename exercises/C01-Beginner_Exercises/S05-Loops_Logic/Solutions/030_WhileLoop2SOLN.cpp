// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void WhileLoop2Soln::runExercise()
{
    int y=0;
    int verticalstep=10;

    while ( y < 400 )
    {
        y += verticalstep;
        fwcLine(0, 200, 200, y, BLUE, 1);
    }

    y=0;

    while ( y < 400 )
    {
        y += verticalstep;
        fwcLine(400, 200, 200, y, RED, 1);
    }
}
