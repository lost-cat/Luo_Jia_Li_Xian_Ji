#include "BigAssignmentPP.h"
#include <qpushbutton.h>
#include <qlabel.h>
#include <QMessageBox>
#include <QObject>
#include <qdebug.h>
#include<qtimer.h>
#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
BigAssignmentPP::BigAssignmentPP(maincharc*mm,QWidget *parent)
	: QWidget(parent)
{
	/*int physicalstrength = 150;
	int *strength = new int;
	float cash = 1000.00;
	float *money = new float(cash);*/
	QString *which = new QString;
	ui.setupUi(this);
	setAutoFillBackground(true);
	QPalette backgoundCanteen = this->palette();
	backgoundCanteen.setBrush(backgroundRole(), QPixmap(":/Resources/canteen.png"));
	setPalette(backgoundCanteen);
	setFixedSize(680, 510);
	setWindowTitle(QStringLiteral("梅园食堂"));
	//调整按钮大小
//	ui.food->resize(100, 38);
//	ui.drink->resize(100, 38);
	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.money->setText(QString("金钱:%1").arg(mm->money).toUtf8());
		});
	//连接离开食堂的按钮
	connect(ui.leaveCanteen, &QPushButton::clicked, [=]() {
		
		emit backToChoose();

		});

	ui.canteenWords->hide();
	ui.firstFoodAndDrink->hide();
	ui.secondFoodAndDrink->hide();
	ui.closeInformation->hide();
	ui.canteenWords->setReadOnly(true);
	
	//购买饭菜
	connect(ui.food, &QToolButton::clicked, [=]() {
		*which = "food";
		ui.canteenWords->setText(QString("同学，你今天想吃点什么啊").toUtf8());
		ui.firstFoodAndDrink->setIcon(QIcon(":/Resources/liang.jpg"));
		ui.secondFoodAndDrink->setIcon(QIcon(":/Resources/yi.png"));
		ui.firstFoodAndDrink->setText(QString("俩荤俩素 12元").toUtf8());
		ui.secondFoodAndDrink->setText(QString("   一荤一素 8元").toUtf8());
		ui.canteenWords->show();
		ui.firstFoodAndDrink->show();
		ui.secondFoodAndDrink->show();
		ui.closeInformation->show();
		});
		
	//购买饮料
	connect(ui.drink, &QToolButton::clicked, [=]() {
		*which = "drink";
		ui.canteenWords->setText(QString("同学，喝杯饮料心情会变好哟！").toUtf8());
		ui.firstFoodAndDrink->setIcon(QIcon(":/Resources/juice.jpg"));
		ui.secondFoodAndDrink->setIcon(QIcon(":/Resources/cocacola.jpg"));
		ui.firstFoodAndDrink->setText(QString("    果汁 3元 ").toUtf8());
		ui.secondFoodAndDrink->setText(QString("    可乐 3.5元 ").toUtf8());
		ui.canteenWords->show();
		ui.firstFoodAndDrink->show();
		ui.secondFoodAndDrink->show();
		ui.closeInformation->show();
		});

	//购买结果输出
	    //饭菜
			connect(ui.firstFoodAndDrink, &QToolButton::clicked, [=]() {
				if (*which == "food")
				{
				mm->money-=12.0;
				//恢复已损失行动力的75%
				mm->movepoint +=( mm->movepointMax-mm->movepoint)*0.75;
				ui.textEdit->append(QString("两荤两素 购买成功！\n剩余的钱:%1").arg(mm->money).toUtf8());
				
				//qDebug() << "两荤两素 购买成功！\n剩余的钱：" << *money << endl;
				
				}
				else if (*which == "drink")
				{
				mm->money -= 3.0;
				//恢复已损失行动力的10%
				mm->movepoint += (mm->movepointMax - mm->movepoint) *0.2;
				ui.textEdit->append(QString("果汁 购买成功！\n剩余的钱:%1").arg(mm->money).toUtf8());
				//qDebug() << "果汁 购买成功！\n剩余的钱：" << *money << endl;
				}
			});	
			connect(ui.secondFoodAndDrink, &QToolButton::clicked, [=]() {
				if (*which == "food")
				{
				mm->money -= 8.0;
				//恢复已损失行动力的50%
				mm->movepoint += (mm->movepointMax - mm->movepoint) * 0.5;
				ui.textEdit->append(QString("一荤一素 购买成功!\n剩余的钱:%1").arg(mm->money).toUtf8());

				//qDebug() << "一荤一素 购买成功！\n剩余的钱：" << *money << endl;
				}
				else if (*which == "drink")
				{
				mm->money -= 4;
				//恢复已损失行动力的15%
				mm->movepoint += (mm->movepointMax - mm->movepoint) * 0.25;
				ui.textEdit->append(QString("快乐水 购买成功！\n剩余的钱:%1").arg(mm->money).toUtf8());
				//qDebug() << "可乐 购买成功！\n剩余的钱：" << *money << endl;
				}
				
				});
		

	//关闭购买框
	//connect(ui.closeInformation, &QPushButton::clicked, [=]() {
	//	ui.canteenWords->hide();
	//	ui.firstFoodAndDrink->hide();
	//	ui.secondFoodAndDrink->hide();
	//	ui.closeInformation->hide();
	//	});
}


