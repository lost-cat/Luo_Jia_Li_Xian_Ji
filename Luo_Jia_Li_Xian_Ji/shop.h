#pragma once

#include <QWidget>
#include "ui_shop.h"
#include"maincharc.h"
#include"Items.h"
#include<QMessageBox>
#include<QIcon>
class shop : public QWidget
{
	Q_OBJECT

public:
	shop(maincharc*,QWidget *parent = Q_NULLPTR);
	~shop();
signals:
	void backtomain();
private:
	Ui::shop ui;
};
