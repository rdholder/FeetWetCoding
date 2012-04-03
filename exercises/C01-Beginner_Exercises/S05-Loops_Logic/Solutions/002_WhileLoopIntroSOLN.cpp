// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void WhileLoopIntroSoln::runExercise()
{
    int x=50, y=50, n=0, col=0, row=0;      // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep=20, horizontalstep=20;

    // we can base our loop on x...
    while ( x < 100 )
    {
        fwcCircle(x, y, 5, BLACK, 1, true);
        x += horizontalstep;
    }

    // ...or we can base it on the number of circles we want.
    x = 50;
    y = 100;
    while ( n < 5 )
    {
        fwcCircle(x, y, 5, BLUE, 1, true);
        x += horizontalstep;
        n++;
    }

    // Notice that postincrement in the conditional behaves the
    // same as incrementing within the loop...
    n = 0;
    x = 50;
    y = 150;
    while ( n++ < 5 )
    {
        fwcCircle(x, y, 5, DARKGREEN, 1, true);
        x += horizontalstep;
    }

    // ...but preincrementing does not!
    n = 0;
    x = 50;
    y = 200;
    while ( n++ < 5 )
    {
        fwcCircle(x, y, 5, RED, 1, true);
        x += horizontalstep;
    }

    x = 50;
    y = 250;
    while ( row++ < 5 )
    {
        while ( col++ < 5 )
        {
            fwcCircle(x, y, 5, DARKRED, 1, true);
            x += horizontalstep;
        }
        col = 0;
        x = 50;
        y += verticalstep;
    }

    row = 0;
    col = 0;
    x = 200;
    y = 50;
    while ( row++ < 15 )
    {
        while ( col++ < 10 )
        {
            fwcCircle(x, y, 5, DARKCYAN, 1, true);
            x += horizontalstep;
        }
        col = 0;
        x = 200;
        y += verticalstep;
    }

    seeout << "The grid of DARKCYAN circles is 15x10, starting at 200,50.\n\n";
    seeout << "Also, adjusting the number of black circles is not as simple";
    seeout << " because in that loop we are just filling circles until x";
    seeout << " reaches some value, rather than counting circles the way we";
    seeout << " are doing in the later loops.\n";
}
