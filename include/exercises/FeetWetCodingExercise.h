// FeetWetCoding/include/exercises/FeetWetCodingExercise.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef FEETWETCODINGEXERCISE_H
#define FEETWETCODINGEXERCISE_H

#include <QObject>
#include <feetwetcodinglib.h>

class FeetWetCodingExercise : public QObject
{
    Q_OBJECT
public:
    explicit FeetWetCodingExercise(QObject *parent = 0);
    virtual ~FeetWetCodingExercise();

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
