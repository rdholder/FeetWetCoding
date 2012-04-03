// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

void AssignmentArithmetic::runExercise()
{
    int x = 0, y = 0, a = 1, b = 3, c = 5, d = 7;

    fwcText("Reference Exercise:", 50, 150, BLUE, 20);
    fwcText("no solution needed.", 50, 180, BLUE, 20);

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


