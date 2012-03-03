#ifndef SEEOUT_H
#define SEEOUT_H

#include <feetwetcodinglib.h>

//SeeOut is a simulated "cout" that prints to a
// text widget in addition to std::out
class SeeOut
{

public:

    void setColor(Color color)
    {
        QMutexLocker globallocker(&globalmutex);
        if ( !Gsoln && exerciseOut )
        {
//            exerciseOut->setTextColor(getQColor(color));
        }
        if ( Gsoln && solnOut )
        {
//            solnOut->setTextColor(getQColor(color));
        }
    }

    void setFontSize(int size)
    {
        QMutexLocker globallocker(&globalmutex);
        if ( !Gsoln && exerciseOut )
        {
//            exerciseOut->setFontPointSize(size);
        }
        if ( Gsoln && solnOut )
        {
//            solnOut->setFontPointSize(size);
        }
    }

    template <typename T>
    SeeOut& operator<<(const T& x)
    {
        QMutexLocker locker(&mutex);
        mOss.str("");
        mOss << x;
        std::cerr << mOss.str();

        QMutexLocker globallocker(&globalmutex);
        if ( !Gsoln && exerciseOut )
        {
//            exerciseOut->insertPlainText(mOss.str().c_str());
        }
        if ( Gsoln && solnOut )
        {
//            solnOut->insertPlainText(mOss.str().c_str());
        }

        return *this;
    }

private:
    std::ostringstream mOss;
    QMutex mutex;
};

#endif // SEEOUT_H
