#include <ExerciseLauncher.h>
#include <SeeOut.h>
#include <utility>

std::queue< std::pair< SeeOut::RequestType, QString > > SeeOut::exerciseOutMsgQueue;
std::queue< std::pair< SeeOut::RequestType, QString > > SeeOut::solnOutMsgQueue;
QMutex globalmutex;

extern QTextEdit *exerciseOut;
extern QTextEdit *solnOut;
extern FWCView *view;

ExerciseLauncher::ExerciseLauncher(QObject *parent)
    :QObject(parent)
    ,mThread(NULL)
    ,mWhichPaneHasFocus(0)
    ,mPaneHighlight(NULL)
{
    initSharedDataBuffers();

    //Start time for processing requests from the exercise thread
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
}

ExerciseLauncher::~ExerciseLauncher()
{
    //IMPORTANT!!! Calling code retains ownership of all pointers
    //in this class. Don't delete them!

    qDebug() << "~ExerciseLauncher()";
    stopCurrentExercise();
}

//IMPORTANT!!! Calling code retains ownership of the mSelectedExercise
//pointer. ExerciseLauncher should not delete this passed in pointer!
void ExerciseLauncher::launchExercise( FeetWetCodingExercise *exercise )
{
    qDebug() << "ExerciseLauncher::launchExercise() - assigning exercise to mThread...";
    mThread = exercise;
    if ( mThread )
    {
        qDebug() << "ExerciseLauncher::runExercise() - call mThread.start()";
        mThread->start();
        qDebug() << "ExerciseLauncher::runExercise() - back from calling mThread.start()";
    }
    else
    {
        qDebug() << "ExerciseLauncher::launchExercise() - mThread is NULL after assgnmt!";
    }
}

void ExerciseLauncher::stopCurrentExercise()
{
    qDebug() << "ENTER - ExerciseLauncher::stopCurrentExercise()";
    if ( !mThread )
    {
        qDebug() << "ExerciseLauncher::stopCurrentExercise() - mThread is already NULL";
        qDebug() << "EXIT EARLY - ExerciseLauncher::stopCurrentExercise()";
        return;
    }

    if( mThread->isRunning() )
    {
        qDebug() << "ExerciseLauncher::stopCurrentExercise() - mThread is not NULL and still running";
        qDebug() << "ExerciseLauncher() - call mThread->terminate()";
        mThread->terminate();
        qDebug() << "ExerciseLauncher() - call mThread->wait()";
        mThread->wait();
        qDebug() << "ExerciseLauncher() - back from calling mThread->wait()";
    }
    else
    {
        qDebug() << "ExerciseLauncher::stopCurrentExercise() - mThread is not NULL but no longer running";
    }

    initSharedDataBuffers();

    qDebug() << "EXIT - ExerciseLauncher::stopCurrentExercise()";
}

void ExerciseLauncher::initSharedDataBuffers()
{
    QMutexLocker locker(&eventMutex);

    mItems.clear();
    mRenderItemUpdates.clear();
    mRenderedItems.clear();

    //Setup key event maps
    //TODO: SIZE THESE BASES ON NUM_PANES. ALWAYS 2 PANES FOR NOW.
    mCollectingKeyEvents[0] = false;
    mCollectingKeyEvents[1] = false;
    mNewKeyEventReceived[0] = false;
    mNewKeyEventReceived[1] = false;
}

void ExerciseLauncher::startCollectingKeyBoardInput( int pane )
{
    QMutexLocker locker(&eventMutex);
    if ( mCollectingKeyEvents.end() != mCollectingKeyEvents.find(pane) &&
         mNewKeyEventReceived.end() != mNewKeyEventReceived.find(pane) )
    {
        mCollectingKeyEvents[pane] = true;
        mNewKeyEventReceived[pane] = false;
    }
}

void ExerciseLauncher::stopCollectingKeyBoardInput( int pane )
{
    QMutexLocker locker(&eventMutex);
    if ( mCollectingKeyEvents.end() != mCollectingKeyEvents.find(pane) &&
         mNewKeyEventReceived.end() != mNewKeyEventReceived.find(pane) )
    {
        mCollectingKeyEvents[pane] = false;
        mNewKeyEventReceived[pane] = false;
    }
}

bool ExerciseLauncher::wasNewKeyEventReceived( int pane )
{
    QMutexLocker locker(&eventMutex);
    if ( mCollectingKeyEvents.end() != mCollectingKeyEvents.find(pane) &&
         mNewKeyEventReceived.end() != mNewKeyEventReceived.find(pane) )
    {
        return (mCollectingKeyEvents[pane] && mNewKeyEventReceived[pane]);
    }

    return false;
}

