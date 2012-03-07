// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void SingleKey1::runExercise()
{
    int x = 100, y = 0;
    int fontSize = 200;
    std::string key;
    Color color = DARKBLUE;

    seeout << "Press keys, or q to quit.\n";

    while ( key != "q" || key != "Q" )
    {
        key = waitForKeyPress();
        DrawRectangle(0,0,399,399,WHITE,1,true);
        DrawText(key, x, y, DARKGREEN, fontSize);
    }
}
