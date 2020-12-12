#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include <vector>

#include "qpoint3d.h"
#include "edge.h"
#include "triangle.h"

class Draw : public QWidget
{
    Q_OBJECT

private:
    std::vector <QPoint3D> points;
    std::vector <Edge> dt;
    std::vector <Edge> contours;
    std::vector <Triangle> dtm;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void setPoints(std::vector<QPoint3D> &points_){points=points_;}
    std::vector<QPoint3D> & getPoints(){return points;}
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    std::vector<Edge> & getDT(){return dt;}
    void setContours(std::vector<Edge> &contours_){contours = contours_;}
    std::vector<Edge> & getContours(){return contours;}
    void setDTM(std::vector<Triangle> &dtm_){dtm = dtm_;}
    std::vector<Triangle> & getDTM(){return dtm;}

    //void loadFile(std::string &string_path);
    void loadFile(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &min_z, double &max_z);

signals:

public slots:
};

#endif // DRAW_H
