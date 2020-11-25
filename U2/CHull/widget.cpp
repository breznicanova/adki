#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "draw.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //Get points
    std::vector<QPoint> points = ui->Canvas->getPoints();

    if(points.empty()){
        QMessageBox::critical(this,tr("Error"),
                          tr("The vector of points is empty!!\n"
                             "The program will end predictably."),QMessageBox::Cancel);
    }


    //Create Convex hull
    QPolygon ch;
    Algorithms alg;

    clock_t start_timer = std::clock();

    //Jarvis Scan
    if (ui->comboBox->currentIndex()==0)
        ch = alg.jarvis(points);
    //QHull
    else if (ui->comboBox->currentIndex()==1)
        ch = alg.qhull(points);
    //Sweep Line
    else if (ui->comboBox->currentIndex()==2)
        ch = alg.sweepLine(points);
    //Graham Scan
    else
        ch = alg.graham(points);

    //Sort out points on Convex hull

    std::vector<QPoint> colPoints;

    for (int i; i<points.size();i++)
    {
        if (ch.contains(points[i]))
        {
            colPoints.push_back(points[i]);
        }
    }

    ui -> Canvas -> setColoredPoints(colPoints);

    //Draw strictly convex hull
    if (ui->checkBox->isChecked())
    {
        QPolygon strictly_ch = Algorithms::strictlyCH(ch);
        ui->Canvas->setCH(strictly_ch);
        repaint();
    }
    //Or not
    else
    {
        ui->Canvas->setCH(ch);
        repaint();
    }

    clock_t end_timer = std::clock();

    clock_t time = end_timer-start_timer;

    //Set time
    ui -> label -> setText(QString::number(time) + "ms");
}

void Widget::on_clear_CH_clicked()
{
    //Get Convex Hull
    QPolygon &ch = ui->Canvas->getCH();

    //Clear points
    ch.clear();

    //Repaint screen
    repaint();
}

void Widget::on_generate_clicked()
{
    std::vector<QPoint> points;
    Draw drw;
    int n, height, width;
    if (ui->comboBox_2->currentIndex()==0){
        n = ui->lineEdit->text().toInt();
        height = ui->Canvas->height();
        width = ui->Canvas->width();
        points = drw.circle(n,height,width);
    }
    else if (ui->comboBox_2->currentIndex()==1){
        n = ui->lineEdit->text().toInt();
        points = drw.grid(n);
    }
    else if (ui->comboBox_2->currentIndex()==2){
        n = ui->lineEdit->text().toInt();
        points = drw.random(n);
    }

    if(points.size()==1){
        QMessageBox::information(this,tr(""),
                          tr("The vector of points is empty.\n"
                             "Set count of points!"),QMessageBox::Ok);
    }
    ui->Canvas->setPoints(points);
    ui->Canvas->repaint();
}


void Widget::on_clear_all_clicked()
{

    //Get Convex Hull
    QPolygon &ch = ui->Canvas->getCH();

    //Clear Convex Hull
    ch.clear();

    //Clear points
    ui->Canvas->clearC();

    //Repaint screen
    repaint();
}
