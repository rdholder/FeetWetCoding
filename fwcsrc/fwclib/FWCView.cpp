#include <fwclib/FWCView.h>

void FWCView::keyPressEvent( QKeyEvent *k )
{
    //Send signal to QObjects who wouldn't otherwise get it,
    //for example the exercise chooser, which will pass it into
    //the current exercise thread.
    emit keyPressSignal(k);
}

void FWCView::mouseMoveEvent(QMouseEvent *event)
{
    if ( !event )
        return;

    //Send signal to QObjects who wouldn't otherwise get it,
    //for example the exercise chooser, which will use the
    //mouse's current position to determine which exercise
    //pane should receive keyboard input.
    emit newMousePos(event->pos());
}

