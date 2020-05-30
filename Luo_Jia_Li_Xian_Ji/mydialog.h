#pragma once

#include <QWidget>
#include "ui_mydialog.h"

class mydialog : public QWidget
{
	Q_OBJECT

public:
	mydialog(QWidget *parent = Q_NULLPTR);
	~mydialog();

private:
	Ui::mydialog ui;
};
