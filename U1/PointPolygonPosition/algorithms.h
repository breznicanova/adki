#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <vector>
#include <QPointF>
#include <QPolygonF>

class Algorithms
{
public:
    Algorithms();
    int getPointLinePosition(QPointF &q, QPointF &p1, QPointF &p2);
    double getAngle(QPointF &p1,QPointF &p2,QPointF &p3,QPointF &p4);
    int getPositionWinding(QPointF &q, std::vector<QPointF> &pol);
    int getPositionRay(QPointF &q, std::vector<QPointF> &pol);

};

#endif // ALGORITHMS_H
