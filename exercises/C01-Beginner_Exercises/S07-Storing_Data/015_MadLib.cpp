// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S07.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void MadLib::runExercise()
{

    Color color = DARKBLUE;
    int number_of_nouns(10);
    std::string noun[] = {"lizard", "psychiatrist", "astronaut", "Elbonian", "spaceship",
                           "Ostrich", "Cabbage", "towel", "jellyfish", "programmer"};

    std::string key;

    while ( key != "q" && key != "Q" )
    {
        seeout << "The " << noun[random(number_of_nouns)];

        key = waitForKeyPress();
    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
