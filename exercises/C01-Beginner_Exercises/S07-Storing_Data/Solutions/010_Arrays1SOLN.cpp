// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S07.h>
#include <math.h>

// ==========================================
// =       THIS IS THE SOLUTION CODE        =
// =    THIS IS *NOT* THE EXERCISE CODE     =
// = (If you meant to look at the exercise  =
// = it's in the directory above this one.) =
// ==========================================

void Arrays1Soln::runExercise()
{

    int x, y, person(0), key_as_int(-1), week(1);
    int lottery_amount(0);
    int bank_account_person1(0);
    int bank_account_person2(0);
    int bank_account_person3(0);
    int bank_account_person4(0);
    int bank_account_person5(0);
    int bank_account_person6(0);
    int bank_account_person7(0);


    Color color = DARKBLUE;
    int number_of_people(7);
    int array_of_bank_accounts[number_of_people];

    std::string key;

    for (person = 0; person < number_of_people; person++ )  // always initialize your array!
    {
        array_of_bank_accounts[person] = 0;
    }

    while ( key != "q" && key != "Q" )
    {
        lottery_amount = random(100);
        fwcClearItems();
        fwcText("Week #",50,50,color);
        fwcInt(week++,300,50,color);
        fwcText("The winning lottery ticket pays $", 50, 100, color);
        fwcInt(lottery_amount,300,100,color);
        fwcText("Press key 1-7 to choose who gets the money!", 50,200,color);

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
        if ( key_as_int == 3 )
        {
            bank_account_person3 += lottery_amount;
        }
        if ( key_as_int == 4 )
        {
            bank_account_person4 += lottery_amount;
        }
        if ( key_as_int == 5 )
        {
            bank_account_person5 += lottery_amount;
        }
        if ( key_as_int == 6 )
        {
            bank_account_person6 += lottery_amount;
        }
        if ( key_as_int == 7 )
        {
            bank_account_person7 += lottery_amount;
        }

        seeout << "OLD  WAY: Person(Balance):";
        seeout << " 1(" << bank_account_person1 << ")";
        seeout << " 2(" << bank_account_person2 << ")";
        seeout << " 3(" << bank_account_person3 << ")";
        seeout << " 4(" << bank_account_person4 << ")";
        seeout << " 5(" << bank_account_person5 << ")";
        seeout << " 6(" << bank_account_person6 << ")";
        seeout << " 7(" << bank_account_person7 << ")";
        seeout << "\n";

        if ( key_as_int >=0 && key_as_int < number_of_people )  // always check that your index is sane!
        {
            array_of_bank_accounts[key_as_int] += lottery_amount;
        }

        seeout << "NEW WAY: Person(Balance):";

        for (person = 0; person < number_of_people; person++ )
        {
            seeout << " " << person+1 << "(" << array_of_bank_accounts[person] << ")";
        }
        seeout << "\n";

    }

    fwcClearItems();
    fwcText("DONE!", 60, 150, DARKBLUE, 60);
}
