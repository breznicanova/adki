#ifndef REMOVEBYANGLE_H
#define REMOVEBYANGLE_H
#include <QtGui>

class removeByAngle
{
private:
    QPoint q;

public:
    removeByAngle(QPoint &p){q=p;};

    bool operator() (QPoint &p1, QPoint &p2)
    {
        //Compute direction sigma1, sigma2
        double sigma1 = atan2(p1.y()-q.y(),p1.x()-q.x());
        double sigma2 = atan2(p2.y()-q.y(),p2.x()-q.x());

        //Remove points with same direction
        return sigma1 == sigma2;
    }
};

#endif // REMOVEBYANGLE_H
