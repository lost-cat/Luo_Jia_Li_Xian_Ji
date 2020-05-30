#pragma once

#include <QWidget>
#include "ui_Choose.h"
#include"maincharc.h"
#include<qpushbutton.h>
class Choose : public QWidget
{
	Q_OBJECT

public:
	Choose(maincharc *mm,QWidget *parent = Q_NULLPTR);
	~Choose();
	int week;
	int day;
signals:
	void backToHome();

private:
	Ui::Choose ui;
};
