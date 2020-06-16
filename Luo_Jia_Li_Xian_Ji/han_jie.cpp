#include "han_jie.h"
#include <qmovie.h>
#include <qpushbutton.h>

han_jie::han_jie(maincharc* mm, QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


	setAutoFillBackground(true);
	QPalette backgound = this->palette();
	backgound.setBrush(backgroundRole(), QPixmap(":/plotphoto/luojiashan3.jpg"));
	setPalette(backgound);
	//setFixedSize(500, 491);
	setWindowTitle(QStringLiteral("汉街"));

	//餐厅动画
	QMovie* canting = new QMovie(":/plotphoto/hanjie2.gif");
	ui.label_4->setMovie(canting);
	canting->start();
	ui.label_4->hide();
	ui.pushButton_2->hide();
	//影院动画
	QMovie* yingyuan = new QMovie(":/plotphoto/hanjie3.gif");
	ui.label_5->setMovie(yingyuan);
	yingyuan->start();
	ui.label_5->hide();
	ui.pushButton_3->hide();

	ui.textEdit->hide();

	//逛街
	connect(ui.toolButton, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit->show();
			ui.textEdit->setText(QStringLiteral("逛街\n 偶遇老同学，一起玩的很开心！\n  情商+20！！"));
			mm->qinShang += 20;
			mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit->append("No Enough Movepoint");
		}

		//connect(ui.toolButton, &QPushButton::clicked, [=]() {
			//ui.textEdit->hide();
			//});
		});

	//餐厅
	connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
		if (mm->money >= 100)
		{
			ui.label_4->show();
			ui.pushButton_2->show();
			mm->money -= 100;
			mm->movepoint += 50;
			mm->HP += 2;
		}
		else {
			ui.textEdit->setText(QStringLiteral("餐厅\n 钱不够了哦！还是回去吃食堂吧！\n "));
		}


		});
	connect(ui.pushButton_2, &QPushButton::clicked, [=]() {
		ui.label_4->hide();
		ui.pushButton_2->hide();
		ui.textEdit->show();
		ui.textEdit->setText(QStringLiteral("餐厅\n 吃饱了才有力气减肥，以后要常来！\n 金钱-100！！ 健康+2！！"));

		//connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
			//ui.textEdit->hide();
			//ui.label_4->hide();
			//ui.pushButton_2->hide();
			//});
		});
	//影院
	connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
		if (mm->money >= 50) {
			ui.label_5->show();
			ui.pushButton_3->show();
			mm->meiLi += 1;
			mm->qinShang += 30;
			mm->money -= 50;
		}
		else {
			ui.textEdit->setText(QStringLiteral("电影院\n 钱不够了哦！快去兼职赚钱吧！\n "));
		}
		
		});
connect(ui.pushButton_3, &QPushButton::clicked, [=]() {
			ui.label_5->hide();
			ui.pushButton_3->hide();
			ui.textEdit->show();
			ui.textEdit->setText(QStringLiteral("电影院\n 这部年少的你真好看，不虚此行！！\n 魅力+1！！  情商+30！！ 金钱-100"));
			
			//connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
				//ui.textEdit->hide();
				//ui.label_5->hide();
				//ui.pushButton_3->hide();
				//});
			});
	//离开
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		emit back();
		});
}






































