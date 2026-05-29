#include "buff.h"
#include "ui_buff.h"

Buff::Buff(int buff,int turn,QPixmap pix,BuffOrDebuff b,BuffType type,QWidget *parent)
    : QWidget(parent)
    ,buff(buff)
    ,turn(turn)
    ,pix(pix)
    ,type(type)
    ,b(b)
    ,ui(new Ui::Buff)
{
    ui->setupUi(this);

    qDebug() << "bf14wwwwwwwwwwww" << pix;
    // ui->buffIconLabel->setPixmap(pix.scaled(
    //     1,1
    //     )
    // );
    ui->buffIconLabel->setPixmap(pix);
    ui->buffIconLabel->setScaledContents(false);
    qDebug() << pix.size();


    // setLayout(buffLayout);
}

int Buff::getBuff(){
    return buff;
}

bool Buff::updateTurn(){
    /*バフのターン処理*/
    bool tf;
    turn --;
    if(turn>0){
        tf = true;
    }else if(turn <= 0){
        ui->buffIconLabel->hide();
        tf = false;
    }
    return tf;
}

BuffType Buff::getType(){
    return type;
}

BuffOrDebuff Buff::getOr(){
    return b;
}

int Buff::getTurn(){
    return turn;
}

QLabel* Buff::getPix(int h,int size){
    // qDebug() << "bf38";
    // if (pix.isNull()) {
    //     qDebug() << "QPixmap 読み込み失敗";
    // } else {
    //     qDebug() << "QPixmap 読み込み成功"
    //              << pix.size();
    // }
    // qDebug() << "bf45";
    // ui->buffIconLabel->setPixmap(
    //     pix.scaled(
    //         h,
    //         h,
    //         Qt::KeepAspectRatio,
    //         Qt::SmoothTransformation
    //         )
    //     );
    // qDebug() << "bf58";
    // ui->buffIconLabel->setProperty("numOfEle",size);
    // qDebug() << "bf60";
    // return buffIconLabel;
}

void Buff::setPix(){
    ui->buffIconLabel->setPixmap(pix);
}

void Buff::labelResize(int h){

}

void Buff::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    if (!pix.isNull()) {
        // ラベルの現在のサイズ（レイアウトによって決定されたサイズ）に合わせて
        // 比率を維持したまま画像をリサイズして表示
        QPixmap scaled = pix.scaled(
            this->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
            );
        ui->buffIconLabel->setPixmap(scaled);
        qDebug() << "bf100 buffLayoutSize" << this->size();
        qDebug() << "bf101 resizedSize:" << pix;
        qDebug() << "bf101 resizedSize:" << scaled;
    }
}

Buff::~Buff()
{
    delete ui;
}
