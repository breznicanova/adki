#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <QtGui>
#include <vector>

class Algorithms
{
 public:
    Algorithms();

    double getAngle(QPoint &p1, QPoint &p2, QPoint &p3, QPoint &p4);
    static int getPointLinePosition(QPoint &q, QPoint &p1, QPoint &p2);
    double getPointLineDist(QPoint &a, QPoint &p1, QPoint &p2);
    double distanceOfTwoPoints(QPoint &p1, QPoint &p2);
    QPolygon jarvis(std::vector<QPoint> &points);
    QPolygon qhull(std::vector<QPoint> &points);
    QPolygon sweepLine(std::vector<QPoint> &points);
    void qh(int s, int e, std::vector<QPoint> &points, QPolygon &ch);
    static QPolygon removeDuplicite(std::vector<QPoint> &points);
    static QPolygon grahamScan(std::vector<QPoint> &points);

};

#endif // ALGORITHMS_H
