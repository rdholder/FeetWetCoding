#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <underconstruction/gamewidget.h>

class TetrisWidget : public GameWidget
{
public:
    TetrisWidget(QWidget *parent = 0) : GameWidget(parent){}
    ~TetrisWidget(){}
};

#endif // TETRISWIDGET_H
