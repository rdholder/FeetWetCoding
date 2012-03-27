// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S05.h>

void Switch1Soln::runExercise()
{
    int x = 0, y = 0, size = 30;
    int horizontalstep = 50, verticalstep = 50;
    bool iscircle = true;
    Color color = BLUE;

    //fwcDrawRectangle(0, 0, 400, 400, BLACK, 1, true);

    for ( x = 0; x < 400; x += horizontalstep )
    {
        for (y = 0; y < 400; y += verticalstep )
        {
            if ( random(1) == 1 )
            {
                iscircle = true;
            }
            else
            {
                iscircle = false;
            }
            switch ( random(8) ){
            case 1:
                color = BLUE;
                break;
            case 2:
                color = RED;
                break;
            case 3:
                color = BLACK;
                break;
            case 4:
                color = CYAN;
                break;
            case 5:
                color = GREEN;
                break;
            case 6:
                color = YELLOW;
                break;
            case 7:
                color = DARKBLUE;
            }

            if ( random(2) )
            {
                fwcDrawCircle(x+size/2, y+size/2, size/2, color, 5, random(2) );
            }
            else
            {
                fwcDrawRectangle(x, y, size, size, color, 5, random(2));
            }
        }
    }
    seeout << "Click the \"Re-start Exercise\" button a few times to get an idea";
    seeout << " of the behavior we are looking for here.\n\n";
    seeout << "Since we are picking the colors, shapes and fill randomly here,";
    seeout << " the goal is not to get both sides looking exactly alike, but";
    seeout << " rather, to match the *behavior*.\n\n";
    seeout << "The extra colors you need are named BLACK, YELLOW, GREEN, CYAN";
    seeout << " and DARKBLUE.\n";
}
