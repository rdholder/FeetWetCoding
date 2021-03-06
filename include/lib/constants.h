// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Here we decide the size and location of our window on the screen.  This is how we tell the
// computer how big to make our window, and where to put it on the screen when our program runs.
const int WINDOW_X(10);                 // Window upper left corner X location
const int WINDOW_Y(30);                 // Window upper left corner Y location
const int BORDER(50);                   // Border width between window and drawing area
const int OUTTEXT_HEIGHT(180);          // Additional height to allow for output text at bottom.
const int WINDOW_WIDTH(800);            // The width of the window in pixels.
const int WINDOW_HEIGHT(400);           // The height of the window in pixels.
const int MIN_X(0);                     // The upper left corner of our drawing area, x location.
const int MIN_Y(0);                     // The upper left corner of our drawing area, y location.
const int MAX_X(MIN_X+WINDOW_WIDTH);    // The lower right corner of our drawing area, x location.
const int MAX_Y(MIN_Y+WINDOW_HEIGHT);   // The lower right corner of our drawing area, y location.

const int KEEPGOINGSIGNAL(1);
const int ENDPROGRAMSIGNAL(2);

#endif // CONSTANTS_H
