// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S07.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void BubbleSort1Soln::runExercise()
{

    Color color = DARKBLUE;
    int element(0), swapper(0), count(0);
    int number_of_elements(10);
    int array[number_of_elements];
    int x_origin(50), y_origin(180), x(x_origin), y(y_origin), horizontal_step(30), vertical_step(50);
    bool we_swapped(false), collision(false);
    int random_candidate(0);

    std::string key;

    for ( element = 0; element < number_of_elements; element++ )
    {
        do
        {
            collision = false;
            random_candidate = random(number_of_elements)+1;
            for ( count = 0; count < number_of_elements; count++ )
            {
                if ( array[count] == random_candidate )
                {
                    collision = true;
                }
            }
        } while (collision);
        array[element] = random_candidate;
        seeout << array[element] << " ";
    }
    seeout << "\n";

    while ( key != "q" && key != "Q" )
    {
        fwcClearItems();

        for ( element = 0; element < number_of_elements; element++ )
        {
            fwcInt(array[element], x, y+vertical_step, color, 12);
            x += horizontal_step;
        }

        x = x_origin;

        for ( element = 1; element < number_of_elements; element++ )
        {
            if ( array[element] < array[element-1] )
            {
                swapper = array[element];
                array[element] = array[element-1];
                array[element-1] = swapper;

                seeout.setColor(RED);
                seeout << array[element-1] << " ";
                seeout << array[element] << " ";
            }
            else
            {
                seeout.setColor(BLACK);
                if ( element == 1 )
                {
                    seeout << array[element-1] << " ";
                }
                seeout << array[element] << " ";
            }
        }
        seeout.setColor(BLACK);
        seeout << "\n";

        key = waitForKeyPress();

    }
    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
