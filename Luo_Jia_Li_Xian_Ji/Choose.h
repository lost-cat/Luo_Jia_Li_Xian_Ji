#pragma once

#include <QWidget>
#include "ui_Choose.h"
#include"maincharc.h"
#include<qpushbutton.h>
#include"BigAssignmentPP.h"
#include"TeachingBuilding.h"
#include"luo_jia_shan.h"
#include"huo_dong_zhong_xin.h"
#include"tu_shu_guan.h"
#include"han_jie.h"
class Choose : public QWidget
{
	Q_OBJECT

public:
	Choose(maincharc *mm,QWidget *parent = Q_NULLPTR);
	~Choose();
	int week;
	int day;
	BigAssignmentPP* carteen;
	TeachingBuilding* teachingBuilding;
	luo_jia_shan* san;
	huo_dong_zhong_xin* huo;
	tu_shu_guan* tu;
	han_jie* han;
signals:
	void backToHome();

private:
	Ui::Choose ui;
};
