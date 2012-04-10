// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

void ChangeText::runExercise()
{
    std::string key;
    bool toggle_blue(true);

    seeout << "Press keys to toggle blue circle color and text color description, or q to quit.\n";

    int circle = fwcCircle(200,200,75,BLUE,1,true);
    fwcText("Circle color is:", 100, 300, BLUE, 24);
    int circle_color_text = fwcText("BLUE",180,350,BLUE,20);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();            // = is pronounced "GETS"

        if ( toggle_blue )     // == is pronounced "EQUALS" :-)
        {
            toggle_blue = false;
            fwcChangeColor(circle,BLUE,true);
            fwcChangeText(circle_color_text,"BLUE");
        }
        else
        {
            toggle_blue = true;
            fwcChangeColor(circle,RED,true);
            fwcChangeText(circle_color_text,"RED");
        }
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
