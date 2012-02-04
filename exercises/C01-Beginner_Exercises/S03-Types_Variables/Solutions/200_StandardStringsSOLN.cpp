
// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S03.h>
extern bool Gsoln;

using std::string;

int StandardStringsSoln::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = true;

    string towel ("Always know where your towel is!");
    string fordsays ("Don't Panic!");
    string swap ("sometext");

    DrawText("seeout output below:", 50, 170, BLUE, 20);

    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    swap = towel;
    fordsays = "Time is an illusion, lunchtime doubly so.";
    towel.clear();
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";
    towel = "Don't forget to bring a towel!";
    towel = swap;
    seeout << "towel contains: " << towel << "\n";
    seeout << "fordsays contains: " << fordsays << "\n";
    seeout << "Characters in towel string: " << towel.size();
    seeout << "  Characters in fordsays string: " << fordsays.size() << "\n\n";

    return 0;
}


