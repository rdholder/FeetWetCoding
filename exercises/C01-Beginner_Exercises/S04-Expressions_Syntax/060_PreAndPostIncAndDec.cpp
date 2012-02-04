// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S04.h>

using std::string;

void PreAndPostIncAndDec::runExercise()     // copy the exercise name & paste it into main.cpp
{
    int sum = 0;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "1st sum: " << sum++ << "\n";
    seeout << "2nd sum: " << sum++ << "\n";
    seeout << "3rd sum: " << ++sum << "\n";
    seeout << "4th sum: " << sum-- << "\n";
    seeout << "5th sum: " << sum-- << "\n";
    seeout << "6th sum: " << --sum << "\n";
    seeout << "7th sum: " << ++sum << "\n";
}


