// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ForLoops3Soln::runExercise()
{
    int a = 1, x = 385, y = 0;  // = is pronounced GETS, == is pronounced EQUALS

    for ( y = 0; y < 375; y += 25 )
    {
        if ( a > 9 ) x -= 10;
        fwcInt( a, x, y, BLUE, 15);
        a++;
        x = 385;
    }
}
