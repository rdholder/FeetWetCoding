// copyright (c) 2011 Robert Holder, Janice Dugger.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// HandsDirtyCPP/exercises/Chapter01/DrawingPuzzlesSoln.cpp
// Chapter 01 Exercise 10: Drawing Code Puzzles!
//

// OPEN HandsDirtyCPP/helpinfo/html/DrawingPuzzles.html
// for more information about this exercise.

#include <setup.h>

// HandsDirtyCPP Example 1:  Introductory Drawing Examples Solution.

int DrawingPuzzlesSoln::runExercise()
{
    ClearScreen();

    // Declare the variables we will use.
    int x, y, radius, height;
    Color color;

    // This section draws the concentric blue circles.  Can you figure out how to change
    // the code here so that there are no blue circles outside the red box?
    for ( radius = 10; radius < 100; radius = radius + 20 )
    {
        DrawCircle(100, 100, radius, BLUE, 3);
    }
    DrawRectangle(50, 50, 100, 100, RED, 3);


//    // This section draws the arrangement of circles.  Can you figure out how to change
//    // the DrawEllipse for the GRAY circles so they fit with the BLUE, RED and GREEN circles?
//    for ( radius = 10; radius < 100; radius = radius + 10 )
//    {
//        DrawCircle( 100-radius, 100-radius, radius, 1, BLUE );
//    }

//    for ( radius = 10; radius < 100; radius = radius + 10 )
//    {
//        DrawCircle(120, 100-radius, radius, 1, RED );
//    }

//    for ( radius = 10; radius < 100; radius = radius + 10 )
//    {
//        DrawCircle( 100-radius, 120+(radius/21), radius, 1, GREEN );
//    }

//    for ( radius = 10; radius < 100; radius = radius + 10 )
//    {
//        DrawCircle( 120, 120, radius, 1, GRAY );
//    }



    // Draw our bar graph looking thingy (which shows up to the right of the arrangement of
    // circles in black.  Can you add a line of code so that the missing line is drawn horizontally
    // across the screen in the middle of the "bars"?  (Hint: this is where y = 100 for the whole line.)
    y = 100;
    for (x = 250; x < MAX_X - 20; x = x + 20)
    {
        height = randomRange(-100, 100);
        DrawLine(x, 100, x, 100 + height, BLACK, 2);
        DrawLine(x, 100 + height, x + 10, 100 + height, BLACK, 2);
        DrawLine(x + 10, 100 + height, x + 10, 100, BLACK, 2);



        DrawLine(x, 100, x + 10, 100, BLACK, 2); // this will draw each box's bottom
    }
    DrawLine(250, 100, MAX_X - 20, 100, BLACK, 2); // or you could do it all in one shot like this
    // notice you can draw lines, circles, etc. on top of each other and whichever one was drawn last
    // is the one that will show up.


    // another, easier way to draw the bar graph... but it's broken and the bars are overlapping each
    // other!  can you fix it?
    for (x = 20; x < MAX_X/3; x = x + 10)
    {
        DrawRectangle(x, 400, 10, randomRange(-100, 100), BLUE, 2);  // 10 is the right size, not 20!  :-)
    }


    // draw a grid of circles.  the circles are randomly colored.  can you figure out how to make
    // all the circles in a vertical column the same color?
    for (x = 300; x < MAX_X - 20; x = x + 20)
    {
        for (y = 250; y < MAX_Y - 20; y = y + 20)
        {
            switch ( x % 7 )    // don't feel bad if you don't know what this is!  if you found another
                                // way to do this, so long as it works, that's what counts!  :-)
            {
            case 1: color = BLACK;  break;
            case 2: color = RED;    break;
            case 3: color = GREEN;  break;
            case 4: color = YELLOW; break;
            case 5: color = BLUE;   break;
            case 6: color = PINK;   break;
            case 7: color = GRAY;   break;
            }

            DrawCircle(x, y, 15, color, 2);
        }
    }

    return ENDPROGRAMSIGNAL;
}
