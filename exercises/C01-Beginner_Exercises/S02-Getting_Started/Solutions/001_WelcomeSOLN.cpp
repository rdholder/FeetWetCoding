// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S02.h>

void WelcomeSoln::runExercise()
{
    //ORIG CONTENT
    //DrawText("Welcome to FeetWetCoding!", 20, 150, RED, 20);

    //SAMPLE CONTENT FOR NEW THREADED ARCHITECTURE
    // USAGE: DrawText("Text.", x, y, color, fontsize);
    DrawText("Welcome to FeetWetCoding!", 20, 30, BLUE, 20);
    DrawLine(20, 70, 360, 70, BLUE, 2);

    //******************************************************************
    // ATTN ROB: All this stuff from here down is just exmample code
    //           for YOU so you can see how to use the new features
    //           enabled by the threading. It's not intended for the
    //           users, so you can remove it when you're done with it.
    //******************************************************************

    //Seeout test
//    seeout << "The quick brown fox ";
//    seeout.setColor(BLUE);
//    seeout << "jumps over the lazy ";
//    seeout.setColor(RED);
//    seeout.setFontSize(18);
//    seeout << "DOG";
//    seeout << "\n" << 1 << "," << 2 << "," << 3.0 << "\n";

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
    y+=30;
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
    y+=30;
    DrawText("Example 3 - getKeyboardString()", 20, y, BLUE, 14);
    sleep(1);
    DrawText("What's your name?", x, y+20, RED, fontSize);
    name = getKeyboardString();
    std::string message = "Hi, " + name + "!";
    DrawText(message, x+50, y+50, DARKGREEN, 18);

    //Example 4: Animation()
    y+=80;
    DrawText("Example 4 - Animation:", x, y, BLUE, 14);
    y+=50;

    x = 0;
    int dx(2);
    int circle = DrawCircle(x,y,20,PINK,1, true);

    while (x < 380)
    {
        x+=dx;
        ShiftDrawnItem(circle, dx, 0);
        msleep(20);
    }
}
