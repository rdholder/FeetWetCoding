// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S03.h>

void DrawingVersusSeeoutSoln::runExercise()
{
    int x = 42;     // = is pronounced GETS, == is pronounced EQUALS
    int y = 32767;
    int a = 100;
    int b = 200;

    // make the left graphics area look like the right one and you will see what I mean.  :-)
    DrawText("It's more work to draw variables graphically...", 30, 50, BLUE, 12);
    DrawText("x ==", 30, 100, BLUE, 20);
    DrawInt(x, 100, 100, BLUE, 20);
    DrawText("y ==", 200, 100, BLUE, 20);
    DrawInt(y, 300, 100, BLUE, 20);
    DrawText("a ==", 30, 300, BLUE, 20);
    DrawInt(a, 100, 300, BLUE, 20);
    DrawText("b ==", 200, 300, BLUE, 20);
    DrawInt(b, 300, 300, BLUE, 20);

    seeout << "...than it is to show them with seeout!\n";
    seeout << "x == " << x  << "  y == " << y << "\n";
    seeout << "a == " << a  << "  b == " << b << "\n";
}


