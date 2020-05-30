#pragma once

#include <QWidget>
#include "ui_shop.h"
#include"maincharc.h"
class shop : public QWidget
{
	Q_OBJECT

public:
	shop(maincharc*,QWidget *parent = Q_NULLPTR);
	~shop();
private:
	Ui::shop ui;
};
