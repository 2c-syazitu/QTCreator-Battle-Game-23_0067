#ifndef HEAL_H
#define HEAL_H

#include "skill.h"
#include "player.h"
#include "mainwindow.h"

class Heal : public Skill
{
public:
    Heal(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side);

    int getDmg();
    void activate(Character& atk,Character& def,MainWindow* w) override;

private:
    int dmg;
};

#endif // HEAL_H
