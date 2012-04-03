// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void PreAndPostIncAndDecSoln::runExercise()     // copy the exercise name & paste it into main.cpp
{
    int sum = 0;

    fwcText("...the seeout output below.", 50, 150, BLUE, 20);


    seeout << "1st sum: " << sum++ << "\n";
    seeout << "2nd sum: " << ++sum << "\n";
    seeout << "3rd sum: " << sum++ << "\n";
    seeout << "4th sum: " << ++sum << "\n";
    seeout << "5th sum: " << sum-- << "\n";
    seeout << "6th sum: " << --sum << "\n";
    seeout << "7th sum: " << --sum << "\n\n";

    seeout << "You can get these numbers without adding or deleting any";
    seeout << " lines from your program, but rather just by changing the";
    seeout << " ++ and -- operators.\n";
}


