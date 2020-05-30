#pragma once

#include <QWidget>
#include "ui_Select_course.h"

class Select_course : public QWidget
{
	Q_OBJECT

public:
	Select_course(int num,QString name,int pro,QString Rec, QWidget *parent = Q_NULLPTR);
	~Select_course();
	int getNum() { return this->num; };
	QString getName() { return this->name; };
	int getPro() { return this->pro; };
	void addPro(int times,int per) {
		for (int i = 0; i < times; i++)
		{
			 pro += 5*per;
		}
	}
	QString getWeakPoint() { return this->recommendState; };
private:
	Ui::Select_course ui;
	int num;
	QString name;
	int pro;
	QString  recommendState;
};
