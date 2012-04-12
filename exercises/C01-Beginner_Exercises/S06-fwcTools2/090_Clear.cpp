// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// this exercise needs to come earlier in the sequence
// probably 020_Clear.cpp.  Don't forget to change menu.

void Clear::runExercise()
{
    int x(100), y(0), count(0), numberofcircles(50), objectsize(20);
    int fontSize(200);
    std::string key;
    Color color = DARKGREEN;

    seeout << "When you press a key, all graphical objects will be deleted.\n";

    for(count=0; count<numberofcircles; ++count)
    {
        x=random(400-(objectsize*2))+objectsize;
        y=random(400-(objectsize*2))+objectsize;
        fwcCircle(x,y,objectsize,DARKRED,1,true);    }

    key = waitForKeyPress();

    fwcClearItems();
    fwcText("DONE!", 60, 150, color, 60);
}
