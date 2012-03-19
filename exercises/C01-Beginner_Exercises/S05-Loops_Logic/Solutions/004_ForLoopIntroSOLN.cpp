// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void ForLoopIntroSoln::runExercise()
{
    int x = 50, y = 50, n = 0, col = 0, row = 0;      // = is pronounced GETS, == is pronounced EQUALS
    int verticalstep = 20, horizontalstep = 20;

    // we can base our loop on x...
    for ( x = 50; x < 325; x += horizontalstep)
    {
        fwcDrawCircle(x, y, 10, BLACK, 1, true);
    }

    // ...or we can base it on the number of circles we want.
    x = 50;
    y = 100;
    for ( n = 0; n < 5; n++)
    {
        fwcDrawCircle(x, y, 10, BLUE, 1, true);
        x += horizontalstep;
    }

    n = 0;
    x = 50;
    y = 200;
    for ( n = 0; n < 5; ++n)
    {
        fwcDrawCircle(x, y, 10, RED, 1, true);
        x += horizontalstep;
    }

    x = 50;
    y = 250;
    for ( row = 0; row < 5; row++ )
    {
        for ( col = 0; col < 5; col++ )
        {
            fwcDrawCircle(x, y, 10, DARKRED, 1, true);
            x += horizontalstep;
        }
        x = 50;
        y += verticalstep;
    }

    x = 200;
    y = 100;
    for ( row = 0; row < 15; row++ )
    {
        for ( col = 0; col < 10; col++ )
        {
            fwcDrawCircle(x, y, 10, DARKCYAN, 1, true);
            x += horizontalstep;
        }
        col = 0;
        x = 200;
        y += verticalstep;
    }
    seeout << "The grid of DARKCYAN circles is 15x10, starting at 200,100.\n\n";
    seeout << "Also, adjusting the number of black circles is not as simple";
    seeout << " because in that loop we are just filling circles until x";
    seeout << " reaches some value, rather than counting circles the way we";
    seeout << " are doing in the later loops.\n";
}
