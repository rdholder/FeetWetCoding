// FeetWetCoding/exercises/C01-BeginnerExercises/S03-Types_Variables/080_CONSTANTS.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

void CONSTANTS::runExercise()     // copy the exercise name & paste it into main.cpp
{
    // This exercise only demonstrates const for reference.  There is nothing for you to solve.

    const int LIGHTSPEEDMPH = 186282;
    const int POUNDSPERPINT = 1;
    const int CHESSBOARDX = 8;
    const int CHESSBOARDY = 8;

    int chessboardx = 0;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "The speed of light is " << LIGHTSPEEDMPH << " miles per hour.\n";
    seeout << "A pint is " << POUNDSPERPINT << " pound, the world around.\n";
    seeout << "There are " << CHESSBOARDX * CHESSBOARDY << " squares on a chessboard.\n";
    chessboardx = 20;
    seeout << "There are still " << CHESSBOARDX * CHESSBOARDY << " squares on a chessboard.\n";
    seeout << "In other words, variable and constant names are case-sensitive.\n";
    seeout << "(Nothing to solve in this exercise.)\n";

    // uncomment the next line and compile to see what the error looks like when you try to
    // assign a value to a constant:

    //CHESSBOARDX = 20;

    // ...don't forget to comment it out again after you have seen the error
    // or FeetWetCoding won't compile anymore!
}


