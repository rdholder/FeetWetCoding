#include <include/feetwetcodinglib.h>
#include <exercises/C08-Game_Programming/GameWidget.h>

#include <QPushButton>
#include <QVBoxLayout>

extern FWCView *view;

GameWidget::GameWidget(QWidget *parent)
    :QWidget(parent)
    ,mIsSolution(false)
{
    createLayout();
    makeConnections();

    //Since we have two game widgets (exercise and solution), let our
    //parent widget get the keyboard input and send it to both of us
    setFocusPolicy(Qt::NoFocus);
}

void GameWidget::createLayout()
{
    QGraphicsScene *td2dScene = new QGraphicsScene();
    mTd2dView = new QGraphicsView(td2dScene);
    mTd2dView->setFocusPolicy(Qt::NoFocus);
//    mTd2dView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    mTd2dView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPushButton *startButton = new QPushButton( tr("Start New Game") );
    startButton->setFocusPolicy(Qt::NoFocus);

    QVBoxLayout *vbl = new QVBoxLayout();
    vbl->addWidget(mTd2dView);
    vbl->addWidget(startButton);
    this->setLayout(vbl);
}

void GameWidget::makeConnections()
{
    connect(view, SIGNAL(keyPressSignal(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
}

void GameWidget::keyPressEvent( QKeyEvent *k )
{
    this->handleKeyPress(k);
}

