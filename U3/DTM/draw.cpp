#include "draw.h"

#include <fstream>

Draw::Draw(QWidget *parent) : QWidget(parent)
{

}

void Draw::setContours(std::vector<Edge> &contours_,std::vector<double> &contour_heights_,int dz_){
    contours = contours_;
    contour_heights = contour_heights_;
    dz = dz_;
}

void Draw::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.begin(this);

    //Draw points
    for (int i = 0; i < points.size(); i++)
    {
        painter.drawEllipse(points[i].x() - 5, points[i].y() - 5, 5, 5);
    }

    //Draw Delaunay edges
    QPen p(Qt::green, 1);
    painter.setPen(p);

    for (int i = 0; i < dt.size(); i++)
    {
        painter.drawLine(dt[i].getStart(), dt[i].getEnd());
    }

    //Draw contour lines
    int main_contour = dz * 5;

    for (int i = 0; i < contours.size(); i++)
    {
        double text_x = (contours[i].getStart().x() + contours[i].getEnd().x())/2;
        double text_y = (contours[i].getStart().y() + contours[i].getEnd().y())/2;
        int height = contour_heights[i];
        if(height%(main_contour))
        {
            QPen q(QColor(139,69,19), 1);
            painter.setPen(q);
            painter.drawLine(contours[i].getStart(), contours[i].getEnd());
        }
        else
        {
            QPen q(QColor(139,69,19), 2);
            painter.setPen(q);
            painter.drawLine(contours[i].getStart(), contours[i].getEnd());
            painter.drawText(text_x, text_y, QString::number(height));
        }
    }

    //Draw slope
    if(slope == TRUE)
    {
        for (Triangle t : dtm)
        {
            double k = 255/180.0;
            //Get triangle vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();

            //Get slope
            int colorSlope = 255 - t.getSlope() * k;

            //Create color and set brush
            QColor c(colorSlope,colorSlope,colorSlope);
            painter.setBrush(c);

            //Create triangle, add vertices
            QPolygonF triangle;
            triangle.append(QPointF(p1.x(), p1.y()));
            triangle.append(QPointF(p2.x(), p2.y()));
            triangle.append(QPointF(p3.x(), p3.y()));

            //Draw triangle
            painter.drawPolygon(triangle);
        }
        painter.end();
    }


    //Draw aspect
    if(aspect == TRUE)
    {
        for (Triangle t : dtm)
        {
            double k = 255.0 / 360;
            //Get triangle vertices
            QPoint3D p1 = t.getP1();
            QPoint3D p2 = t.getP2();
            QPoint3D p3 = t.getP3();

            //Get aspect
            int colorAspect = 255 - t.getAspect() * k;

            //Create color and set brush
            QColor c(colorAspect, colorAspect, colorAspect);
            painter.setBrush(c);

            //Create triangle, add vertices
            QPolygonF triangle;
            triangle.append(QPointF(p1.x(), p1.y()));
            triangle.append(QPointF(p2.x(), p2.y()));
            triangle.append(QPointF(p3.x(), p3.y()));

            //Draw triangle
            painter.drawPolygon(triangle);
        }

        //Draw contour lines
        QPen q(Qt::gray, 1);
        painter.setPen(q);

        for (int i = 0; i < contours.size(); i++)
        {
            painter.drawLine(contours[i].getStart(), contours[i].getEnd());
        }

        painter.end();
    }
}


void Draw::mousePressEvent(QMouseEvent *event)
{
    //Get coordinates of cursor
    QPoint3D p;
    p.setX(event ->x());
    p.setY(event ->y());
    double random = std::rand() * 200.0 / RAND_MAX;
    p.setZ(random);

    //Add point to the list
    points.push_back(p);

    repaint();
};

//void Draw::loadFile(std::string &string_path)
void Draw::loadFile(std::string &path, std::vector<QPoint3D> &points,  QSizeF &canvas_size, double &min_z, double &max_z)
{
    double x, y, z;
    QPoint3D p;

    //Storing all polygons
    double min_x = std::numeric_limits<double>::max();
    double min_y = std::numeric_limits<double>::max();
    double max_x = std::numeric_limits<double>::min();
    double max_y = std::numeric_limits<double>::min();
    min_z = std::numeric_limits<double>::max();
    max_z = std::numeric_limits<double>::min();


    std::ifstream myfile(path);
    if(myfile.is_open())
    {
        while(myfile >> x >> y >> z)
        {
            p.setX(x);
            p.setY(y);
            p.setZ(z);

            points.push_back(p);

            if(x < min_x) min_x = x;
            if(x > max_x) max_x = x;
            if(y < min_y) min_y = y;
            if(y > max_y) max_y = y;
            if(z < min_z) min_z = z;
            if(z > max_z) max_z = z;
        }

        myfile.close();
    }

        //Scale points to canvas size
        double h = canvas_size.height() - 40;
        double w = canvas_size.width() - 40;

        double x_coef = w/(max_x-min_x);
        double y_coef = h/(max_y-min_y);

        for(unsigned int i = 0; i < points.size(); i++)
        {
            points[i].setX((points[i].x()-min_x)*x_coef);
            points[i].setY((points[i].y()-min_y)*y_coef);
        }
}
