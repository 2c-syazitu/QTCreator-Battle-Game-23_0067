#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H

#include <vector>
#include "player.h"

class Player;
class Character;

class CharacterList
{
public:
    CharacterList();

    std::vector<Character*>& getCharacterList();
    void setCharacterList(Character* p);
    std::vector<Character*>& getAlivePlayerList();
    std::vector<Character*>& getAliveEnemyList();
    std::vector<Character*>& getDeadPlayerList();
    std::vector<Character*>& getDeadEnemyList();
    std::vector<Character*>& getPlayerList();
    std::vector<Character*>& getEnemyList();
    void updataList(Character* p);
    std::vector<Character*> getCharacterListAvoidMe(Character* me, const std::vector<Character*>& list);


private:
    std::vector<Character*> characterList;
    std::vector<Character*> alivePlayerList;
    std::vector<Character*> aliveEnemyList;
    std::vector<Character*> deadPlayerList;
    std::vector<Character*> deadEnemyList;
    std::vector<Character*> playerList;
    std::vector<Character*> enemyList;
    // std::vector<Player*>& list;
};



#endif // CHARACTERLIST_H
