// FeetWetCoding/exercises/C01-BeginnerExercises/S03-Types_Variables/040_DrawingVersusSeeout.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

void DrawingVersusSeeout::runExercise()
{
    int x = 42;     // = is pronounced GETS, == is pronounced EQUALS
    int y = 32767;
    int a = 100;
    int b = 200;

    // make the left graphics area look like the right one and you will see what I mean.  :-)
    DrawText("It's more work to draw variables graphically...", 30, 50, BLUE, 12);
    DrawText("x ==", 30, 100, BLUE, 20);
    DrawInt(x, 30, 100, BLUE, 20);
    DrawText("y ==", 200, 100, BLUE, 20);
    DrawInt(y, 200, 100, BLUE, 20);
    DrawText("a ==", 30, 300, BLUE, 20);
    DrawInt(a, 30, 300, BLUE, 20);
    DrawText("b ==", 200, 300, BLUE, 20);
    DrawInt(b, 200, 300, BLUE, 20);

    seeout << "...than it is to show them with seeout!\n";
    seeout << "x == " << x  << "  y == " << y << "\n";
    // add a seeout line here for a and b
}


