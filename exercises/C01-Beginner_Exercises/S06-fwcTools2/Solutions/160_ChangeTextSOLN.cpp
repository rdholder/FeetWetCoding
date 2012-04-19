// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ChangeTextSoln::runExercise()
{
    std::string key;

    seeout << "Press keys R, G or B to change circle color and text color description, or q to quit.\n";

    int circle = fwcCircle(200,200,75,BLUE,1,true);
    fwcText("Circle color is:", 100, 300, BLUE, 24);
    int circle_color_text = fwcText("BLUE",180,350,BLUE,20);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();            // = is pronounced "GETS"

        if ( key == "r" || key == "R" )     // == is pronounced "EQUALS" :-)
        {
            fwcChangeColor(circle,RED,true);
            fwcChangeText(circle_color_text,"RED");
        }
        if ( key == "g" || key == "G" )
        {
            fwcChangeColor(circle,GREEN,true);
            fwcChangeText(circle_color_text,"GREEN");
        }
        if ( key == "b" || key == "B" )
        {
            fwcChangeColor(circle,BLUE,true);
            fwcChangeText(circle_color_text,"BLUE");
        }
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
