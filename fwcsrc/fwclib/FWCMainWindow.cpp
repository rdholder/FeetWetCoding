#include <fwclib/FWCMainWindow.h>
#include <fwclib/FWCView.h>
#include <fwclib/FWCSettings.h>
#include <fwclib/FWCExerciseChooser.h>
#include <fwclib/constants.h>
#include <QTextEdit>
#include <QTime>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QPushButton>

FWCMainWindow *theWindow(NULL);
FWCView *view(NULL);
FWCExerciseChooser *exerciseChooser(NULL);
QTextEdit *exerciseOut(NULL);
QTextEdit *solnOut(NULL);

FWCMainWindow::FWCMainWindow()
    :mView(NULL)
    ,mChooser(NULL)
    ,mExerciseOut(NULL)
    ,mSolnOut(NULL)
{
    init();
}

FWCMainWindow::~FWCMainWindow()
{
    if ( mView )
    {
        delete mView;
        mView = NULL;
    }
    if ( mChooser )
    {
        delete mChooser;
        mChooser = NULL;
    }
    if ( mExerciseOut )
    {
        delete mExerciseOut;
        mExerciseOut = NULL;
    }
    if ( mSolnOut )
    {
        delete mSolnOut;
        mView = NULL;
    }
}

void FWCMainWindow::init()
{
    //Read configuration settings
    FWCSettings settings;
    settings.initSettingsFile();

    //Setup the GUI
    setupGUI();

}

void FWCMainWindow::setupGUI()
{
    QGraphicsScene *scene = new QGraphicsScene(-BORDER, -BORDER,
                                               DRAW_AREA_W+BORDER*2,
                                               DRAW_AREA_H+BORDER*1.75);
    //Create the GUI elements
    mView = new FWCView(scene);
    mView->setRenderHint(QPainter::TextAntialiasing);
    mView->setMouseTracking(true);
    mView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mExerciseOut = new QTextEdit();
    mExerciseOut->ensureCursorVisible();
    mExerciseOut->setReadOnly(true);
    mExerciseOut->setFocusPolicy(Qt::NoFocus);

    mSolnOut = new QTextEdit();
    mSolnOut->ensureCursorVisible();
    mSolnOut->setReadOnly(true);
    mSolnOut->setFocusPolicy(Qt::NoFocus);

    mChooser = new FWCExerciseChooser();

    //Non-member GUI elements
    QPushButton *restartExercise = new QPushButton( tr( "Re-start Exercise") );
    restartExercise->setFocusPolicy(Qt::NoFocus);

    QFrame *separator = new QFrame();
    separator->setFrameStyle( QFrame::VLine | QFrame::Sunken );

    QWidget *mainWindowPanel = new QWidget();

    //Make connections to events we need to listen for
    QObject::connect(restartExercise, SIGNAL(clicked()),
                     mChooser, SLOT(runCurrentExercise()));
    QObject::connect(mView, SIGNAL(keyPressSignal(QKeyEvent*)),
                     mChooser, SLOT(handleKeyEvent(QKeyEvent*)));
    QObject::connect(mView, SIGNAL(newMousePos(QPoint)),
                     mChooser, SLOT(handleNewMousePosEvent(QPoint)));

    //Layout the GUI
    QHBoxLayout *hlayout1 = new QHBoxLayout();
    hlayout1->addStretch();
    hlayout1->addLayout(mChooser->getChooserLayout());
    hlayout1->addWidget(separator, 0 );
    hlayout1->addWidget(restartExercise);

    //--------------------------------------------------------------------
    //TODO: This is the beginning of trying to draw the labels over the
    //exercise/solution boxes here instead of in the exercise base class.
    //This is probably still the better way to do it, but it should be
    //all of the stuff (the entire reference box, grid coordinates, etc.)
    //and not just the labels, which is not a priority right now. Do them
    //all at once at some point. (janice, April 2012)
    //--------------------------------------------------------------------
//    QString labelText = "<font color='black' size='3'>" + tr("Make YOUR Code...") + "</font>";
//    QLabel *yourSideLabel = new QLabel(labelText);
//    yourSideLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

//    labelText = "<font color='black' size='4'>" + tr("...do what the SOLUTION code does.") + "</font>";
//    QLabel *solnSideLabel = new QLabel(labelText);
//    solnSideLabel->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

//    QHBoxLayout *hlayout2 = new QHBoxLayout();
//    hlayout2->addStretch();
//    hlayout2->addWidget(yourSideLabel);
//    hlayout2->addSpacing(DRAW_AREA_W/2);
//    hlayout2->addWidget(solnSideLabel);
//    hlayout2->addStretch();
//    QVBoxLayout *vlayout2 = new QVBoxLayout();
//    vlayout2->addSpacing(10);
//    vlayout2->addLayout(hlayout2);
//    vlayout2->addStretch();
//    mView->setLayout(vlayout2);

    QHBoxLayout *hlayout3 = new QHBoxLayout();
    hlayout3->addWidget(mExerciseOut);
    hlayout3->addWidget(mSolnOut);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addLayout(hlayout1);
    vlayout->addWidget(mView);
    vlayout->addLayout(hlayout3);
    mainWindowPanel->setLayout(vlayout);

    //Set the main window geometry and central widget
    this->setGeometry(WINDOW_X, WINDOW_Y,
                      DRAW_AREA_W+BORDER*2,
                      DRAW_AREA_H+BORDER*3+OUTTEXT_HEIGHT);
    setCentralWidget(mainWindowPanel);
    setWindowTitle( tr("FeetWetCoding") );

    // Done creating drawing area, so ok to run.
    // Choose the first Exercise in the list
    mChooser->setOkToRun(true);
    mChooser->runCurrentExercise();

    //Set the globals
    view = mView;
    exerciseChooser = mChooser;
    exerciseOut = mExerciseOut;
    solnOut = mSolnOut;
    theWindow = this;
}
