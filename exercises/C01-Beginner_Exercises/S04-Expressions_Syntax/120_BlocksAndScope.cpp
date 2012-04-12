// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

void BlocksAndScope::runExercise()     // copy the exercise name & paste it into main.cpp
{
    int a = 10;

    // braces {} start and end a "block" or section of code.  This is a way of grouping
    // multiple commands together into one executable unit.

    // DO NOT DECLARE MULTIPLE VARIABLES OF THE SAME NAME IN YOUR CODE LIKE THIS
    // WHEN YOU ARE WRITING YOUR OWN PROGRAMS!

    // This example is only to demonstrate to you that each block has it's own scope.
    // Scoping issues can come into play when writing your algorithms, and especially
    // when debugging them.

    fwcText("Reference Exercise:", 50, 150, BLUE, 20);
    fwcText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "1st a == " << a << "\n";
    { // new scope
        int a = 20;
        seeout << "2nd a == " << a << "\n";
        { // new scope
            int a = 30;
            seeout << "3rd a == " << a << "\n";
        } // this scope ends
        seeout << "4th a == " << a << "\n";
    } // this scope ends
    seeout << "5th a == " << a << "\n";

}


