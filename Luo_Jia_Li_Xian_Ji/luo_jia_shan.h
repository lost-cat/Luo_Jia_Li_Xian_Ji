#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_luo_jia_shan.h"
#include "maincharc.h"

class luo_jia_shan : public QMainWindow
{
	Q_OBJECT

public:
	luo_jia_shan(maincharc* mm, QWidget *parent = Q_NULLPTR);
signals:
	void	back();
private:
	Ui::luo_jia_shanClass ui;
};
