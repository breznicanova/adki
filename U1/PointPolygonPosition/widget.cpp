#include "widget.h"
#include "ui_widget.h"
#include "algorithms.h"
#include <QtGui>
#include <QMessageBox>
#include <fstream>
#include <string.h>
#include "qdebug.h"
#include <QFileDialog>
#include <iostream>

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


void Widget::on_drawPointPolygon_clicked()
{
    //Change drawing mode
    ui->Canvas->changeMode();
}


void Widget::on_analyze_clicked()
{
    //Get point q
    QPoint q= ui->Canvas->getPoint();

    //Get polygon
    std::vector<QPolygon> polygons = ui->Canvas->getPolygons();

    //Get combo-box status, select method
    Algorithms alg;
    QPolygon one_polygon;
    std::vector<int> result;
    std::vector<QPoint> pol;
    int p = 0;
    int res = 0;

    //Get one polygon
    for (int j = 0; j < polygons.size(); j++) {
        one_polygon = polygons[j];
        for (int  i= 0; i< one_polygon.size(); i++) {

            pol.push_back(one_polygon[i]);

        }

        for (int k = 0; k < pol.size(); k++) {
            if (q == pol[k])
                p += 1;
        }

        //Check if point q is on vertex
        if (p < 1)
            {

            //Select method
            if (ui->comboBox->currentIndex() == 0)
            {
                res = alg.getPositionWinding(q, pol);
            }
            else
                res = alg.getPositionRay(q, pol);
                result.push_back(res);
            }
        else result.push_back(1);
        pol.clear();
        p=0;
    }

    int i = 1;
    int j = -1;
    int k = -2;
    if (std::count(result.begin(), result.end(),i))
        ui->label->setText("Inside");
    else if (std::count(result.begin(), result.end(),j))
        ui->label->setText("Edge");
    else if (std::count(result.begin(), result.end(),k))
        ui->label->setText("Line");

    else
        ui->label->setText("Outside");


    ui->Canvas->setResult(result);
    ui->Canvas->repaint();
}


void Widget::on_clear_clicked()
{
    ui->Canvas->clearC();
    ui->label->setText("");
}


void Widget::on_importPolygons_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "../",
                                                    tr("Text Files (*.txt)"));
    std::string string_path = path.toStdString();

    ui->Canvas->loadFile(string_path);




}
