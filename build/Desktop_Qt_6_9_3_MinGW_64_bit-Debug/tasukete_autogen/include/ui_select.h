/********************************************************************************
** Form generated from reading UI file 'select.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_select
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *selectLayout;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelBut;

    void setupUi(QDialog *select)
    {
        if (select->objectName().isEmpty())
            select->setObjectName("select");
        select->resize(400, 300);
        horizontalLayoutWidget = new QWidget(select);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 110, 361, 80));
        selectLayout = new QHBoxLayout(horizontalLayoutWidget);
        selectLayout->setObjectName("selectLayout");
        selectLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(select);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(210, 190, 160, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelBut = new QPushButton(horizontalLayoutWidget_2);
        cancelBut->setObjectName("cancelBut");

        horizontalLayout->addWidget(cancelBut);


        retranslateUi(select);

        QMetaObject::connectSlotsByName(select);
    } // setupUi

    void retranslateUi(QDialog *select)
    {
        select->setWindowTitle(QCoreApplication::translate("select", "Dialog", nullptr));
        cancelBut->setText(QCoreApplication::translate("select", "\343\202\255\343\203\243\343\203\263\343\202\273\343\203\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select: public Ui_select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
