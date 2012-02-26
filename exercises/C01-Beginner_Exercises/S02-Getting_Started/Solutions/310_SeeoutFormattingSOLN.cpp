// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void seeoutFormattingSoln::runExercise()
{
    DrawText("Make the seeout output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1\n";
    seeout << "2\n";
    seeout << "3\n\n\n";
    seeout << "I";
    seeout << " need";
    seeout << " my";
    seeout << " spaces!\n";
}


