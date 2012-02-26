// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void WhileLoopIntro::runExercise()
{
    int x=50, y=50, n=0, col=0, row=0;      // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=20, horizontalstep=20;

    // we can base our loop on x...
    while ( x < 150 )
    {
        DrawCircle(x, y, 10, BLACK, 1, true);
        x += horizontalstep;
    }

    // ...or we can base it on the number of circles we want.
    x = 50;
    y = 100;
    while ( n < 5 )
    {
        DrawCircle(x, y, 10, BLUE, 1, true);
        x += horizontalstep;
        n++;
    }
    DrawText("...5 circles.", x, y, BLUE, 10);

    // Notice that postincrement in the conditional behaves the
    // same as incrementing within the loop...
    n = 0;  // what happens when you comment this out?
    x = 50;
    y = 150;
    while ( n++ < 5 )
    {
        DrawCircle(x, y, 10, DARKGREEN, 1, true);
        x += horizontalstep;
    }
    DrawText("...5 circles.", x, y, DARKGREEN, 10);

    // ...but preincrementing does not!
    n = 0;
    x = 50;
    y = 200;
    while ( ++n < 5 )
    {
        DrawCircle(x, y, 10, RED, 1, true);
        x += horizontalstep;
    }
    DrawText("...NOT 5 circles!", x, y, RED, 10);

    x = 50;
    y = 250;
    while ( ++row < 5 )
    {
        while ( ++col < 5 )
        {
            DrawCircle(x, y, 10, DARKRED, 1, true);
            x += horizontalstep;
        }
        col = 0;
        x = 50;
        y += verticalstep;
    }
    DrawText("...NOT 5x5!", x, y, DARKRED, 10);
}
