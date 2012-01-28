// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/include/constants.h
// Constants definitions for use by all the source files in FeetWetCoding.

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Here we decide the size and location of our window on the screen.  This is how we tell the
// computer how big to make our window, and where to put it on the screen when our program runs.
const int WINDOW_X(50);                 // Window upper left corner X location
const int WINDOW_Y(50);                 // Window upper left corner Y location
const int WINDOW_WIDTH(800);            // The width of the window in pixels.
const int WINDOW_HEIGHT(600);           // The height of the window in pixels.
const int MIN_X(0);                     // The upper left corner of our drawing area, x location.
const int MIN_Y(0);                     // The upper left corner of our drawing area, y location.
const int MAX_X(MIN_X+WINDOW_WIDTH);    // The lower right corner of our drawing area, x location.
const int MAX_Y(MIN_Y+WINDOW_HEIGHT);   // The lower right corner of our drawing area, y location.

const int KEEPGOINGSIGNAL(1);
const int ENDPROGRAMSIGNAL(2);

typedef enum {
    BLANK,
    LEFTRIGHT,
    TOPBOTTOM
} RefBoxLayout;

typedef enum {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PINK,
    DARKYELLOW,
    GRAY
} Color;

#endif // CONSTANTS_H
