// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void CenteredTextSoln::runExercise()
{
    int fontsize_as_int(0);
    std::string text_input, fontsize_input;

//    seeout.setColor(DARKRED);
//    seeout.setFontSize(20);

    int prompt_message = fwcText("You will probably never see this in the drawing area because it will be replaced almost instantly!",10,20,DARKRED);
    int display_string = fwcText("Placeholder string",200,200,DARKBLUE);

    while ( text_input != "q" && text_input != "Q" )
    {
        fwcChangeText(prompt_message, "Type a string of text and hit enter, or enter q to quit.");
        text_input = getKeyboardString();
        seeout.setColor(BLACK);
        seeout << "text_input == ";
        seeout.setColor(DARKGREEN);
        seeout << text_input;

        fwcChangeText(prompt_message, "Now enter a fontsize:");
        fontsize_input = getKeyboardString();
        fontsize_as_int = atoi(fontsize_input.c_str());
        seeout.setColor(BLACK);
        seeout << ", fontsize_input == ";
        seeout.setColor(DARKGREEN);
        seeout << fontsize_input << "\n";

        fwcChangeText(display_string, text_input);
        fwcChangeFontSize(display_string,fontsize_as_int);
        fwcMoveItem(display_string,200-(text_input.length()*fontsize_as_int)/2,200);

    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
