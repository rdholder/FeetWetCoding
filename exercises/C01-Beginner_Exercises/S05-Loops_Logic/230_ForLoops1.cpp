// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void ForLoops1::runExercise()
{
    int col = 0, row = 0;                   // = is pronounced GETS, == is pronounced EQUALS
    int rowHeight = 26;
    int colWidth = 40;
    int fontSize = 15;

    for ( row = 0; row < 10; row++ )
    {
        for ( col = 0; col < 10; col++ )
        {
            DrawInt( row, col*colWidth, row*rowHeight, BLUE, fontSize);
            DrawText( ",", col*colWidth+9, row*rowHeight, BLUE, fontSize);
            DrawInt( col, col*colWidth+15, row*rowHeight, BLUE, fontSize);
        }
    }
}
