// copyright (c) 2011 Robert Holder, Janice Dugger.
// See HELP.html included in this distribution.

#include <fwclib/setup.h>
#include <fwclib/feetwetcodinglib.h>
#include <fwclib/FWCView.h>
#include <fwclib/FWCSettings.h>
#include <fwclib/FWCExerciseChooser.h>
#include <QTextEdit>
#include <QDir>
#include <stdexcept>

using namespace std;

//Global variables we need
extern FWCView *view;
extern FWCExerciseChooser *exerciseChooser;
extern QTextEdit *exerciseOut;
extern QTextEdit *solnOut;


////////////////////////////////////////////
// FWC convenience functions for the user
////////////////////////////////////////////

QColor getQColor( Color color )
{
    switch (color) {
    case COLOR0:
        return Qt::gray;
    case COLOR1:
        return QColor(Qt::color1);
    case BLACK:
        return QColor(Qt::black);
    case WHITE:
        return QColor(Qt::white);
    case DARKGRAY:
        return QColor(Qt::darkGray);
    case GRAY:
        return QColor(Qt::gray);
    case LIGHTGRAY:
        return QColor(Qt::lightGray);
    case RED:
        return QColor(Qt::red);
    case GREEN:
        return QColor(Qt::green);
    case BLUE:
        return QColor(Qt::blue);
    case CYAN:
        return QColor(Qt::cyan);
    case MAGENTA:
        return QColor(Qt::magenta);
    case YELLOW:
        return QColor(Qt::yellow);
    case DARKRED:
        return QColor(Qt::darkRed);
    case DARKGREEN:
        return QColor(Qt::darkGreen);
    case DARKBLUE:
        return QColor(Qt::darkBlue);
    case DARKCYAN:
        return QColor(Qt::darkCyan);
    case DARKMAGENTA:
        return QColor(Qt::darkMagenta);
    case DARKYELLOW:
        return QColor(Qt::darkYellow);
    case TRANSPARENT:
        return QColor(Qt::transparent);
    case PINK:
        return QColor(255, 0, 255);             // decimal rgb
    case LAVENDER:
        return QColor("#aa88ff");               // hex rgb
    default:
        return Qt::black;
    };
}

std::string getNameForColor( Color color )
{
    switch (color) {
    case COLOR0:
        return "COLOR0";
    case COLOR1:
        return "COLOR1";
    case BLACK:
        return "BLACK";
    case WHITE:
        return "WHITE";
    case DARKGRAY:
        return "DARKGRAY";
    case GRAY:
        return "GRAY";
    case LIGHTGRAY:
        return "LIGHTGRAY";
    case RED:
        return "RED";
    case GREEN:
        return "GREEN";
    case BLUE:
        return "BLUE";
    case CYAN:
        return "CYAN";
    case MAGENTA:
        return "MAGENTA";
    case YELLOW:
        return "YELLOW";
    case DARKRED:
        return "DARKRED";
    case DARKGREEN:
        return "DARKGREEN";
    case DARKBLUE:
        return "DARKBLUE";
    case DARKCYAN:
        return "DARKCYAN";
    case DARKMAGENTA:
        return "DARKMAGENTA";
    case DARKYELLOW:
        return "DARKYELLOW";
    case TRANSPARENT:
        return "TRANSPARENT";
    case PINK:
        return "PINK";
    case LAVENDER:
        return "LAVENDER";
    default:
        return "ERROR";
    };
}

// random:  returns a random int between 0 and "biggest" inclusive
// for example random(100) returns an int between 0 and 100
int random(int biggest)
{
    if (biggest > 0)
    {
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
// if they need 0 through x they should use random(x);
// if they need -x through 0, they should use random(x) * -1;
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


/////////////////////////////////
//FWC drawing utils
/////////////////////////////////

void ClearScreen()
{
    if ( view && view->scene() )
    {
        view->scene()->clear();
    }
    if ( exerciseChooser )
    {
        exerciseChooser->sceneCleared();
    }
}

void ClearOutputArea()
{
    if ( NULL == exerciseOut || NULL == solnOut )
        return;

    exerciseOut->clear();
    solnOut->clear();

    SeeOut outboxes;
    outboxes.setIsSolution(false);
    outboxes.setColor(BLUE);
    outboxes.setFontSize(8);
    outboxes << "Exercise output\n\n";

    outboxes.setIsSolution(true);
    outboxes.setColor(BLUE);
    outboxes.setFontSize(8);
    outboxes << "Solution output\n\n";
}

QGraphicsItem* fwcLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth )
{
    QGraphicsLineItem *newLine = new QGraphicsLineItem(xStart, yStart, xEnd, yEnd);

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);
    newLine->setPen(pen);
    view->scene()->addItem(newLine);

    return newLine;
}

