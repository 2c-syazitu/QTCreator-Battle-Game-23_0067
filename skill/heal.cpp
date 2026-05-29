#include "heal.h"

Heal::Heal(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side)
    :Skill(name,cost,baseDmg,rate,type,range,side)
    , dmg(dmg)
{

}

int Heal::getDmg()
{
    return dmg;
}

void Heal::activate(Character& atk,Character& def,MainWindow* w)
{
    qDebug() << "hl20:" << atk.getName() << " heal to " << def.getName() << " with " << this->getName();
    w->sys.singleHeal(*this,atk,def,w);
}
