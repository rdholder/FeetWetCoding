// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S03.h>
extern bool Gsoln;

int CONSTANTS::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;

    // This exercise only demonstrates const for reference.  There is nothing for you to solve.

    const int LIGHTSPEEDMPH(186282);
    const int POUNDSPERPINT(1);
    const int CHESSBOARDX(8);
    const int CHESSBOARDY(8);

    int boardsquares = 0;
    int chessboardx = 0;

    DrawText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "The speed of light is " << LIGHTSPEEDMPH << " miles per hour.\n";
    seeout << "A pint is " << POUNDSPERPINT << " pound, the world around.\n";
    seeout << "There are " << CHESSBOARDX * CHESSBOARDY << " squares on a chessboard.\n";
    chessboardx = 20;
    seeout << "There are still " << CHESSBOARDX * CHESSBOARDY << " squares on a chessboard.\n";
    seeout << "(In other words, variable and constant names are case-sensitive.)\n";
    seeout << "(Nothing to solve in this exercise.\n)";

    // uncomment the next line and compile to see what the error looks like when you try to
    // assign a value to a constant:

    //CHESSBOARDX = 20;

    // ...don't forget to comment it out again after you have seen the error
    // or FeetWetCoding won't compile anymore!


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    return 0;
}

