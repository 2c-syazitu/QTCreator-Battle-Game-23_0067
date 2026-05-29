#include "player.h"
#include "select.h"
#include "ui_player.h"
#include "characterlist.h"
#include <iostream>

Player::Player(const QString name,int hp, int mp,int atk,int def,int spd,int luk,CharacterType type,QWidget *parent)
    : QWidget(parent)
    , Character(name,hp,mp,atk,def,spd,luk,type)
    , ui(new Ui::Player)
{
    ui->setupUi(this);

    emptyLabel = new QLabel();
    // QPixmap pix(":/character/playerImage/power.png");
    // emptyLabel->setPixmap(pix);
    // emptyLabel->setScaledContents(true);

    qDebug() << "pl21" ;
    ui->buffIcon->addWidget(emptyLabel);
    ui->nameLabel->setText(name);
    ui->hpLabel->setText(QString("HP: %1").arg(hp));
    ui->mpLabel->setText(QString("MP: %1").arg(mp));

}

void Player::calcDmg(int dmg)
{
    /*HPが0以下であればHPに0をセット*/
    nowHp -= dmg;

    if(nowHp <= 0){
        ui->hpLabel->setText(QString("HP: %1").arg(0));
        nowHp = 0;
        this->changeAlive();
    }else{
        ui->hpLabel->setText(QString("HP: %1").arg(nowHp));
        // nowHp = nowHp;
    }
}

void Player::heal(int i){
    nowHp += i;

    if(nowHp > maxHp){
        ui->hpLabel->setText(QString("HP: %1").arg(maxHp));
        nowHp = maxHp;
    }else{
        ui->hpLabel->setText(QString("HP: %1").arg(nowHp));
    }
}

void Player::setNowMp(int mp)
{
    ui->mpLabel->setText(QString("MP: %1").arg(mp));
    nowMp = mp;
}

void Player::changeAlive()
{
    /*生き死にを逆に変更
      生きてる場合は背景を白に
      死んでる場合はグレーに変更*/
    if(isAlive){
        isAlive = false;

        ui->nameLabel->setStyleSheet("color: red;");
    }else{
        isAlive = true;
        ui->nameLabel->setStyleSheet("color: black;");
    }
    characterList->updataList(this);
    if(!isAlive){
        qDebug()<< this->getName() << "is dead";
    }

}

void Player::setBuffList(Buff* buff){
    qDebug() << "pl125 buffIconLablSize = " << this->size();
    qDebug() << "pl125 buffIconLablSize = " << ui->nameLabel->size();
    qDebug() << "pl125 buffIconLablSize = " << ui->hpLabel->size();
    qDebug() << "pl125 buffIconLablSize = " << ui->mpLabel->size();
    qDebug() << "pl125 buffIconLablSize = " << this->size() - ui->nameLabel->size() - ui->hpLabel->size() - ui->mpLabel->size();

    buffList.push_back(buff);
    /*レイアウトにラベルを配置*/
    ui->buffIcon->addWidget(buff);
    // ui->no1->setPixmap(buff->getPix());

    buff->setStyleSheet("background-color: red;");

    /*バフリストにバフを追加*/

}

void Player::eraseBuff(int i){
    buffList.erase(buffList.begin() + i);
    buffList[i]->hide();
}

void Player::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    // // 上段エリアの高さを取得
    // int h = layout()->itemAt(0)->geometry().height();

    // // 正方形にする（小さくしたいなら 0.8 倍など）
    // int size = h * 0.8;

    // buffLabel->setFixedSize(h, h);

    // if (!->pix.isNull()) {
    // //     buffLabel->setPixmap(
    // //         pix.scaled(size, size,
    // //                    Qt::KeepAspectRatio,
    // //                    Qt::SmoothTransformation)
    // //         );
    // }
    // QPixmap scaled = .scaled(
    //     ui->buffIconLabel->size(),
    //     Qt::KeepAspectRatio,
    //     Qt::SmoothTransformation
    //     );
    // ui->buffIconLabel->setPixmap(scaled);

}


Player::~Player()
{
    delete ui;
}
