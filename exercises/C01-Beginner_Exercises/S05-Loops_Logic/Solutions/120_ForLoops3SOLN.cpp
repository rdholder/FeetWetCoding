// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ForLoops3Soln::runExercise()
{
    int a = 1, x = 200, y = 200;        // = is pronounced GETS, == is pronounced EQUALS

    seeout << "Click the \"Re-start Exercise\" button a few times to get an idea";
    seeout << " of the behavior we are looking for here.\n\n";
    seeout << "This exercise draws numbers on the screen randomly. The point is to match";
    seeout << " the drawing behavior, NOT to try to make the left side look";
    seeout << " EXACTLY like the right side!\n\n";
    seeout << " Notice that the numbers on this side stay within the drawing area box.";
    seeout << " Can you make your code draw the numbers right up to the RIGHT and BOTTOM";
    seeout << " edges of the drawing area box, but not go over? (Don't worry about getting";
    seeout << " right up to the top and left edges for this exercise.)\n\n";

    for ( a = 0; a < 200; a++)
    {
        x = random(385);
        y = random(375);

        if ( a > 9 && x > 370 ) x -= 10;
        if ( a > 99 && x > 355 ) x -= 10;
        fwcInt( a, x, y, BLUE, 15);
    }
}
