// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int DeclaringIntegersSoln::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = true;

    int x = 200;     // = is pronounced GETS, == is pronounced EQUALS
    int y = 300;
    int a = 404, b = 1201;
    int c = 100, d = 100, e = 100;

    DrawText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "x,y == (" << x  << "," <<  y << ")\n";
    seeout << "apples: " << a << "\n";
    seeout << "bananas: " << b << "\n";
    seeout << "coconuts: " << c << "\n";
    seeout << "dates: " << d << "\n";
    seeout << "emblic: " << e << "\n";

    return 0;
}


