#ifndef C01_S04_H
#define C01_S04_H

#include <exercises/FeetWetCodingExercise.h>

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// CH01/S04/Expressions_Syntax
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class AssignmentArithmetic : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit AssignmentArithmetic(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class PreAndPostIncAndDec : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit PreAndPostIncAndDec(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class Misdirection : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Misdirection(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class MisdirectionSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit MisdirectionSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

#endif // C01_S04_H
