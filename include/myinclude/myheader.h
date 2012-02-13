// FeetWetCoding/include/myinclude/myheader.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef MYHEADER_H
#define MYHEADER_H

#include <setup.h>
#include <exercises/FeetWetCodingExercise.h>

class myprogram : public FeetWetCodingExercise
{
    Q_OBJECT
public:
    explicit myprogram(QObject *parent = 0)
        :FeetWetCodingExercise(parent){}

signals:

public slots:

protected:
    void runExercise();
};

#endif // MYHEADER_H
