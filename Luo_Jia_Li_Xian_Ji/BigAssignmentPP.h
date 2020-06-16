#pragma once

#include <QtWidgets/QWidget>
#include <ui_BigAssignmentPP.h>
#include"maincharc.h"
class BigAssignmentPP : public QWidget
{
	Q_OBJECT

public:
	BigAssignmentPP(maincharc*,QWidget *parent = Q_NULLPTR);
signals:
	void backToChoose();
private:
	Ui::BigAssignmentPPClass ui;
};
