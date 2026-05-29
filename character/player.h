#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QLabel>
#include <QObject>
#include <QVBoxLayout>
#include <QPushButton>

// #include <QLine>
#include "character.h"

class CharacterList;
class SkillList;
class MainWindow;


namespace Ui {
class Player;
}

class CharacterList;

class Player : public QWidget, public Character
{
    Q_OBJECT

public:
    explicit Player(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type,QWidget *parent = nullptr);
    ~Player();


    void calcDmg(int) override;
    void heal(int) override;
    void setNowMp(int) override;
    void changeAlive() override;
    void setBuffList(Buff* buff)override;
    void eraseBuff(int i) override;
    void resizeEvent(QResizeEvent *event) override;


private:
    Ui::Player *ui;

    // QVBoxLayout* layOut;
    // QLabel *nameLabel;
    // QLabel *hpLabel;
    // QLabel *mpLabel;
    // QHBoxLayout *buffIcon;
    // QLabel* buffLabel;
    // QVBoxLayout* labelLayout;
    // QFrame* line;
    // QPixmap pix;

    // QLabel* sizeLabel;

    QLabel* emptyLabel;

    double h;
    double buffHeightRate;
    double lineHeightRate;
    double statasHeightRate;
    double buffH;
    double lineH;
    double statasH;


private slots:
    // void AttackButtonClicked();

};

#endif // PLAYER_H
