/********************************************************************************
** Form generated from reading UI file 'skilllist.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKILLLIST_H
#define UI_SKILLLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SkillList
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *SkillLabel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *cansellBut;

    void setupUi(QWidget *SkillList)
    {
        if (SkillList->objectName().isEmpty())
            SkillList->setObjectName("SkillList");
        SkillList->resize(400, 300);
        horizontalLayoutWidget = new QWidget(SkillList);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 90, 371, 80));
        SkillLabel = new QHBoxLayout(horizontalLayoutWidget);
        SkillLabel->setObjectName("SkillLabel");
        SkillLabel->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(SkillList);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(220, 170, 160, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cansellBut = new QPushButton(horizontalLayoutWidget_2);
        cansellBut->setObjectName("cansellBut");

        horizontalLayout->addWidget(cansellBut);


        retranslateUi(SkillList);

        QMetaObject::connectSlotsByName(SkillList);
    } // setupUi

    void retranslateUi(QWidget *SkillList)
    {
        SkillList->setWindowTitle(QCoreApplication::translate("SkillList", "Form", nullptr));
        cansellBut->setText(QCoreApplication::translate("SkillList", "\343\202\255\343\203\243\343\203\263\343\202\273\343\203\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SkillList: public Ui_SkillList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKILLLIST_H
