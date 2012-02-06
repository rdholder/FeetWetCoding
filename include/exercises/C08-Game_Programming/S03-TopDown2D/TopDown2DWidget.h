#ifndef TETRISWIDGET_H
#define TETRISWIDGET_H

#include <exercises/C08-Game_Programming/GameWidget.h>

class TopDown2DWidget : public GameWidget
{
public:
    TopDown2DWidget(QWidget *parent = 0);
    ~TopDown2DWidget(){}

protected:
    void initializeGameBoard();
    void handleKeyPress(QKeyEvent *k);

private:
    void drawPlayer();
    void drawCoins();
    void movePlayer( short x, short y );

    QGraphicsPixmapItem *mPlayerPixmap;
    short mPlayerX;
    short mPlayerY;
};

#endif // TETRISWIDGET_H
