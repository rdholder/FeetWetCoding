// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/310_SeeoutFormatting.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void seeoutFormatting::runExercise()
{
    DrawText("Make the seeout output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1";
    seeout << "2";
    seeout << "3" << "\n";
    seeout << "I";
    seeout << "need";
    seeout << "my";
    seeout << "spaces!\n";
}

