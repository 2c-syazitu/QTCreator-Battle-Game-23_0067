/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QFrame *line_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *playerLayout;
    QFrame *line_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *attackBut;
    QPushButton *skillBut;
    QPushButton *itemBut;
    QPushButton *defBut;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *enemyLayout;
    QFrame *line;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *turnLabel;
    QLabel *textLabel;
    QFrame *line_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1062, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1051, 611));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        line_4 = new QFrame(frame);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(0, 430, 1051, 31));
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 260, 1031, 181));
        playerLayout = new QHBoxLayout(horizontalLayoutWidget);
        playerLayout->setObjectName("playerLayout");
        playerLayout->setContentsMargins(0, 0, 0, 0);
        line_5 = new QFrame(frame);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(0, 500, 1051, 31));
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);
        horizontalLayoutWidget_2 = new QWidget(frame);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(9, 520, 1031, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        attackBut = new QPushButton(horizontalLayoutWidget_2);
        attackBut->setObjectName("attackBut");

        horizontalLayout->addWidget(attackBut);

        skillBut = new QPushButton(horizontalLayoutWidget_2);
        skillBut->setObjectName("skillBut");

        horizontalLayout->addWidget(skillBut);

        itemBut = new QPushButton(horizontalLayoutWidget_2);
        itemBut->setObjectName("itemBut");

        horizontalLayout->addWidget(itemBut);

        defBut = new QPushButton(horizontalLayoutWidget_2);
        defBut->setObjectName("defBut");

        horizontalLayout->addWidget(defBut);

        horizontalLayoutWidget_3 = new QWidget(frame);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 1031, 251));
        enemyLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        enemyLayout->setObjectName("enemyLayout");
        enemyLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(frame);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 250, 1051, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 450, 1031, 61));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        turnLabel = new QLabel(gridLayoutWidget);
        turnLabel->setObjectName("turnLabel");

        gridLayout->addWidget(turnLabel, 0, 0, 1, 1);

        textLabel = new QLabel(gridLayoutWidget);
        textLabel->setObjectName("textLabel");

        gridLayout->addWidget(textLabel, 0, 2, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 0, 1, 1, 1);

        gridLayout->setColumnStretch(2, 15);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1062, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        attackBut->setText(QCoreApplication::translate("MainWindow", "\346\224\273\346\222\203", nullptr));
        skillBut->setText(QCoreApplication::translate("MainWindow", "\343\202\271\343\202\255\343\203\253", nullptr));
        itemBut->setText(QCoreApplication::translate("MainWindow", "\351\201\223\345\205\267", nullptr));
        defBut->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241", nullptr));
        turnLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        textLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
