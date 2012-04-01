// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void OnYourOwnSoln::runExercise()  // copy the exercise name & paste it into main.cpp
{
    fwcDrawText("I am learning C++, baby!!! :-D", 10, 10, BLACK, 20);
    fwcDrawCircle(200, 100, 25, BLUE, 10, true);
    fwcDrawLine(180, 150, 100, 75, GREEN, 20);
    fwcDrawLine(220, 150, 300, 100, RED, 20);
    fwcDrawRectangle(175, 250, 25, 150, DARKRED, 1, TRUE);
    fwcDrawRectangle(200, 250, 25, 150, YELLOW, 1, true);
    fwcDrawRectangle(175, 150, 50, 100, CYAN, 10, true);
    seeout << "This is the first C++ program I've written on my own!!!" << "\n";

}



