#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <QWidget>
#include <QtGui>
#include <QPointF>
#include <QPolygonF>

class Draw : public QWidget
{
    Q_OBJECT
private:
    boolean draw_mode;  //true = polygon, false = point
    QPolygonF polygon;
    std::vector <QPolygonF> polygons;
    QPointF q;
    std::vector <int> result;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void changeMode(){draw_mode = !draw_mode;}
    QPointF & getPoint(){return q;}
    void loadFile(std::string &string_path);
    std::vector<QPolygonF> getPolygons (){return polygons;}
    void setResult(std::vector<int> res){result = res;}
    void clearC();
};

#endif // DRAW_H
