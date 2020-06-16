#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_huo_dong_zhong_xin.h"
#include "maincharc.h"

class huo_dong_zhong_xin : public QMainWindow
{
	Q_OBJECT

public:
	huo_dong_zhong_xin(maincharc* mm, QWidget *parent = Q_NULLPTR);
signals:
	void back();
private:
	Ui::huo_dong_zhong_xinClass ui;
};
