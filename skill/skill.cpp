#include "skill.h"

// Skill::Skill(QString name, int cost,Player* user,Player* target)
//     : name(name),cost(cost),user(user),target(target)
Skill::Skill(QString name, int cost,int baseDmg,double rate,Type type, Range range,Side side)
    : name(name)
    ,cost(cost)
    ,baseDmg(baseDmg)
    ,rate(rate)
    ,type(type)
    ,range(range)
    ,side(side)
{

}

QString Skill::getName()
{
    return name;
}

int Skill::getCost()
{
    return cost;
}

int Skill::getBaseDmg(){
    return baseDmg;
}

double Skill::getRate(){
    return rate;
}

void Skill::activate(Character& atk,Character& def,MainWindow* w)
{

}

Type Skill::getType(){
    return type;
}

Range Skill::getRange(){
    return range;
}

Side Skill::getSide(){
    return side;
}

int Skill::getTurn(){

}

QPixmap Skill::getImage(){

}
