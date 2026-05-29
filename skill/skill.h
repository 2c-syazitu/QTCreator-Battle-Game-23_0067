#ifndef SKILL_H
#define SKILL_H

#include <QWidget>
#include "player.h"
// #include "mainwindow.h"

class MainWindow;

enum class Type{
    Attack,
    Skill
};

enum class Range{
    Single,
    Area
};

enum class Side{
    Ally,
    Enemy
};

class Skill : public QWidget
{
    Q_OBJECT

public:
    // Skill(QString name, int cost,Player* user,Player* target);
    Skill(QString name, int cost,int baseDmg,double rate,Type type, Range range,Side side);

    virtual ~Skill() = default;

    QString getName();
    int getCost();
    int getBaseDmg();
    double getRate();
    Type getType();
    Range getRange();
    Side getSide();
    // Player* getUser();
    // Player* getTarget();

    virtual void activate(Character& atk,Character& def,MainWindow* w);
    virtual int getTurn();
    virtual QPixmap getImage();

private:
    QString name;
    int cost;
    int baseDmg;
    double rate;
    Type type;
    Range range;
    Side side;
};

#endif // SKILL_H
