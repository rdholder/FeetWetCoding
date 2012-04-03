// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <setup.h>
#include <exercises/FeetWetCodingExerciseBase.h>
#include <ExerciseLauncher.h>

using namespace std;

extern QMutex globalmutex;

FeetWetCodingExerciseBase::FeetWetCodingExerciseBase(QObject *parent)
    :QThread(parent)
    ,mSoln(false)
    ,mPane(0)
    ,mSolutionPtr(NULL)
{
#ifdef DEBUG
    qDebug() << "DEBUG: FeetWetCodingExerciseBase::FeetWetCodingExerciseBase() - (GUI) ThreadID: " << qApp->thread()->currentThread();
#endif

    mParent = dynamic_cast<ExerciseLauncher *>(parent);
}

FeetWetCodingExerciseBase::~FeetWetCodingExerciseBase()
{
}

void FeetWetCodingExerciseBase::run()
{
#ifdef DEBUG
    qDebug() << "DEBUG: FeetWetCodingExerciseBase::run() - (Exercise/Soln) ThreadID: " << qApp->thread()->currentThread();
#endif

    int ctime = QTime::currentTime().msec();
    qsrand(ctime);

    runExercise();
}

void FeetWetCodingExerciseBase::runExercise()
{
}

std::string FeetWetCodingExerciseBase::waitForKeyPress()
{
    if ( !mParent ) return std::string();

    bool received(false);

    mParent->startCollectingKeyBoardInput(mPane);
    while ( !received )
    {
        // Check to see if a new key event has come in
        received = mParent->wasNewKeyEventReceived(mPane);
        this->msleep(10);
    }

    QKeySequence key;
    QString keystr;
    mParent->getKeyEventInfo(key, keystr, mPane, true);
    mParent->newKeyEventWasConsumed(mPane);
    mParent->stopCollectingKeyBoardInput(mPane);

    return keystr.toStdString();
}

std::string FeetWetCodingExerciseBase::getKeyboardString()
{
    if ( !mParent ) return std::string("");

    bool done(false);
    QString keystr, fullstring;
    QKeySequence key;
    int id(-1);

    mParent->startCollectingKeyBoardInput(mPane);
    while ( !done )
    {
        // Check to see if a new key event has come in
        if ( mParent->wasNewKeyEventReceived(mPane) )
        {
            // Get the key and notify Exercise
            // that new key event was consumed
            mParent->getKeyEventInfo(key, keystr, mPane);
            mParent->newKeyEventWasConsumed(mPane);

            if ( Qt::Key_Enter == key || Qt::Key_Return == key )
            {
                done = true;
                continue;
            }
            else
            {
#ifdef DEBUG

                qDebug() << "DEBUG: keyEvent is NOT EMPTY - APPENDING " << keystr << " to string " << fullstring;
#endif
                fullstring.append(keystr);
            }

            if ( id < 0 )
            {
                id = fwcText("Input: " + fullstring.toStdString(), 10, 380, GRAY, 12);
            }
            else
            {
                fwcChangeText(id, "Input: " + fullstring.toStdString());
            }
        }
        this->msleep(10);
    }

    if ( id >= 0 )
    {
        fwcEraseItem(id);
    }

    mParent->stopCollectingKeyBoardInput(mPane);

    return fullstring.toStdString();
}

