// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2D.h>
#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.h>

extern FWCView *view;

TopDown2D::TopDown2D(QObject *parent)
    :FeetWetCodingExercise(parent)
    ,mTd2dWidget(NULL)
{
    Gsoln = false;
    this->runExercise();
    this->setupSolution();
    view->setFocus();
}

TopDown2D::~TopDown2D()
{
    if ( mTd2dWidget )
    {
        mTd2dWidget->hide();
        delete mTd2dWidget;
        mTd2dWidget = NULL;
    }
    if ( mSolutionPtr )
    {
        delete mSolutionPtr;
        mSolutionPtr = NULL;
    }
}

void TopDown2D::runExercise()
{
    mTd2dWidget = new TopDown2DWidget(view);
    mTd2dWidget->setIsSolution(false);

    mTd2dWidget->setAutoFillBackground(true);
    mTd2dWidget->setBackgroundRole(QPalette::Window);
    mTd2dWidget->setGeometry(BORDER+2, BORDER/2+2, WINDOW_WIDTH/2-2, WINDOW_HEIGHT-2);

    mTd2dWidget->show();

    seeout << "Use arrow keys to move ship.\n";
    seeout << "MOVE SHIP MOVE SHIP MOVE SHIP MOVE SHIP\n";
    seeout << "YOU KNOW WHAT YOU DOING TAKE OFF EVERY ZIG\n";
}


