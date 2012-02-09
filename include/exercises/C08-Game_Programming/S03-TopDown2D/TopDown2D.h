#ifndef TOPDOWN2D_H
#define TOPDOWN2D_H

#include <exercises/FeetWetCodingExercise.h>

class TopDown2DWidget;

class TopDown2DSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TopDown2DSoln(QObject *parent=0);
    virtual ~TopDown2DSoln();

signals:

public slots:

protected:
    void runExercise();

    TopDown2DWidget * mTd2dWidget;
};

class TopDown2D : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TopDown2D(QObject *parent = 0);
    virtual ~TopDown2D();

signals:

public slots:

protected:
    void runExercise();

    //Hide this implementation from the student
    void setupSolution()
    {
        DrawReferenceBox(LEFTRIGHT);
        mSolutionPtr = new TopDown2DSoln(); // Executes soln's runExercise();
    }

    TopDown2DWidget * mTd2dWidget;
};

#endif // TOPDOWN2D_H
