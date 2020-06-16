#include "tu_shu_guan.h"
#include <qpushbutton.h>
#include <qmovie.h>
#include<qtimer.h>
tu_shu_guan::tu_shu_guan(maincharc* mm, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setAutoFillBackground(true);
	QPalette backgound = this->palette();
	backgound.setBrush(backgroundRole(), QPixmap(":/plotphoto/luojiashan3.jpg"));
	setPalette(backgound);
	setWindowTitle(QStringLiteral("图书馆"));

	ui.label_3->hide();
	ui.pushButton_2->hide();
	ui.textEdit_2->hide();
	ui.pushButton_3->hide();
	ui.pushButton_4->hide();

	//读书动图
	QMovie* dushu = new QMovie(":/plotphoto/tushuguan3.gif");
	ui.label_3->setMovie(dushu);
	dushu->start();


	//书架
	connect(ui.toolButton, &QPushButton::clicked, [=]() {
		if (mm->movepoint>30)
		{
		ui.label_3->show();
		ui.pushButton_2->show();
		mm->movepoint -= 30;
		}
		else
		{
			ui.textEdit->append("No Enough Movepoint");
		}
		});
		connect(ui.pushButton_2, &QPushButton::clicked, [=]() {
			ui.label_3->hide();
			ui.pushButton_2->hide();
			ui.textEdit->setText(QStringLiteral("读书\n 读万卷书，行万里路！\n 你的各项属性提升了"));
			mm->zhiLI +=30;
			mm->qinShang += 30;
			mm->img += 30;
	});		
	//图书管理员
	connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
		ui.textEdit_2->show();
		ui.pushButton_3->show();
		ui.pushButton_4->show();
		ui.textEdit_2->setText(QStringLiteral("课余时间来做兼职吧，既能锻炼自己，又有报酬哦！"));
		
	
    });
	connect(ui.pushButton_3, &QPushButton::clicked, [=]() {
		if (mm->movepoint>30)
		{
			ui.textEdit->setText(QStringLiteral("兼职\n 兼职中......\n 金钱+70"));
			mm->movepoint -= 30;
			mm->money += 70;
			ui.textEdit_2->hide();
			ui.pushButton_3->hide();
			ui.pushButton_4->hide();
		}
		else
		{
			ui.textEdit->append("No Enough Movepoint");
		}
			
			});
	connect(ui.pushButton_4, &QPushButton::clicked, [=]() {
			ui.textEdit->setText(QStringLiteral("还是空出时间来做点喜欢做的事情吧！"));
			ui.textEdit_2->hide();
			ui.pushButton_3->hide();
			ui.pushButton_4->hide();
			});
	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		/*ui.week->setText(QString("第 %1周").arg(this->week));
		ui.day->setText(QString("星期%1").arg(this->day));*/
		//ui.money->setText(QString::number(mm->money));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		ui.ima->setText(QString::number(mm->img));
		/*c->day = this->day;
		c->week = this->week;*/
		});

		//离开
		connect(ui.pushButton, &QPushButton::clicked, [=]() {
			
			emit backTochoose();
			ui.textEdit->clear();
			ui.textEdit_2->clear();
			});

		




}
