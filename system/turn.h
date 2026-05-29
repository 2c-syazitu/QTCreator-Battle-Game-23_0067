#ifndef TURN_H
#define TURN_H

#include "player.h"
#include <random>

class MainWindow;

class Turn
{
public:
    Turn(CharacterList& list,MainWindow* w);

    Character* getTurnHolder();
    int getRound();
    void startTurn();
    void changeTurn();
    void sortBySpd();

private:
    int round;
    int turn;
    std::vector<int> spdList;
    std::vector<Character*> sortedBySpd;
    std::mt19937 gen;
    MainWindow* w;
    CharacterList& list;
    Character* turnHolder;

};

#endif // TURN_H
