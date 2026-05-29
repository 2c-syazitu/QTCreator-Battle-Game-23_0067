#include "attack.h"

Attack::Attack(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side)
    :Skill(name,cost,baseDmg,rate,type,range,side)
    , dmg(dmg)
{

}

int Attack::getDmg()
{
    return dmg;
}

void Attack::activate(Character& atk,Character& def,MainWindow* w)
{

}
