// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QFontMetrics>
#include <QFile>
#include <QMutex>
#include <feetwetcodinglib.h>
#include <include/lib/FWCExerciseChooser.h>

using namespace std;

FWCView *view(NULL);
QDialog *theWindow(NULL);
QTextEdit *exerciseOut(NULL);
QTextEdit *solnOut(NULL);

solutionOrientation::solutionOrientation(RefBoxLayout initialOrientation)
{
    itsOrientation = initialOrientation;
}

solutionOrientation::~solutionOrientation()
{
}

solutionOrientation::RefBoxLayout solutionOrientation::getOrientation()
{
    return itsOrientation;
}

void solutionOrientation::setOrientation(RefBoxLayout orientation)
{
    itsOrientation = orientation;
}

void appSetup()
{
    initSettingsFile();
    setupDrawingUtils();
}

void initSettingsFile()
{
    QFile srcFile("../FeetWetCoding/defaultconfig.txt");
    QFile destFile("config.txt");
    if ( !destFile.exists() )
    {
        srcFile.copy("config.txt");
    }
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
    view = new FWCView(scene);
    view->setRenderHint(QPainter::TextAntialiasing);

    exerciseOut = new QTextEdit();
    exerciseOut->ensureCursorVisible();
    exerciseOut->setReadOnly(true);
    exerciseOut->setFocusPolicy(Qt::NoFocus);

    solnOut = new QTextEdit();
    solnOut->ensureCursorVisible();
    solnOut->setReadOnly(true);
    solnOut->setFocusPolicy(Qt::NoFocus);

    FWCExerciseChooser *exerciseChooser = new FWCExerciseChooser();

    QHBoxLayout *hlayout1 = new QHBoxLayout();
    QPushButton *restartExercise = new QPushButton( QObject::tr( "Re-start Exercise") );
    restartExercise->setFocusPolicy(Qt::NoFocus);
    QObject::connect(restartExercise, SIGNAL(clicked()),
                     exerciseChooser, SLOT(runCurrentExercise()));
    QObject::connect(view, SIGNAL(keyPressSignal(QKeyEvent*)),
                     exerciseChooser, SLOT(handleKeyEvent(QKeyEvent*)));
    view->setMouseTracking(true);
    QObject::connect(view, SIGNAL(newMousePos(QPoint)),
                     exerciseChooser, SLOT(handleNewMousePosEvent(QPoint)));

    hlayout1->addStretch();
    hlayout1->addLayout(exerciseChooser->getChooserLayout());
    QFrame *f = new QFrame();
    f->setFrameStyle( QFrame::VLine | QFrame::Sunken );
    hlayout1->addWidget( f, 0 );
    hlayout1->addWidget(restartExercise);

    QHBoxLayout *hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(exerciseOut);
    hlayout2->addWidget(solnOut);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addLayout(hlayout1);
    vlayout->addWidget(view);
    vlayout->addLayout(hlayout2);

    // Create the run-time window
    theWindow = new QDialog();
    theWindow->setLayout(vlayout);
    theWindow->setGeometry(WINDOW_X, WINDOW_Y,
                           WINDOW_WIDTH+2.5*BORDER,
                           WINDOW_HEIGHT+2.5*BORDER+OUTTEXT_HEIGHT);
    theWindow->show();

    // Done creating drawing area, so ok to run.
    // Choose the first Exercise in the list
    exerciseChooser->setOkToRun(true);
    exerciseChooser->runCurrentExercise();

    //Finally, give focus to the drawing area
    view->setFocus();
}

void initOutputArea()
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

void ClearScreen()
{
    if ( view && view->scene() )
    {
        view->scene()->clear();
    }
}

QGraphicsItem* DrawLineRender( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness )
{
    QGraphicsLineItem *newLine = new QGraphicsLineItem(xStart, yStart, xEnd, yEnd);

    // Create a line and add it to the scene
    QPen pen;
    pen.setColor(getQColor(color));
    pen.setWidth(thickness);
    newLine->setPen(pen);
    view->scene()->addItem(newLine);

    return newLine;
}

QGraphicsItem* DrawCircleRender( int x, int y, int r, Color color, int thickness, bool solid)
{
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

    return newCircle;
}

QGraphicsItem* DrawCircleRGBRender( int x, int y, int r, int red, int green, int blue, int thickness, bool solid )
{
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

    return newCircle;
}

QGraphicsItem* DrawEllipseRender( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
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

    return newCircle;
}

QGraphicsItem* DrawRectangleRender( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
    QGraphicsRectItem *newRect = new QGraphicsRectItem(x, y, w, h);

//    qDebug() << "newRect: " << x << "," << y <<"," << w << "," << h;
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

    return newRect;
}


QGraphicsItem* DrawTextRender( std::string text, int x, int y,  Color color, int size )
{
    QGraphicsTextItem *newText = new QGraphicsTextItem(text.c_str());

    // Create a line and add it to the scene
    QFont font(qApp->font());
    font.setPointSize(size);
    newText->setFont(font);
    newText->setPos(x, y);
    newText->setDefaultTextColor(getQColor(color));
    view->scene()->addItem(newText);

    return newText;
}

QGraphicsItem* DrawIntRender( int number, int x, int y, Color color, int fontSize )
{
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

    return newText;
}

QGraphicsItem* DrawFloatRender( float number, int x, int y, Color color, int fontSize, int decimalPlaces )
{
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

    return newText;
}

QGraphicsItem* DrawImageRender( std::string filename, int x, int y )
{
    QPixmap pixmap( filename.c_str() );
    QGraphicsPixmapItem *newPixmap = new QGraphicsPixmapItem(pixmap);

    // Load an image from a file and add it to the scene
    newPixmap->setPos(x, y);
    view->scene()->addItem(newPixmap);

    return newPixmap;
}

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
//    qDebug() << "emit newMousePos("<<event->pos()<<")";
    emit newMousePos(event->pos());
}
