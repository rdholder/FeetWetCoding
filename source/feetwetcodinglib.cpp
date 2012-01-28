// copyright (c) 2011 eotsucodefoundry.com.  All rights reserved.
// See LICENSE.txt included with this software distribution for conditions of use.


#include <setup.h>

extern QGraphicsScene *scene;
extern QGraphicsView *view;
extern FeetWetCodingExercise *exercise;
extern QPainter *appPainter;
//extern MainWindow *mainWindow;
extern QTimer appLoopTimer;
extern solutionOrientation drawingAreaLayout;
extern bool Gsoln;

solutionOrientation::solutionOrientation(RefBoxLayout initialOrientation)
{
    itsOrientation = initialOrientation;
}

solutionOrientation::~solutionOrientation()
{
}

RefBoxLayout solutionOrientation::getOrientation()
{
    return itsOrientation;
}

void solutionOrientation::setOrientation(RefBoxLayout orientation)
{
    itsOrientation = orientation;
}

void setupDrawingUtils()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec()/4);

///////////// DISREGARD THIS STUFF FOR NOW--IT WAS ME TRYING TO FIGURE OUT QPAINTER ///////////////
//    if ( 0 )
//    {
//        mainWindow = new MainWindow();
//        mainWindow->setGeometry(WINDOW_X, WINDOW_Y, WINDOW_WIDTH+WINDOW_X, WINDOW_HEIGHT+WINDOW_Y);

//        if ( 0 )
//        {
//            scene = new QGraphicsScene(MIN_X, MIN_Y, MAX_X, MAX_Y);
//            view = new eoView(scene);
//            view->setRenderHint(QPainter::TextAntialiasing);
//            view->setGeometry(WINDOW_X, WINDOW_Y, WINDOW_WIDTH+WINDOW_X, WINDOW_HEIGHT+WINDOW_Y);
//            mainWindow->setCentralWidget(view);
//        }

//        appPainter = new QPainter();
//        appPainter->begin(mainWindow);
//        mainWindow->show();
//    }
//    else
////////////////////////////////////////////////////////////////////////////////////////////////
    {
        // Set up our Window (Don't worry about this stuff for now! :-)
        scene = new QGraphicsScene(MIN_X, MIN_Y, MAX_X, MAX_Y);
        view = new eoView(scene);

        view->setRenderHint(QPainter::TextAntialiasing);
        view->setGeometry(WINDOW_X, WINDOW_Y, WINDOW_WIDTH+WINDOW_X, WINDOW_HEIGHT+WINDOW_Y);

        view->show();       //Show window


    }
}

void ClearScreen()
{
    if ( scene )
        scene->clear();
}

void DrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        xStart += 400;
        xEnd += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        yStart += 300;
        yEnd += 300;
    }

    QGraphicsLineItem *newLine = new QGraphicsLineItem(xStart, yStart, xEnd, yEnd);

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);
    newLine->setPen(pen);
    scene->addItem(newLine);
    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawCircle( int x, int y, int r, Color color, int thickness, bool solid)
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(x-(r/2), y-(r/2), r, r);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create an ellipse and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    scene->addItem(newCircle);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawCircleRGB( int x, int y, int r, int red, int green, int blue, int thickness, bool solid )
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(x-(r/2), y-(r/2), r, r);

    QColor color;
//    QRgb splat = 4280457642;

    // Create a line and add it to the scene
    QPen pen;
    //pen.setColor(getQColor(color));
    color.setRed(red);
    color.setGreen(green);
    color.setBlue(blue);
    pen.setColor(color);
    //pen.setColor(splat);
    pen.setWidth(thickness);

    if ( solid )
    {
        QBrush brush(color, Qt::SolidPattern);
        newCircle->setBrush(brush);
    }

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    scene->addItem(newCircle);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid )
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(x-(w/2), y-(h/2), w, h);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    scene->addItem(newCircle);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QGraphicsRectItem *newRect = new QGraphicsRectItem(x, y, w, h);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newRect->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);
    newRect->setPen(pen);
    scene->addItem(newRect);

    scene->update();   //Render stuff
    view->show();       //Show everything
}


void DrawText( std::string text, int x, int y,  Color color, int size )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QGraphicsTextItem *newText = new QGraphicsTextItem(text.c_str());

    // Create a line and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(size);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    scene->addItem(newText);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawInt( int number, int x, int y, Color color, int fontSize )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QString str;
    str.setNum(number);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Create a line and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    scene->addItem(newText);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawFloat( float number, int x, int y, Color color, int fontSize, int decimalPlaces )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += 400;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += 300;
    }

    QString str;
    str.setNum(number, 'f', decimalPlaces);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Create a line and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    scene->addItem(newText);

    scene->update();   //Render stuff
    view->show();       //Show everything

}

void DrawImage( int x, int y, QString filename )
{
    QPixmap pixmap( filename );
    QGraphicsPixmapItem *newPixmap = new QGraphicsPixmapItem(pixmap);

    // Load an image from a file and add it to the scene
    newPixmap->setPos(x, y);
    scene->addItem(newPixmap);

    scene->update();   //Render stuff
    view->show();       //Show everything
}

