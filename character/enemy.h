#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <random>
#include "character.h"
#include "battlesystem.h"
#include "characterlist.h"

namespace Ui {
class Enemy;
}

class Enemy : public QWidget, public Character
{
    Q_OBJECT

public:
    explicit Enemy(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type,QWidget *parent = nullptr);
    ~Enemy();

    void calcDmg(int) override;
    void heal(int) override;
    void setNowMp(int) override;
    void changeAlive() override;
    void loadAlg() override;
    void setMainWindowAndBattleSystem(MainWindow* w,BattleSystem sys);

private:
    Ui::Enemy *ui;
    // QLabel* imageLabel;
    // QLabel* nameLabel;
    MainWindow* w;
    BattleSystem sys;
    std::mt19937 gen;
};

#endif // ENEMY_H
