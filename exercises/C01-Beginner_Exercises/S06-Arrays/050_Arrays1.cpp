// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>
#include <math.h>

void Arrays1::runExercise()
{
    int n = 0, x = 20, y = 50;
    int horizontalstep = 50, verticalstep = 40;
    int CircleSizes[8] = { 5, 10, 15, 20, 25, 30, 35, 40 };
    Color color = DARKBLUE;

    for ( n = 1; n < 8; n++ )
    {
        DrawCircle( x, y, CircleSizes[n], color, 1, true);
        x += horizontalstep;

    }

    x = 20;
    y += verticalstep;

    for ( n = 1; n < 8; n++ )
    {
        DrawCircle( x, y, CircleSizes[n], color, 1, true);
        x += horizontalstep;

    }
}
