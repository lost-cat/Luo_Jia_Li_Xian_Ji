#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Luo_Jia_Li_Xian_Ji.h"
#include<qtimer.h>
#include"shop.h"
#include"fight.h"
#include"Choose.h"
#include"skill.h"

class Luo_Jia_Li_Xian_Ji : public QMainWindow
{
	Q_OBJECT

public:
	Luo_Jia_Li_Xian_Ji(QWidget *parent = Q_NULLPTR);
	fight *f ;
	maincharc*mm;
	shop* sh;
	Choose* c;
	skill* sk;
	int week, day;
	void	paintEvent(QPaintEvent*);
	void sleep();
private:
	Ui::Luo_Jia_Li_Xian_JiClass ui;
};
