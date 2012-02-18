// FeetWetCoding/source/feetwetcodinglib.cpp
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QFontMetrics>
#include <QFile>
#include <feetwetcodinglib.h>
#include <include/lib/FWCExerciseChooser.h>

using namespace std;

FWCView *view(NULL);
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
    QDialog *theWindow =  new QDialog();
    theWindow->setLayout(vlayout);
    theWindow->setGeometry(WINDOW_X, WINDOW_Y,
                           WINDOW_WIDTH+2.5*BORDER,
                           WINDOW_HEIGHT+2.5*BORDER+OUTTEXT_HEIGHT);
    theWindow->show();

    initOutputArea();

    // Done creating drawing area, so ok to run.
    // Choose the first Exercise in the list
    exerciseChooser->setOkToRun(true);

    std::cerr << "Done setting up drawing area. Tell chooser to run its selected exercise...\n";
    exerciseChooser->runCurrentExercise();
}

void initOutputArea()
{
    if ( NULL == exerciseOut || NULL == solnOut )
        return;

    exerciseOut->clear();
    solnOut->clear();

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
    {
        view->scene()->clear();
    }
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

    oss.str("");
    oss << 0 << "," << WINDOW_HEIGHT;
    DrawText(oss.str(), -10, WINDOW_HEIGHT, GRAY, dimsSize);

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

QColor getQColor( Color color )
{
    QColor c;
    switch (color) {
    case COLOR0:
        return QColor(Qt::gray);
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
    switch ( k->key() )
    {
    case Qt::Key_Q:
        cerr << "Quitting the app...\n";
        QApplication::exit();
        break;
    default:
        break;
    }

    //Since there are two game widgets (exercise and solution), let
    //the main view get the keyboard input and send it to the two
    //widgets through a signal
    emit keyPressSignal(k);
}
