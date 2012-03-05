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
    void setKeyEventInfo( QKeySequence key, QString str );
    void getKeyEventInfo( QKeySequence &key, QString &str );
    void setWhichPaneHasFocus( int pane );
    int getWhichPaneHasFocus();
    void setRenderItem( FeetWetCodingExercise::RenderItem item );
    void updateRenderItem( FeetWetCodingExercise::RenderItemUpdate update );
    void handleRenderRequests();
    void handleRenderUpdates();
    void handleSeeOutRequests();

public slots:

    void update();

private:

    FeetWetCodingExercise *mThread;

    std::map<int, bool> mCollectingKeyEvents;
    std::map<int, bool> mNewKeyEventReceived;

    QKeySequence mKey;
    QString mKeyString;
    int mWhichPaneHasFocus;
    QGraphicsItem *mPaneHighlight;
    std::deque<FeetWetCodingExercise::RenderItem> mItems;
    std::deque<FeetWetCodingExercise::RenderItemUpdate> mRenderItemUpdates;
    std::map<int, QGraphicsItem*> mRenderedItems;

    QMutex eventMutex;
    QMutex itemMutex;

};

#endif // EXERCISELAUNCHER_H
