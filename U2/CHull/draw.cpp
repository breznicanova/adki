#include "draw.h"
#include <QTimer>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}
void Draw::mousePressEvent(QMouseEvent *e)
{
    //Get coordinates
    int x = e->x();
    int y = e->y();

    //Add point to the list
    QPoint p(x,y);
    points.push_back(p);

    //Repaint
    repaint();

}


void Draw::paintEvent(QPaintEvent *e)
{
    //Start draw
    QPainter qp(this);
    qp.begin(this);

    //Draw points
    int r = 5;
    for(int i = 0; i < points.size(); i++)
    {
        qp.drawEllipse(points[i].x() - r,points[i].y() - r, 2 * r, 2 * r);
    }

    //Draw polygon
    qp.drawPolygon(ch);

    //End draw
    qp.end();
}


std::vector<QPoint> Draw::circle(int n,int height, int width){

    std::vector<QPoint> points;
    QPoint p, center;

    double phi = 2*M_PI/n;

    center.setX(width/2);
    center.setY(height/2);

    for (int i = 0; i < n; i++)
    {
         p.setX(center.x() + (height/2-100) * cos(phi*i));
         p.setY(center.y() + (height/2-100) * sin(phi*i));
         points.push_back(p);
    }
    return points;
}

std::vector<QPoint> Draw::grid(int n){

    QPoint point;

    int count = sqrt(n);

    for (int x = 0; x < count; x++)
    {
        for (int y = 0; y < count; y++)
        {
            point.setX(x*20+10);
            point.setY(y*20+10);
            points.push_back(point);
        }
    }

    return points;
}

std::vector<QPoint> Draw::random(int n){

    std::vector<QPoint> points;
    QPoint p;

    for(int i = 0;i<n;i++){

        double x = rand()%500+50;
        double y = rand()%500+50;
        p.setX(x);
        p.setY(y);
        points.push_back(p);
    }

    return points;
}


void Draw::clearC()
{
    //Clear points
    points.clear();

    //Repaint screen
    repaint();
}
