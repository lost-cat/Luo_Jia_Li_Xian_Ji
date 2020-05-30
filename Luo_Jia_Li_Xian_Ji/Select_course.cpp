#include "Select_course.h"

Select_course::Select_course(int num, QString name, int pro, QString Rec, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->num = num;
	this->name = name;
	this->pro = pro;
	this->recommendState = Rec;




}

Select_course::~Select_course()
{
}
