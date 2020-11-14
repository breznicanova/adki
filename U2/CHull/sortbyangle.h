#ifndef SORTBYANGLE_H
#define SORTBYANGLE_H
#include <cmath>
#include "algorithms.h"
#include <QtGui>


class sortByAngle
{
private:
    QPoint q;

public:
    sortByAngle(QPoint &p){q = p;}

    bool operator()(QPoint &p1, QPoint &p2)
    {
       //Compute directions sigma1, sigma2
        double sigma1 = atan2(p1.y()-q.y(),p1.x()-q.x());
        double sigma2 = atan2(p2.y()-q.y(),p2.x()-q.x());

       //Compute distance d1,d2
        double d1 = (p1.x()-q.x())*(p1.x()-q.x())+(p1.y()-q.y())*(p1.y()-q.y());
        double d2 = (p2.x()-q.x())*(p2.x()-q.x())+(p2.y()-q.y())*(p2.y()-q.y());

       //Comparator
        return sigma1 < sigma2 || (sigma1 == sigma2) && (d1 > d2);
    }
};

#endif // SORTBYANGLE_H
