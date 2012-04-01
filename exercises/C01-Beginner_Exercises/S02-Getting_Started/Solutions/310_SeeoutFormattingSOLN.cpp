// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void seeoutFormattingSoln::runExercise()
{
    fwcDrawText("Make the seeout output", 30, 80, BLUE, 20);
    fwcDrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1\n" << "2\n3\n\n\n";
    seeout << "I";
    seeout << " need";
    seeout << " my";
    seeout << " spaces!\n";
}


