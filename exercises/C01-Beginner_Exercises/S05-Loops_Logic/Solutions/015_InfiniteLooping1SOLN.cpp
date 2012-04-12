// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void InfiniteLooping1Soln::runExercise()
{
    int x=20, y=20;
    int verticalstep=30;

    while ( y < 400 )
    {
        fwcText("y must exceed 400 for this loop to end!", x, y, BLUE, 10);
        y += verticalstep;  // when this line was commented out, y stayed 20 forever!

    }
}
