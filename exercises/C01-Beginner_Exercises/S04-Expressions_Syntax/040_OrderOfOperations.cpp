// copyright (c) 2011 eotsucodefoundry.com.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/SeeOut.cpp

// Chapter 01 Exercise 00: Using SeeOut to print output.

// OPEN FeetWetCoding/helpinfo/html/ch00ex00TITLE.html
// for more information about this exercise.

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

    // ...so basically, when in doubt, force things to resolve the way you want by grouping
    // terms in parentheses according to which ones you want resolved first in an equation
    // you are writing code for. It seemed very mysterious to me at first, but after you
    // play around with it a bit, it starts to feel more natural.  :-)

    int x = 0, y = 0, a = 7, b = 11, c = 128, d = 3;

    DrawText("Reference Exercise:", 50, 150, BLUE, 20);
    DrawText("no solution needed.", 50, 180, BLUE, 20);

    x = a + b * c / d;
    seeout << "1st x: " << a << " + " << b << " * " << c << " / " << d << " == " << x << "\n";
    seeout << "because " << b << " * " << c << " == " << b * c;
    seeout << " and " << b * c << " / " << d << " == " << b * c / d << " so ";
    seeout << b * c / d << " + " << a << " == " << a + b * c / d << "\n\n";

    x = (a + b) * c / d;
    seeout << "2nd x: (" << a << " + " << b << ") * " << c << " / " << d << " == " << x << "\n";
    seeout << "because (" << a << " + " << b << ") == " << a + b;
    seeout << " and " << a + b << " * " << c << " == " << (a + b) * c;
    seeout << " so " << (a + b) * c << " / " << d << " == " << (a + b) * c / d << "\n\n";

    x = (a + b) * (c / d);
    seeout << "3rd x: (" << a << " + " << b << ") * (" << c << " / " << d << ") == " << x << "\n";
    seeout << "because (" << a << " + " << b << ") == " << a + b;
    seeout << " and "<< c << " / " << d << " == " << c / d << " so " << a + b << " * " << c / d;
    seeout << " == " << x << "\n\n";

    x = (a + b * c) / d;
    seeout << "4th x: (" << a << " + " << b << " * " << c << ") / " << d << " == " << x << "\n";
    seeout << "becuase (" << a << " + " << b << " * " << c << ") == " << a + b * c;
    seeout << "so " << a + b * c << " / " << d << " == " << x << "\n";

}


