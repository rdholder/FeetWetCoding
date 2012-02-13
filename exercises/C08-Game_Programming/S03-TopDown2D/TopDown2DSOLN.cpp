// FeetWetCoding/exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DSOLN.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2D.h>
#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.h>

extern FWCView *view;

TopDown2DSoln::TopDown2DSoln(QObject *parent)
    :FeetWetCodingExercise(parent)
    ,mTd2dWidget(NULL)
{
    Gsoln = true;
    this->runExercise();
}

TopDown2DSoln::~TopDown2DSoln()
{
    if ( mTd2dWidget )
    {
        mTd2dWidget->hide();
        delete mTd2dWidget;
        mTd2dWidget = NULL;
    }
}

void TopDown2DSoln::runExercise()
{
    int solnOffset(WINDOW_WIDTH/2);

    mTd2dWidget = new TopDown2DWidget(view);
    mTd2dWidget->setIsSolution(true);

    mTd2dWidget->setAutoFillBackground(true);
    mTd2dWidget->setBackgroundRole(QPalette::Window);
    mTd2dWidget->setGeometry(BORDER+2+solnOffset, BORDER/2+2, WINDOW_WIDTH/2-2, WINDOW_HEIGHT-2);

    mTd2dWidget->show();
}

