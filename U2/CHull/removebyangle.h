#ifndef REMOVEBYANGLE_H
#define REMOVEBYANGLE_H
#include <QtGui>
#include <cmath>


class removeByAngle
{
private:
    QPoint q;

public:
    removeByAngle(QPoint &p){q = p;}

    bool operator()(const QPoint &p1,const QPoint &p2) const
    {
       //Compute directions sigma1, sigma2
        double sigma1 = atan2(p1.y()-q.y(),p1.x()-q.x());
        double sigma2 = atan2(p2.y()-q.y(),p2.x()-q.x());

        //Remove points with same directions
        return sigma1 == sigma2;
    }
};

#endif // REMOVEBYANGLE_H
