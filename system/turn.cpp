#include "turn.h"
#include <algorithm>
#include "characterlist.h"
#include "mainwindow.h"



Turn::Turn(CharacterList& list,MainWindow* w)
    :round(1)
    ,turn(0)
    ,gen(std::random_device{}())
    ,w(w)
    ,list(list)
{
    this->sortedBySpd = list.getCharacterList();
    sortBySpd();
    Character* turnHolder = this->getTurnHolder();
}


Character* Turn::getTurnHolder(){
    return sortedBySpd[turn];
}

int Turn::getRound(){
    return round;
}

void Turn::startTurn(){
    /*俺のターン!ドロー!!!!*/
    turnHolder = this->getTurnHolder();



    w->changeTurnLabel();
    if (turnHolder->getType() == CharacterType::Enemy) {
        turnHolder->loadAlg();
    }
}


void Turn::changeTurn(){
    /*生存者リストがともに空出ないなら*/
    if((!list.getAlivePlayerList().empty()) && (!list.getAliveEnemyList().empty())){

        /*バフのターン処理*/
        for(int i=turnHolder->getBuffList().size()-1;i>=0;i--){
            qDebug() << "tu48:skill's turn = " <<turnHolder->getBuffList()[i]->getTurn();
            /*バフの残りターンが0以上の場合true*/
            if(!turnHolder->getBuffList()[i]->updateTurn()){
                qDebug() << "tu51:skill's turn = " <<turnHolder->getBuffList()[i]->getTurn();
                turnHolder->getBuffList().erase(turnHolder->getBuffList().begin() + i);
                // c->eraseBuff(i);
                qDebug() << "tu34:buff erased!!" << turnHolder->getBuffList().size();
            }
        }

        /*ターンの進行
          各ラウンドに各プレイヤーは1ターンずつ
          ランド開始時に素早さでソート*/
        turn = (turn + 1) % sortedBySpd.size();
        if(turn >= sortedBySpd.size()){
            turn = 0;
            round ++;
            sortBySpd();
        }

        /*死亡しているプレイヤーはスキップ*/
        while(!sortedBySpd[turn]->getAlive()){
            if(turn >= sortedBySpd.size()){
                turn = 0;
                round ++;
                sortBySpd();
            }
            turn++;
        }
        /*テスト*/
        qDebug() <<"changeTurn";
        for(int i=0;i<sortedBySpd.size();i++){
            if(sortedBySpd[i]->getAlive()){
                qDebug() << sortedBySpd[i]->getNowHp()
                         << sortedBySpd[i]->getName().toStdString()
                         <<"------------";
            }
        }
        w->changeTurnLabel();
        this->startTurn();
    }else {
        /*死んでしまうとは情けない...*/
        w->setText("全滅した！");
    }
}


void Turn::sortBySpd(){
    /*早い順にソート*/
    std::sort(sortedBySpd.begin(), sortedBySpd.end(),
              [](Character* a, Character* b) {
                  return a->getSpd() > b->getSpd();
              });


    /*等速を別のリストにコピー*/
    std::vector<Character*> sameSpdList;
    int i=0,j=1;
    while(i < sortedBySpd.size()-1){
        if(sortedBySpd[i]->getSpd() == sortedBySpd[i+j]->getSpd()){
            sameSpdList.push_back(sortedBySpd[i]);
            while(sortedBySpd[i]->getSpd() == sortedBySpd[i+j]->getSpd()){
                sameSpdList.push_back(sortedBySpd[i+j]);
                if(sortedBySpd.size()-1 == i+j){
                    break;
                }
                j++;
            }
            /*ランダム処理*/
            std::vector<int> randomInt;
            for (int i = 0; i < sameSpdList.size(); ++i) {
                randomInt.push_back(i);
            }
            std::shuffle(randomInt.begin(), randomInt.end(), gen);
            for(int random=0;random<randomInt.size();random++){
                sortedBySpd[i + random] = sameSpdList[randomInt[random]];
            }
            sameSpdList.clear();
        }
        i+=j;
        j=1;
    }
    for(int i=0;i<sortedBySpd.size();i++){
        qDebug() << sortedBySpd[i]->getName().toStdString() <<"*******************";
    }
}

