// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

void OrderOfOperations::runExercise()
{
    // Read:
    // http://www.cplusplus.com/doc/tutorial/operators/
    // "The C Programming Language", Kernighan & Ritchie, page 200 Section A7, "Expressions"

    // For arithmetic, the simplified basics of precendence, or "order of operations" are:
    // resolve everything in parentheses first.
    // resolve innermost parentheses before outer ones.
    // * resolves before /
    // / resolves before + and -

    // In this exercise, you will see some equations that LOOK very similar to each
    // other, and yet give different results!

    // THIS STUFF CAN BE CONFUSING!  Just try to absorb the basic idea here that the
    // compiler needs to have rules to decide what order to solve what parts of your
    // equation first, and you can force certain parts of an equation to be solved
    // first by putting that part in () parentheses.

    // Basically, when in doubt, force things to resolve the way you want by grouping
    // terms in parentheses. It seemed very mysterious to me at first, but after you
    // play around with it a bit, it starts to feel more natural.  :-)

    double x = 0, a = 4, b = 8, c = 16, d = 2;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    x = a + b * c / d;
    seeout << "1st x: " << a << " + " << b << " * " << c << " / " << d << " == " << x << "\n";
    seeout << " because " << b << " * " << c << " == " << b * c << "\n";
    seeout << " and " << b * c << " / " << d << " == " << b * c / d << "\n";
    seeout << " so " << b * c / d << " + " << a << " == " << a + b * c / d << "\n\n";

    x = (a + b) * c / d;
    seeout << "2nd x: (" << a << " + " << b << ") * " << c << " / " << d << " == " << x << "\n";
    seeout << " because (" << a << " + " << b << ") == " << a + b << "\n";
    seeout << " and " << a + b << " * " << c << " == " << (a + b) * c << "\n";
    seeout << " so " << (a + b) * c << " / " << d << " == " << (a + b) * c / d << "\n\n";

    x = a + (b * c) / d;
    seeout << "3rd x: " << a << " + (" << b << " * " << c << ") / " << d << " == " << x << "\n";
    seeout << " because (" << b << " * " << c << ") == " << b * c << "\n";
    seeout << " and "<< b * c << " / " << d << " == " << b * c / d << "\n";
    seeout << " so " << b * c / d << " + " << a << " == " << a + (b * c) / d << "\n\n";

    x = (a + b * c) / d;
    seeout << "4th x: (" << a << " + " << b << " * " << c << ") / " << d << " == " << x << "\n";
    seeout << " because (" << b << " * " << c << ") == " << b * c << "\n";
    seeout << " and " << a << " + " << b * c << " == " << a + b * c << "\n";
    seeout << " so " << a + b * c << " / " << d << " == " << (a + b * c) / d << "\n";

}


