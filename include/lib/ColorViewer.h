// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef COLORVIEWER_H
#define COLORVIEWER_H

#include <ExerciseLauncher.h>

class ColorViewer
{
public:
    ColorViewer(ExerciseLauncher *renderServer=NULL):mRenderServer(renderServer){}
    void show();

private:

    int DrawCircle( int x, int y, int r, Color color, int thickness, bool solid=false);
    int DrawText( std::string text, int x, int y, Color color, int size=12);

    ExerciseLauncher *mRenderServer;
};

#endif // COLORVIEWER_H
