// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

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
