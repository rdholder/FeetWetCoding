// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void ForLoops1Soln::runExercise()
{
    int col = 0, row = 0;                   // = is pronounced GETS, == is pronounced EQUALS

    for ( row = 0; row < 10; row++ )
    {
        for ( col = 0; col < 10; col++ )
        {
            DrawInt( row, col*40, row*26, BLUE, 15);
            DrawText( ",", col*40+10, row*26, BLUE, 15);
            DrawInt( col, col*40+15, row*26, BLUE, 15);
        }
    }
}
