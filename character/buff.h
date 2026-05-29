#ifndef BUFF_H
#define BUFF_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QObject>

namespace Ui {
class Buff;
}

enum class BuffType{
    Atk,
    Def,
    Spd,
    Luc
};

enum class BuffOrDebuff{
    Buff,
    Debuff
};

class Buff : public QWidget
{
    Q_OBJECT

public:
    explicit Buff(int buff,int turn,QPixmap pix,BuffOrDebuff b,BuffType type,QWidget *parent = nullptr);
    ~Buff();

    int getBuff();
    bool updateTurn();
    BuffType getType();
    BuffOrDebuff getOr();
    int getTurn();
    QLabel* getPix(int h,int size);
    void setPix();
    void labelResize(int h);
    void resizeEvent(QResizeEvent *event);



private:
    Ui::Buff *ui;

    QPixmap pix;
    int buff;
    int turn;
    BuffType type;
    BuffOrDebuff b;

    QLabel* buffIconLabel;
};

#endif // BUFF_H
