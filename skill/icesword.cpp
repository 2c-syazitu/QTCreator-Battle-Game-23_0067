#include "icesword.h"
#include "skill.h"

IceSword::IceSword(QString name,int cost,int baseDmg,double rate,Type type, Range range,Side side)
    :Skill(name,cost,baseDmg,rate,type,range,side)
    , dmg(dmg)
{

}

int IceSword::getDmg()
{
    return dmg;
}

void IceSword::activate(Character& atk,Character& def,MainWindow* w)
{
    qDebug() << "ic20:" << atk.getName() << " attack to " << def.getName() << " with " << this->getName();
    w->sys.singleAttack(*this,atk,def,w);

}



