#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_han_jie.h"
#include "maincharc.h"

class han_jie : public QMainWindow
{
	Q_OBJECT

public:
	han_jie(maincharc* mm, QWidget *parent = Q_NULLPTR);
signals:
	void back();
private:
	Ui::han_jieClass ui;
};
