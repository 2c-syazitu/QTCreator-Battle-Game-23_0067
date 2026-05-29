#include "atkbuff.h"

AtkBuff::AtkBuff(QString name,int cost,int baseDmg,double rate,int turn,Type type, Range range,Side side)
    :Skill(name,cost,baseDmg,rate,type,range,side)
    ,turn(turn)
    ,pix(":/skill/buffIcon/power.png")
{

}

int AtkBuff::getTurn(){
    return turn;
}

void AtkBuff::activate(Character& atk,Character& def,MainWindow* w){
    qDebug() << "ab16";
    w->sys.singleBuff(*this,atk,def,w);
}


QPixmap AtkBuff::getImage(){
    qDebug() << "ab21";
    if (pix.isNull()) {
        qDebug() << "QPixmap 読み込み失敗";
    } else {
        qDebug() << "QPixmap 読み込み成功"
                 << pix.size();
    }
    return pix;
}
