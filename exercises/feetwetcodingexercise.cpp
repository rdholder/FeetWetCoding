// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <exercises/FeetWetCodingExercise.h>
#include <ExerciseLauncher.h>

using namespace std;

//static variable definition
int FeetWetCodingExercise::renderedItemsCount(0);

FeetWetCodingExercise::FeetWetCodingExercise(QObject *parent)
    :QThread(parent)
//    ,mDrawingAreaLayout(BLANK)
    ,mSoln(false)
    ,mSolutionPtr(NULL)
{
    mParent = dynamic_cast<ExerciseLauncher *>(parent);
}

FeetWetCodingExercise::~FeetWetCodingExercise()
{
    std::cerr << "FeetWetCodingExercise::~FeetWetCodingExercise()\n";
}

void FeetWetCodingExercise::run()
{
    runExercise();
}

void FeetWetCodingExercise::runExercise()
{
}

void FeetWetCodingExercise::update()
{
    this->runExercise();
}

std::string FeetWetCodingExercise::waitForKeyboardInput()
{
    if ( !mParent ) return std::string("");

    bool received(false);
    QString keystr;

    while ( !received )
    {
        // Check to see if a new key event has come in
        received = mParent->wasNewKeyEventReceived();
        this->msleep(100);
    }

    // Notify Exercise that new key event was consumed
    // Get the key.
    if ( mParent->getKeyEvent() )
    {
        mParent->newKeyEventWasConsumed();
        keystr = mParent->getKeyEvent()->text();
    }
    return keystr.toStdString();
}

int FeetWetCodingExercise::DrawLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int thickness )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = LINE;
    item.x = xStart;
    item.y = yStart;
    item.xEnd = xEnd;
    item.yEnd = yEnd;
    item.color = color;
    item.linewidth = thickness;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawCircle( int x, int y, int r, Color color, int thickness, bool solid)
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = CIRCLE;
    item.x = x;
    item.y = y;
    item.radius = r;
    item.color = color;
    item.linewidth = thickness;
    item.solid = solid;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawCircleRGB( int x, int y, int r, int thickness, int red, int green, int blue, bool solid )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = CIRCLERGB;
    item.x = x;
    item.y = y;
    item.radius = r;
    item.RGBred = red;
    item.RGBgreen = green;
    item.RGBblue = blue;
    item.linewidth = thickness;
    item.solid = solid;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawEllipse( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = ELLIPSE;
    item.x = x;
    item.y = y;
    item.width = w;
    item.height = h;
    item.color = color;
    item.linewidth = thickness;
    item.solid = solid;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawRectangle( int x, int y, int w, int h, Color color, int thickness, bool solid )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = RECTANGLE;
    item.x = x;
    item.y = y;
    item.width = w;
    item.height = h;
    item.color = color;
    item.linewidth = thickness;
    item.solid = solid;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawText( std::string text, int x, int y, Color color, int size)
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = TEXT;
    item.text = text;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawInt( int number, int x, int y, Color color, int size )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = INT;
    item.intvalue = number;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawFloat( float number, int x, int y, Color color, int size, int decimalPlaces )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = FLOAT;
    item.floatvalue = number;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;
    item.decimalplaces = decimalPlaces;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

int FeetWetCodingExercise::DrawImage( std::string filename, int x, int y )
{
    RenderItem item;
    item.ID = renderedItemsCount++;
    item.type = IMAGE;
    item.imagefile = filename;
    item.x = x;
    item.y = y;

    //If successful, return the handle to the QGraphicsItem
    //that will be added to the scene for this item in case
    //we need to operate on it later.
    if ( SendRenderRequest(item) )
    {
        return item.ID;
    }

    return -1;
}

//void FeetWetCodingExercise::DrawReferenceBox( RefBoxLayout layout )
void FeetWetCodingExercise::DrawReferenceBox( RefBoxLayout layout )
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

//    switch (layout) {
//    case LEFTRIGHT:
//        mDrawingAreaLayout.setOrientation(LEFTRIGHT);
//        DrawLine( WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, GRAY, 1);

//        oss.str("");
//        oss << WINDOW_WIDTH/2 << "," << 0;
//        DrawText(oss.str(), (WINDOW_WIDTH/2-BORDER/2), -20, GRAY, dimsSize);

//        oss.str("");
//        oss << WINDOW_WIDTH/2 << "," << WINDOW_HEIGHT;
//        DrawText(oss.str(), WINDOW_WIDTH/2-BORDER/2, WINDOW_HEIGHT, GRAY, dimsSize);

//        oss.str("");
//        oss << "Make this side...";
//        qApp->font().setPointSize(textSize);
//        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
//        DrawText( oss.str(), WINDOW_WIDTH*.25-strWidth/2, -20, GRAY, 10);

//        oss.str("");
//        oss << "...look like this side.";
//        qApp->font().setPointSize(textSize);
//        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
//        DrawText( oss.str(), WINDOW_WIDTH*.75-strWidth/2, -20, GRAY, textSize);
//        break;

//    case TOPBOTTOM:
//        mDrawingAreaLayout.setOrientation(TOPBOTTOM);
//        DrawLine( 0, WINDOW_HEIGHT/2, WINDOW_WIDTH, WINDOW_HEIGHT/2, GRAY, 1);

//        oss.str("");
//        oss << 0 << "," << WINDOW_HEIGHT/2;
//        DrawText(oss.str(), -40, WINDOW_HEIGHT/2-10, GRAY, dimsSize);

//        oss.str("");
//        oss << WINDOW_WIDTH << "," << WINDOW_HEIGHT/2;
//        DrawText(oss.str(), WINDOW_WIDTH, WINDOW_HEIGHT/2-10, GRAY, dimsSize);

//        oss.str("");
//        oss << "Make the top look like the bottom.";
//        qApp->font().setPointSize(textSize);
//        strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
//        DrawText(oss.str(), WINDOW_WIDTH/2-strWidth/2, -20, GRAY, textSize);

//        break;
//    case BLANK:
//        break;
//        // draw nothing inside the box
//    };
}

bool FeetWetCodingExercise::SendRenderRequest( RenderItem item )
{
    if ( !mParent )
    {
        qDebug() << "FeetWetCodingExercise::sendRenderRequest() mParent is NULL!";
        return false;
    }

    {
        QMutexLocker globallocker(&globalmutex);
        if ( Gsoln )
        {
            item.x += WINDOW_WIDTH/2;
        }
    }

//    {
//        QMutexLocker globallocker(&globalmutex);
//        if ( mDrawingAreaLayout.getOrientation() == LEFTRIGHT && Gsoln )
//        {
//            item.x += WINDOW_WIDTH/2;
//        }
//        if ( mDrawingAreaLayout.getOrientation() == TOPBOTTOM && Gsoln)
//        {
//            item.y += WINDOW_HEIGHT/2;
//        }
//    }

    mParent->setRenderItem(item);

    return true;
}

