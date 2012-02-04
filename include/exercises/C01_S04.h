#ifndef C01_S04_H
#define C01_S04_H

#include <exercises/FeetWetCodingExercise.h>

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// CH01/S04/Expressions_Syntax
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class GetsAndPlusGets : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GetsAndPlusGets(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class GetsAndPlusGetsSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit GetsAndPlusGetsSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

#endif // C01_S04_H
