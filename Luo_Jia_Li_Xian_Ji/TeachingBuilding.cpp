#include "TeachingBuilding.h"
#include <qpushbutton.h>
#include <qmessagebox.h>
#include<qtimer.h>

TeachingBuilding::TeachingBuilding(maincharc* mm, QWidget* parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	int *which= new int;

	setAutoFillBackground(true);
	QPalette backgoundTeachingBuilding = this->palette();
	backgoundTeachingBuilding.setBrush(backgroundRole(), QPixmap(":/pix/TeachingBuilding .png"));
	setPalette(backgoundTeachingBuilding);
	setFixedSize(680, 510);
	setWindowTitle(QStringLiteral("教五"));

	//连接离开按钮
	connect(ui.leaveTeachingBuilding, &QPushButton::clicked, [=]() {
		emit backToChoose();
		count = 1;
		});

	//信息界面
	ui.firstChoice->hide();
	ui.secondChoice->hide();
	ui.teachingBuildingWords->hide();
	/*QPalette pl = ui.result->palette();*/
	/*pl.setBrush(QPalette::Base, QBrush(QColor(255, 0, 0, 0)));*/
	/*ui.result->setPalette(pl);*/

	//听讲座
	connect(ui.listenToLecture, &QPushButton::clicked, [=]() {
		/*ui.result->setText(QStringLiteral(" "));*/
		ui.firstChoice->setText(QStringLiteral("感觉挺有意思的，去！"));
		ui.secondChoice->setText(QStringLiteral("好无聊，不去啦！"));
		ui.teachingBuildingWords->show();
		ui.firstChoice->show();
		ui.secondChoice->show();
		});
		connect(ui.firstChoice, &QPushButton::clicked, [=]() {
			if (mm->movepoint<=20)
			{
				/*ui.result->setText(QString("No Enough Movepoint").toUtf8().data());*/
				QMessageBox::warning(this, "SORRY", "NO ENOUGH MOVEPOINT ");
			}
			else
			{
				mm->movepoint -= 20;
				QMessageBox::information(this, QStringLiteral("听讲座"), QStringLiteral("  听讲座\n\n  听完莫先生的讲座受益匪浅！\n  智力 +20\n  想象力 +10"));
				//ui.result->setText(QStringLiteral("    听讲座\n\n    听完莫先生的讲座受益匪浅！\n    智力 +2\n    想象力 +1"));
				ui.firstChoice->hide();
				ui.secondChoice->hide();
				ui.teachingBuildingWords->hide();
				mm->zhiLI += 20;
				mm->img += 10;
			}
			
			});
		connect(ui.secondChoice, &QPushButton::clicked, [=]() {
			//ui.result->setText(QStringLiteral(" "));
			ui.firstChoice->hide();
			ui.secondChoice->hide();
			ui.teachingBuildingWords->hide();
			});
		

	//上课
	connect(ui.attendClass, &QPushButton::clicked, [=]() {
		//*which = 0;
		if (count>3)
		{
			/*ui.result->setText(QString("今天课全部上完了，明天再来吧").toUtf8().data());*/
			QMessageBox::warning(this, "SORRY", "You have Attend Enough Class");
		}
		else
		{
			if (mm->movepoint<15)
			{
				/*ui.result->setText(QString("No Enough Movepoint").toUtf8().data());*/
				QMessageBox::warning(this, "SORRY", "NO ENOUGH MOVEPOINT ");
			}
			else
			{
				mm->movepoint -= 15;
				//ui.result->setText(QStringLiteral(" "));
				ui.teachingBuildingWords->setText(QStringLiteral("学习了高级语言程序设计，感觉自己变得更聪明啦！").toUtf8());
			/*	ui.secondChoice->setText(QStringLiteral("离开教室...").toUtf8().data());
				ui.teachingBuildingWords->show();
				ui.secondChoice->show();*/
				ui.secondChoicePlus->setText(QStringLiteral("离开教室..."));
				ui.firstChoice->hide();
				ui.secondChoice->hide();
				ui.secondChoicePlusPlus->hide();
				ui.teachingBuildingWords->show();
				ui.secondChoicePlus->show();
				/*this->which(which,mm);*/
				count++;
			}
			
		}
		
		});
	connect(ui.secondChoicePlus, &QPushButton::clicked, [=]() {
		ui.secondChoicePlus->close();
		ui.teachingBuildingWords->close();
		QMessageBox::information(this, QStringLiteral("上自习"), QStringLiteral("  上课\n\n  智力 +2"));
		mm->zhiLI += 2;
		});

	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		ui.img->setText(QString::number(mm->img));
		//c->day = this->day;
		//c->week = this->week;
		});
	//上自习
	connect(ui.selfStudy, &QPushButton::clicked, [=]() {
	/*	*which = 1;*/
		if (mm->movepoint<45)
		{
			/*ui.result->setText(QString("No Enough Movepoint").toUtf8().data());*/
			QMessageBox::warning(this, "SORRY", "NO ENOUGH MOVEPOINT ");
		}
		else
		{
			mm->movepoint -= 45;
		/*	ui.result->setText(QStringLiteral(" "));*/
			ui.teachingBuildingWords->setText(QStringLiteral("学过的知识掌握得更加牢固啦！").toUtf8());
			/*ui.secondChoice->setText(QStringLiteral("离开自习室...").toUtf8());
			ui.teachingBuildingWords->show();
			ui.secondChoice->show();
			this->which(which,mm);*/
			ui.secondChoicePlusPlus->setText(QStringLiteral("离开自习室..."));
			ui.firstChoice->hide();
			ui.secondChoice->hide();
			ui.secondChoicePlus->hide();
			ui.teachingBuildingWords->show();
			ui.secondChoicePlusPlus->show();
		}
		
		});
	connect(ui.secondChoicePlusPlus, &QPushButton::clicked, [=]() {
		ui.secondChoicePlusPlus->close();
		ui.teachingBuildingWords->close();
		QMessageBox::information(this, QStringLiteral("上自习"), QStringLiteral("  自习\n\n  智力 +30"));
		mm->zhiLI += 30;
		});
}
int TeachingBuilding:: count = 1;
//void TeachingBuilding::which(int* a,maincharc *b)
//{
//	if (*a == 0)
//	{
//		connect(ui.secondChoice, &QPushButton::clicked, [=]() {
//			ui.secondChoice->close();
//			ui.teachingBuildingWords->close();
//			ui.result->setText(QStringLiteral("    上课\n\n    智力 +20").toUtf8());
//			b->zhiLI+= 20;
//			});
//	}
//	else if(* a == 1)
//	{
//		connect(ui.secondChoice, &QPushButton::clicked, [=]() {
//			ui.secondChoice->close();
//			ui.teachingBuildingWords->close();
//			ui.result->setText(QStringLiteral("    自习\n\n    智力 +50").toUtf8());
//			b->zhiLI+= 50;
//			});
//	}
//}
