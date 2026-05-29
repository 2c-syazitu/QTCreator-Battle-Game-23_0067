#include "createcharacter.h"
#include "player.h"
#include "characterlist.h"
#include "skilllist.h"
#include <iostream>

CreateCharacter::CreateCharacter() {
    /*                             名前, HP, MP, ATK,DEF,SPD,LUK*/
    qDebug() << "cc9";
    list.setCharacterList(new Player("Hwei",   100,12,20, 10, 12, 10,CharacterType::Player));
    qDebug() << "cc11";
    list.setCharacterList(new Player("Aurora", 100,13,20, 10, 12, 10,CharacterType::Player));
    qDebug() << "c13";
    list.setCharacterList(new Player("Zyra",   100,14,20, 10, 12, 10,CharacterType::Player));
    qDebug() << "cc15";
    list.setCharacterList(new Player("Skarner",100,15,20, 10, 12, 10,CharacterType::Player));
    qDebug() << "cc17";

    list.setCharacterList(new Enemy("Doragon",100,10,20,10,120,10,CharacterType::Enemy));
    list.setCharacterList(new Enemy("Doragon",100,10,20,10,102,10,CharacterType::Enemy));
    list.setCharacterList(new Enemy("Doragon",100,10,20,10,1,10,CharacterType::Enemy));

}
