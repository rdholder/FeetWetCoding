// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S03.h>
using std::string;

extern bool Gsoln;

int StandardStrings::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;

    string towel ("Always know where your towel is!");
    string fordsays ("Don't Panic!");
    string swap ("sometext");

    DrawText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    swap = fordsays;
    fordsays = towel;
    towel.clear();
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    towel = "Don't forget to bring a towel!";
    fordsays = swap;
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";

    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame
    StandardStringsSoln *solution = new StandardStringsSoln();
    solution->runExercise();        // run Soln code to show what solution looks like

    return 0;
}


