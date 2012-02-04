// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.


#include <setup.h>
#include <QHBoxLayout>
#include <QDialog>
#include <QFontMetrics>

using namespace std;

QGraphicsView *view(NULL);
QTextEdit *exerciseOut(NULL);
QTextEdit *solnOut(NULL);

solutionOrientation drawingAreaLayout(BLANK);
bool Gsoln = false;

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
    //Seed the random number generator
    QTime time = QTime::currentTime();
    qsrand(time.msec()/4);

    // Setup the drawing area stuff
    QGraphicsScene *scene = new QGraphicsScene(-BORDER, -BORDER/2,
                                               WINDOW_WIDTH+BORDER*2,
                                               WINDOW_HEIGHT+BORDER);
    view = new eoView(scene);
    view->setRenderHint(QPainter::TextAntialiasing);

    QVBoxLayout vlayout;
    QHBoxLayout hlayout;
    exerciseOut = new QTextEdit();
    solnOut = new QTextEdit();
    exerciseOut->setReadOnly(true);
    solnOut->setReadOnly(true);
    hlayout.addWidget(exerciseOut);
    hlayout.addWidget(solnOut);
    vlayout.addWidget(view);
    vlayout.addLayout(&hlayout);

    // Create the run-time window
    QDialog *theWindow =  new QDialog();
    theWindow->setLayout(&vlayout);
    theWindow->setGeometry(WINDOW_X, WINDOW_Y,
                           WINDOW_WIDTH+2.5*BORDER,
                           WINDOW_HEIGHT+2*BORDER+OUTTEXT_HEIGHT);
    theWindow->show();

    SeeOut outboxes;
    Gsoln = false;
    exerciseOut->setTextColor(Qt::blue);
    solnOut->setTextColor(Qt::blue);
    exerciseOut->setFontPointSize(8);
    solnOut->setFontPointSize(8);

    outboxes << "Exercise output\n\n";
    Gsoln = true;
    outboxes << "Solution output\n\n";
    Gsoln = false;

    exerciseOut->setTextColor(Qt::black);
    solnOut->setTextColor(Qt::black);
    exerciseOut->setFontPointSize(10);
    solnOut->setFontPointSize(10);

}

void ClearScreen()
{
    if ( view && view->scene() )
        view->scene()->clear();
}

void DrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        xStart += WINDOW_WIDTH/2;
        xEnd += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        yStart += WINDOW_HEIGHT/2;
        yEnd += WINDOW_HEIGHT/2;
    }

    QGraphicsLineItem *newLine = new QGraphicsLineItem(xStart, yStart, xEnd, yEnd);

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);
    newLine->setPen(pen);
    view->scene()->addItem(newLine);
}

void DrawCircle( int x, int y, int r, Color color, int thickness, bool solid)
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
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
    view->scene()->addItem(newCircle);
}

void DrawCircleRGB( int x, int y, int r, int red, int green, int blue, int thickness, bool solid )
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
    }

    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(x-(r/2), y-(r/2), r, r);

    QColor color;

    // Create a line and add it to the scene
    QPen pen;
    color.setRed(red);
    color.setGreen(green);
    color.setBlue(blue);
    pen.setColor(color);
    pen.setWidth(thickness);

    if ( solid )
    {
        QBrush brush(color, Qt::SolidPattern);
        newCircle->setBrush(brush);
    }

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);
}

void DrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid )
{

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
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
    view->scene()->addItem(newCircle);
}

void DrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
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
    view->scene()->addItem(newRect);
}


void DrawText( std::string text, int x, int y,  Color color, int size )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
    }

    QGraphicsTextItem *newText = new QGraphicsTextItem(text.c_str());

    // Create a line and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(size);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);
}

void DrawInt( int number, int x, int y, Color color, int fontSize )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
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
    view->scene()->addItem(newText);
}

void DrawFloat( float number, int x, int y, Color color, int fontSize, int decimalPlaces )
{
    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
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
    view->scene()->addItem(newText);
}

void DrawImage( QString filename, int x, int y )
{
    QPixmap pixmap( filename );
    QGraphicsPixmapItem *newPixmap = new QGraphicsPixmapItem(pixmap);

    if ( drawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
    {
        x += WINDOW_WIDTH/2;
    }
    if ( drawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln )
    {
        y += WINDOW_HEIGHT/2;
    }

    // Load an image from a file and add it to the scene
    newPixmap->setPos(x, y);
    view->scene()->addItem(newPixmap);
}

void DrawReferenceBox( RefBoxLayout layout )
{
    DrawRectangle( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, GRAY, 1);
    std::ostringstream oss;
    int strWidth(10);
    int dimsSize(8);
    int textSize(10);

    oss << 0 << "," << 0;
    DrawText(oss.str(), -10, -20, GRAY, dimsSize);

//    oss.str("");
//    oss << WINDOW_WIDTH << "," << 0;
//    DrawText(oss.str(), WINDOW_WIDTH-30, -20, GRAY, dimsSize);

    oss.str("");
    oss << 0 << "," << WINDOW_HEIGHT;
    DrawText(oss.str(), -10, WINDOW_HEIGHT, GRAY, dimsSize);

//    oss.str("");
//    oss << WINDOW_WIDTH << "," << WINDOW_HEIGHT;
//    DrawText(oss.str(), WINDOW_WIDTH-30, WINDOW_HEIGHT, GRAY, dimsSize);

    switch (layout) {
    case LEFTRIGHT:
        drawingAreaLayout.setOrientation(LEFTRIGHT);
        DrawLine( WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, GRAY, 1);

        oss.str("");
        oss << WINDOW_WIDTH/2 << "," << 0;
        DrawText(oss.str(), (WINDOW_WIDTH/2-BORDER/2), -20, GRAY, dimsSize);

        oss.str("");
        oss << WINDOW_WIDTH/2 << "," << WINDOW_HEIGHT;
        DrawText(oss.str(), WINDOW_WIDTH/2-BORDER/2, WINDOW_HEIGHT, GRAY, dimsSize);

        oss.str("");
        oss << "Make this side...";
        qApp->font().setPointSize(textSize);
        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
        DrawText( oss.str(), WINDOW_WIDTH*.25-strWidth/2, -20, GRAY, 10);

        oss.str("");
        oss << "...look like this side.";
        qApp->font().setPointSize(textSize);
        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
        DrawText( oss.str(), WINDOW_WIDTH*.75-strWidth/2, -20, GRAY, textSize);
        break;

    case TOPBOTTOM:
        drawingAreaLayout.setOrientation(TOPBOTTOM);
        DrawLine( 0, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT/2, GRAY, 1);

        oss.str("");
        oss << 0 << "," << WINDOW_HEIGHT/2;
        DrawText(oss.str(), -40, WINDOW_HEIGHT/2-10, GRAY, dimsSize);

        oss.str("");
        oss << WINDOW_WIDTH << "," << WINDOW_HEIGHT/2;
        DrawText(oss.str(), WINDOW_WIDTH, WINDOW_HEIGHT/2-10, GRAY, dimsSize);

        oss.str("");
        oss << "Make the top look like the bottom.";
        qApp->font().setPointSize(textSize);
        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
        DrawText(oss.str(), WINDOW_WIDTH/2-strWidth/2, -20, GRAY, textSize);

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
        //colortest();
        break;
    case Qt::Key_Q:
        cerr << "I got a 'q' - Quitting the app...\n";
        QApplication::exit();
        break;
    default:
        //cerr << "I got a rock\n";
        break;
    }
}
