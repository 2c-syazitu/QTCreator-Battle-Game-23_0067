#ifndef ATKBUFF_H
#define ATKBUFF_H

#include "skill.h"
#include "player.h"
#include "mainwindow.h"

class AtkBuff : public Skill
{
public:
    AtkBuff(QString name,int cost,int baseDmg,double rate,int turn,Type type, Range range,Side side);

    int getTurn()override;
    void activate(Character& atk,Character& def,MainWindow* w)override;
    QPixmap getImage()override;

private:
    int turn;
    QPixmap pix;
};

#endif // ATKBUFF_H
