// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S03.h>

void Chars::runExercise()
{
    // We will get into strings and arrays in Chapter 01, Section 06.
    // You will probably almost never actually use single character variables in
    // this way, but this exercise is here for the sake of completeness, and for
    // your reference.  There is nothing for you to solve in this exercise.

    char lettera = 'A';     // individual letters get ' quotes, not " quotes
    char letterb = 'B';     // because " denotes a string.  Don't worry, we'll get to it.  :-)

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "Grades for Mr. Picklefeather's English Class:\n";
    seeout << "Jane: " << lettera << "\n";
    seeout << "Jill: " << letterb << "\n";
    seeout << "(Nothing to solve in this exercise.)\n";
}


