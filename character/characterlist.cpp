#include "CharacterList.h"
#include "player.h"
#include <iostream>
#include "character.h"



CharacterList::CharacterList() {

}

/*CharacterListにcharacterを追加*/
void CharacterList::setCharacterList(Character* p){
    /*全体リスト*/
    if(std::find(characterList.begin(),characterList.end(),p) == characterList.end()){
        characterList.push_back(p);
    }

    if(p->getAlive()){
        if(p->getType() == CharacterType::Player){
            /*プレイヤーの生存者リスト*/
            if(std::find(alivePlayerList.begin(),alivePlayerList.end(),p) == alivePlayerList.end()){
                alivePlayerList.push_back(p);
            }
        }else{
            /*エネミーの生存者リスト*/
            if(std::find(aliveEnemyList.begin(),aliveEnemyList.end(),p) == aliveEnemyList.end()){
                aliveEnemyList.push_back(p);
            }
        }
    }else{
        if(p->getType() == CharacterType::Player){
            /*プレイヤーの死亡者リスト*/
            if(std::find(deadPlayerList.begin(),deadPlayerList.end(),p) == deadPlayerList.end()){
                deadPlayerList.push_back(p);
            }
        }else{
            /*エネミーの死亡者リスト*/
            if(std::find(deadEnemyList.begin(),deadEnemyList.end(),p) == deadEnemyList.end()){
                deadEnemyList.push_back(p);
            }
        }
    }
    if(p->getType() == CharacterType::Player){
        /*プレイヤーの全体リスト*/
        playerList.push_back(p);
    } else {
        /*エネミーの全体リスト*/
        enemyList.push_back(p);
    }
}

std::vector<Character*>& CharacterList::getCharacterList() {
    return characterList;
}

std::vector<Character*>& CharacterList::getAlivePlayerList(){
    return alivePlayerList;
}

std::vector<Character*>& CharacterList::getAliveEnemyList(){
    return aliveEnemyList;
}

std::vector<Character*>& CharacterList::getDeadPlayerList(){
    return deadPlayerList;
}

std::vector<Character*>& CharacterList::getDeadEnemyList(){
    return deadEnemyList;
}

std::vector<Character*>& CharacterList::getPlayerList(){
    return playerList;
}

std::vector<Character*>& CharacterList::getEnemyList(){
    return enemyList;
}


/*aliveListとdeadListの更新*/
void CharacterList::updataList(Character* p){
    if(p->getType() == CharacterType::Player){
        if(p->getAlive()){
            if(std::find(deadPlayerList.begin(),deadPlayerList.end(),p) != deadPlayerList.end()){
                auto it = std::find(deadPlayerList.begin(),deadPlayerList.end(),p);
                deadPlayerList.erase(it);
            }
            if(std::find(alivePlayerList.begin(),alivePlayerList.end(),p) == alivePlayerList.end()){
                alivePlayerList.push_back(p);
            }
        }else{
            if(std::find(alivePlayerList.begin(),alivePlayerList.end(),p) != alivePlayerList.end()){
                auto it = std::find(alivePlayerList.begin(),alivePlayerList.end(),p);
                alivePlayerList.erase(it);
            }
            if(std::find(deadPlayerList.begin(),deadPlayerList.end(),p) == deadPlayerList.end()){
                deadPlayerList.push_back(p);
            }
        }
    }else{
        if(p->getAlive()){
            if(std::find(deadEnemyList.begin(),deadEnemyList.end(),p) != deadEnemyList.end()){
                auto it = std::find(deadEnemyList.begin(),deadEnemyList.end(),p);
                deadEnemyList.erase(it);
            }
            if(std::find(aliveEnemyList.begin(),aliveEnemyList.end(),p) == aliveEnemyList.end()){
                aliveEnemyList.push_back(p);
            }
        }else{
            if(std::find(aliveEnemyList.begin(),aliveEnemyList.end(),p) != aliveEnemyList.end()){
                auto it = std::find(aliveEnemyList.begin(),aliveEnemyList.end(),p);
                aliveEnemyList.erase(it);
            }
            if(std::find(deadEnemyList.begin(),deadEnemyList.end(),p) == deadEnemyList.end()){
                deadEnemyList.push_back(p);
            }
        }
    }

}

std::vector<Character*> CharacterList::getCharacterListAvoidMe(Character* me, const std::vector<Character*>& list)
{
    std::vector<Character*> avoidList;
    for (auto player : list) {
        if (player != me) {  // 自分以外
            avoidList.push_back(player);
        }
    }
    return avoidList;  // 値で返す（コピーまたはムーブ）
}

