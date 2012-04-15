// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void CenteredText::runExercise()
{
    int key_as_int(0);


    std::string key;

    seeout.setColor(DARKRED);
    seeout.setFontSize(20);
    seeout << "Enter a string of text.\n";

    while ( key != "q" && key != "Q" )
    {
        key = getKeyboardString();
        key_as_int = atoi(key.c_str());
        fwcInt(key_as_int,200,200,DARKBLUE,20);
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
