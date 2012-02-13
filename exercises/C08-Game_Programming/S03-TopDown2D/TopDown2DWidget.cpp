// FeetWetCoding/exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C08-Game_Programming/S03-TopDown2D/TopDown2DWidget.h>
#include <setup.h>

TopDown2DWidget::TopDown2DWidget(QWidget *parent)
    :GameWidget(parent)
    ,mPlayerPixmap(NULL)
    ,mPlayerX(0)
    ,mPlayerY(0)
{
    Gsoln = getIsSolution();
    initializeGameBoard();
}

void TopDown2DWidget::initializeGameBoard()
{
    drawPlayer();
    drawCoins();

    getView()->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    getView()->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void TopDown2DWidget::drawPlayer()
{
    QPixmap pixmap(":images/spaceship50x59.jpg");
    mPlayerPixmap = new QGraphicsPixmapItem(pixmap);
    getView()->scene()->addItem(mPlayerPixmap);
    mPlayerPixmap->setZValue(1000);
    movePlayer(mPlayerX, mPlayerY);
}

void TopDown2DWidget::drawCoins()
{
    const unsigned short NUM_COINS = 10;
    const unsigned short radius(5);
    unsigned short x, y;

    QGraphicsEllipseItem *newCircle(NULL);
    QColor color(200, 180, 30); //red, green, blue
    QPen pen(color);
    QBrush brush(color, Qt::SolidPattern);

    for ( int i=0; i < NUM_COINS; ++i )
    {
        x = random(WINDOW_WIDTH/2-BORDER);
        y = random(WINDOW_HEIGHT-BORDER);

        newCircle=new QGraphicsEllipseItem(x-(radius/2), y-(radius/2), radius, radius);
        newCircle->setBrush(brush);
        newCircle->setPen(pen);
        getView()->scene()->addItem(newCircle);
    }
}

void TopDown2DWidget::handleKeyPress(QKeyEvent *k)
{
    //Print to our output widgets. Set the global
    //Gsoln to print to the correct widget.
    Gsoln = getIsSolution();
    const unsigned short INCR(8);

    switch ( k->key() )
    {
    case Qt::Key_Up:
        mPlayerY -= INCR;
        break;

    case Qt::Key_Down:
        mPlayerY += INCR;
        break;

    case Qt::Key_Left:
        mPlayerX -= INCR;
        break;

    case Qt::Key_Right:
        mPlayerX += INCR;
        break;

    default:
        QWidget::keyPressEvent(k);
        return;
    }

    if ( mPlayerX < 0 )
        mPlayerX = WINDOW_WIDTH/2;

    else if ( mPlayerX > WINDOW_WIDTH/2 )
        mPlayerX = 0;

    else if ( mPlayerY < 0 )
        mPlayerY = WINDOW_HEIGHT;

    else if ( mPlayerY > WINDOW_HEIGHT )
        mPlayerY = 0;

    movePlayer(mPlayerX, mPlayerY);
}

void TopDown2DWidget::movePlayer( short x, short y )
{
    mPlayerPixmap->setPos(x, y);
}
