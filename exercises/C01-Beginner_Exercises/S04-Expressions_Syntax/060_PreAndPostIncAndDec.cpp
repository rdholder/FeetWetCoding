// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <setup.h>
#include <exercises/C01_S04.h>
using std::string;

extern bool Gsoln;

int PreAndPostIncAndDec::runExercise()     // copy the exercise name & paste it into main.cpp
{
    Gsoln = false;

    int a = 0, b = 1, c = 3, d = 5, e = 7;
    int swap1 = 0, swap2 = 0, sum = 0;

    seeout << "1st sum: " << sum++ << "\n";
    seeout << "2nd sum: " << sum++ << "\n";
    seeout << "3rd sum: " << ++sum << "\n";


    // This is FeetWetCoding internal stuff you can ignore for now:
    DrawReferenceBox(LEFTRIGHT);    // draw the graphical reference frame

    return 0;
}


