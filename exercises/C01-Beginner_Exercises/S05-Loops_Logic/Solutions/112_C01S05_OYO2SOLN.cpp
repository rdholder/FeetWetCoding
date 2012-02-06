// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/EXERCISENAME.cpp

// Chapter 01 Exercise 02: INTroduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/EXERCISENAME.html
// for more information about this exercise.

#include <exercises/C01_S05.h>

void C01S05_OYO2Soln::runExercise()
{
    int x=0, y=0;
    int step=50;

    DrawLine(0, 200, 400, 200, BLACK, 1);
    DrawLine(200, 0, 200, 400, BLACK, 1);

    while ( x < 400 )
    {
        DrawLine(x, 200, x, 195, BLACK, 1);
        DrawLine(200, y, 205, y, BLACK, 1);
        x += step;
        y = x;
    }
    x = -200;
    y = -200;
    while ( x < 200 && y < 200 )
    {
        DrawInt(x, x+195, 180, BLACK, 7);
        DrawInt(y, 205, ((y * -1) + 195), BLACK, 7);
        x += step;
        y += step;
    }
    DrawText("x", 5, 210, BLACK, 10);
    DrawText("y", 180, 5, BLACK, 10);
    seeout << "Later in your learning you will come across coordinate space\n";
    seeout << "transformations which will make writing this kind of code cleaner and\n";
    seeout << "clearer, but for now, you'll just have to transform the x,y\n";
    seeout << "coordinates of the graph to the x,y coordinates of the drawing area\n";
    seeout << "yourself.  :-)\n\n";
    seeout << "No fair using a bunch of individual DrawInt() calls to draw the\n";
    seeout << "numeric axis labels individually!  Draw the numeric axis labels\n";
    seeout << "in a while loop to make yourself learn! :-D\n";
}
