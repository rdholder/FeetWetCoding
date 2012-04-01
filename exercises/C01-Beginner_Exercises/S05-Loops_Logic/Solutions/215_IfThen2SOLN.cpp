// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void IfThen2Soln::runExercise()
{
    int x=0, y=0;
    int horizontalstep=50, verticalstep=50;
    Color color = DARKBLUE;

    for ( x = 0; x < 400; x += horizontalstep )
    {
        for (y = 0; y < 400; y += verticalstep )
        {
            if ( color == DARKBLUE ) color = DARKCYAN;   // = is pronounced GETS, == is pronounced EQUALS  :-)
            else color = DARKBLUE;
            fwcDrawRectangle(x, y, 48, 48, color, 1, true);
        }
    }
}
