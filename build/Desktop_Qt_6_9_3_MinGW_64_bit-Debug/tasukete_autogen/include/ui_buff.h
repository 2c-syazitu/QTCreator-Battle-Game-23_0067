/********************************************************************************
** Form generated from reading UI file 'buff.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUFF_H
#define UI_BUFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buff
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *buffIconLabel;

    void setupUi(QWidget *Buff)
    {
        if (Buff->objectName().isEmpty())
            Buff->setObjectName("Buff");
        Buff->resize(568, 341);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Buff->sizePolicy().hasHeightForWidth());
        Buff->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(Buff);
        horizontalLayout->setObjectName("horizontalLayout");
        buffIconLabel = new QLabel(Buff);
        buffIconLabel->setObjectName("buffIconLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buffIconLabel->sizePolicy().hasHeightForWidth());
        buffIconLabel->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(buffIconLabel);


        retranslateUi(Buff);

        QMetaObject::connectSlotsByName(Buff);
    } // setupUi

    void retranslateUi(QWidget *Buff)
    {
        Buff->setWindowTitle(QCoreApplication::translate("Buff", "Form", nullptr));
        buffIconLabel->setText(QCoreApplication::translate("Buff", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buff: public Ui_Buff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUFF_H
