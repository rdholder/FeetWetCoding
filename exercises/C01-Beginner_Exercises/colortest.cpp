// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.

// FeetWetCoding/exercises/Chapter01/ch01ex10DrawingPuzzles.cpp
// Chapter 01 Exercise 10: Drawing Code Puzzles!

#include <setup.h>
#include <exercises.h>

extern QGraphicsScene *scene;

int colortest()
{
    // Declare the variables we will use.
    int radius, thickness, red=0, green=0, blue=0, dru, drd, dgu, dgd, dbu, dbd, dcolormax=15;
    bool reddown = false, greendown = false, bluedown = false;
//    QColor color;
//    QRect rect(10, 20, 80, 60);

    ClearScreen();

//    QPainter painter(this);
//    painter.setPen(pen);
//    painter.setBrush(brush);
//    painter.drawLine(rect.bottomLeft(), rect.topRight());

  for (int i=0; i < 5; ++i)
  {
    dru = random(dcolormax); drd = random(dcolormax);
    dgu = random(dcolormax); dgd = random(dcolormax);
    dbu = random(dcolormax); dbd = random(dcolormax);

    for ( radius = 1; radius < MAX_X; radius+=5 )
    {
        switch ( random(3)+1 )
        {
        case 1:
            //red +=2;
            if (reddown) red-=random(drd);
            else red+=random(dru);
            if (red>255) { red = 250; reddown = true;}
            if (red < 0) { red = 0; reddown = false;}
            break;
        case 2:
            if (greendown) green-=random(dgd);
            else green+=random(dgu);
            if (green>255) { green = 250; greendown = true;}
            if (green < 0) { green = 0; greendown = false;}
            break;
            break;
        case 3:
            //blue++;
            if (bluedown) blue-=random(dbd);
            else blue+=random(dbu);
            if (blue>255) { blue = 250; bluedown = true;}
            if (blue < 0) { blue = 0; bluedown = false;}
            break;
        default:
            red=200;
            green=200;
            blue=200;
            break;
        }

        thickness = 7;
        DrawCircleRGB( MAX_X/2, MAX_Y/2, radius, thickness, red, green, blue );

    }
    cerr << "next loop: " << i << "\n";
  }

  cerr << "SCENE NOW HAS THIS MANY ITEMS: " << scene->items().length() << std::endl;

//    for ( radius = 10; radius < MAX_X; radius++ )
//    {
//        switch ( random(2)+1 )
//        {
//        case 1:
//            if (!random(2)) red+=random(10)-3;
//            if (red > 255 || red < 0) red = 0;
//            break;
//        case 2:
//            if (!random(2)) green+=random(10)-4;
//            if (green > 255 || green < 0) green =0;
//            break;
//        case 3:
//            if (!random(2)) blue+=random(10)-1;
//            if (blue > 255 || blue < 0) blue =0;
//            break;
//        }
//        DrawCircle( MAX_X/2, MAX_Y/2, radius, 1, red, green, blue );
//    }

    return 0;
}
