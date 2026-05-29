#ifndef SELECT_H
#define SELECT_H

#include <QDialog>

#include "battlesystem.h"
#include "character.h"
#include "player.h"
#include "skill.h"

enum class SelectMode {
    /*通常攻撃*/
    Attack,
    /*スキル*/
    Skill
};

/*スキルの対象範囲*/
enum class TargetRange {
    /*単体*/
    Single,
    /*全体*/
    Area
};

/*スキルの対象*/
enum class TargetSide{
    /*敵*/
    Enemy,
    /*味方*/
    Ally
};

namespace Ui {
class select;
}

class select : public QDialog
{
    Q_OBJECT

public:
    explicit select(std::vector<Character*>& list,Character* me,MainWindow* w,Skill* skill,QWidget *parent = nullptr);
    ~select();

signals:
    void playerSelected(Character* target);

private slots:
    void on_pushButton_clicked(int);
    void on_cancelBut_clicked();

public:
    void setBut(std::vector<Character*>&);
    std::vector<Character*>& listFormatting(std::vector<Character*>& list);

private:
    Ui::select *ui;

    // character me;
    std::vector<Character*>& selectList;
    std::vector<Character*> targetList;
    BattleSystem sys;
    MainWindow *w;
    Character* me;
    Type type;
    Side side;
    Range range;
};



#endif // SELECT_H
