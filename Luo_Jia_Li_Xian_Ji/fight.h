#pragma once

#include <QWidget>
#include "ui_fight.h"
#include"maincharc.h"
#include "Select_course.h"
class Select_course;
class fight : public QWidget
{
	Q_OBJECT

public:
	fight(maincharc *man,QWidget *parent = Q_NULLPTR);	 //��man����fight��
	~fight();
//	static int count;
	void courseChange(Select_course *);
	int day = 1;
	double per = 1;
	int times =1;
signals:
	void backToMainscence();
	void feiqingwangshi();
private:
	Ui::fight ui;
	Select_course *m1;
};
