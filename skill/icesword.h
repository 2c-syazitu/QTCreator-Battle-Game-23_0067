#ifndef ICESWORD_H
#define ICESWORD_H

#include "skill.h"
#include "player.h"
#include "mainwindow.h"

class IceSword : public Skill
{
public:
    IceSword(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side);

    int getDmg();
    void activate(Character& atk,Character& def,MainWindow* w) override;

private:
    int dmg;
};

#endif // ICESWORD_H
