// copyright (c) 2011 Robert Holder, Janice Dugger.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// HandsDirtyCPP/exercises/Chapter01/CirclesIdea1.cpp

// Chapter 01 Exercise 03: First Variables Exercise

// OPEN HandsDirtyCPP/helpinfo/html/CirclesIdea1.html
// for more information about this exercise.

#include <setup.h>

int CirclesIdea1::runExercise()
{

    ClearScreen();

    // Declare the variables we will use.
    int x, y=MAX_Y, radius=5, height=0, dh=30;
    bool ascending=true;

    //Color color;

    for ( x = 0; x < MAX_X; x = x + (radius * 2) )
    {
        DrawCircle( x, y-height, radius, BLUE, 3 );
        height += dh--;
    }

    height = 0; dh = 30;

    for ( x = 100; x < MAX_X; x = x + (radius * 2) )
    {
        DrawCircle( x, y-height, radius, PINK, 3 );
        height += dh--;
    }

    height = 0;

    for ( x = 0; x < MAX_X; x = x + (radius * 2) )
    {

        DrawCircle( x, height, radius, RED, 3);
        if (ascending) height += radius*5;
        else height -= radius*5;

        if (height > MAX_Y) ascending = false;
        if (height < 0) ascending = true;

    }
    //DrawRectangle( 50, 50, 100, 100, 3, RED );

    return 0;
}
