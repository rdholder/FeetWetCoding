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
    virtual int runExercise()=0;

protected:
    SeeOut seeout;
};

#endif // FEETWETCODINGEXERCISE_H
