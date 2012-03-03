// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

// Open (double-click) the README.html file to access the documentation.

#include <exercises/C01_S02.h>

void Welcome::runExercise()
{
    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("Welcome to FeetWetCoding!", 20, 30, BLUE, 20);
    DrawText("______________________", 20, 30, BLUE, 20);

    //******************************************************************
    // ATTN ROB: All this stuff from here down is just exmample code
    //           for YOU so you can see how to use the new features
    //           enabled by the threading. It's not intended for the
    //           users, so you can remove it when you're done with it.
    //******************************************************************

    //Example 1: Pause while looping using sleep()/msleep()/usleep()
    sleep(1);
    int x=20;
    int y=80;
    int fontSize = 14;
    int count(4);
    DrawText("Example 1 - Pause while looping:", x, y, BLUE, 14);
    sleep(1);
    while (--count)
    {
        y+=20;
        DrawText("Hi! Count is now: ", x, y, RED, fontSize);
        DrawInt(count, x+270, y, RED, fontSize);
        sleep(1);
    }

    //Example 2: Wait for keyboard input while looping using waitForKeyPress()
    y+=50;
    DrawText("Example 2 - waitForKeyPress():", x, y, BLUE, 14);
    sleep(1);
    std::string key, name;
    count = 2;
    while (count)
    {
        y+=20;
        if ( 2 == count )
            DrawText("Hi! Please enter a letter: ", x, y, RED, fontSize);
        else
            DrawText("Thanks! Please enter another one: ", x, y, RED, fontSize);
        key = waitForKeyPress();
        DrawText(key, x+300, y, DARKGREEN, fontSize);
        count--;
    }


    //Example 3: Wait for keyboard input while looping using getKeyboardString()
    y+=50;
    DrawText("Example 3 - getKeyboardString()", 20, y, BLUE, 14);
    sleep(1);
    DrawText("What's your name?", x, y+20, RED, fontSize);
    name = getKeyboardString();
    std::string message = "Hi, " + name + "!";
    DrawText(message, x+70, y+70, DARKGREEN, 18);
}
