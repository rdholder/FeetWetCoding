// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void WhileLoop2::runExercise()
{
    int x=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int horizontalstep=15;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(200, 0, x, 200, BLUE, 1);
    }

    x=0;

    while ( x < 400 )
    {
        x += horizontalstep;
        DrawLine(200, 400, x, 200, RED, 1);
    }
}
