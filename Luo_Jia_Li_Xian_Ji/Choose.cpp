#include "Choose.h"
#include<qtimer.h>
#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
Choose::Choose(maincharc*mm,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		ui.week->setText(QString("µÚ %1ÖÜ").arg(this->week));
		ui.day->setText(QString("ÐÇÆÚ%1").arg(this->day));
		ui.money->setText(QString::number(mm->money));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		
		});
	connect(ui.shuse, &QPushButton::clicked, [=]() {
		emit this->backToHome();

		});
}

Choose::~Choose()
{
}
