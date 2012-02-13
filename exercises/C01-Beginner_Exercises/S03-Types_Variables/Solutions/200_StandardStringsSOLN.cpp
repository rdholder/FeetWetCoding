// FeetWetCoding/exercises/C01-BeginnerExercises/S03-Types_Variables/200_StandardStringsSOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S03.h>

using std::string;

void StandardStringsSoln::runExercise()
{
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
}


