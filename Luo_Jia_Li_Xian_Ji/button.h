#pragma once

#include<qpushbutton.h>
class button : public QPushButton
{
	Q_OBJECT

public:
	//button(QObject *parent);
	button(QString normalImg, QString pressImg="");
	QString normalImgPath;
	QString pressImgPath;
	~button();
};
