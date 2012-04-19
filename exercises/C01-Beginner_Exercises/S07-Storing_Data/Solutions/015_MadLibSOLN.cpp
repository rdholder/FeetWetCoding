// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S07.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void MadLibSoln::runExercise()
{

    Color color = DARKBLUE;
    int number_of_nouns(10);
    std::string noun[] = {"lizard", "psychiatrist", "astronaut", "Elbonian", "spaceship",
                           "Ostrich", "Cabbage", "towel", "jellyfish", "programmer"};
    int number_of_verbs(10);
    std::string verb[] = {"dropped", "kicked", "ate", "flushed", "sproinged",
                           "evaporated", "transmogrified", "irritated", "collapsed", "dreamed"};
    int number_of_adjectives(10);
    std::string adjective[] = {"purple", "fuzzy", "narrow", "amazing", "dreamy",
                                "irritating", "contrary", "explosive", "fried", "hungry"};

    std::string key;

    fwcText("MadLib! :-)",150,150,DARKRED,20);
    fwcText("Press any key for a new sentence or q to quit",50,200,DARKBLUE);

    while ( key != "q" && key != "Q" )
    {
        seeout << "The " << noun[random(number_of_nouns)] << " ";
        seeout << verb[random(number_of_verbs)] << " the ";
        seeout << adjective[random(number_of_adjectives)] << " ";
        seeout << noun[random(number_of_nouns)] << ".\n";

        key = waitForKeyPress();
    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
