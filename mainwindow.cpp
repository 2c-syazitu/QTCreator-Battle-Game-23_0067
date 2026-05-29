#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "characterlist.h"
#include "select.h"
#include "skilllist.h"
#include "icesword.h"
#include "heal.h"
#include "atkbuff.h"
#include "attack.h"
#include "skilllist.h"
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , list(create.list)
    , sys(sys)
{
    ui->setupUi(this);

    /*playerのリストを作成*/
    players = list.getCharacterList();

    /*ターンの初期設定*/
    this->turn = new Turn (list,this);
    turnHolder = turn->getTurnHolder();

    ui->turnLabel->setText(QString("%1のターン\n").arg(turn->getTurnHolder()->getName()));

    for(int i=0;i<players.size();i++){
        /*各プレイヤーにプレイヤーリストを渡す*/
        players[i]->setCharacterList(list);
        /*各プレイヤーにスキルリストを渡す*/
        players[i]->setSkillList(new SkillList(players,players[i],this));
        /*通常攻撃の設定*/
        players[i]->setAttack(new Attack("攻撃",0,0,1.0,Type::Attack,Range::Single,Side::Enemy));
        /*スキルの仮置き*/
        players[i]->getSkillList()->setSkillList(new IceSword("アイスソード",10,10,1.0,Type::Skill,Range::Single,Side::Enemy));
        players[i]->getSkillList()->setSkillList(new Heal("ヒール",10,10,1.0,Type::Skill,Range::Single,Side::Ally));
        players[i]->getSkillList()->setSkillList(new AtkBuff("バイキルト",10,10,1.0,1,Type::Skill,Range::Single,Side::Ally));

    }

    /*プレイヤーのレイアウト設定*/
    for(int i=0;i<players.size();i++){
        if (Player* p = dynamic_cast<Player*>(players[i])) {
            ui->playerLayout->addWidget(p);
        }
        if (Enemy* p = dynamic_cast<Enemy*>(players[i])) {
            ui->enemyLayout->addWidget(p);
            /*Enemyにmainwindowとbattlesystemを渡す*/
            p->setMainWindowAndBattleSystem(this,sys);
        }
    }


    turn->startTurn();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_attackBut_clicked()
{
    /*ターンの保持者*/
    Character *p = turn->getTurnHolder();
    /*通常攻撃の生成*/
    Skill* attack = p->getAttack();
    select *sel = new select(players,turn->getTurnHolder(),this,attack);

    /*selで選択されたプレイヤー(target)に対して攻撃*/
    connect(sel, &select::playerSelected, this, [this,p,attack](Character* target){
        qDebug() << "mw62選択されたプレイヤー:" << target->getName();

        /*battleSystemで攻撃*/
        sys.attack(*attack,*p, *target, this);
    });
    sel->exec();
}


void MainWindow::on_skillBut_clicked()
{
    Character *p = turn->getTurnHolder();
    SkillList* skillList = p->getSkillList();
    skill = nullptr;

    /*選択されたスキルをskillに代入*/
    connect(skillList, &SkillList::playerSelected, this, [this,p](Skill* s){
        skill = s;
    });
    skillList->exec();

    if(!skill){
        return;
    }else{
        qDebug() << "--------------" <<skill->getName();
    }
    if(p->getNowMp() > skill->getCost()){
        /*skillの攻撃対象を表示*/
        select *sel = new select(players,turn->getTurnHolder(),this,skill);


        connect(sel, &select::playerSelected, this, [this,p](Character* target){
            qDebug() << "mw105選択されたプレイヤー:" << target->getName();

            /*battleSystemで攻撃*/
            qDebug() <<"mw113";
            skill->activate(*p, *target, this);
            qDebug() << "mw115";
            /*MPの消化*/
            p->setNowMp(p->getNowMp() - skill->getCost());
        });
        sel->exec();
        qDebug() << "mw118";
    }else{
        this->setText("MPが足りません...");
    }
}


void MainWindow::setText(const QString &text)
{
    ui->textLabel->setText(text);
    QTimer::singleShot(2000,this,[this](){
        ui->textLabel->clear();
    });
}

/*遅延*/
void MainWindow::changeTurnLabel()
{
    QTimer::singleShot(2000,this,[this](){
        ui->turnLabel->setText(QString("%1のターン\n").arg(turn->getTurnHolder()->getName()));
    });
}



