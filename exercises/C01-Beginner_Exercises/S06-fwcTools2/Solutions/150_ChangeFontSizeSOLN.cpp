// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <exercises/C01_S06.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void ChangeFontSizeSoln::runExercise()
{
    int minfontsize(2), maxfontsize(30), step(3);
    int word1x(100), word1y(200), word1fontsize(minfontsize);
    int word2x(200), word2y(200), word2fontsize(minfontsize);
    int word3x(300), word3y(200), word3fontsize(minfontsize);

    std::string key;

    seeout << "Hover mouse over the drawing area above and press + or -";
    seeout << " to change the word sizes.  Press q to quit.\n";

    int word1 = fwcText("ALL",word1x,word1y,DARKBLUE,word1fontsize);
    int word2 = fwcText("YOUR",word2x,word2y,DARKBLUE,word2fontsize);
    int word3 = fwcText("BASE",word3x,word3y,DARKBLUE,word3fontsize);

    while ( key != "q" && key != "Q" )
    {
        key = waitForKeyPress();        // = is pronounced "GETS"

        if ( key == "+" )               // == is pronounced "EQUALS" :-)
        {

            if ( word1fontsize < maxfontsize )
            {
                word1fontsize += step;
                fwcChangeFontSize(word1, word1fontsize);
                word1x -= 10;
                word1y -= 3;
                fwcMoveItem(word1,word1x,word1y);
            }
            else if ( word2fontsize < maxfontsize )
            {
                word2fontsize += step;
                fwcChangeFontSize(word2, word2fontsize);
                word2x -= 7;
                word2y -= 3;
                fwcMoveItem(word2,word2x,word2y);
            }
            else if ( word3fontsize < maxfontsize )
            {
                word3fontsize += step;
                fwcChangeFontSize(word3, word3fontsize);
                word3x -= 2;
                word3y -= 3;
                fwcMoveItem(word3,word3x,word3y);
            }
        }

        if ( key == "-" )               // == is pronounced "EQUALS" :-)
        {
            if ( word3fontsize > minfontsize )
            {
                word3fontsize -= step;
                fwcChangeFontSize(word3, word3fontsize);
                word3x += 2;
                word3y += 3;
                fwcMoveItem(word3,word3x,word3y);
            }
            else if ( word2fontsize > minfontsize )
            {
                word2fontsize -= step;
                fwcChangeFontSize(word2, word2fontsize);
                word2x += 7;
                word2y += 3;
                fwcMoveItem(word2,word2x,word2y);
            }
            else if ( word1fontsize > minfontsize )
            {
                word1fontsize -= step;
                fwcChangeFontSize(word1, word1fontsize);
                word1x += 10;
                word1y += 3;
                fwcMoveItem(word1,word1x,word1y);
            }
        }
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