void ExerciseLauncher::newKeyEventWasConsumed( int pane )
{
    QMutexLocker locker(&eventMutex);
    if ( mNewKeyEventReceived.end() != mNewKeyEventReceived.find(pane) )
    {
        mNewKeyEventReceived[pane] = false;
    }
}

void ExerciseLauncher::setKeyEventInfo( QKeySequence key, QString str )
{
    QMutexLocker locker(&eventMutex);
    mKey = key;
    mKeyString = str;
    mNewKeyEventReceived[mWhichPaneHasFocus] = true;
//    qDebug() << "ExerciseLauncher::setKeyEventInfo( " << key << ", " << str;
}

void ExerciseLauncher::getKeyEventInfo( QKeySequence &key, QString &str/*, int pane*/ )
{
    QMutexLocker locker(&eventMutex);
    key = mKey;
    str = mKeyString;
//    pane = mWhichPaneHasFocus;
    qDebug() << "ExerciseLauncher::getKeyEventInfo( " << key << ", " << str;
}

void ExerciseLauncher::setWhichPaneHasFocus( int pane )
{
    QMutexLocker locker(&eventMutex);
    //qDebug() << "ExerciseLauncher::setWhichPaneHasFocus(" << pane << ")";
    mWhichPaneHasFocus = pane;

    //TODO: RESETTING POS ON THIS ISN'T WORKING FOR SOME REASON.
    return;

    if ( mPaneHighlight )
    {
        view->scene()->removeItem(mPaneHighlight);
        delete mPaneHighlight;
        mPaneHighlight = NULL;
    }
    switch ( mWhichPaneHasFocus )
    {
    case 0:
        if ( mPaneHighlight )
        {
            //mPaneHighlight->setPos(0, 0);
        }
        else
        {
            mPaneHighlight = DrawRectangleRender( 0, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, GREEN, 3);
        }
        break;

    case 1:
        if ( mPaneHighlight )
        {
            //mPaneHighlight->setPos( WINDOW_WIDTH/2, 0 );
        }
        else
        {
            mPaneHighlight = DrawRectangleRender( WINDOW_WIDTH/2, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, GREEN, 3);
        }
        break;

    default:
        break;
    }
}

int ExerciseLauncher::getWhichPaneHasFocus()
{
    QMutexLocker locker(&eventMutex);
    return mWhichPaneHasFocus;
}
void ExerciseLauncher::setRenderItem( FeetWetCodingExercise::RenderItem item)
{
    //Store the item in the queue for rendering
    //during the next event processing timeout
    QMutexLocker locker(&itemMutex);
    mItems.push_back(item);
    //qDebug() << "Queue item " << item.ID << " for rendering";
}

void ExerciseLauncher::updateRenderItem(FeetWetCodingExercise::RenderItemUpdate update)
{
    QMutexLocker locker(&itemMutex);
    mRenderItemUpdates.push_back(update);
}

void ExerciseLauncher::handleRenderRequests()
{
    if (mItems.empty())
        return;

    FeetWetCodingExercise::RenderItem item;
    {
        QMutexLocker locker(&itemMutex);
        item = mItems.front();
        mItems.pop_front();
    }

    QGraphicsItem *gItem(NULL);

    switch (item.type) {

    case FeetWetCodingExercise::LINE:
        gItem = DrawLineRender( item.x, item.y, item.xEnd, item.yEnd, item.color, item.linewidth);
        break;
    case FeetWetCodingExercise::CIRCLE:
        gItem = DrawCircleRender( item.x, item.y, item.radius, item.color, item.linewidth, item.solid);
        break;
    case FeetWetCodingExercise::CIRCLERGB:
        gItem = DrawCircleRGBRender( item.x, item.y, item.radius, item.linewidth, item.RGBred, item.RGBgreen, item.RGBblue, item.solid);
        break;
    case FeetWetCodingExercise::ELLIPSE:
        gItem = DrawEllipseRender( item.x, item.y, item.width, item.height, item.color, item.linewidth, item.solid);
        break;
    case FeetWetCodingExercise::RECTANGLE:
        gItem = DrawRectangleRender( item.x, item.y, item.width, item.height, item.color, item.linewidth, item.solid);
        break;
    case FeetWetCodingExercise::TEXT:
        gItem = DrawTextRender( item.text, item.x, item.y, item.color, item.fontsize);
        break;
    case FeetWetCodingExercise::INT:
        gItem = DrawIntRender( item.intvalue, item.x, item.y, item.color, item.fontsize);
        break;
    case FeetWetCodingExercise::FLOAT:
        gItem = DrawFloatRender( item.floatvalue, item.x, item.y, item.color, item.fontsize, item.decimalplaces );
        break;
    case FeetWetCodingExercise::IMAGE:
        gItem = DrawImageRender( item.imagefile, item.x, item.y );
        break;
    }

    //Save the graphics item that was returned in case we need to
    //do something with it later
    {
        QMutexLocker locker(&itemMutex);
        mRenderedItems[item.ID] = gItem;
    }

//    qDebug() << "Rendered item " << item.ID;
}

