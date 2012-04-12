#include <lib/MyCode.h>

void MyCode9::runExercise()
{
    fwcText("How random are our random numbers?", 50, 100, BLUE, 24);

    int n = 0;

    int IntOccurance[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    //Color color = DARKBLUE;

    for ( n = 1; n < 10000000; n++ )
    {
        IntOccurance[random(10)]++;
    }

    for ( n = 0; n < 10; n++ )
    {
        seeout << n << ": " << IntOccurance[n] << "\n";
    }
}
