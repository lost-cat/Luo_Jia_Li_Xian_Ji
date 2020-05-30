#pragma once

#include <QWidget>
#include "ui_skill.h"
#include"maincharc.h"
#include<qmessagebox.h>
class skill : public QWidget
{
	Q_OBJECT

public:
	skill(maincharc*, QWidget *parent = Q_NULLPTR);
	~skill();
signals:
	void backToMainScence();
private:
	Ui::skill ui;
};
