#ifndef SEEOUT_H
#define SEEOUT_H

#include <iostream>
#include <sstream>
#include <queue>
#include <QMutex>
#include <QDebug>

using namespace std;

//Global variables we need
extern QMutex globalmutex;

//SeeOut is a simulated "cout" that prints to a
// text widget in addition to std::out
class SeeOut
{

public:

    SeeOut():mIsSolution(false){}
    ~SeeOut(){}

    typedef enum
    {
        MESSAGE,
        COLOR,
        FONTSIZE
    } RequestType;

    void setIsSolution(bool isSolution)
    {
        mIsSolution = isSolution;
    }

    void setColor(Color color)
    {
        QString colorStr = QString::number((int)color);
        if ( !mIsSolution )
        {
            QMutexLocker globallocker(&globalmutex);
            exerciseOutMsgQueue.push_back(make_pair<RequestType,QString>(COLOR, colorStr));
        }
        else
        {
            QMutexLocker globallocker(&globalmutex);
            solnOutMsgQueue.push_back(make_pair<RequestType,QString>(COLOR, colorStr));
        }
    }

    void setFontSize(int size)
    {
        QString sizeStr = QString::number(size);
        if ( !mIsSolution )
        {
            QMutexLocker globallocker(&globalmutex);
            exerciseOutMsgQueue.push_back(make_pair<RequestType,QString>(FONTSIZE, sizeStr));
        }
        else
        {
            QMutexLocker globallocker(&globalmutex);
            solnOutMsgQueue.push_back(make_pair<RequestType,QString>(FONTSIZE, sizeStr));
        }
    }

    template <typename T>
    SeeOut& operator<<(const T& x)
    {
        mOss.str("");
        mOss << x;
        std::cerr << mOss.str();

        if ( !mIsSolution )
        {
            QMutexLocker globallocker(&globalmutex);
            exerciseOutMsgQueue.push_back(make_pair<RequestType,QString>(MESSAGE, mOss.str().c_str()));
        }
        else
        {
            QMutexLocker globallocker(&globalmutex);
            solnOutMsgQueue.push_back(make_pair<RequestType,QString>(MESSAGE, mOss.str().c_str()));
        }

        return *this;
    }

    static std::deque<std::pair<SeeOut::RequestType, QString> >exerciseOutMsgQueue;
    static std::deque<std::pair<SeeOut::RequestType, QString> >solnOutMsgQueue;

private:
    std::ostringstream mOss;
    bool mIsSolution;
};

#endif // SEEOUT_H
