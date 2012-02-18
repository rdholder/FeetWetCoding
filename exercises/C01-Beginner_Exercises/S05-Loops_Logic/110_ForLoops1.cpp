// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/230_ForLoops2.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoops1::runExercise()
{
    int col = 0, row = 0;                   // = is pronounced GETS, == is pronounced EQUALS

    for ( row = 0; row < 8; row++ )
    {
        for ( col = 0; col < 8; col++ )
        {
            DrawInt( row, col*50, row*50, BLUE, 30);
            DrawText( ",", col*50+15, row*50, BLUE, 30);
            DrawInt( col, col*50+20, row*50, BLUE, 30);
        }
    }
}
