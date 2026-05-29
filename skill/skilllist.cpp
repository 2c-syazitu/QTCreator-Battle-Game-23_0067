#include "skilllist.h"
#include "ui_skilllist.h"
#include "select.h"

SkillList::SkillList(std::vector<Character*> selectList,Character* me,MainWindow* w,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SkillList)
    , me(me)
    , w(w)
{
    ui->setupUi(this);
    setSkillBut();
}

SkillList::~SkillList()
{
    delete ui;
}

/*スキルをリストに追加、ボタンの配置*/
void SkillList::setSkillList(Skill* s)
{
    if(std::find(skillList.begin(),skillList.end(),s) == skillList.end())
    {
        skillList.push_back(s);
        this->setSkillBut();
    }
}

std::vector<Skill*>& SkillList::getSkillList()
{
    return skillList;
}

/*スキルボタンの配置、設定*/
void SkillList::setSkillBut(){
    /*既存のスキルの名前の確認*/
    QSet<QString> existingNames;
    for (int j = 0; j < ui->SkillLabel->count(); ++j)
    {
        QWidget* widget = ui->SkillLabel->itemAt(j)->widget();
        if (auto btn = qobject_cast<QPushButton*>(widget))
        {
            existingNames.insert(btn->text());
        }
    }

    // 新しいスキルボタンを追加
    for (int i = 0; i < skillList.size(); i++)
    {
        Skill* skill = skillList[i];
        QString skillName = skill->getName();
        if (existingNames.contains(skillName))
        {
            continue;
        }

        QPushButton* btn = new QPushButton(skillName);
        btn->setProperty("skillPtr", QVariant::fromValue(skillList[i]));

        ui->SkillLabel->addWidget(btn);
        connect(btn, &QPushButton::clicked, this, [this,skill](){
            this->on_pushButton_clicked(skill);
        });
    }
}


/*スキルを取得済みの場合のみ標示*/
void SkillList::on_pushButton_clicked(Skill* skill)
{
    /*親に対象を返す*/
    emit playerSelected(skill);
    this->close();
}

/*キャンセルボタンの作成、配置*/
void SkillList::on_cansellBut_clicked()
{
    this->close();
}
