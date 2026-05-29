#include "character.h"

// Character::Character(const QString name,int hp, int mp,int atk,int def,int spd,int luk)
Character::Character(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type)
    :name(name)
    ,maxHp(hp)
    ,maxMp(mp)
    ,nowHp(hp)
    ,nowMp(mp)
    ,atk(atk)
    ,def(def)
    ,spd(spd)
    ,luk(luk)
    ,isAlive(true)
    ,type(type)


{
    /*生きてるよ*/
    isAlive = bool(true);
}

QString Character::getName(){
    return name;
}

int Character::getMaxHp(){
    return maxHp;
}

int Character::getMaxMp(){
    return maxMp;
}

int Character::getNowHp(){
    return nowHp;
}

int Character::getNowMp(){
    return nowMp;
}

int Character::getAtk(){
    return atk;
}

int Character::getDef(){
    return def;
}

int Character::getSpd(){
    return spd;
}

int Character::getLuk(){
    return luk;
}

bool Character::getAlive(){
    return isAlive;
}

SkillList* Character::getSkillList(){
    return skillList;
}

std::vector<Buff*>& Character::getBuffList(){
    return buffList;
}

CharacterType Character::getType(){
    return type;
}

Skill* Character::getAttack(){
    return attack;
}

void Character::setMaxHp(int hp){
    this->maxHp = hp;
}

void Character::setMaxMp(int mp){
    this->maxMp = mp;
}

void Character::calcDmg(int hp){
    // this->nowHp = hp;
}

void Character::heal(int hp){
    this->nowHp = hp;
}

void Character::setNowMp(int mp){
    this->nowMp = mp;
}

void Character::setAtk(int atk){
    this->atk = atk;
}

void Character::setDef(int def){
    this->def = def;
}

void Character::setSpd(int spd){
    this->spd = spd;
}

void Character::setLuk(int luk){
    this->luk = luk;
}

void Character::changeAlive(){

}

void Character::setSkillList(SkillList* skillList){
    this->skillList = skillList;
}

void Character::setCharacterList(CharacterList& list)
{
    this->characterList = &list;
}

void Character::setBuffList(Buff* buff){
    buffList.push_back(buff);
}

void Character::setMainWindow(MainWindow* w){
    this->w = w;
}

void Character::setAttack(Skill* attack){
    this->attack = attack;
}

void Character::eraseBuff(int i){

}

void Character::loadAlg(){

}
