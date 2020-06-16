#include "Luo_Jia_Li_Xian_Ji.h"
#include"Select_course.h"
#include<qpainter.h>
#include"button.h"

#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
using namespace std;
Luo_Jia_Li_Xian_Ji::Luo_Jia_Li_Xian_Ji(QWidget *parent)
	: QMainWindow(parent)
{
	this->week = 1;
	this->day = 1;
	ui.setupUi(this);
	ui.textEdit->setReadOnly(true);
	/*ui.textEdit->append("wuhandx");
	ui.textEdit->append("haoa");*/
	// 初始化主角
	mm = new maincharc(this, 150, 100, 0, 50, 50, 100000,50);
	//外出窗口的初始化。
	c = new Choose(mm);
	sk = new skill(mm);
	f = new fight(mm);
	sh = new shop(mm);
	sh->setWindowTitle("淘多多");
	//商店按钮的设置
	

	
	
	


	//每0.1s刷新数据
	QTimer *t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		ui.week->setText(QString("第 %1周").arg(this->week));
		ui.day->setText(QString("星期%1").arg(this->day));
		ui.money->setText(QString::number(mm->money));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		ui.ima->setText(QString::number(mm->img));
		c->day = this->day;
		c->week = this->week;
	});

	//设定标题
	setWindowTitle("珞珈历险记");
	//设定固定大小
	setFixedSize(645, 716);
	sh->resize(this->size());
	//商店按钮的实现
	connect(ui.tao, &QPushButton::clicked, [=]()           //设置商店按钮
	{

		QTimer::singleShot(500, this, [=]() {
			this->hide();
			sh->setGeometry(this->geometry());
			sh->show();
		});
		
	});
	//f是主窗口的成员，
	
	f->setFixedSize(581, 672);
	connect(ui.leaarn, &QPushButton::clicked, [=]()          //设置学习用按钮
	{
		QTimer::singleShot(100, this, [=](){
			this->hide();
			f->setGeometry(this->geometry());
			f->show();
		});
		////	fight::count++;

		});
		connect(f, &fight::backToMainscence, [=]() 
		{
		f->hide();
		this->setGeometry(f->geometry());
		this->show();
		sleep();
		mm->recover();
		mm->recverPer = 1;

	});
		connect(ui.ski, &QPushButton::clicked, [=]() {
			this->hide();
			sk->setGeometry(this->geometry());
			sk->show();
			});
		connect(sk, &skill::backToMainScence, [=]() {
			sk->hide();
			this->setGeometry(sk->geometry());
			this->show();
			});
		//外出按钮的实现
		connect(ui.goout, &QPushButton::clicked, [=]() {

			QTimer::singleShot(500, this, [=]() {
				this->hide();
				c->setGeometry(this->geometry());
				c->show();
				});

			});
		connect(c, &Choose::backToHome, [=]() {
			c->hide();
			this->setGeometry(c->geometry());
			this->show();
			});
		connect(sh, &shop::backtomain, [=]() {
			sh->hide();
			this->setGeometry(sh->geometry());
			this->show();
			});
}

		void Luo_Jia_Li_Xian_Ji::paintEvent(QPaintEvent *)
		{
			QPainter painter(this);
			QPixmap pix;
			//pix.load(":/pix/pix2.jpg");
			painter.drawPixmap(0, 0, this->width(), this->height(), pix);
		}

		void Luo_Jia_Li_Xian_Ji::sleep()
		{
			this->day += 1;
			ui.textEdit->append("新的一天到了，今天也要元气满满哦。");
			if (this->day>7)
			{
				this->week += 1;
				this->day = 1;
				mm->money += 1000;
				ui.textEdit->append("你获得了生活费1000元");
			}
		}


