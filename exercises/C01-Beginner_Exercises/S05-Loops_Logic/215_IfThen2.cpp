// FeetWetCoding/exercises/C01-BeginnerExercises/S05-Loops_Logic/215_IfThen2.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void IfThen2::runExercise()
{
    int x=0, y=0;
    int horizontalstep=50, verticalstep=50;
    Color color = DARKCYAN;

    for ( x = 0; x < 400; x += horizontalstep )
    {
        for (y = 0; y < 400; y += verticalstep )
        {
            DrawRectangle(x, y, 48, 48, color, 1, true);
        }
        if ( color == DARKCYAN ) color = DARKBLUE;   // = is pronounced GETS, == is pronounced EQUALS  :-)
        else color = DARKCYAN;
    }
}
