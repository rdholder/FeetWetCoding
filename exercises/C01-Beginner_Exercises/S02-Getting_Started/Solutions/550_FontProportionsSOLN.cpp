// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S02.h>

void FontProportionsSoln::runExercise()
{
    DrawInt( 1, 100, 100, BLUE, 8);
    DrawRectangle( 100, 100, 10, 15, RED, 1);

    DrawInt( 2, 300, 100, BLUE, 12);
    DrawRectangle( 300, 100, 12, 20, RED, 1);

    DrawInt( 3, 100, 300, BLUE, 15);
    DrawRectangle( 100, 300, 15, 23, RED, 1);

    DrawInt( 4, 300, 300, BLUE, 20);
    DrawRectangle( 300, 300, 20, 30, RED, 1);
}


