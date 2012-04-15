#include <ExerciseLauncher.h>
#include <SeeOut.h>
#include <QDialog>
#include <QTextEdit>
#include <QTime>
#include <QTransform>
#include <utility>
#include <float.h>
#include <math.h>

std::deque< std::pair< SeeOut::RequestType, QString > > SeeOut::exerciseOutMsgQueue;
std::deque< std::pair< SeeOut::RequestType, QString > > SeeOut::solnOutMsgQueue;
QMutex globalmutex;

extern QTextEdit *exerciseOut;
extern QTextEdit *solnOut;
extern FWCView *view;
extern QDialog *theWindow;

//static variable definition
int ExerciseLauncher::renderedItemsCount(0);

ExerciseLauncher::ExerciseLauncher(QObject *parent)
    :QObject(parent)
    ,mTimer(NULL)
    ,mThread(NULL)
    ,mNumPanes(2)
    ,mWhichPaneHasFocus(0)
    ,mPaneHighlight(NULL)
{
    initSharedDataBuffers();

    //Connect timer for processing requests from the exercise thread
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(update()));
}

ExerciseLauncher::~ExerciseLauncher()
{
    //IMPORTANT!!! Calling code retains ownership of all pointers
    //in this class. Don't delete them!

    stopCurrentExercise();
}

//IMPORTANT!!! Calling code retains ownership of the FeetWetCodingExercise
//pointer passed in here. ExerciseLauncher should not delete this pointer!
//The pointer is assigned to mThread, so don't delete mThread.
void ExerciseLauncher::launchExercise( FeetWetCodingExercise *exercise )
{
    if ( NULL == exercise )
    {
        qDebug() << "ERROR: ExerciseLauncher::launchExercise() - exercise is NULL!";
        return;
    }

#ifdef DEBUG
    qDebug() << "DEBUG: ExerciseLauncher::launchExercise() - assigning exercise to mThread...";
#endif
    mThread = exercise;

    if ( mThread )
    {
        mTimer->start();
        mThread->start();
    }
    else
    {
        qDebug() << "ERROR: ExerciseLauncher::launchExercise() - mThread is NULL after assgnmt!";
    }
}

void ExerciseLauncher::stopCurrentExercise()
{
    if ( !mThread )
    {
        return;
    }

    if( mThread->isRunning() )
    {
#ifdef DEBUG
        qDebug() << "DEBUG: ExerciseLauncher::stopCurrentExercise() - mThread is not NULL and still running";
        qDebug() << "DEBUG: ExerciseLauncher() - call mThread->terminate(); mThread->wait()";
#endif
        mThread->terminate();
        mThread->wait();
    }
    else
    {
#ifdef DEBUG
        qDebug() << "DEBUG: ExerciseLauncher::stopCurrentExercise() - mThread is not NULL but no longer running";
#endif
    }

    initSharedDataBuffers();
}

void ExerciseLauncher::initSharedDataBuffers()
{
    //This method grabs the eventMutex lock, so don't do it here
    clearRenderedItems();

    //Setup key event maps
    {
        QMutexLocker locker(&eventMutex);

        for ( int i=0; i < mNumPanes; ++i )
        {
            mCollectingKeyEvents[i] = false;
            mNewKeyEventReceived[i] = false;
            mKeyEvents[i] = std::deque<QKeyEvent>();
        }
    }
}

