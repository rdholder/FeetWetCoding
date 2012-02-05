#ifndef FEETWETCODINGEXERCISE_H
#define FEETWETCODINGEXERCISE_H

#include <QObject>
#include <feetwetcodinglib.h>

class FeetWetCodingExercise : public QObject
{
    Q_OBJECT
public:
    explicit FeetWetCodingExercise(QObject *parent = 0);

signals:

public slots:
    virtual void update();

protected:
    virtual void runExercise();
    virtual void setupSolution(){} //=0;

    SeeOut seeout;
    FeetWetCodingExercise *mSolutionPtr;
};

#endif // FEETWETCODINGEXERCISE_H