void ExerciseLauncher::handleRenderUpdates()
{
    if (mRenderItemUpdates.empty())
        return;

    FeetWetCodingExercise::RenderItemUpdate update;
    {
        QMutexLocker locker(&itemMutex);
        update = mRenderItemUpdates.front();
        mRenderItemUpdates.pop_front();
    }

    FeetWetCodingExercise::RenderItemUpdateType type = update.type;
    int itemID = update.ID;

    //Hold the lock from here till the end of the method
    QMutexLocker locker(&itemMutex);

    std::map<int, QGraphicsItem*>::iterator iter = mRenderedItems.find(itemID);

    if ( mRenderedItems.end() == iter )
        return;

    if ( NULL == mRenderedItems[itemID] )
        return;

    QGraphicsItem *item = mRenderedItems[itemID];

    switch (type) {

    case FeetWetCodingExercise::MOVE:
        item->moveBy(update.dx, update.dy);
        break;

    case FeetWetCodingExercise::DELETE:
        view->scene()->removeItem(item);

        //Remove this item from the mRenderedItems map
        if ( mRenderedItems.end() != mRenderedItems.find(itemID) )
        {
            mRenderedItems.erase(mRenderedItems.find(itemID));
            delete item;
            item = NULL;
        }
        break;

    case FeetWetCodingExercise::CHANGE_X_Y:
        item->setPos(update.x, update.y);
        break;

    case FeetWetCodingExercise::CHANGE_XEND_YEND:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_WIDTH_AND_HEIGHT:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_RADIUS:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_COLOR:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_LINE_WIDTH:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_FONT_SIZE:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_INT_VAL:
        //TODO: FINISH CODING THESE
        break;

    case FeetWetCodingExercise::CHANGE_FLOAT_VAL:
        //TODO: FINISH CODING THESE
        break;

    default:
        break;
    }
}

void ExerciseLauncher::handleSeeOutRequests()
{
    //MIGHT NEED TO MAKE THIS A WHILE LOOP AND GO TILL EMPTY (OR MAX PROCESSED PER UPDATE).
    //AND SAME WITH OTHER DATA BEING PASSED AROUND, LIKE KEYEVENTS, DRAWN ITEMS, ETC.
    //LET'S WAIT AND SEE IF IT'S NEEDED, THOUGH.

    if ( !SeeOut::exerciseOutMsgQueue.empty() && exerciseOut )
    {
        std::pair<SeeOut::RequestType, QString> request;

        {
            QMutexLocker globallocker(&globalmutex);
            request = SeeOut::exerciseOutMsgQueue.front();
            SeeOut::exerciseOutMsgQueue.pop();
        }

        SeeOut::RequestType type(request.first);
        QString value(request.second);

        switch (type) {

        case SeeOut::MESSAGE:
            exerciseOut->insertPlainText(value);
            break;

        case SeeOut::COLOR:
            exerciseOut->setTextColor(getQColor((Color)value.toInt()));
            break;

        case SeeOut::FONTSIZE:
            exerciseOut->setFontPointSize(value.toInt());
            break;

        default:
            break;
        }
    }

    if ( !SeeOut::solnOutMsgQueue.empty() && solnOut )
    {
        std::pair<SeeOut::RequestType, QString> request;

        {
            QMutexLocker globallocker(&globalmutex);
            request = SeeOut::solnOutMsgQueue.front();
            SeeOut::solnOutMsgQueue.pop();
        }

        SeeOut::RequestType type(request.first);
        QString value(request.second);

        switch (type) {

        case SeeOut::MESSAGE:
            solnOut->insertPlainText(value);
            break;

        case SeeOut::COLOR:
            solnOut->setTextColor(getQColor((Color)value.toInt()));
            break;

        case SeeOut::FONTSIZE:
            solnOut->setFontPointSize(value.toInt());
            break;

        default:
            break;
        }
    }
}

void ExerciseLauncher::update()
{
    handleRenderRequests();
    handleRenderUpdates();
    handleSeeOutRequests();
}
