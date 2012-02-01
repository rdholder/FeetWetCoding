// copyright (c) 2011 eotsucodefoundry.com.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
extern bool Gsoln;

int seeoutIntro::runExercise()  // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;              // is this exercise code or solution code?

    DrawText("Make the seeout output", 30, 80, BLUE, 20);
    DrawText("in the boxes below match...", 30, 120, BLUE, 20);

    // seeout is a FeetWetCoding tool designed to work like std::cout, except
    // that it prints its output right into your working window so you don't
    // have to go looking for it in the QtCreator IDE (we'll learn how to do that
    // a little later).

    seeout << "1" << "\n";   // the "\n" (newline) means move down to the next line
    seeout << "2" << "\n";
    seeout << "3" << "\n";
    seeout << "4" << "\n";
    seeout << "5" << "\n";



    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    seeoutIntroSoln *solution = new seeoutIntroSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}


