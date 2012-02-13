// FeetWetCoding/exercises/C01-BeginnerExercises/S02-GettingStarted/400_OnYourOwnSOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

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



