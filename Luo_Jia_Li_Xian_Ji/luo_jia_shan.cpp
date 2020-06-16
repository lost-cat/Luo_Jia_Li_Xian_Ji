#include "luo_jia_shan.h"
#include <qpushbutton.h>
#include<qtimer.h>
luo_jia_shan::luo_jia_shan(maincharc* mm, QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setAutoFillBackground(true);
	QPalette backgound = this->palette();
	backgound.setBrush(backgroundRole(), QPixmap(":/plotphoto/luojiashan3.jpg"));
	setPalette(backgound);
	//setFixedSize(500, 491);
	setWindowTitle(QStringLiteral("珞珈山"));

	ui.question->hide();
	ui.choice1->hide();
	ui.choice2->hide();

	

	//散步
	connect(ui.sanbu, &QPushButton::clicked, [=]() {
		ui.question->setText(QStringLiteral("今天天气这么好，快到山上去散散步吧！"));
		ui.choice1->setText(QStringLiteral("散步"));
		ui.choice2->setText(QStringLiteral("不去啦"));
		ui.question->show();
		ui.choice1->show();
		ui.choice2->show();
		
		
		});
	connect(ui.choice2, &QPushButton::clicked, [=]() {
			ui.textEdit->setText(QStringLiteral("你感觉没什么意思，就离开了\n "));
			ui.question->hide();
			ui.choice1->hide();
			ui.choice2->hide();
			});
connect(ui.choice1, &QPushButton::clicked, [=]() {
			if (mm->movepoint>20)
			{	ui.textEdit->setText(QStringLiteral("散步\n  山上的空气格外清新呢！\n  健康+2!!"));
			ui.question->hide();
			ui.choice1->hide();
			ui.choice2->hide();
			mm->HP += 2;
			mm->movepoint -= 20;
			}
			else
			{
				ui.textEdit->append("No Enough Movepoint");
			}
		
			});
	//狐狸
	connect(ui.xiaohuli, &QPushButton::clicked, [=]() {
		ui.question->setText(QStringLiteral("小狐狸珞珞好可爱哦！要不要上前去看看呢？"));
		ui.choice1->setText(QStringLiteral("上前投喂"));
		ui.choice2->setText(QStringLiteral("转身离开"));
		ui.question->show();
		ui.choice1->show();
		ui.choice2->show();
		
	connect(ui.choice1, &QPushButton::clicked, [=]() {
		if (mm->movepoint>20)
		{
	ui.textEdit->setText(QStringLiteral("小狐狸珞珞\n  出门带了点事物，刚好派上用场，看它吃的好香哦！\n  魅力+2!!"));
		ui.question->hide();
		ui.choice1->hide();
		ui.choice2->hide();
		mm->meiLi+= 2;
		mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit->append("No Enough Movepoint");
		}
	
		});
	connect(ui.choice2, &QPushButton::clicked, [=]() {
		ui.textEdit->setText(QStringLiteral("小狐狸珞珞\n  还是离它远一点吧，不要打扰野生动物的正常生活！\n  智慧+2!!"));
		ui.question->hide();
		ui.choice1->hide();
		ui.choice2->hide();
		mm->zhiLI +=10;
		});
});
	//樱花城堡
	connect(ui.yinghuachengbao, &QPushButton::clicked, [=]() {
		ui.question->setText(QStringLiteral("樱花大道两边的樱花开了，要不要去看一下呢？"));
		ui.choice1->setText(QStringLiteral("好啊，去看看！"));
		ui.choice2->setText(QStringLiteral("算啦，回去学习吧！"));
		ui.question->show();
		ui.choice1->show();
		ui.choice2->show();
		
	connect(ui.choice1, &QPushButton::clicked, [=]() {
		if (mm->movepoint>10)
		{
ui.textEdit->setText(QStringLiteral("樱花城堡\n  落英缤纷，盛世之景，美不胜收......\n  健康+1!！魅力+1！!"));
		ui.question->hide();
		ui.choice1->hide();
		ui.choice2->hide();
		mm->HP+= 1;
		mm->meiLi+= 1;
		mm->movepoint -= 10;
		}
		else
		{
			ui.textEdit->append("No Enough Movepoint");
		}
		
		});
	connect(ui.choice2, &QPushButton::clicked, [=]() {
		ui.textEdit->setText(QStringLiteral("樱花城堡\n  ddl是第一生产力，加油！\n "));
		ui.question->hide();
		ui.choice1->hide();
		ui.choice2->hide();
		});
});

	//离开
	connect(ui.leave, &QPushButton::clicked, [=]() {
		ui.textEdit->clear();
		emit back();
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

}
