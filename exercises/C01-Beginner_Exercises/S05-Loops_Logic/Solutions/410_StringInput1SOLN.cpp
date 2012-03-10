// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>
#include <math.h>

void StringInput1Soln::runExercise()
{
    int x;
    int fontSize = 15;
    std::string name, greeting;
    Color color = DARKBLUE;

    DrawText("Mouseover this window, then", 30, 100, color);
    DrawText("type your name and hit ENTER:", 30, 130, color);
    name = getKeyboardString();
    DrawRectangle(3, 3, 397, 397, WHITE, 1, true);

    greeting.assign("Hi ");
    greeting.append(name);
    greeting.append("!!! :-)");

    x = 200-(greeting.size()*fontSize)/4;

    DrawText(greeting, x, 180, color, fontSize);

    seeout << "Notice that in this solution, the greeting is more or less";
    seeout << " centered in the drawing area, regardless of how many";
    seeout << " characters are in your name.  Re-start this exercise and";
    seeout << " try longer and shorter names to see what I mean.\n";
}
