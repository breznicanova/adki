#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include "triangle.h"

#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    z_min = 0;
    z_max = 500;
    dz = 10;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_7_clicked()
{
    //Create contour lines
    Algorithms a;
    std::vector<Edge> dt;

    //DT needs to be created
    if(dt.size() == 0)
    {
        //Get points
        std::vector<QPoint3D> points = ui->Canvas->getPoints();

        //Create DT
        dt = a.DT(points);

        //Set DT
        ui->Canvas->setDT(dt);
    }

    //Create contour lines
    int dz = ui -> lineEdit_3 -> text().toInt();
    std::vector<double> contour_heights;
    std::vector<Edge> contours = a.contourLines(dt, z_min, z_max, dz, contour_heights);

    //Set contours
    ui -> Canvas -> setContours(contours, contour_heights, dz);

    //Repaint
    repaint();
}


void Widget::on_pushButton_11_clicked()
{
    //Get points
    std::vector<QPoint3D> &points = ui->Canvas->getPoints();

    //Clear points
    points.clear();

    //Repaint
    repaint();
}


void Widget::on_pushButton_12_clicked()
{
    //Get DT and contours
    std::vector<Edge> &dt = ui->Canvas->getDT();
    std::vector<Edge> &contours = ui->Canvas->getContours();

    //Clear DT and contour lines
    dt.clear();
    contours.clear();

    //Repaint
    repaint();
}


void Widget::on_lineEdit_editingFinished()
{
    //Set z_min
    z_min = ui -> lineEdit -> text().toDouble();
}


void Widget::on_lineEdit_2_editingFinished()
{
    //Set z_max
    z_max = ui -> lineEdit_2 -> text().toDouble();
}


void Widget::on_lineEdit_3_editingFinished()
{
    //Set dz
    dz = ui -> lineEdit_3 -> text().toDouble();
}


void Widget::on_pushButton_2_clicked()
{
    Algorithms a;
    std::vector<Edge> dt;
    bool slope = FALSE;
    bool aspect = FALSE;

    //DT needs to be created
    if(dt.size() == 0)
    {
        //Get points
        std::vector<QPoint3D> points = ui->Canvas->getPoints();

        //Create DT
        dt = a.DT(points);

        //Set DT
        ui->Canvas->setDT(dt);
    }

    //Analyze DTM
    std::vector<Triangle> dtm = a.analyzeDTM(dt);

    //Set analysis
    ui->Canvas->setDTM(dtm);

    //Set method
    if (ui->comboBox->currentIndex()==0){
        slope = TRUE;
        aspect = FALSE;
    }
    else if (ui->comboBox->currentIndex()==1){
        slope = FALSE;
        aspect = TRUE;
    }

    ui->Canvas->setAspect(aspect);
    ui->Canvas->setSlope(slope);

    //Repaint
    repaint();
}


void Widget::on_pushButton_3_clicked()
{
    //Clear DTM analysis
    std::vector<Edge> &dt = ui->Canvas->getDT();
    std::vector<Triangle> &dtm = ui->Canvas->getDTM();

    //Clear DTM
    dt.clear();
    dtm.clear();

    //Repaint
    repaint();
}


void Widget::on_pushButton_4_clicked()
{
    //Get all
    std::vector<QPoint3D> &points = ui->Canvas->getPoints();
    std::vector<Edge> &dt = ui->Canvas->getDT();
    std::vector<Edge> &contours = ui->Canvas->getContours();
    std::vector<Triangle> &dtm = ui->Canvas->getDTM();

    //Clear all
    points.clear();
    dt.clear();
    contours.clear();
    dtm.clear();

    //Repaint
    repaint();
}

void Widget::on_pushButton_clicked()
{
   //ui->Canvas->clearDT();

   std::vector<QPoint3D> points;

   QSizeF canvas_size = ui->Canvas->size();

   QString path = QFileDialog::getOpenFileName(
               this,
               tr("Select file"),
               "/",
               "Text file (*.txt);;All files (*.*)");

   std::string path_utf8 = path.toUtf8().constData();

   QString msg;

   Draw drw;
   drw.loadFile(path_utf8, points, canvas_size, z_min, z_max);

   ui->Canvas->setPoints(points);

   ui->Canvas->repaint();
}

