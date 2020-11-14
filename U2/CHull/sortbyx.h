#ifndef SORTBYX_H
#define SORTBYX_H

#include <QtGui>

class sortByX
{
public:
    sortByX(){};

    //Sorter by x-coordinate
    bool operator () (QPoint &p1, QPoint &p2)
    {
        return p1.x() < p2.x();
    }
};

#endif // SORTBYX_H
