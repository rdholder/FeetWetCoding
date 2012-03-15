// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>
#include <math.h>

void StringInput1Soln::runExercise()
{
    int x;
    int fontSize = 15;
    std::string name, greeting;
    Color color = DARKBLUE;

    int text1 = DrawText("Mouseover this window, then", 30, 100, color);
    int text2 = DrawText("type your name and hit ENTER:", 30, 130, color);
    name = getKeyboardString();

    //Clear the old text...
    EraseItem(text1);
    EraseItem(text2);

    //And add the new...
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
