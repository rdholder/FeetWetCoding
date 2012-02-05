// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

#include <exercises/C01_S04.h>

using std::string;

void AssignmentArithmetic::runExercise()
{
    int x = 0, y = 0, a = 1, b = 3, c = 5, d = 7;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    x = a + b;
    y = c + d;
    seeout << "1st x,y: " << x << "," << y << "\n";
    x = x + 1;
    y += 1;
    seeout << "2nd x,y: " << x << "," << y << "\n";
    x = x - 1;
    y -= 1;
    seeout << "3rd x,y: " << x << "," << y << "\n";
    x = x * 3;
    y *= 3;
    seeout << "4th x,y: " << x << "," << y << "\n";
    x = x / 2;
    y /= 2;
    seeout << "5th x,y: " << x << "," << y << "\n";
}


