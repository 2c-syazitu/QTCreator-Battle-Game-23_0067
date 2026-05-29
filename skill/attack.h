#ifndef ATTACK_H
#define ATTACK_H

#include "skill.h"
#include "player.h"
#include "mainwindow.h"

class Attack : public Skill
{
public:
    Attack(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side);

    int getDmg();
    void activate(Character& atk,Character& def,MainWindow* w) override;

private:
    int dmg;
};

#endif // ATTACK_H
