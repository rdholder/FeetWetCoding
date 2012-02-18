// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/115_ForLoops2.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoops2::runExercise()
{
    int a = 1, x = 385, y = 0;      // = is pronounced GETS, == is pronounced EQUALS

    for ( y = 0; y < 375; y += 25 )
    {
        DrawInt( a, x, y, BLUE, 15);
        a++;
    }
}
