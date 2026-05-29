#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

class MainWindow;
#include "character.h"
#include "player.h"
#include "skill.h"
#include "buff.h"



class BattleSystem
{
public:
    BattleSystem();

public:
    // void attack(character& atk, character& def, MainWindow *window);
    void attack(Skill& s,Character& atk, Character& def,MainWindow* w);
    void singleAttack(Skill& s,Character& atk, Character& def,MainWindow* w);
    void areaAttack(Skill* s,Character& atk,std::vector<Character*>& def,MainWindow* w);
    void singleHeal(Skill& s,Character& atk,Character& def,MainWindow* w);
    void singleBuff(Skill& s,Character& atk, Character& def,MainWindow* w);
    void areaBuff(Skill* s,Character& atk,std::vector<Character*>& def,MainWindow* w);
    int calcRateToEnemy(Skill& s,Character& atk,Character& def);
    int calcRateToAlly(Skill& s,Character& atk);
    void calcBuff(Character& atk,Character& def);
    void resetStatas();

private:
    int atkerAtk;
    int atkerDef;
    int defenderAtk;
    int defenderDef;/*
    int baseDmg;
    double rate;*/

};

#endif // BATTLESYSTEM_H
