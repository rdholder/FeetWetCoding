// FeetWetCoding/include/exercises/C08-Game_Programming/GameWidget.h
// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QGraphicsView>

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);

    void setIsSolution(const bool soln) { mIsSolution = soln; }
    bool getIsSolution() const { return mIsSolution; }
    QGraphicsView * getView() { return mTd2dView; }

signals:

public slots:
    virtual void keyPressEvent(QKeyEvent *k);

protected:
    virtual void createLayout();
    virtual void makeConnections();
    virtual void initializeGameBoard()=0;
    virtual void handleKeyPress(QKeyEvent *k)=0;

private:
    bool mIsSolution;
    QGraphicsView * mTd2dView;
};

#endif // GAMEWIDGET_H
