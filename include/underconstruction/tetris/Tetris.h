#ifndef TETRIS_H
#define TETRIS_H

#include <exercises/FeetWetCodingExercise.h>

class Tetris : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit Tetris(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

class TetrisSoln : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit TetrisSoln(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

#endif // TETRIS_H
