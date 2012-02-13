// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/240_ForLoops2SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoops2Soln::runExercise()
{
    int a = 1, x = 385, y = 0;                   // = is pronounced GETS, == is pronounced EQUALS

    for ( y = 0; y < 375; y += 25 )
    {
        if ( a > 9 ) x -= 10;
        DrawInt( a, x, y, BLUE, 15);
        a++;
        x = 385;
    }
}
