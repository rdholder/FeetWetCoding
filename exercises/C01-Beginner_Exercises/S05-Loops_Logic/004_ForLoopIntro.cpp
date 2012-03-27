// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoopIntro::runExercise()
{
    int x = 50, y = 50, n = 0, col = 0, row = 0;      // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep = 20, horizontalstep = 20;

    // we can base our loop on x...
    for ( x = 50; x < 400; x += horizontalstep)
    {
        fwcDrawCircle(x, y, 5, BLACK, 1, true);
    }

    // ...or we can base it on the number of circles we want.
    // Also, notice that with for loops, postincrement...
    x = 50;
    y = 100;
    for ( n = 0; n < 5; n++)
    {
        fwcDrawCircle(x, y, 5, BLUE, 1, true);
        x += horizontalstep;
    }

    // ...and preincrement work the same as each other compared to how
    // they worked in the while loops in the WhileLoopIntro exercise.
    n = 0;
    x = 50;
    y = 200;
    for ( n = 0; n < 5; ++n)
    {
        fwcDrawCircle(x, y, 5, RED, 1, true);
        x += horizontalstep;
    }

    x = 50;
    y = 250;
    for ( row = 0; row < 4; row++ )
    {
        for ( col = 0; col < 4; col++ )
        {
            fwcDrawCircle(x, y, 5, DARKRED, 1, true);
            x += horizontalstep;
        }
        x = 50;
        y += verticalstep;
    }
}
