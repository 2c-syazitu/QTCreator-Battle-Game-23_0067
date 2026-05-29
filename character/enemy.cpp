#include "enemy.h"
#include "ui_Enemy.h"

Enemy::Enemy(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type,QWidget *parent)
    : QWidget(parent)
    , Character(name,hp,mp,atk,def,spd,luk,type)
    // ,gen(std::random_device{}())
    , ui(new Ui::Enemy)
{
    ui->setupUi(this);

    /*画像の表示*/
    QPixmap pix(":/character/enemyImage/doragon.png");
    ui->imageLabel->setPixmap(pix);
    ui->imageLabel->setScaledContents(true);

    /*名前の表示*/
    ui->nameLabel->setText(name);

    // QVBoxLayout *layOut = new QVBoxLayout(this);
    // setLayout(layOut);
}


void Enemy::calcDmg(int dmg){
    /*ダメージの反映*/
    this->nowHp -= dmg;

    /*HPが0以下の場合HPを0にセット
      生死を反転させる*/
    if(nowHp <= 0){
        nowHp = 0;
        this->changeAlive();
    }
}

void Enemy::heal(int i){
    this->nowHp += i;

    if(nowHp > maxHp){
        nowHp = maxHp;
    }
}

void Enemy::setNowMp(int mp){

}

void Enemy::changeAlive(){
    /*生死の反転*/

    if(isAlive){
        /*死んだ場合は、画像と名前を非表示*/
        isAlive = false;
        ui->imageLabel->hide();
        ui->nameLabel->clear();
    }else{
        /*生き返った場合は、画像と名前を再表示*/
        isAlive = true;
        ui->imageLabel->show();
        ui->nameLabel->setText(name);
    }
}

void Enemy::loadAlg(){
    /*攻撃対象選択のための乱数を生成*/
    qDebug() << "en59";
    std::random_device rd;
    std::mt19937 gen(rd());

    /*プレイヤーリストの取得*/
    std::vector<Character*>& list = characterList->getAlivePlayerList();
    /*0~リストの最大の要素数までの乱数の生成*/
    std::uniform_int_distribution<int> dist(0, list.size()-1);
    int n = dist(gen);
    if(!list.empty()){
        qDebug() << "en79";
        sys.attack(*attack,*this,*list[n],w);
    }
}

void Enemy::setMainWindowAndBattleSystem(MainWindow* w, BattleSystem sys){
    this->w = w;
    this->sys = sys;
}

Enemy::~Enemy()
{
    delete ui;
}