bool ExerciseLauncher::collectingKeyEvents()
{
    QMutexLocker locker(&eventMutex);
    for ( int i=0; i < mNumPanes; ++i )
    {
        if ( mCollectingKeyEvents[i] )
        {
            return true;
        }
    }
    return false;
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

void ExerciseLauncher::setKeyEvent( QKeyEvent event )
{
    QMutexLocker locker(&eventMutex);
    mKeyEvents[mWhichPaneHasFocus].push_back(event);

    mNewKeyEventReceived[mWhichPaneHasFocus] = true;
}

bool ExerciseLauncher::getKeyEventInfo( QKeySequence &key, QString &str, int pane, bool latestOnly )
{
    QMutexLocker locker(&eventMutex);
    if ( mKeyEvents.end() == mKeyEvents.find(pane) )
        return false;

    if ( (mKeyEvents[pane]).empty() )
        return false;

    if ( latestOnly )
    {
        QKeyEvent event((mKeyEvents[pane]).back());
        (mKeyEvents[pane]).clear();
        key = event.key();
        str = event.text();
    }
    else
    {
        QKeyEvent event((mKeyEvents[pane]).front());
        (mKeyEvents[pane]).pop_front();
        key = event.key();
        str = event.text();
    }
    return true;
}

void ExerciseLauncher::setWhichPaneHasFocus( int pane )
{
    if ( !collectingKeyEvents() )
    {
        if ( mPaneHighlight )
        {
            view->scene()->removeItem(mPaneHighlight);
            mPaneHighlight = NULL;
        }
        return;
    }

    //Make sure the view can get keyboard input
    if ( view )
        view->setFocus();

    QMutexLocker locker(&eventMutex);

    //Only give focus if we're collecting for this pane
    if ( mCollectingKeyEvents[pane] )
    {
        mWhichPaneHasFocus = pane;
    }

    if ( NULL == mPaneHighlight )
    {
        mPaneHighlight = fwcRectangleRender( 0, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT, GREEN, 2);
    }

    switch ( mWhichPaneHasFocus )
    {
    case 0:
            mPaneHighlight->setPos(0, 0);
        break;

    case 1:
            mPaneHighlight->setPos(WINDOW_WIDTH/2, 0);
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
int ExerciseLauncher::setRenderItem( FeetWetCodingExerciseBase::RenderItem item)
{
    //Store the item in the queue for rendering
    //during the next event processing timeout
    QMutexLocker locker(&itemMutex);
    item.ID = renderedItemsCount++;
    mItems.push_back(item);
    return item.ID;
}

void ExerciseLauncher::updateRenderItem(FeetWetCodingExerciseBase::RenderItemUpdate update)
{
    QMutexLocker locker(&itemMutex);
    mRenderItemUpdates.push_back(update);
}

void ExerciseLauncher::handleRenderRequests()
{
    QTime renderTimer;
    renderTimer.start();

    FeetWetCodingExerciseBase::RenderItem item;

    while ( renderTimer.elapsed() < 10 )
    {
        {
            QMutexLocker locker(&itemMutex);

            if (mItems.empty())
                break;

            item = mItems.front();
            mItems.pop_front();
        }

        QGraphicsItem *gItem(NULL);

        switch (item.type) {

        case FeetWetCodingExerciseBase::LINE:
            gItem = fwcLineRender( item.x, item.y, item.xEnd, item.yEnd, item.color, item.linewidth);
            break;
        case FeetWetCodingExerciseBase::CIRCLE:
            gItem = fwcCircleRender( item.x, item.y, item.radius, item.color, item.linewidth, item.solid);
            break;
        case FeetWetCodingExerciseBase::CIRCLERGB:
            gItem = fwcCircleRGBRender( item.x, item.y, item.radius, item.linewidth, item.RGBred, item.RGBgreen, item.RGBblue, item.solid);
            break;
        case FeetWetCodingExerciseBase::ELLIPSE:
            gItem = fwcEllipseRender( item.x, item.y, item.width, item.height, item.color, item.linewidth, item.solid);
            break;
        case FeetWetCodingExerciseBase::RECTANGLE:
            gItem = fwcRectangleRender( item.x, item.y, item.width, item.height, item.color, item.linewidth, item.solid);
            break;
        case FeetWetCodingExerciseBase::TEXT:
            gItem = fwcTextRender( item.text, item.x, item.y, item.color, item.fontsize);
            break;
        case FeetWetCodingExerciseBase::INT:
            gItem = fwcIntRender( item.intvalue, item.x, item.y, item.color, item.fontsize);
            break;
        case FeetWetCodingExerciseBase::FLOAT:
            gItem = fwcFloatRender( item.floatvalue, item.x, item.y, item.color, item.fontsize, item.decimalplaces );
            break;
        case FeetWetCodingExerciseBase::IMAGE:
            gItem = fwcImageRender( item.imagefile, item.x, item.y );
            break;
        }

        //Save the graphics item that was returned in case we need to
        //do something with it later
        {
            QMutexLocker locker(&itemMutex);
            mRenderedItems[item.ID] = gItem;
        }
    }
}

void ExerciseLauncher::handleRenderUpdates()
{
    QTime renderTimer;
    renderTimer.start();

    FeetWetCodingExerciseBase::RenderItemUpdate update;
    QGraphicsItem *item(NULL);
    QGraphicsLineItem *lineItem(NULL);
    QGraphicsEllipseItem  *ellipseItem(NULL);
    QGraphicsRectItem *rectItem(NULL);
    QGraphicsTextItem *textItem(NULL);
    //QGraphicsPixmapItem *pixmapItem(NULL);
    QAbstractGraphicsShapeItem *shapeItem(NULL);
    QFont font(qApp->font());
    QPen pen;
    QBrush brush(Qt::SolidPattern);

    QTransform transform;
    int centerX, centerY;

    while ( renderTimer.elapsed() < 10 )
    {
        {
            QMutexLocker locker(&itemMutex);

            if (mRenderItemUpdates.empty())
                break;

            update = mRenderItemUpdates.front();
            mRenderItemUpdates.pop_front();
        }

        FeetWetCodingExerciseBase::RenderItemUpdateType type = update.type;
        int itemID = update.ID;

        //Hold the lock from here till the end of the method
        QMutexLocker locker(&itemMutex);

        std::map<int, QGraphicsItem*>::iterator iter = mRenderedItems.find(itemID);

        if ( mRenderedItems.end() == iter )
            return;

        if ( NULL == mRenderedItems[itemID] )
            return;

        item = mRenderedItems[itemID];

        switch (type) {

        case FeetWetCodingExerciseBase::MOVE:
            item->setPos(update.x, update.y);

            //If it's an ellipse, then shift origin from top left to center
            ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item);
            if ( ellipseItem )
            {
                ellipseItem->moveBy(-ellipseItem->rect().width()/2, -ellipseItem->rect().height()/2);
            }

            break;

        case FeetWetCodingExerciseBase::SHIFT:
            item->moveBy(update.dx, update.dy);
            break;

        case FeetWetCodingExerciseBase::ERASE:
            view->scene()->removeItem(item);

            //Remove this item from the mRenderedItems map
            if ( mRenderedItems.end() != mRenderedItems.find(itemID) )
            {
                mRenderedItems.erase(mRenderedItems.find(itemID));
                delete item;
                item = NULL;
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_Z:
            item->setZValue(update.z);
            break;

        case FeetWetCodingExerciseBase::SCALE:
            transform = QTransform();

            centerX = item->boundingRect().center().x();
            centerY = item->boundingRect().center().y();
            transform.translate( centerX , centerY );
            item->setTransform( transform );

            item->setScale(item->scale() * update.scalefactor);

            centerX = item->boundingRect().center().x()*item->scale();
            centerY = item->boundingRect().center().y()*item->scale();
            transform.translate( -centerX , -centerY );
            item->setTransform( transform );

            break;

        case FeetWetCodingExerciseBase::ROTATE:
            transform = QTransform();
            centerX = item->boundingRect().width()/2;
            centerY = item->boundingRect().height()/2;
            transform.translate( centerX , centerY );
            transform.rotate( update.angledegrees );
            transform.translate( -centerX , -centerY );
            item->setTransform( transform );
            break;

        case FeetWetCodingExerciseBase::CHANGE_XEND_YEND:
            lineItem = dynamic_cast<QGraphicsLineItem *>(item);
            if ( lineItem )
            {
                lineItem->setLine(lineItem->line().x1(),
                                  lineItem->line().y1(),
                                  update.xEnd, update.yEnd);
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_WIDTH_AND_HEIGHT:
            rectItem = dynamic_cast<QGraphicsRectItem *>(item);
            if ( rectItem )
            {
                rectItem->setRect(rectItem->rect().x(),
                              rectItem->rect().y(),
                              update.width, update.height);
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_RADIUS:
            //It's only a circle if it's a QGraphicsEllipseItem
            //AND it's width and height are identical. Since they're floats
            //we can't just compare directly... need to compare absolute value
            //of their difference against FLT_EPSILON (a tiny value that's essentially
            //zero for most purposes.)
            ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item);
            if ( ellipseItem &&
                 fabs(ellipseItem->rect().width() - ellipseItem->rect().height()) < FLT_EPSILON)
            {
                //ellipseItem->setRect(-update.radius, -update.radius, update.radius*2, update.radius*2);
                //Get current center location so we can recenter circle after setting radius
                centerX=ellipseItem->pos().x()+ellipseItem->rect().width()/2;
                centerY=ellipseItem->pos().y()+ellipseItem->rect().height()/2;
                ellipseItem->setRect(0, 0, update.radius*2, update.radius*2);
                ellipseItem->setPos(centerX-update.radius, centerY-update.radius);
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_COLOR:
            shapeItem = dynamic_cast<QAbstractGraphicsShapeItem *>(item);
            if ( shapeItem )
            {
                if ( update.solid )
                {
                    brush.setColor(getQColor(update.color));
                    shapeItem->setBrush(brush);
                }
                pen.setColor(getQColor(update.color));
                shapeItem->setPen(pen);
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_LINE_WIDTH:
            shapeItem = dynamic_cast<QAbstractGraphicsShapeItem *>(item);
            if ( shapeItem )
            {
                pen = shapeItem->pen();
                pen.setWidth(update.linewidth);
                shapeItem->setPen(pen);
            }
            else
            {
                lineItem = dynamic_cast<QGraphicsLineItem *>(item);
                if ( lineItem )
                {
                    pen = lineItem->pen();
                    pen.setWidth(update.linewidth);
                    lineItem->setPen(pen);
                }
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_FONT_SIZE:
            textItem = dynamic_cast<QGraphicsTextItem *>(item);
            if ( textItem )
            {
                font.setPointSize(update.fontsize);
                textItem->setFont(font);
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_TEXT_VAL:
            textItem = dynamic_cast<QGraphicsTextItem *>(item);
            if ( textItem )
            {
                textItem->setPlainText(update.textval.c_str());
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_INT_VAL:
            textItem = dynamic_cast<QGraphicsTextItem *>(item);
            if ( textItem )
            {
                textItem->setPlainText(QString::number(update.intval));
            }
            break;

        case FeetWetCodingExerciseBase::CHANGE_FLOAT_VAL:
            textItem = dynamic_cast<QGraphicsTextItem *>(item);
            if ( textItem )
            {
                textItem->setPlainText(QString::number(update.floatval));
            }
            break;

        default:
            break;
        }
    }
}

void ExerciseLauncher::handleSeeOutRequests()
{
    QTime renderTimer;
    renderTimer.start();

    std::pair<SeeOut::RequestType, QString> request;
    SeeOut::RequestType type;
    QString value;

    if ( exerciseOut )
    {
        while ( renderTimer.elapsed() < 10 )
        {
            {
                QMutexLocker globallocker(&globalmutex);

                if ( SeeOut::exerciseOutMsgQueue.empty() )
                    break;

                request = SeeOut::exerciseOutMsgQueue.front();
                SeeOut::exerciseOutMsgQueue.pop_front();
            }

            type = request.first;
            value = request.second;

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
    }

    renderTimer.start();

    if ( solnOut )
    {
        while ( renderTimer.elapsed() < 10 )
        {
            {
                QMutexLocker globallocker(&globalmutex);

                if ( SeeOut::solnOutMsgQueue.empty() )
                    break;

                request = SeeOut::solnOutMsgQueue.front();
                SeeOut::solnOutMsgQueue.pop_front();
            }

            type = request.first;
            value = request.second;

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
}

void ExerciseLauncher::checkNeedForPanelSelection()
{
    static bool collecting(false);
    static const int LEFT(0);
    static const int RIGHT(1);
    int leftOrRight;
    bool leftSideCollecting(false);
    bool rightSideCollecting(false);

    {
        //Lock, grab the data, unlock
        QMutexLocker locker(&eventMutex);
        leftSideCollecting = mCollectingKeyEvents[LEFT];
        rightSideCollecting = mCollectingKeyEvents[RIGHT];
    }

    if ( collectingKeyEvents() != collecting )
    {
        collecting = collectingKeyEvents();

        //Assume LEFT till we learn otherwise
        leftOrRight = LEFT;

        if ( collecting )
        {
            if ( leftSideCollecting && rightSideCollecting )
            {
                //Both sides are collecting keyboard input.
                //See which side of the screen the mouse is
                //currently on and set focus there.
                if ( QCursor::pos().x() > theWindow->width()/2 )
                    leftOrRight = RIGHT;
            }
            else if ( leftSideCollecting )
            {
                //Only the left side is collecting
                leftOrRight = LEFT;
            }
            else if ( rightSideCollecting )
            {
                //Only the right side is collecting
                leftOrRight = RIGHT;
            }
        }
        else
        {
            //Since we're not collecting, pass invalid pane
            //to trigger the method to get rid of the highlighting.
            leftOrRight = -1;
        }

        //Set the focus
        setWhichPaneHasFocus(leftOrRight);
    }
}

void ExerciseLauncher::sceneCleared()
{
    clearRenderedItems();
}

void ExerciseLauncher::clearRenderedItems()
{
    QMutexLocker locker(&eventMutex);
    mItems.clear();
    mRenderItemUpdates.clear();
    mRenderedItems.clear();
    SeeOut::exerciseOutMsgQueue.clear();
    SeeOut::solnOutMsgQueue.clear();

    //If rendered items just got cleared
    //then this pointer is no longer valid
    mPaneHighlight = NULL;
}

bool ExerciseLauncher::buffersAreEmpty()
{
    QMutexLocker locker(&eventMutex);

    bool empty = mItems.empty() &&
                 mRenderItemUpdates.empty()&&
                 SeeOut::exerciseOutMsgQueue.empty() &&
                 SeeOut::solnOutMsgQueue.empty();

#ifdef DEBUG
    //This is actually kind of neat to watch. Primes 2 has lots of
    //rendered items, so it's a good one.
    //Keep it commented out when not specifically watching it, tho.
    //--------------------------------------------------------------
//    if ( empty )
//        qDebug() << "WE'RE EMPTY!";
//    else
//    {
//        int numItems = mItems.size() + mRenderItemUpdates.size() + SeeOut::exerciseOutMsgQueue.size() + SeeOut::solnOutMsgQueue.size();
//        qDebug() << "NUM ITEMS LEFT IN BUFFERS: " << numItems;
//    }
//    int numRenderedItems = mRenderedItems.size();
//    qDebug() << "NUM RENDERED ITEMS: " << numRenderedItems;
#endif

    return empty;
}

void ExerciseLauncher::update()
{
    handleRenderRequests();
    handleRenderUpdates();
    handleSeeOutRequests();
    checkNeedForPanelSelection();

    if ( buffersAreEmpty() && mThread->isFinished() && mThread->solutionIsFinished() )
    {
#ifdef DEBUG
        qDebug() << "DEBUG: Thread is done and buffers are empty so stopping timer - &&&&&&&&&&&&&&&&&&&";
#endif
        mTimer->stop();

        emit currentExerciseFinished();
    }
}
