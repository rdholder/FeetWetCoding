// copyright (c) 2011 Robert Holder, Janice Dugger.
// See LICENSE.txt included with this software distribution for conditions of use.


#include <setup.h>
#include <QHBoxLayout>
#include <QComboBox>
#include <QDialog>
#include <QFontMetrics>
#include <exercises/exercises.h>

using namespace std;

FWCView *view(NULL);
QTextEdit *exerciseOut(NULL);
QTextEdit *solnOut(NULL);
FWCExerciseSelector *exerciseSelector(NULL);
QComboBox *chapterSelection(NULL);
QComboBox *sectionSelection(NULL);
QComboBox *exerciseSelection(NULL);
QHBoxLayout *hlayout(NULL);

solutionOrientation drawingAreaLayout(BLANK);
bool Gsoln = false;


FeetWetCodingExercise * exerciseFactory( std::string const& name )
{
    //Chapter 1

    //Section 2 - Getting_Started
    std::cerr << "HERE ...\n";
    if( "Welcome" == name ){ return new Welcome(); }
    if( "ChangeText" == name ){ return new ChangeText(); }
    if( "ChangeX" == name ){ return new ChangeX(); }
    if( "ChangeY" == name ){ return new ChangeY(); }
    if( "ChangeXY" == name ){ return new ChangeXY(); }
    if( "ChangeColor" == name ){ return new ChangeColor(); }
    if( "ChangeFont" == name ){ return new ChangeFont(); }
    if( "DrawLines" == name ){ return new DrawLines(); }
    if( "DrawCircles" == name ){ return new DrawCircles(); }
    if( "DrawRectangles" == name ){ return new DrawRectangles(); }
    if( "DrawDots" == name ){ return new DrawDots(); }
    if( "DrawEllipses" == name ){ return new DrawEllipses(); }
    if( "DrawingText" == name ){ return new DrawingText(); }
    if( "DrawingImages" == name ){ return new DrawingImages(); }
    if( "seeoutIntro" == name ){ return new seeoutIntro(); }
    if( "seeoutFormatting" == name ){ return new seeoutFormatting(); }
    if( "OnYourOwn" == name ){ return new OnYourOwn(); }

    //Section 3 - Types_Variables
    if( "Integers" == name ){ return new Integers(); }
    if( "DrawingVersusSeeout" == name ){ return new DrawingVersusSeeout(); }
    if( "Floats" == name ){ return new Floats(); }
    if( "CONSTANTS" == name ){ return new CONSTANTS(); }
    if( "Chars" == name ){ return new Chars(); }
    if( "StandardStrings" == name ){ return new StandardStrings(); }
//    if( "ChoosingVariableNames" == name ){ return new ChoosingVariableNames(); }

    //Section 4 - Expessions_Syntax
    if( "AssignmentArithmetic" == name ){ return new AssignmentArithmetic(); }
//    if( "OrderOfOperations" == name ){ return new OrderOfOperations(); }
    if( "PreAndPostIncAndDec" == name ){ return new PreAndPostIncAndDec(); }
//    if( "DivisionGotchas" == name ){ return new DivisionGotchas(); }
//    if( "ModulusOperator" == name ){ return new ModulusOperator(); }
//    if( "Booleans" == name ){ return new Booleans(); }
//    if( "BlocksAndScope" == name ){ return new BlocksAndScope(); }
//    if( "MathFunctions" == name ){ return new MathFunctions(); }
//    if( "random-randomRange" == name ){ return new random-randomRange(); }
    if( "Misdirection" == name ){ return new Misdirection(); }

    //Section 5 - Loops_Logic
    if( "WhileLoop1" == name ){ return new WhileLoop1(); }
    if( "InfiniteLooping1" == name ){ return new InfiniteLooping1(); }
    if( "C01S05_OYO1" == name ){ return new C01S05_OYO1(); }
    if( "C01S05_OYO2" == name ){ return new C01S05_OYO2(); }
    if( "WhileLoop2" == name ){ return new WhileLoop2(); }
    if( "WhileLoop3" == name ){ return new WhileLoop3(); }
    if( "C01S05_OYO3" == name ){ return new C01S05_OYO3(); }
    if( "C01S05_OYO4" == name ){ return new C01S05_OYO4(); }
    if( "WhileLoop4" == name ){ return new WhileLoop4(); }
    if( "WhileLoop5" == name ){ return new WhileLoop5(); }
    if( "IfThen1" == name ){ return new IfThen1(); }
    if( "IfThen2" == name ){ return new IfThen2(); }
    if( "C01S05_OYO5" == name ){ return new C01S05_OYO5(); }

    //Chapter 8 - Game_Programming

    //Section 3 - TopDown2D
    if( "TopDown2D" == name ){ return new TopDown2D(); }

    return NULL;
}

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
    exerciseSelector = new FWCExerciseSelector();

    // Need to instantiate exerciseSelector
    // before calling setupDrawingUtils
    setupDrawingUtils();
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

    //This will get filled out with the
    //exercise selection widgets as needed
    hlayout = new QHBoxLayout();

    QHBoxLayout *hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(exerciseOut);
    hlayout2->addWidget(solnOut);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addLayout(hlayout);
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

    // Choose the first Exercise in the list
    if ( NULL != exerciseSelector )
    {
        exerciseSelector->selectChapter("");
    }
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

