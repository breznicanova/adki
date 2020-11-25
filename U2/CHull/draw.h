#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>
#include <QtGui>

class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint> points;     //Input points
    std::vector<QPoint> coloredPoints;
    QPolygon ch;                    //Convex Hull

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    std::vector<QPoint> & getPoints(){return points;}
    QPolygon & getCH() {return ch;}
    void setCH(QPolygon &ch_){ch = ch_;}
    void setPoints(std::vector<QPoint> points_){points = points_;}
    void setColoredPoints(std::vector<QPoint> points_){coloredPoints = points_;}
    std::vector<QPoint> circle(int n, int height, int width);
    std::vector<QPoint> grid(int n);
    std::vector<QPoint> random(int n);
    void clearC();
signals:

};

#endif // DRAW_H

