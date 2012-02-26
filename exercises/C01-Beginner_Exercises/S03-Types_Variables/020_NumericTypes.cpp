// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

void NumericTypes::runExercise()
{
    // Exercises in Sections 3 and 4 are mostly for reference, so that in later
    // sections you can quickly refer back here to see the trivial examples
    // of how things are declared and what the basic syntax looks like.

    // http://stackoverflow.com/questions/2386772/difference-between-float-and-double
    // http://stackoverflow.com/questions/3687904/whats-the-least-negative-integer-value-that-can-be-exactly-represented-by-dou
    // if you like math: http://docs.oracle.com/cd/E19422-01/819-3693/ncg_goldberg.html

    int x = 100;        // = is pronounced GETS, == is pronounced EQUALS
    long y;             // remember to initialize every variable!

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "x == " << x << "\n";
    seeout << "y == " << y << "\n";

    seeout << "sizeof x is " << sizeof(x) << "\n";
    seeout << "sizeof y is " << sizeof(y) << "\n";
}


