#pragma once

#include <QWidget>
#include "ui_shopWidgetsClass.h"

class shopWidgetsClass : public QWidget
{
	Q_OBJECT

public:
	shopWidgetsClass(QWidget *parent = Q_NULLPTR);
	~shopWidgetsClass();

private:
	Ui::shopWidgetsClass ui;
};
