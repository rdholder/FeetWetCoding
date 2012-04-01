// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void FontProportionsSoln::runExercise()
{
    fwcDrawInt( 1, 100, 100, BLUE, 8);
    fwcDrawRectangle( 100, 100, 10, 15, RED, 1);

    fwcDrawInt( 2, 300, 100, BLUE, 12);
    fwcDrawRectangle( 300, 100, 12, 20, RED, 1);

    fwcDrawInt( 3, 100, 300, BLUE, 15);
    fwcDrawRectangle( 100, 300, 15, 23, RED, 1);

    fwcDrawInt( 4, 300, 300, BLUE, 20);
    fwcDrawRectangle( 300, 300, 20, 30, RED, 1);
}