FWCExerciseSelector::FWCExerciseSelector(QObject *parent)
    :QObject(parent)
    ,mSelectedExercise(NULL)
    ,mCurrentChapter("")
    ,mCurrentSection("")
    ,mCurrentExercise("")
{
    createExercisesMap();
}

FWCExerciseSelector::~FWCExerciseSelector()
{
}

void FWCExerciseSelector::createExercisesMap()
{
    mExerciseMap.clear();

    std::map<QString, std::vector<QString> > sections;
    std::vector<QString> exercises;

    //C01-Beginner_Exercises
    sections.clear();

    //S02-Getting_Started
    exercises.clear();
    exercises.push_back( "Welcome" );
    exercises.push_back( "ChangeText" );
    exercises.push_back( "ChangeX" );
    exercises.push_back( "ChangeY" );
    exercises.push_back( "ChangeXY" );
    exercises.push_back( "ChangeColor" );
    exercises.push_back( "ChangeFont" );
    exercises.push_back( "DrawLines" );
    exercises.push_back( "DrawCircles" );
    exercises.push_back( "DrawRectangles" );
    exercises.push_back( "DrawDots" );
    exercises.push_back( "DrawEllipses" );
    exercises.push_back( "DrawingText" );
    exercises.push_back( "DrawingImages" );
    exercises.push_back( "seeoutIntro" );
    exercises.push_back( "seeoutFormatting" );
    exercises.push_back( "OnYourOwn" );
    sections["S02-Getting_Started"] = exercises;

    //S03-Types_Variables
    exercises.clear();
    exercises.push_back( "Integers" );
    exercises.push_back( "DrawingVersusSeeout" );
    exercises.push_back( "Floats" );
    exercises.push_back( "CONSTANTS" );
    exercises.push_back( "Chars" );
    exercises.push_back( "StandardStrings" );
    exercises.push_back( "ChoosingVariableNames" );
    sections["S03-Types_Variables"] = exercises;

    //S04-Expressions_Syntax
    exercises.clear();
    exercises.push_back( "AssignmentArithmetic" );
    exercises.push_back( "OrderOfOperations" );
    exercises.push_back( "PreAndPostIncAndDec" );
    exercises.push_back( "DivisionGotchas" );
    exercises.push_back( "ModulusOperator" );
    exercises.push_back( "Booleans" );
    exercises.push_back( "BlocksAndScope" );
    exercises.push_back( "MathFunctions" );
    exercises.push_back( "random-randomRange" );
    exercises.push_back( "Misdirection" );
    sections["S04-Expressions_Syntax"] = exercises;

    //S05-Loops_Logic
    exercises.clear();
    exercises.push_back( "WhileLoop1" );
    exercises.push_back( "InfiniteLooping1" );
    exercises.push_back( "C01S05_OYO1" );
    exercises.push_back( "C01S05_OYO2" );
    exercises.push_back( "WhileLoop2" );
    exercises.push_back( "WhileLoop3" );
    exercises.push_back( "C01S05_OYO3" );
    exercises.push_back( "C01S05_OYO4" );
    exercises.push_back( "WhileLoop4" );
    exercises.push_back( "WhileLoop5" );
    exercises.push_back( "IfThen1" );
    exercises.push_back( "IfThen2" );
    exercises.push_back( "C01S05_OYO5" );
    sections["S05-Loops_Logic"] = exercises;

    mExerciseMap["C01-Beginner_Exercises"] = sections;


    //C08-Game_Programming
    sections.clear();

    //S03-TopDown2D
    exercises.clear();
    exercises.push_back( "TopDown2D" );
    sections["S03-TopDown2D"] = exercises;

    mExerciseMap["C08-Game_Programming"] = sections;
}