QGraphicsItem* fwcCircleRender( int x, int y, int r, Color color, int linewidth, bool solid)
{
    //Usage: QGraphicsEllipseItem(x, y, width, height). Positions its top left corner at x, y.
    //Therefore, to make a circle with radius r and position its center at x,y, we need to
    //shift x,y by -radius and multiply r by 2 before passing them on to the QGraphicsEllipseItem
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, r*2, r*2);
    newCircle->setPos(x-r, y-r);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create an ellipse and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcCircleRGBRender( int x, int y, int r, int red, int green, int blue, int linewidth, bool solid )
{
    //Usage: QGraphicsEllipseItem(x, y, width, height). Positions its top left corner at x, y.
    //Therefore, to make a circle with radius r and position its center at x,y, we need to
    //shift x,y by -radius and multiply r by 2 before passing them on to the QGraphicsEllipseItem
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, r*2, r*2);
    newCircle->setPos(x-r, y-r);

    QColor color;

    // Create a line and add it to the scene
    QPen pen;
    color.setRed(red);
    color.setGreen(green);
    color.setBlue(blue);
    pen.setColor(color);
    pen.setWidth(linewidth);

    if ( solid )
    {
        QBrush brush(color, Qt::SolidPattern);
        newCircle->setBrush(brush);
    }

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcEllipseRender( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    //Shift position so that origin goes from top left corner to center of ellipse
    QGraphicsEllipseItem *newCircle = new QGraphicsEllipseItem(0, 0, w, h);
    newCircle->setPos(x-(w/2), y-(h/2));

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newCircle->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);

    //painter.setRenderHint(QPainter::Antialiasing);
    newCircle->setPen(pen);
    view->scene()->addItem(newCircle);

    return newCircle;
}

QGraphicsItem* fwcRectangleRender( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    QGraphicsRectItem *newRect = new QGraphicsRectItem(0, 0, w, h);
    newRect->setPos(x, y);

    if ( solid )
    {
        QBrush brush(Qt::SolidPattern);
        brush.setColor(getQColor(color));
        newRect->setBrush(brush);
    }

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(linewidth);
    newRect->setPen(pen);
    view->scene()->addItem(newRect);

    return newRect;
}


QGraphicsItem* fwcTextRender( std::string text, int x, int y,  Color color, int size )
{
    QGraphicsTextItem *newText = new QGraphicsTextItem(text.c_str());

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(size);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcIntRender( int number, int x, int y, Color color, int fontSize )
{
    QString str;
    str.setNum(number);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcFloatRender( float number, int x, int y, Color color, int fontSize, int decimalPlaces )
{
    QString str;
    str.setNum(number, 'f', decimalPlaces);

    QGraphicsTextItem *newText = new QGraphicsTextItem(str);

    // Configure the text and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(fontSize);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* fwcImageRender( std::string filename, int x, int y )
{
    QString imageFilePath;
    try
    {
        FWCSettings settings;
        imageFilePath = settings.getImgDirPath() + QDir::separator() + QString(filename.c_str());
    }
    catch ( std::runtime_error ex )
    {
        qDebug() << ex.what();
        return NULL;
    }

    if ( false == QFile::exists(imageFilePath) )
    {
        SeeOut seeout;
        seeout << "ERROR: Can't find image file " << imageFilePath.toStdString() << "\n";
        return NULL;
    }

    QPixmap pixmap;
    if ( false == pixmap.load(imageFilePath) )
    {
        SeeOut seeout;
        seeout << "ERROR: Unable to create pixmap from image file " << imageFilePath.toStdString() << "\n";
        return NULL;
    }

    QGraphicsPixmapItem *newPixmap = new QGraphicsPixmapItem(pixmap);

    // Load an image from a file and add it to the scene
    newPixmap->setPos(x, y);
    view->scene()->addItem(newPixmap);

    return newPixmap;
}
