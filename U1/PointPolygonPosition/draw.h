#ifndef DRAW_H
#define DRAW_H

#include <vector>
#include <QWidget>
#include <QtGui>

class Draw : public QWidget
{
    Q_OBJECT
private:
    boolean draw_mode;  //true = polygon, false = point
    QPolygon polygon;
    std::vector <QPolygon> polygons;
    QPoint q;
    std::vector <int> result;

public:
    explicit Draw(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void changeMode(){draw_mode = !draw_mode;}
    QPoint & getPoint(){return q;}
    void loadFile(std::string &string_path);
    std::vector<QPolygon> getPolygons (){return polygons;}
    void setResult(std::vector<int> res){result = res;}
    void clearC();
};

#endif // DRAW_H
