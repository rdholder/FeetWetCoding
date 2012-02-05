// copyright (c) 2011 Robert Holder, Janice Dugger.  
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/Misdirection.cpp

// Chapter 01 Exercise 02: Introduction to INTeger variables.

// OPEN FeetWetCoding/helpinfo/html/Misdirection.html
// for more information about this exercise.

#include <exercises/C01_S04.h>

void MisdirectionSoln::runExercise()
{
    int verticalstep=0;
    int a=0, x=2, y=50;

    // This exercise was a bit of a dirty trick:  the variable "int a" never really
    // gets used to *do* anything! :-D  If it took you some time to figure this out
    // that may be from being distracted by a += x; and not noticing that y, x were
    // transposed.  Yes, I did that on purpose.  Sorry!

    // But you have to be able to catch this kind of thing, in your own code, and
    // when looking at other people's code.  Just because a program compiles doesn't
    // mean that it actually *does what it claims to do*!  You may feel like I pulled
    // a fast one on you (and I kind of did) but you just learned a valuable lesson.
    // As your programs get longer, you will start to find errors very similar to
    // the kind of "confusion" that this exercise represented.

    verticalstep=y;
    a=x;
    DrawText("First sentence.", x, y, BLACK, 15);
    y = y + verticalstep;
    DrawText("Second sentence.", x, y, BLACK, 15);
    y += verticalstep;
    DrawText("Third sentence.", x, y, BLACK, 15);
    y += verticalstep;
    a += x;
    DrawText("Fourth sentence.", x, y, RED, 15);
    y += verticalstep;
    DrawText("Fifth sentence.", x, y, BLACK, 15);
}
