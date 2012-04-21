// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#ifndef COLORVIEWER_H
#define COLORVIEWER_H

#include <fwclib/ExerciseLauncher.h>

class ColorViewer
{
public:
    ColorViewer(ExerciseLauncher *renderServer=NULL):mRenderServer(renderServer){}
    void show();

private:

    int fwcCircle( int x, int y, int r, Color color, int linewidth, bool solid=false);
    int fwcText( std::string text, int x, int y, Color color, int size=12);

    ExerciseLauncher *mRenderServer;
};

#endif // COLORVIEWER_H
