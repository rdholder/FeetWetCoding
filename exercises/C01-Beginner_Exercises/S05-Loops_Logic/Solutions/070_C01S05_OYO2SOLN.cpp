// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void C01S05_OYO2Soln::runExercise()
{
    int n=0;

    while ( n++ < 50 )
    {
        DrawCircle(random(400), random(400), random(50), BLUE, 1, true);
    }
    seeout << "There are 50 circles of random size and location.\n";
}
