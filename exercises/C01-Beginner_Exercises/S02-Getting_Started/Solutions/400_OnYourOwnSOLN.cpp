// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S02.h>

void OnYourOwnSoln::runExercise()  // copy the exercise name & paste it into main.cpp
{
    DrawText("I am learning C++, baby!!! :-D", 10, 10, BLACK, 20);
    DrawRectangle(100, 100, 200, 200, YELLOW, 10, true);
    DrawCircle(200, 200, 100, BLUE, 10);
    DrawLine(400, 200, 200, 400, GREEN, 3);
    DrawLine(0, 200, 200, 400, RED, 10);
    seeout << "This is the first C++ program I've written on my own!!!" << "\n";

}



