// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void DrawingVersusSeeoutSoln::runExercise()
{
    int x = 42;     // = is pronounced GETS, == is pronounced EQUALS
    int y = 32767;
    int a = 100;
    int b = 200;

    // make the left graphics area look like the right one and you will see what I mean.  :-)
    fwcText("It's more work to draw variables graphically...", 30, 50, BLUE, 12);
    fwcText("x ==", 30, 100, BLUE, 20);
    fwcInt(x, 100, 100, BLUE, 20);
    fwcText("y ==", 200, 100, BLUE, 20);
    fwcInt(y, 300, 100, BLUE, 20);
    fwcText("a ==", 30, 300, BLUE, 20);
    fwcInt(a, 100, 300, BLUE, 20);
    fwcText("b ==", 200, 300, BLUE, 20);
    fwcInt(b, 300, 300, BLUE, 20);

    seeout << "...than it is to show them with seeout!\n";
    seeout << "x == " << x  << "  y == " << y << "\n";
    seeout << "a == " << a  << "  b == " << b << "\n";
}