void DrawReferenceBox( RefBoxLayout layout )
{
    DrawRectangle( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GRAY, 1);
    DrawText("0,0", -10, -20, GRAY, 10);
    DrawText("800,0", WINDOW_WIDTH-30, -20, GRAY, 10);
    DrawText("0,600", -10, WINDOW_HEIGHT, GRAY, 10);
    DrawText("800,600", WINDOW_WIDTH-30, WINDOW_HEIGHT, GRAY, 10);

    switch (layout) {
    case LEFTRIGHT:
        drawingAreaLayout.setOrientation(LEFTRIGHT);
        DrawLine( 400, 0, 400, 600, GRAY, 1);
        DrawText("400,0", 375, -20, GRAY, 10);
        DrawText("400,600", 375, WINDOW_HEIGHT, GRAY, 10);
        DrawText( "Make this side...", 150, -20, GRAY, 10);
        DrawText( "...look like this side.", 550, -20, GRAY, 10);
        break;
    case TOPBOTTOM:
        drawingAreaLayout.setOrientation(TOPBOTTOM);
        DrawLine( 0, 300, 800, 300, GRAY, 1);
        DrawText("0, 300", -40, 300, GRAY, 10);
        DrawText("800,300", 805,300, GRAY, 1);
        DrawText("Make the top look like the bottom.", 300, -20, GRAY, 10);
        break;
    case BLANK:
    break;
        // draw nothing inside the box
    };
}

//void PuzzleSetup(RefBoxLayout orientation, bool soln)
//{
//    Gsoln = soln;
//    DrawReferenceBox(orientation);     // draw the graphical reference frame
//}

Qt::GlobalColor getQColor( Color color )
{
    switch (color) {
        case BLACK:
            return Qt::black;
        case RED:
            return Qt::red;
        case GREEN:
            return Qt::green;
        case YELLOW:
            return Qt::yellow;
        case BLUE:
            return Qt::blue;
        case PINK:
            return Qt::magenta;
        case DARKYELLOW:
            return Qt::darkYellow;
        case GRAY:
            return Qt::gray;
    };
    return Qt::black;
}


// random:  returns a random int between 0 and "biggest" inclusive
// for example random(100) returns an int between 0 and 100
int random(int biggest)
{
    if (biggest > 0)
    {
        //Seed the random number generator
        //qsrand(QTime::currentTime().msec());

        //Calculate a random number within the specified range
        return (qrand() % biggest + 1) -1;
    }
    else
    {
        return 0;
    }
}

// randomRange: return a number between smallest and biggest
// you can supply positive or negative ints, just make sure smallest < biggest
// for example calling it with 10,20 will give you a random int betwen 10 and 20
// supplying -30,20 will give a random int between -30 and 20
int randomRange(int smallest, int biggest)
{
    if ( smallest < biggest && smallest != 0 && biggest != 0 )
    {
        return (qrand() % (biggest - (smallest + 1))) + smallest;
    }
    else
    {
        return 0;
    }
}

void eoView::keyPressEvent( QKeyEvent *k )
{
    switch ( k->key() )
    {
    case Qt::Key_Up:
        cerr << "UP\n";
        break;
    case Qt::Key_Down:
        cerr << "DOWN\n";
        break;
    case Qt::Key_Left:
        cerr << "LEFT\n";
        break;
    case Qt::Key_Right:
        cerr << "RIGHT\n";
        break;
    case Qt::Key_C:
        ClearScreen();
        break;
    case Qt::Key_R:
        colortest();
        break;
    case Qt::Key_Q:
        cerr << "I got a 'q' - Quitting the app...\n";
        QApplication::exit();
        break;
    default:
        cerr << "I got a rock\n";
        break;
    }
}

//void eoView::paintEvent(QPaintEvent *event)
//{
//    cerr << "eoView::paintEvent()\n";
//    QPen pen(Qt::black, 2, Qt::SolidLine);

//    QPainter painter(this);

//    painter.setPen(pen);
//    painter.drawLine(20, 40, 250, 40);

//    pen.setStyle(Qt::DashLine);
//    painter.setPen(pen);
//    painter.drawLine(20, 80, 250, 80);

//    pen.setStyle(Qt::DashDotLine);
//    painter.setPen(pen);
//    painter.drawLine(20, 120, 250, 120);

//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);
//    painter.drawLine(20, 160, 250, 160);

//    pen.setStyle(Qt::DashDotDotLine);
//    painter.setPen(pen);
//    painter.drawLine(20, 200, 250, 200);


//    QVector<qreal> dashes;
//    qreal space = 4;

//    dashes << 1 << space << 5 << space;

//    pen.setStyle(Qt::CustomDashLine);
//    pen.setDashPattern(dashes);
//    painter.setPen(pen);
//    painter.drawLine(20, 240, 250, 240);
//}
