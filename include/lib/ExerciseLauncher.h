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
    bool wasNewKeyEventReceived();
    void newKeyEventWasConsumed();
    QKeySequence getKey();
    QKeyEvent *getKeyEvent();
    void setKeyEvent( QKeyEvent *event );
    void setRenderItem( FeetWetCodingExercise::RenderItem item);
    void handleRenderRequests();

public slots:

    void update();

private:

    FeetWetCodingExercise *mThread;

    bool mNewKeyEventReceived;

    QKeySequence mKey;
    QKeyEvent *mKeyEvent;
    std::queue<FeetWetCodingExercise::RenderItem> mItems;
    std::map<int, QGraphicsItem*> mRenderedItems;

    QMutex eventMutex;
    QMutex itemMutex;

};

#endif // EXERCISELAUNCHER_H
