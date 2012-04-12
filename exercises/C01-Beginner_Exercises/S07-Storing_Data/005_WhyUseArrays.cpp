// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S07.h>
#include <math.h>

void WhyUseArrays::runExercise()
{

    int x, y, person(0), key_as_int(-1), week(1);
    int lottery_amount(0);
    int bank_account_person1(0);
    int bank_account_person2(0);

    Color color = DARKBLUE;

    std::string key;

    seeout << "Bank Balances for Person:\n";
    seeout << "1\t2\n";

    while ( key != "q" && key != "Q" )
    {
        lottery_amount = random(1000);
        fwcClearItems();
        fwcText("Week #",20,300,color);
        fwcInt(week++,300,300,color);
        fwcText("The winning lottery ticket pays $", 20, 330, color);
        fwcInt(lottery_amount,300,330,color);
        fwcText("Press key 1 or 2 to choose who gets the money!", 20,350,color);

        key = waitForKeyPress();
        key_as_int = atoi(key.c_str());

        //seeout << "You pressed: " << key << " " << key_as_int << "\n";

        if ( key_as_int == 1 )
        {
            bank_account_person1 += lottery_amount;
        }
        if ( key_as_int == 2 )
        {
            bank_account_person2 += lottery_amount;
        }

        seeout << "$" << bank_account_person1 << "\t";
        seeout << "$" << bank_account_person2 << "\t";
        seeout << "\n";
    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
