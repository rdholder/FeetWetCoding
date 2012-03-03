// copyright (c) 2011 Robert Holder, Janice Dugger.
// See README.html included in this distribution.

#include <exercises/C01_S11.h>
#include <math.h>

void TheEventLoop::runExercise()
{
    DrawText("Exercise Under\nConstruction", 50, 100, BLUE, 24);
}


// START OF POTENTIAL EXERCISE CODE
// NOT SURE THIS IS WHAT WE WANT BUT
// DON'T WANT TO LOSE IT JUST YET
// --janice
//
//
//#include <QApplication>
//#include <QPushButton>
//using std::string;

////This is the drawing area where the exercises
////get rendered. It comes from feetwetcodinglib.h
//extern FWCView *view;

//class ExerciseWidget : public QFrame
//{
//public:
//    ExerciseWidget() : QFrame(NULL){}
//    ~ExerciseWidget(){}

//    void setBackgroundColor( Color background=LIGHTGRAY );

//protected slots:
//    virtual void mousePressEvent ( QMouseEvent * event );

//};

//void ExerciseWidget::setBackgroundColor( Color background )
//{
//    DrawRectangle(0, 0, this->width(), this->height(), background, 1, true);
//}

//void ExerciseWidget::mousePressEvent ( QMouseEvent * event )
//{
//    Gsoln = false;

//    this->setBackgroundColor();
//    int x = event->x();
//    int y = event->y();

//    //TODO: GIVE THEM std::ostringstream AND std::string LESSON
//    std::ostringstream message;
//    message << "Clicked: " << x << ", " << y;

//    DrawText("X", x-13, y-25, RED, 24);
//    DrawText(message.str(), x+15, y-15, BLUE);
//}

//void TheEventLoop::runExercise()
//{
//    ExerciseWidget* widget = new ExerciseWidget();
//    widget->setGeometry(0, 0, 400, 400);
//    view->scene()->addWidget(widget);
//}
