// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S06.h>
#include <math.h>

void StringInput1::runExercise()
{
    int x = 10, y = 20, count;
    int fontSize = 20;
    std::string name, greeting;
    Color color = DARKBLUE;

    int text1 = DrawText("Mouseover this window, then", 30, 100, color);
    int text2 = DrawText("type your name and hit ENTER:", 30, 130, color);
    name = getKeyboardString();

    //Clear the old text...
    EraseItem(text1);
    EraseItem(text2);

    //And add the new...
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
