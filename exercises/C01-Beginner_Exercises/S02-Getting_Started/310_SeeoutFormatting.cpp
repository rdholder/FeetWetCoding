// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void seeoutFormatting::runExercise()
{
    fwcText("Make the seeout output", 30, 80, BLUE, 20);
    fwcText("in the boxes below match...", 30, 120, BLUE, 20);

    seeout << "1" << "2" << "3";
    seeout << "\n";
    seeout << "I";
    seeout << "need";
    seeout << "my";
    seeout << "spaces!\n";
}


