#include "select.h"
#include "ui_select.h"
#include "mainwindow.h"
#include "characterlist.h"
#include <iostream>

select::select(std::vector<Character*>& selectList,Character* me,MainWindow* w,Skill* skill,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::select)
    , selectList(selectList)
    // , targetList(listFormatting(selectList))//対象リスト
    // , targetList(targetList)
    , me(me)
    , w(w)
    , type(skill->getType())
    , side(skill->getSide())
    , range(skill->getRange())
{
    ui->setupUi(this);

    targetList = listFormatting(selectList);
    setBut(targetList);

}

select::~select()
{
    delete ui;
}

std::vector<Character*>& select::listFormatting(std::vector<Character*>& list){
    /*mode,side,rangeを参照して対象リストの整形、ボタンの配置*/
    qDebug() << "sl33";
    /*通常攻撃*/
    if(type == Type::Attack){
        for(int i=0;i<list.size();i++){
            if(list[i]->getType() == CharacterType::Enemy){
                targetList.push_back(list[i]);
            }
        }
    /*スキル*/
    }else{
        if(side == Side::Enemy){
            if(range == Range::Single){
                /*敵単体*/
                for(int i=0;i<list.size();i++){
                    if(list[i]->getType() == CharacterType::Enemy){
                        targetList.push_back(list[i]);
                    }
                }
            }else{
                /*敵全体*/

            }
        }else if(side == Side::Ally){
            if(range == Range::Single){
                for(int i=0;i<list.size();i++){
                    if(list[i]->getType() == CharacterType::Player){
                        targetList.push_back(list[i]);
                    }
                }
            }else if(range == Range::Area){

            }
        }
    }
    return targetList;
}

void select::setBut(std::vector<Character*>& list){
    this->targetList = list;
    for(int i=0;i<list.size();i++){
        /*対象のボタンの作成、配置*/
        QPushButton* btn = new QPushButton(QPushButton(list[i]->getName()));
        ui->selectLayout->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, [this, i](){
            this->on_pushButton_clicked(i);
        });

        /*HPが0以下のプレイヤーのボタンの背景をグレーに変更*/
        if(list[i]->getNowHp() <= 0){
            btn->setStyleSheet("background-color: gray;");
        }
    }
}

void select::on_pushButton_clicked(int i)
{
    /*親に対象を返す*/
    emit playerSelected(targetList[i]);
    this->close();
}

/*キャンセルボタンの作成、配置*/
void select::on_cancelBut_clicked()
{
    this->close();
}
