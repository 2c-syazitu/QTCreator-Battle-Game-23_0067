#ifndef SKILLLIST_H
#define SKILLLIST_H

#include <QWidget>

#include "skill.h"
// #include "player.h"
#include "mainwindow.h"
#include "select.h"
#include "battlesystem.h"

class Player;
class Character;

namespace Ui {
class SkillList;
}

class SkillList : public QDialog
{
    Q_OBJECT

public:
    explicit SkillList(std::vector<Character*>,Character*,MainWindow*,QWidget *parent = nullptr);
    ~SkillList();


public:
    void setSkillList(Skill*);
    std::vector<Skill*>& getSkillList();
    void setSkillBut();
    void on_pushButton_clicked(Skill* skill);
    BattleSystem sys;

signals:
    void playerSelected(Skill* target);

private:
    Ui::SkillList *ui;

    std::vector<Skill*> skillList;
    Character* me;
    MainWindow* w;


private slots:
    void on_cansellBut_clicked();

};
#endif // SKILLLIST_H
