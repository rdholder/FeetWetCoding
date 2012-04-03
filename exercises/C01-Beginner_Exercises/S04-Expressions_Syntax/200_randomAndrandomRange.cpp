// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

void randomAndrandomRange::runExercise()     // copy the exercise name & paste it into main.cpp
{
    // USAGE: random(int biggest)
    // Return a random number between 0 and biggest.

    // USAGE: randomRange(int smallest, int biggest)
    // Return a number between smallest and biggest.  You can supply positive or negative ints,
    // just make sure smallest < biggest, for example calling it with 10,20 will give you a
    // random int betwen 10 and 20.  Supplying -30,20 will give a random int between -30 and 20
    // If you need 0 through x you should use random(x);
    // If you need -x through 0, you should use random(x) * -1;

    int a = 0, b = 0;

    fwcText("Reference Exercise:", 50, 150, BLUE, 20);
    fwcText("no solution needed.", 50, 180, BLUE, 20);

    seeout << "You can run this program several times to see that the numbers change";
    seeout << " by clicking the \"Re-start Exercise\" button.\n\n";

    a = random(100);
    b = random(100);
    seeout << "Two random numbers:  a == " << a << ", b == " << b << "\n";
    seeout << "They retain their values until you call random again:\n";
    seeout << "a == " << a << ", b == " << b << "\n\n";

    a = random(100);
    b = random(100);
    seeout << "New random numbers:  a == " << a << ", b == " << b << "\n\n";

    a = randomRange(10, 20);
    b = randomRange(-1000, 10);
    seeout << "randomRange() chooses a number within the range you specified:\n";
    seeout << "a == " << a << ", b == " << b << "\n";
}


