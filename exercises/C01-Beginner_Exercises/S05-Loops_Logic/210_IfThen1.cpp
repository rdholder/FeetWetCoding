// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/210_IfThen1.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void IfThen1::runExercise()
{
    int x=0, y=0;                   // = is pronounced GETS, == is pronounced EQUALS
    int horizontalstep=70, verticalstep=70;
    Color color = BLUE;

    while ( x < 400 )
    {
        while ( y < 400 )
        {
            if ( x < y) color = RED;
            if ( x > y) color = BLUE;
            DrawRectangle(x, y, 40, 40, color, 1, true);
            y += verticalstep;
        }
        y=0;
        x += horizontalstep;
    }
}
