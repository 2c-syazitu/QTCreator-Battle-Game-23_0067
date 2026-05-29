#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "battlesystem.h"
#include "./ui_mainwindow.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "turn.h"
#include "createcharacter.h"

class Skill;
class Turn;
class Player;
class Character;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // void updateHpLabel(int hp,character def);




private slots:
    void on_attackBut_clicked();
    void on_skillBut_clicked();
    // void on_pushButton_3_clicked();
    // void on_pushButton_4_clicked();

public:
    Turn* turn;
    void setText(const QString &text);
    void changeTurnLabel();
    BattleSystem sys;
    Skill* skill;


private:
    Ui::MainWindow *ui;

    std::vector<Character*> players;
    std::vector<Character*> playersAvoidMe;
    Character* turnHolder;
    QString updataText;
    CreateCharacter create;
    CharacterList& list;



};
#endif // MAINWINDOW_H
