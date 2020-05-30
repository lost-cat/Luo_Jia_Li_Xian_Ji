#include "button.h"
button::button(QString normalImg, QString pressImg ) 
{
	this->normalImgPath = normalImg;
	this->pressImgPath = pressImg;
	QPixmap p;
	p.load(normalImg);
	this->setFixedSize(p.width(), p.height());
	this->setStyleSheet("QPushButton{ border:0px; }");
	setIcon(p);
	this->setIconSize(QSize(p.width(), p.height()));


}
button::~button()
{
}
