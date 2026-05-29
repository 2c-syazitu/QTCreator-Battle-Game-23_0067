/********************************************************************************
** Form generated from reading UI file 'enemy.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMY_H
#define UI_ENEMY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Enemy
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel;
    QLabel *nameLabel;

    void setupUi(QWidget *Enemy)
    {
        if (Enemy->objectName().isEmpty())
            Enemy->setObjectName("Enemy");
        Enemy->resize(201, 242);
        verticalLayoutWidget = new QWidget(Enemy);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 201, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageLabel = new QLabel(verticalLayoutWidget);
        imageLabel->setObjectName("imageLabel");

        verticalLayout->addWidget(imageLabel);

        nameLabel = new QLabel(verticalLayoutWidget);
        nameLabel->setObjectName("nameLabel");

        verticalLayout->addWidget(nameLabel);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        retranslateUi(Enemy);

        QMetaObject::connectSlotsByName(Enemy);
    } // setupUi

    void retranslateUi(QWidget *Enemy)
    {
        Enemy->setWindowTitle(QCoreApplication::translate("Enemy", "Form", nullptr));
        imageLabel->setText(QCoreApplication::translate("Enemy", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("Enemy", "trsstsetsetse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Enemy: public Ui_Enemy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMY_H
