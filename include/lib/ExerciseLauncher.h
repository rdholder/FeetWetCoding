#ifndef EXERCISELAUNCHER_H
#define EXERCISELAUNCHER_H

#include <exercises/FeetWetCodingExercise.h>
#include <QApplication>
#include <QTimer>
#include <QMutex>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <deque>

class ExerciseLauncher : public QObject
{
    Q_OBJECT

public:

    ExerciseLauncher(QObject *parent=0);
    virtual ~ExerciseLauncher();

    //IMPORTANT!!! Calling code retains ownership of the mSelectedExercise
    //pointer. ExerciseLauncher should not delete this passed in pointer!
    void launchExercise( FeetWetCodingExercise *exercise );
    void stopCurrentExercise();
    void initSharedDataBuffers();
    void startCollectingKeyBoardInput( int pane );
    void stopCollectingKeyBoardInput( int pane );
    bool wasNewKeyEventReceived( int pane );
    void newKeyEventWasConsumed( int pane );
    void setKeyEvent( QKeyEvent event );
    bool getKeyEventInfo( QKeySequence &key, QString &str, int pane );
    void setWhichPaneHasFocus( int pane );
    int getWhichPaneHasFocus();
    int getNumPanes() { return mNumPanes; }

    //Adds a render item request. Returns unique ID of render item.
    int setRenderItem( FeetWetCodingExercise::RenderItem item );

    void updateRenderItem( FeetWetCodingExercise::RenderItemUpdate update );
    void clearRenderedItems();
    bool collectingKeyEvents();

public slots:

    void update();
    void sceneCleared();

signals:
    void currentExerciseFinished();

private:

    //Every item that gets rendered gets a unique ID
    //based on this value, which is incremented with
    //every new rendered item.
    static int renderedItemsCount;

    void handleRenderRequests();
    void handleRenderUpdates();
    void handleSeeOutRequests();
    void checkNeedForPanelSelection();
    bool buffersAreEmpty();

    QTimer *mTimer;
    FeetWetCodingExercise *mThread;

    std::map<int, bool> mCollectingKeyEvents;
    std::map<int, bool> mNewKeyEventReceived;
    std::map<int, std::deque<QKeyEvent> > mKeyEvents;

    QKeySequence mKey;
    QString mKeyString;
    int mNumPanes;
    int mWhichPaneHasFocus;
    QGraphicsItem *mPaneHighlight;
    std::deque<FeetWetCodingExercise::RenderItem> mItems;
    std::deque<FeetWetCodingExercise::RenderItemUpdate> mRenderItemUpdates;
    std::map<int, QGraphicsItem*> mRenderedItems;

    QMutex eventMutex;
    QMutex itemMutex;

};

#endif // EXERCISELAUNCHER_H
