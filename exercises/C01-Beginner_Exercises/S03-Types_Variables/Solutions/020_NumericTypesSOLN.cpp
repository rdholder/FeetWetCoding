// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

void NumericTypesSoln::runExercise()
{
    int x = 100;        // = is pronounced GETS, == is pronounced EQUALS
    double y = 200;     // remember to initialize every variable!

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "x == " << x << "\n";
    seeout << "y == " << y << "\n";

    seeout << "sizeof x is " << sizeof(x) << "\n";
    seeout << "sizeof y is " << sizeof(y) << "\n";
}