int FeetWetCodingExerciseBase::fwcLine( int xStart, int yStart, int xEnd, int yEnd, Color color, int linewidth )
{
    RenderItem item;
    item.type = LINE;
    item.x = xStart;
    item.y = yStart;
    item.xEnd = xEnd;
    item.yEnd = yEnd;
    item.color = color;
    item.linewidth = linewidth;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcCircle( int x, int y, int r, Color color, int linewidth, bool solid )
{
    RenderItem item;
    item.type = CIRCLE;
    item.x = x;
    item.y = y;
    item.radius = r;
    item.color = color;
    item.linewidth = linewidth;
    item.solid = solid;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcCircleRGB( int x, int y, int r, int linewidth, int red, int green, int blue, bool solid )
{
    RenderItem item;
    item.type = CIRCLERGB;
    item.x = x;
    item.y = y;
    item.radius = r;
    item.RGBred = red;
    item.RGBgreen = green;
    item.RGBblue = blue;
    item.linewidth = linewidth;
    item.solid = solid;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcEllipse( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    RenderItem item;
    item.type = ELLIPSE;
    item.x = x;
    item.y = y;
    item.width = w;
    item.height = h;
    item.color = color;
    item.linewidth = linewidth;
    item.solid = solid;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcRectangle( int x, int y, int w, int h, Color color, int linewidth, bool solid )
{
    RenderItem item;
    item.type = RECTANGLE;
    item.x = x;
    item.y = y;
    item.width = w;
    item.height = h;
    item.color = color;
    item.linewidth = linewidth;
    item.solid = solid;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcText( std::string text, int x, int y, Color color, int size )
{
    RenderItem item;
    item.type = TEXT;
    item.text = text;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcInt( int number, int x, int y, Color color, int size )
{
    RenderItem item;
    item.type = INT;
    item.intvalue = number;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcFloat( float number, int x, int y, Color color, int size, int decimalPlaces )
{
    RenderItem item;
    item.type = FLOAT;
    item.floatvalue = number;
    item.x = x;
    item.y = y;
    item.color = color;
    item.fontsize = size;
    item.decimalplaces = decimalPlaces;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

int FeetWetCodingExerciseBase::fwcImage( std::string filename, int x, int y )
{
    RenderItem item;
    item.type = IMAGE;
    item.imagefile = filename;
    item.x = x;
    item.y = y;

    //Return the handle to the QGraphicsItem
    //that will be drawn for this item in case
    //we need to update it later. Save it to
    //the mDrawnItems vector as well, so we
    //can clear all items at once if we want.
    int id = SendRenderRequest(item);
    mDrawnItems.push_back(id);
    return id;
}

void FeetWetCodingExerciseBase::DrawReferenceBox(Color color)
{
    std::ostringstream oss;
    int strWidth(10);
    int dimsSize(8);
    int textSize(10);

    //Save the ref box drawn items so that we can preserve them
    //when all the other drawn items get cleared.
    mRefBoxItems.clear();
    mRefBoxItems.push_back(fwcRectangle( 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, color, 1));

    oss << 0 << "," << 0;
    mRefBoxItems.push_back(fwcText(oss.str(), -10, -20, color, dimsSize));

    oss.str("");
    oss << 0 << "," << WINDOW_HEIGHT;
    mRefBoxItems.push_back(fwcText(oss.str(), -10, WINDOW_HEIGHT, color, dimsSize));

    mRefBoxItems.push_back(fwcLine( WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, color, 1));

    oss.str("");
    oss << WINDOW_WIDTH/2 << "," << 0;
    mRefBoxItems.push_back(fwcText(oss.str(), (WINDOW_WIDTH/2-BORDER/2), -20, color, dimsSize));

    oss.str("");
    oss << WINDOW_WIDTH/2 << "," << WINDOW_HEIGHT;
    mRefBoxItems.push_back(fwcText(oss.str(), WINDOW_WIDTH/2-BORDER/2, WINDOW_HEIGHT, color, dimsSize));

    oss.str("");
    oss << "Make YOUR Code...";
    qApp->font().setPointSize(textSize);
    strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
    mRefBoxItems.push_back(fwcText( oss.str(), WINDOW_WIDTH*.25-strWidth/2, -20, color, 10));

    oss.str("");
    oss << "...do what the SOLUTION code does.";
    qApp->font().setPointSize(textSize);
    strWidth=QFontMetrics(QFont(qApp->font())).width(oss.str().c_str());
    mRefBoxItems.push_back(fwcText( oss.str(), WINDOW_WIDTH*.75-strWidth/2, -20, color, textSize));

    //Draw reference box on top of everything else
    for ( unsigned int i=0; i < mRefBoxItems.size(); ++i )
    {
        fwcChangeZ(mRefBoxItems[i], 1000);
    }
}

int FeetWetCodingExerciseBase::SendRenderRequest( RenderItem item )
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::sendRenderRequest() mParent is NULL!";
        return -1;
    }

    {
        QMutexLocker globallocker(&globalmutex);
        if ( mSoln )
        {
            item.x += WINDOW_WIDTH/2;
            item.xEnd += WINDOW_WIDTH/2;
        }
    }

    return mParent->setRenderItem(item);
}

void FeetWetCodingExerciseBase::fwcMoveItem(int itemID, int newX, int newY)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcMoveItem() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = MOVE;
    update.ID = itemID;
    update.x = newX;
    update.y = newY;

    {
        QMutexLocker globallocker(&globalmutex);
        if ( mSoln )
        {
            update.x += WINDOW_WIDTH/2;
        }
    }

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcShiftItem(int itemID, int xShift, int yShift)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcShiftItem() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = SHIFT;
    update.ID = itemID;
    update.dx = xShift;
    update.dy = yShift;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcEraseItem(int itemID)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcEraseItem() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = ERASE;
    update.ID = itemID;

    mParent->updateRenderItem(update);

    //Remove this item from our local list as well
    std::vector<int>::iterator iter(std::find(mDrawnItems.begin(), mDrawnItems.end(), itemID));
    if ( mDrawnItems.end() != iter )
    {
        mDrawnItems.erase(iter);
    }
}

void FeetWetCodingExerciseBase::fwcChangeZ(int itemID, int z)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeZ() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_Z;
    update.ID = itemID;
    update.z = z;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcScaleItem(int itemID, float scalefactor)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::Scale() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = SCALE;
    update.ID = itemID;
    update.scalefactor = scalefactor;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcRotateItem(int itemID, float angledegrees)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::Rotate() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = ROTATE;
    update.ID = itemID;
    update.angledegrees = angledegrees;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeLineEnd(int itemID, int xEnd, int yEnd)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeLineEnd() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_XEND_YEND;
    update.ID = itemID;
    update.xEnd = xEnd;
    update.yEnd = yEnd;

    {
        QMutexLocker globallocker(&globalmutex);
        if ( mSoln )
        {
            update.xEnd += WINDOW_WIDTH/2;
        }
    }

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeWidthAndHeight(int itemID, int w, int h)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeWidthAndHeight() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_WIDTH_AND_HEIGHT;
    update.ID = itemID;
    update.width = w;
    update.height = h;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeRadius(int itemID, int radius)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeRadius() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_RADIUS;
    update.ID = itemID;
    update.radius = radius;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeColor(int itemID, Color color, bool solid)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeColor() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_COLOR;
    update.ID = itemID;
    update.color = color;
    update.solid = solid;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeLineWidth(int itemID, int width)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeLineWidth() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_LINE_WIDTH;
    update.ID = itemID;
    update.linewidth = width;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeFontSize(int itemID, int size)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeFontSize() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_FONT_SIZE;
    update.ID = itemID;
    update.fontsize = size;

    mParent->updateRenderItem(update);
}


void FeetWetCodingExerciseBase::fwcChangeText(int itemID, std::string text)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeText() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_TEXT_VAL;
    update.ID = itemID;
    update.textval = text;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeInt(int itemID, int intval)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeInt() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_INT_VAL;
    update.ID = itemID;
    update.intval = intval;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcChangeFloat(int itemID, int floatval)
{
    if ( !mParent )
    {
        qDebug() << "ERROR: FeetWetCodingExerciseBase::fwcChangeFloat() mParent is NULL!";
        return;
    }

    RenderItemUpdate update;
    update.type = CHANGE_FLOAT_VAL;
    update.ID = itemID;
    update.floatval = floatval;

    mParent->updateRenderItem(update);
}

void FeetWetCodingExerciseBase::fwcClearItems()
{
    std::vector<int>itemsToErase;
    std::vector<int>::iterator iter;

    for( iter = mDrawnItems.begin(); iter != mDrawnItems.end(); ++iter)
    {
        //Don't erase the ref box drawn elements
        if ( mRefBoxItems.end() == std::find(mRefBoxItems.begin(), mRefBoxItems.end(), *iter) )
        {
            //We can't erase from the main list here since we're iterating
            //over the main list and erasing from it will mess up our iterator.
            //Save the items to erase, then erase from the main list as we
            //iterate over the saved items.
            itemsToErase.push_back(*iter);
        }
    }

    //Now erase the items from the main list
    for ( iter = itemsToErase.begin(); iter != itemsToErase.end(); ++iter )
    {
        fwcEraseItem(*iter);
    }
}

bool FeetWetCodingExerciseBase::solutionIsFinished()
{
    QMutexLocker solnlocker(&solutionmutex);

    if ( NULL == mSolutionPtr )
        return true;

    return mSolutionPtr->isFinished();
}
