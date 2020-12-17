/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <draw.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    Draw *Canvas;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QComboBox *comboBox_2;
    QCheckBox *checkBox;
    QPushButton *generate;
    QPushButton *pushButton;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *clear_CH;
    QPushButton *clear_all;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Canvas = new Draw(Widget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Canvas->sizePolicy().hasHeightForWidth());
        Canvas->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(Canvas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        comboBox_2 = new QComboBox(Widget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        generate = new QPushButton(Widget);
        generate->setObjectName(QString::fromUtf8("generate"));

        verticalLayout->addWidget(generate);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        clear_CH = new QPushButton(Widget);
        clear_CH->setObjectName(QString::fromUtf8("clear_CH"));

        verticalLayout->addWidget(clear_CH);

        clear_all = new QPushButton(Widget);
        clear_all->setObjectName(QString::fromUtf8("clear_all"));

        verticalLayout->addWidget(clear_all);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Create Convex Hull", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Select method: ", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "Jarvis Scan", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "QHull", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "Sweep Line", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "Graham Scan", nullptr));

        label_3->setText(QCoreApplication::translate("Widget", "Enter the number", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "of generated points:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Select shape:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "Circle", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "Grid", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "Random", nullptr));

        checkBox->setText(QCoreApplication::translate("Widget", "Create Strictly Convex Hull", nullptr));
        generate->setText(QCoreApplication::translate("Widget", "Generate", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Create CH", nullptr));
        label->setText(QString());
        clear_CH->setText(QCoreApplication::translate("Widget", "Clear CH", nullptr));
        clear_all->setText(QCoreApplication::translate("Widget", "Clear All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
