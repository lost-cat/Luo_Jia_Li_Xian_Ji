#pragma once

#include <QObject>
class Select_course;
/*
class Weapon
{
public:
	Weapon();
	~Weapon();
	int	 atk;
	int  def;
	int  Hp;
	int   ats;
private:
	
};

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}*/
class maincharc : public QObject
{
	Q_OBJECT

public:
	maincharc(QObject *parent,int mv,int hp,int ml,int zl,int qs,int mn);

	~maincharc();
	int movepoint, HP, meiLi, zhiLI, qinShang;
	int movepointMax = 150;
	int money;
	Select_course *selctedCourse;
	//Weapon weapon;
	void recover();
	
private:
};
