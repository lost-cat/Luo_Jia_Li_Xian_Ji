#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Luo_Jia_Li_Xian_Ji.h"

class Luo_Jia_Li_Xian_Ji : public QMainWindow
{
	Q_OBJECT

public:
	Luo_Jia_Li_Xian_Ji(QWidget *parent = Q_NULLPTR);

private:
	Ui::Luo_Jia_Li_Xian_JiClass ui;
};
