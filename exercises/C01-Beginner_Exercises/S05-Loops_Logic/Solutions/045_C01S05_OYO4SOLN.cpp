// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void C01S05_OYO4Soln::runExercise()
{
    int x=0, y=0;
    int step=50;

    fwcLine(0, 200, 400, 200, BLACK, 1);
    fwcLine(200, 0, 200, 400, BLACK, 1);

    while ( x < 400 )
    {
        fwcLine(x, 200, x, 195, BLACK, 1);
        fwcLine(200, y, 205, y, BLACK, 1);
        x += step;
        y = x;
    }
    x = -200;
    y = -200;
    while ( x < 200 && y < 200 )
    {
        fwcInt(x, x+195, 180, BLACK, 7);
        fwcInt(y, 205, ((y * -1) + 195), BLACK, 7);
        x += step;
        y += step;
    }
    fwcText("x", 5, 210, BLACK, 10);
    fwcText("y", 180, 5, BLACK, 10);

    seeout << "This is another one that takes a little finagling to get just right.\n\n";
    seeout << "No fair using a bunch of individual fwcInt() calls to draw the ";
    seeout << "numeric axis labels individually!  Draw the numeric axis labels ";
    seeout << "in a while loop to make yourself learn! :-D\n\n";
    seeout << "The nice thing about this exercise is that later, when we play around ";
    seeout << "with drawing math functions, you will already have an understanding ";
    seeout << "of how to draw yourself a nice, accurate set of graphical axes!";
}
