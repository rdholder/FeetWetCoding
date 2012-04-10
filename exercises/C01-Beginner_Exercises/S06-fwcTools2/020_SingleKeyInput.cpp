// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// You are seeing some new syntax here with key = waitForKeyPress()
// This is because waitForKeyPress() is a function that is returning
// a value, a character from the keyboard, and that value is stored
// in the key variable.  Don't worry if you don't understand this yet.
// We will get to functions and more soon.  Just try to recognize how
// you accept a key as input from the keyboard and store it in a
// variable here, so that you can use this capability in the coming
// exercises.

void SingleKeyInput::runExercise()
{
    int x = 100, y = 0;
    int fontSize = 200;
    std::string key;
    Color color = DARKGREEN;

    seeout.setColor(DARKRED);
    seeout.setFontSize(15);
    seeout << "Hover mouse over the exercise drawing area and press keys, or q to quit.\n";
    seeout.setFontSize(10);
    seeout.setColor(DARKBLUE);
    seeout << "(Try hitting some CTRL-key combinations to see some special characters";
    seeout << " in addition to the regular alphanumeric characters.  :-)\n";

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();
        fwcClearItems();
        fwcText(key, x, y, color, fontSize);
    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, color, 60);
}