void FWCExerciseSelector::selectChapter( const QString & selection )
{
    // Make sure the selector has been created
    if ( NULL != chapterSelection )
    {
        hlayout->removeWidget(chapterSelection);
        delete chapterSelection;
        chapterSelection = NULL;
    }

    chapterSelection = new QComboBox();
    chapterSelection->setMaxVisibleItems(50);
    QObject::connect(chapterSelection, SIGNAL(activated(QString)),
                     this, SLOT(chapterSelected(QString)));
    for (mChptIter = mExerciseMap.begin(); mChptIter != mExerciseMap.end();
         ++mChptIter)
    {
        chapterSelection->addItem(mChptIter->first);
    }

    hlayout->addStretch();
    hlayout->addWidget(chapterSelection);

    // Find the selection and set it in the list
    if ( mExerciseMap.empty() )
        return;

    if ( selection.isEmpty() )
    {
        mCurrentChapter = mExerciseMap.begin()->first;
        chapterSelection->setCurrentIndex(0);
    }

    else if ( mExerciseMap.find(selection) != mExerciseMap.end() )
    {
        mCurrentChapter = selection;
        chapterSelection->setCurrentIndex(chapterSelection->findText(mCurrentChapter));
    }

    // Update the Section list based on the chapter selection
    if ( NULL != sectionSelection )
    {
        hlayout->removeWidget(sectionSelection);
        delete sectionSelection;
        sectionSelection = NULL;
    }

    sectionSelection = new QComboBox();
    sectionSelection->setMaxVisibleItems(50);
    QObject::connect(sectionSelection, SIGNAL(activated(QString)),
                     this, SLOT(sectionSelected(QString)));

    for ( mSectIter = mExerciseMap[mCurrentChapter].begin();
          mSectIter != mExerciseMap[mCurrentChapter].end();
          ++mSectIter )
    {
        sectionSelection->addItem(mSectIter->first);
    }

    hlayout->addWidget(sectionSelection);

    // Choose the first Section in the list
    selectSection("");
}

void FWCExerciseSelector::selectSection( const QString & selection )
{
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].empty() )
        return;

    if ( selection.isEmpty() )
    {
        mCurrentSection = mExerciseMap[mCurrentChapter].begin()->first;
        sectionSelection->setCurrentIndex(0);
    }

    else if ( mExerciseMap[mCurrentChapter].find(selection) !=
                mExerciseMap[mCurrentChapter].end() )
    {
        mCurrentSection = selection;
        sectionSelection->setCurrentIndex(sectionSelection->findText(mCurrentSection));
    }

    // Update the Section list based on the chapter selection
    if ( NULL != exerciseSelection )
    {
        hlayout->removeWidget(exerciseSelection);
        delete exerciseSelection;
        exerciseSelection = NULL;
    }

    exerciseSelection = new QComboBox();
    exerciseSelection->setMaxVisibleItems(50);
    QObject::connect(exerciseSelection, SIGNAL(activated(QString)),
                     this, SLOT(exerciseSelected(QString)));

    for ( mExIter = mExerciseMap[mCurrentChapter][mCurrentSection].begin();
          mExIter != mExerciseMap[mCurrentChapter][mCurrentSection].end();
          ++mExIter )
    {
        exerciseSelection->addItem(*mExIter);
    }

    hlayout->addWidget(exerciseSelection);

    // Choose the first Exercise in the list
    selectExercise("");
}

void FWCExerciseSelector::selectExercise( const QString & selection )
{
    if ( mExerciseMap.find(mCurrentChapter) == mExerciseMap.end() ||
         mExerciseMap[mCurrentChapter].find(mCurrentSection) ==
         mExerciseMap[mCurrentChapter].end() ||
         mExerciseMap[mCurrentChapter][mCurrentSection].empty() )
    {
        return;
    }

    QString selectedExercise("");

    if ( selection.isEmpty() )
    {
        selectedExercise = mExerciseMap[mCurrentChapter][mCurrentSection].at(0);
        exerciseSelection->setCurrentIndex(0);
    }

    else
    {
        for ( unsigned int i=0; i < mExerciseMap[mCurrentChapter][mCurrentSection].size(); ++i )
        {
            if ( selection == mExerciseMap[mCurrentChapter][mCurrentSection][i] )  // found it
            {
                selectedExercise = selection;
                exerciseSelection->setCurrentIndex(i);
                break;
            }
        }
    }

    // Did we find it?
    if ( selectedExercise.isEmpty() )
        return; // nope, so don't do anything

    // Stop the old exercise
    stopExercise();

    // Start the new one
    mCurrentExercise = selectedExercise;
    runExercise(mCurrentExercise);
}

void FWCExerciseSelector::chapterSelected( const QString & selection )
{
    std::cerr << "chapterSelected(): " << selection.toStdString() << "\n";
    selectChapter(selection);
}

void FWCExerciseSelector::sectionSelected( const QString & selection )
{
    std::cerr << "sectionSelected(): " << selection.toStdString() << "\n";
    selectSection(selection);
}

void FWCExerciseSelector::exerciseSelected( const QString & selection )
{
    std::cerr << "exerciseSelected(): " << selection.toStdString() << "\n";
    selectExercise(selection);
}

void FWCExerciseSelector::stopExercise()
{
    std::cerr << "FWCExerciseSelector::stopExercise()\n";
    if ( mSelectedExercise )
    {
        std::cerr << "Deleting current exercise...\n";
        delete mSelectedExercise;
        mSelectedExercise = NULL;
    }
}

void FWCExerciseSelector::runExercise( const QString & exerciseName )
{
    std::cerr << "FWCExerciseSelector::runExercise( " << exerciseName.toStdString() << " )\n";
    mSelectedExercise = exerciseFactory(exerciseName.toStdString());
}
