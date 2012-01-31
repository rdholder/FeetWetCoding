// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// HandsDirtyCPP/exercises/Chapter01/DrawingPuzzles.cpp
// Chapter 01 Exercise 10: Drawing Code Puzzles!
//

// OPEN HandsDirtyCPP/helpinfo/html/DrawingPuzzles.html
// for more information about this exercise.

// This exercise contains some graphical coding puzzles for you to solve.  The
// code below draws some things on the screen, but there is something a little wrong
// with each one.  You can try to play around with the examples below to fix what is
// wrong in each example, and if you can't figure it out, don't worry!  If you get
// stuck, you can always look at the solution for this exercise, in the file
// HandsDirtyCPP/exercises/ch01ex10DrawingPuzzlesSoln.cpp  Try to solve them on your own
// first, it's good practice.  You can do it!

#include <setup.h>

// eotsu Example 1:  Introductory Drawing Examples

int DrawingPuzzles::runExercise()
{
    ClearScreen();

    // Declare the variables we will use.
    int x, y, radius, height;
    Color color;

    // This section draws the concentric blue circles.  Can you figure out how to change
    // the code here so that there are no blue circles outside the red box?
    for ( radius = 10; radius < 200; radius = radius + 20 )
    {
        DrawCircle( 100, 100, radius, BLUE, 3 );
    }
    DrawRectangle( 50, 50, 100, 100, RED, 3 );

    // Draw our black bar graph looking thingy (which shows up to the right of the blue concentric
    // circles and red box.)  The x-axis (horizontal line) is missing.  (It is present in the blue
    // bar graph in the lower right of the window when the program runs, for comparison.)
    // Can you make the black bar graph have this line?  (Hint: this is where y = 100 for the whole line.)
    y = 100;
    for (x = 250; x < MAX_X - 20; x = x + 20)
    {
        height = randomRange(-100, 100);
        DrawLine(x, 100, x, 100 + height, BLACK, 2);
        DrawLine(x, 100 + height, x + 10, 100 + height, BLACK, 2);
        DrawLine(x + 10, 100 + height, x + 10, 100, BLACK, 2);
        // add a line here to draw the axis through the origin of the "bars"
    }
    // ...or you could add a line here to do it!


    // another, easier way to draw the bar graph... but it's broken and the bars are overlapping each
    // other!  can you fix it?
    for ( x = 20; x < MAX_X/3; x = x + 10)
    {
        DrawRectangle(x, 400, 20, randomRange(-100, 100), BLUE, 2);
    }

    // draw a grid of circles.  the circles are randomly colored.  can you figure out how to make
    // all the circles in a vertical column the same color?
    for ( x = 300; x < MAX_X - 20; x = x + 20)
    {
        for ( y = 250; y < MAX_Y - 20; y = y + 20)
        {
            switch ( random(7) )
            {
            case 1: color = BLACK;  break;
            case 2: color = RED;    break;
            case 3: color = GREEN;  break;
            case 4: color = YELLOW; break;
            case 5: color = BLUE;   break;
            case 6: color = PINK;   break;
            case 7: color = GRAY;   break;
            }

            DrawCircle(x, y, 15, color, 2 );
        }
    }
    return 0;
}
