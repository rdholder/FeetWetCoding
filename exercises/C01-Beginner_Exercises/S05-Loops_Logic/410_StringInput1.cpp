// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>
#include <math.h>

void StringInput1::runExercise()
{
    int x = 10, y = 20, count;
    int fontSize = 20;
    std::string name, greeting;
    Color color = DARKBLUE;

    DrawText("Mouseover this window, then", 30, 100, color);
    DrawText("type your name and hit ENTER:", 30, 130, color);
    name = getKeyboardString();
    DrawRectangle(3, 3, 397, 397, WHITE, 1, true);

    for ( count=0; count < 50; count++ )
    {
        fontSize = random(10)+3;
        greeting.assign("Hi ");
        greeting.append(name);
        greeting.append("!!! :-)");

        x = random(400-greeting.size()*fontSize);
        y = random(400-fontSize*2);
        DrawText(greeting, x, y, color, fontSize);
        msleep(100);
    }
}
