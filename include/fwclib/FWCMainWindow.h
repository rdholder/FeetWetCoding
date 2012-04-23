#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

//Forward class declarations
class FWCView;
class FWCExerciseChooser;
class QTextEdit;

class FWCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    FWCMainWindow();
    ~FWCMainWindow();

private slots:
//    void quit();

private:
    void init();
    void setupGUI();

    FWCView* mView;
    FWCExerciseChooser *mChooser;
    QTextEdit *mExerciseOut;
    QTextEdit *mSolnOut;
};

#endif // MAINWINDOW_H
