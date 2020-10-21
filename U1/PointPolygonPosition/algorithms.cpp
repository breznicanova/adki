#include "algorithms.h"
#include <cmath>
#include "qdebug.h"


Algorithms::Algorithms()
{

}


int Algorithms::getPointLinePosition(QPointF &q, QPointF &p1, QPointF &p2)
{
    //Tolerance
    double eps = 300;

    //Get point and line position
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = q.x() - p1.x();
    double vy = q.y() - p1.y();

    //Determinant
    double t = ux * vy - uy * vx;

    //qDebug() << t;

    // Multiple of the directional vector (p1p2) for coordinates of point "q"
    double m = vx / ux;

    //Point in the left halfplane
    if ( t > eps)
         return 1;

    //Point in the right halfplane
    if (t < -eps)
        return 0;

    // Point on the edge
    if (t >= -eps and t <= eps and m >= 0 and m <= 1)
        return -1;

    // Point on the line but not on the edge
    return -2;
}


double Algorithms::getAngle(QPointF &p1, QPointF &p2, QPointF &p3, QPointF &p4)
{
    //Get vectors u, v
    double ux = p2.x() - p1.x();
    double uy = p2.y() - p1.y();
    double vx = p4.x() - p3.x();
    double vy = p4.y() - p3.y();

    //Norms
    double nu = sqrt(ux * ux + uy * uy);
    double nv = sqrt(vx * vx + vy * vy);

    //Dot product
    double dot = ux * vx + uy * vy;

    return fabs(acos(dot/(nu*nv)));
}


int Algorithms::getPositionWinding(QPointF &q, std::vector<QPointF> &pol)
{
    //Position of a point and polygon: Winding Number Algorithm
    //q inside P: 1
    //q outside P: 0
    //q on P boundary: -1

    double Omega = 0.0;

    //Set tolerance
    const double eps = 1.0e-6;

    //Amount of polygon vertices
    const int n = pol.size();

    //Process all vertices of the polygon
    for (int i = 0; i < n; i++)
    {
        //Get angle omega
        double om = getAngle(q,pol[i],q,pol[(i+1)%n]);

        //Get orientation of q and pol[i], pol[i+1]
        int orientation = getPointLinePosition(q, pol[i], pol[(i+1)%n]);

        // Point on the edge
        if (orientation == -1)
            return -1;

        // Point on the line but not on the edge
        if (orientation == -2)
            return 0;

        //Point in the left halfplane
        if (orientation == 1)
            Omega += om;

        //Point in the right halfplane
        else
            Omega -= om;
    }

    //Point q inside polygon
    if (fabs(fabs(Omega) - 2*M_PI) < eps)
        return 1;

    //Point q outside polygon
    return 0;
}


int Algorithms::getPositionRay(QPointF &q, std::vector<QPointF> &pol)
{
    //Position of a point and polygon: Ray Crossing Algorithm
    //q inside P: 1
    //q outside P: 0
    //q on P boundary: -1

    //Amount of intersections on the right half plane
    int k = 0;

    //Amount of intersections on the left half plane
    int l = 0;

    // Tolerance
    double eps = 1.0e-6;

    //Amount of polygon vertices
    const int n = pol.size();

    //Process all vertices of the polygon
    for (int i = 1; i < n + 1 ; i++)
    {
        //Compute xi, yi, xii, yii
        double xir = pol[i%n].x() - q.x();
        double yir = pol[i%n].y() - q.y();
        double xiir = pol[i-1].x() - q.x();
        double yiir = pol[i-1].y() - q.y();

        //Does segment (pi-1, pi) intersect ray
        if ((yir > 0) && (yiir <= 0) || (yiir > 0) && (yir <= 0))
        {
            //Compute x coordinate of intersection
            double xm = (xir * yiir - xiir * yir)/(yir - yiir);

            //Point q in the right halfplane
            if (xm > -eps)
                k += 1;

            // Point in the left half plane
            if (xm < eps)
                l += 1;
        }
    }

    // Point on the edge
    if (k%2 > l%2 or k%2 < l%2)
        return -1;

    //Get amount of intersections: odd or even
    return k%2;
}


