#ifndef MYHEADER_H
#define MYHEADER_H

#include <QObject>
#include <setup.h>
#include <exercises/FeetWetCodingExercise.h>

class myprogram : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit myprogram(QObject *parent = 0):FeetWetCodingExercise(parent){}

signals:

public slots:
    virtual int runExercise();

};

#endif // MYHEADER_H
