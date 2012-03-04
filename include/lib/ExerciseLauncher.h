#ifndef EXERCISELAUNCHER_H
#define EXERCISELAUNCHER_H

#include <exercises/FeetWetCodingExercise.h>
#include <QApplication>
#include <QTimer>
#include <QMutex>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>
#include <queue>

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
    void startCollectingKeyBoardInput();
    void stopCollectingKeyBoardInput();
    bool wasNewKeyEventReceived();
    void newKeyEventWasConsumed();
    void setKeyEventInfo( QKeySequence key, QString str );
    void getKeyEventInfo( QKeySequence &key, QString &str );
    void setRenderItem( FeetWetCodingExercise::RenderItem item );
    void updateRenderItem( FeetWetCodingExercise::RenderItemUpdate update );
    void handleRenderRequests();
    void handleRenderUpdates();
    void handleSeeOutRequests();

public slots:

    void update();

private:

    FeetWetCodingExercise *mThread;

    bool mCollectingKeyEvents;
    bool mNewKeyEventReceived;

    QKeySequence mKey;
    QString mKeyString;
    std::queue<FeetWetCodingExercise::RenderItem> mItems;
    std::map<int, QGraphicsItem*> mRenderedItems;
    std::queue<FeetWetCodingExercise::RenderItemUpdate> mRenderItemUpdates;

    QMutex eventMutex;
    QMutex itemMutex;

};

#endif // EXERCISELAUNCHER_H
