// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S04.h>

#include <math.h>

void MathFunctions::runExercise()     // copy the exercise name & paste it into main.cpp
{
    // There are more math functions than are listed here, but this should be enough
    // to get you started.

    // Notice we have to include math.h above in order to use these math functions.
    // It appears that these functions can take long int, double and float types,
    // but check the web pages below for specifics on what type of parameter to pass
    // and what type to expect each function to return.

    // REFER TO:
    // "The C Programming Language" Kernighan & Ritchie, Appendix B4, page 250.
    // http://en.cppreference.com/w/cpp/numeric/math
    // http://www.cplusplus.com/reference/clibrary/cmath/
    // http://www.codecogs.com/code/computing/c/math.h/index.php

    double result = 0, x = 0, y = 3.49;

    fwcText("Reference Exercise:", 50, 150, BLUE, 20);
    fwcText("no solution needed.", 50, 180, BLUE, 20);

    x = -20;
//    result = abs(x);
    seeout << "Absolute value of " << x << " == " << result << "\n";

    x = 500;
    result = sqrt(x);
    seeout << "Square root of " << x << " == " << result << "\n";

    x = 0.2;
    result = sin(x);
    seeout << "Sine of " << x << " == " << result << "\n";

    result = cos(x);
    seeout << "Cosine of " << x << " == " << result << "\n";

    result = tan(x);
    seeout << "Tangent of " << x << " == " << result << "\n";

    x = 3.5;
    result = ceil(y);
    seeout << "Ceiling of " << y << " == " << result << "\n";
    result = ceil(x);
    seeout << "Ceiling of " << x << " == " << result << "\n";

    result = floor(y);
    seeout << "Floor of " << y << " == " << result << "\n";
    result = floor(x);
    seeout << "Floor of " << x << " == " << result << "\n";

    result = trunc(y);
    seeout << "Truncate " << y << " == " << result << "\n";
    result = trunc(x);
    seeout << "Truncate " << x << " == " << result << "\n";

    result = round(y);
    seeout << "Round " << y << " == " << result << "\n";
    result = round(x);
    seeout << "Round " << x << " == " << result << "\n";

}
