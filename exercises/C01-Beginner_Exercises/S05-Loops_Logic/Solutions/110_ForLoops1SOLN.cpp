// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ForLoops1Soln::runExercise()
{
    int col = 0, row = 0;       // = is pronounced GETS, == is pronounced EQUALS

    for ( row = 0; row < 10; row++ )
    {
        for ( col = 0; col < 10; col++ )
        {
            fwcInt( row, col*40, row*26, BLUE, 15);
            fwcText( ",", col*40+10, row*26, BLUE, 15);
            fwcInt( col, col*40+15, row*26, BLUE, 15);
        }
    }
}
