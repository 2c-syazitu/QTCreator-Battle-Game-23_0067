#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>
#include <buff.h>


class SkillList;
class CharacterList;
class MainWindow;
class Skill;

enum class CharacterType {
    Player,

    Enemy
};

class Character
{
public:
    // Character(const QString name,int hp, int mp,int atk,int def,int spd,int luk);
    Character(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type);
    virtual ~Character() {}

    QString getName();
    int getMaxHp();
    int getMaxMp();
    int getNowHp();
    int getNowMp();
    int getAtk();
    int getDef();
    int getSpd();
    int getLuk();
    bool getAlive();
    SkillList* getSkillList();
    std::vector<Buff*>& getBuffList();
    CharacterType getType();
    Skill* getAttack();

    void setMaxHp(int);
    void setMaxMp(int);
    virtual void calcDmg(int);
    virtual void heal(int);
    virtual void setNowMp(int);
    void setAtk(int);
    void setDef(int);
    void setSpd(int);
    void setLuk(int);
    virtual void changeAlive();
    void setCharacterList(CharacterList& list);
    virtual void setBuffList(Buff* buff);
    void setSkillList(SkillList* skillList);
    void setMainWindow(MainWindow* w);
    void setAttack(Skill* attack);
    virtual void eraseBuff(int i);
    virtual void loadAlg();





public:
    QString name;
    int maxHp;
    int maxMp;
    int nowHp;
    int nowMp;
    int atk;
    int def;
    int spd;
    int luk;
    bool isAlive;
    SkillList* skillList;
    CharacterList* characterList;
    MainWindow* w;
    CharacterType type;
    std::vector<Buff*> buffList;
    Skill* attack;
};

#endif // CHARACTER_H
