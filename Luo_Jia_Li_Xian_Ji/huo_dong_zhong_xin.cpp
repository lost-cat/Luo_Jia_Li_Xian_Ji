#include "huo_dong_zhong_xin.h"
#include<qtimer.h>
huo_dong_zhong_xin::huo_dong_zhong_xin(maincharc* mm, QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//int* meili = new int;

	setAutoFillBackground(true);
	QPalette backgound = this->palette();
	backgound.setBrush(backgroundRole(), QPixmap(":/plotphoto/luojiashan3.jpg"));
	setPalette(backgound);
	//setFixedSize(500, 491);
	setWindowTitle(QStringLiteral("大学生活动中心"));

	//古琴笛箫吉他社
	connect(ui.toolButton, &QPushButton::clicked, [=]() {
		if (mm->movepoint>30)
		{
	ui.textEdit_2->setText(QStringLiteral("古琴笛箫社\n 弹了一段时间古琴，心情都变好了！\n  魅力+2!!"));
		mm->meiLi += 2;
		mm->movepoint -= 30;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
	
		});

	//球类运动
	connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
		if (mm->movepoint>40)
		{
ui.textEdit_2->setText(QStringLiteral("球类运动社\n 刚刚的篮球赛好激烈呀，不过还好赢啦！\n 健康+2!!"));
		mm->HP += 2;
		mm->movepoint -= 40;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		
		});

	//四六级培训
	connect(ui.toolButton_4, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit_2->setText(QStringLiteral("四六级培训\n 帮助同学们极大地提升了英语水平！\n 智慧+30！！"));
			mm->zhiLI += 30;
			mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		});

	//樱花节
	connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit_2->setText(QStringLiteral("樱花节\n 前面有游客在人工制造樱花雨，你走上去提醒，游客连忙道歉并表示不会出现这种情况了！！\n 情商+2！！"));
			mm->qinShang += 30;
			mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		});

	//离开
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		emit back();
		ui.textEdit_2->clear();
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







//	void huo_dong_zhong_xin::meili(int* a, Maincharc * b)
	//{
		//if (*a == 0)
	//	{
		//	connect(ui.toolButton, &QPushButton::clicked, [=]() {
	//			//ui.secondChoice->close();
	//			//ui.teachingBuildingWords->close();
	//			ui.textEdit_2->setText(QStringLiteral(" 魅力 +2"));
		//		b->meili += 2;
		//		});
		//}
	//	else if (*a == 1)
	//	{
	//		connect(ui.toolButton, &QPushButton::clicked, [=]() {
				//ui.secondChoice->close();
				//ui.teachingBuildingWords->close();
	//			ui.textEdit_2->setText(QStringLiteral("  魅力 +1"));
	//			b->meili += 1;
	//			});
	//	}
	//}






