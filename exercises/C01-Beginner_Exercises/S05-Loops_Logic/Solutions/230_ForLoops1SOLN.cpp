// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/230_ForLoops2SOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

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
