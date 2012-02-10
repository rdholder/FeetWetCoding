// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void ForLoops3Soln::runExercise()
{
    int a = 1, x = 200, y = 200;        // = is pronounced GETS, == is pronounced EQUALS

    seeout << "Run this a few times to see the behavior.";
    seeout << " Notice that the numbers on this side stay within the drawing area box.";
    seeout << " Can you make your code draw the numbers right up to the RIGHT and BOTTOM";
    seeout << " edges of the drawing area box, but not go over? (Don't worry about getting";
    seeout << " right up to the top and left edges for this exercise.)\n\n";

    for ( a = 0; a < 200; a++)
    {
        x = random(385);
        y = random(375);

        if ( a > 9 && x > 370 ) x -= 10;
        if ( a > 99 && x > 355 ) x -= 10;
        DrawInt( a, x, y, BLUE, 15);
    }
}
