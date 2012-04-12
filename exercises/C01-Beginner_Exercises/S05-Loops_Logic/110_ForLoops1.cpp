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
            fwcInt( row, col*50, row*50, BLUE, 30);
            fwcText( ",", col*50+15, row*50, BLUE, 30);
            fwcInt( col, col*50+20, row*50, BLUE, 30);
        }
    }
}
