#ifndef SORTBYYRIGHT_H
#define SORTBYYRIGHT_H
#include <QtGui>

class sortByYRight
{
public:
    sortByYRight(){};

    //Sorter by y-coordinate
    bool operator () (QPoint &p1, QPoint &p2)
    {
        return (p1.y() < p2.y()) || ((p1.y() == p2.y()) && (p1.x() > p2.x())) ;
    }

};

#endif // SORTBYYRIGHT_H

