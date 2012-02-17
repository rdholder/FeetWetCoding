// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/400_OnYourOwnSOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void OnYourOwnSoln::runExercise()  // copy the exercise name & paste it into main.cpp
{
    DrawText("I am learning C++, baby!!! :-D", 10, 10, BLACK, 20);
    DrawCircle(200, 100, 50, BLUE, 10, true);
    DrawLine(180, 150, 100, 75, GREEN, 20);
    DrawLine(220, 150, 300, 100, RED, 20);
    DrawRectangle(175, 250, 25, 150, DARKRED, 1, TRUE);
    DrawRectangle(200, 250, 25, 150, YELLOW, 1, true);
    DrawRectangle(175, 150, 50, 100, CYAN, 10, true);
    seeout << "This is the first C++ program I've written on my own!!!" << "\n";

}



