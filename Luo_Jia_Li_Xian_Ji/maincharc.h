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
	maincharc(QObject *parent,int mv,int hp,int ml,int zl,int qs,int mn,int img);

	~maincharc();
	int movepoint, HP, meiLi, zhiLI, qinShang,img;
	int movepointMax = 150;
	int money;
	double per = 1;
	int times = 1;
	double recverPer=1;
	Select_course *selctedCourse;
	void recover();
	void showState();
private:
};
