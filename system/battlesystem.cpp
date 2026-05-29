#include "BattleSystem.h"
#include "character.h"
#include "mainwindow.h"
#include "iostream"

BattleSystem::BattleSystem()
    :atkerAtk(0)
    ,defenderDef(0)
{

}

void BattleSystem::attack(Skill& s,Character& atk, Character& def,MainWindow* w)
{
    QString text = nullptr;
    calcBuff(atk,def);
    qDebug() << atk.getName() << " attaked " << def.getName() <<
                                "\n base atk = " << atk.getAtk() << " buffed atk = " << atkerAtk;
    int dmg = calcRateToEnemy(s,atk,def);
    qDebug() << "bs19";
    if(def.getNowHp()> 0){
        def.calcDmg(dmg);
        text = QString("%1が%2へ%3のダメージ!!\n").arg(atk.getName()).arg(def.getName()).arg(dmg);
        if(def.getNowHp()<=0){
            text += QString("%1は力尽きた...\n").arg(def.getName());
        }
        w->setText(text);
        w->turn->changeTurn();
    }else{
        w->setText(QString("%1は力尽きています。").arg(def.getName()));
    }
    resetStatas();
}

void BattleSystem::singleAttack(Skill& s,Character& atk,Character& def,MainWindow* w)
{
    QString text = nullptr;
    calcBuff(atk,def);
    if(def.getNowHp() > 0){
        int dmg = calcRateToEnemy(s,atk,def);
        /*ダメージがある場合*/
        if(dmg>0){
            def.calcDmg(dmg);
            qDebug() <<"bs43" << dmg;
            text = QString("%1が%2へ%3のダメージ!!\n").arg(atk.getName()).arg(def.getName()).arg(dmg);

            if(def.getNowHp()<=0)
            {
                text += QString("%1は力尽きた...\n").arg(def.getName());
                def.changeAlive();
            }
            w->setText(text);
            w->turn->changeTurn();
        }else{
            /*ざぁこ*/
            w->setText(QString("%1には効果がなかった...").arg(def.getName()));
            w->turn->changeTurn();
        }
    }else{
        w->setText(QString("%1は力尽きています。").arg(def.getName()));
    }
    resetStatas();
}

void BattleSystem::areaAttack(Skill* s,Character& atk,std::vector<Character*>& def,MainWindow* w)
{

}

void BattleSystem::singleHeal(Skill& s,Character& atk,Character& def,MainWindow* w){
    calcBuff(atk,def);
    QString text = nullptr;
    if(def.getNowHp()>0){
        int heal = calcRateToAlly(s,atk);
        text = QString("%1が%2を%3回復！").arg(atk.getName()).arg(def.getName()).arg(heal);
        def.heal(def.getNowHp() + heal);
        if(def.getNowHp() > def.getMaxHp()){
            def.heal(def.getMaxHp());
        }
    }else{
        text = QString("%1は力尽きています。").arg(def.getName());
    }
    w->setText(text);
    w->turn->changeTurn();
    resetStatas();
}

void BattleSystem::singleBuff(Skill& s,Character& atk,Character& def,MainWindow* w)
{
    QString text = nullptr;
    if(def.getNowHp() > 0){
        qDebug() << "bs92";
        /*自身を対象にした場合1ターン延長(スキルを使ったターンをカウントしない)*/
        if(atk.getName() != def.getName()){
            def.setBuffList(new Buff((atk.getAtk()*s.getRate()),s.getTurn(),s.getImage(),BuffOrDebuff::Buff,BuffType::Atk));
        }else if(atk.getName() == def.getName()){
            def.setBuffList(new Buff((atk.getAtk()*s.getRate()),s.getTurn()+1,s.getImage(),BuffOrDebuff::Buff,BuffType::Atk));
        }

        qDebug() << "bs94";
        text = QString("%1は力がみなぎった!!").arg(def.getName());
        qDebug() << "bs96:skill's turn = " <<s.getTurn();
    }else{
        text = QString("%1は力尽きている...").arg(def.getName());
    }
    w->setText(text);
    w->turn->changeTurn();
}

void BattleSystem::areaBuff(Skill* s,Character& atk,std::vector<Character*>& def,MainWindow* w)
{

}

int BattleSystem::calcRateToEnemy(Skill& s,Character& atk,Character& def)
{
    int baseDmg = s.getBaseDmg();
    double rate = s.getRate();

    int dmg = baseDmg + (atkerAtk * rate) - defenderDef;

    return dmg;
}

int BattleSystem::calcRateToAlly(Skill& s,Character& atk){
    int baseDmg = s.getBaseDmg();
    double rate = s.getRate();

    int dmg = baseDmg + (atk.getAtk() * rate);

    return dmg;
}

void BattleSystem::calcBuff(Character& atk,Character& def)
{
    /*バフの計算*/
    std::vector<Buff*> atkBuffList = atk.getBuffList();
    std::vector<Buff*> defBuffList = def.getBuffList();
    atkerAtk = atk.getAtk();
    defenderDef = def.getDef();

    /*アタッカーのバフ計算*/
    for(int i=0;i<atkBuffList.size();i++){
        /*バフ*/
        if(atkBuffList[i]->getOr() == BuffOrDebuff::Buff){
            if(atkBuffList[i]->getType() == BuffType::Atk){
                atkerAtk += atkBuffList[i]->getBuff();
            }

        /*デバフ*/
        }else if(atkBuffList[i]->getOr() == BuffOrDebuff::Debuff){
            if(atkBuffList[i]->getType() == BuffType::Atk){
                atkerAtk -= atkBuffList[i]->getBuff();
            }
        }
    }

    /*ディフェンダーのバフ計算*/
    for(int i=0;i<defBuffList.size();i++){
        /*バフ*/
        if(defBuffList[i]->getOr() == BuffOrDebuff::Buff){
            if(defBuffList[i]->getType() == BuffType::Atk){
                defenderAtk += defBuffList[i]->getBuff();
            }else if(defBuffList[i]->getType() == BuffType::Def){
                defenderDef += defBuffList[i]->getBuff();
            }

        /*デバフ*/
        }else if(defBuffList[i]->getOr() == BuffOrDebuff::Debuff){
            if(defBuffList[i]->getType() == BuffType::Atk){
                defenderAtk -= defBuffList[i]->getBuff();
            }else if(defBuffList[i]->getType() == BuffType::Def){
                defenderDef -= defBuffList[i]->getBuff();
            }
        }
    }
}

void BattleSystem::resetStatas(){
    /*ステータスのリセット*/
    atkerAtk = 0;
    atkerDef = 0;
    defenderAtk = 0;
    defenderDef = 0;
}












