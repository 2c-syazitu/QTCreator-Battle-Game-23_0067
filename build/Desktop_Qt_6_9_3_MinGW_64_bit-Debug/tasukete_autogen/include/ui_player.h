/********************************************************************************
** Form generated from reading UI file 'player.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYER_H
#define UI_PLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Player
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *buffIcon;
    QFrame *line;
    QLabel *nameLabel;
    QLabel *hpLabel;
    QLabel *mpLabel;

    void setupUi(QWidget *Player)
    {
        if (Player->objectName().isEmpty())
            Player->setObjectName("Player");
        Player->resize(49, 261);
        verticalLayout_2 = new QVBoxLayout(Player);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        buffIcon = new QHBoxLayout();
        buffIcon->setObjectName("buffIcon");
        buffIcon->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);

        verticalLayout->addLayout(buffIcon);

        line = new QFrame(Player);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        nameLabel = new QLabel(Player);
        nameLabel->setObjectName("nameLabel");

        verticalLayout->addWidget(nameLabel);

        hpLabel = new QLabel(Player);
        hpLabel->setObjectName("hpLabel");

        verticalLayout->addWidget(hpLabel);

        mpLabel = new QLabel(Player);
        mpLabel->setObjectName("mpLabel");

        verticalLayout->addWidget(mpLabel);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 3);
        verticalLayout->setStretch(3, 3);
        verticalLayout->setStretch(4, 3);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Player);

        QMetaObject::connectSlotsByName(Player);
    } // setupUi

    void retranslateUi(QWidget *Player)
    {
        Player->setWindowTitle(QCoreApplication::translate("Player", "Form", nullptr));
        nameLabel->setText(QCoreApplication::translate("Player", "name", nullptr));
        hpLabel->setText(QCoreApplication::translate("Player", "hp", nullptr));
        mpLabel->setText(QCoreApplication::translate("Player", "mp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Player: public Ui_Player {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYER_H
