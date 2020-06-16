#pragma once

#include <QtWidgets/QMainWindow>
#include "maincharc.h"
#include <ui_tu_shu_guan.h>

class tu_shu_guan : public QMainWindow
{
	Q_OBJECT

public:
	tu_shu_guan(maincharc* mm,QWidget *parent = Q_NULLPTR);
signals:
	void backTochoose();
private:
	Ui::tu_shu_guanClass ui;
};
