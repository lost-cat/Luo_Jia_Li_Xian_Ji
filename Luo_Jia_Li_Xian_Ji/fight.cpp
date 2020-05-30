#include "fight.h"
#include "maincharc.h"
#include"Select_course.h"
#include"qtimer.h"
#if _MSC_VER >=1600 //VS2010版本号是1600，强制MSVC编译器采用UTF-8编码生成可执行文件
#pragma execution_character_set("utf-8")
#endif
fight::fight(maincharc *man,QWidget *parent)
	: QWidget(parent)
{
		
	
	ui.setupUi(this);
	//设置标题
	this->setWindowTitle("战斗场景");		
	//	
	m1 =man->selctedCourse;
	//设定计时器
	QTimer *t1 = new QTimer();			
	//每0.1s发送一个信号
	t1->start(100);
	//将人物属性显示在战斗窗口上。并实时更新数据
	connect(t1,&QTimer::timeout,[=]()		
	{
		ui.movepoint->setText(QString::number(man->movepoint));
		ui.zili->setText(QString::number(man->zhiLI));
		ui.qinshang->setText(QString::number(man->qinShang));
		ui.jiankang->setText(QString::number(man->HP));
		if (day<=6)
		{
		ui.cou_name->setText((m1+day-1)->getName());
		ui.curpro->setValue((m1 + day-1)->getPro());
		}
		else
		{
			ui.cou_name->setText("----");
			ui.curpro->setValue(NULL);
		}
		
	//ui.mon_hp->setValue(m1->HP);
	//ui.mon_name->setText(m1->name);
	//ui.char_hp->setValue(man->HP);																		
	//ui.atk->setText(QString::number(man->ATK));
	//ui.def->setText(QString::number(man->DEF));
	//ui.adf->setText(QString::number(man->ADF));		
	});
	//学习按钮的实现
	connect(ui.attack, &QPushButton::clicked, [=]()												
	{	
			
			
			(m1 + day - 1)->addPro(1, 1);





			ui.attack->setEnabled(false);






	});
//	//发送信号表明返回主界面
	
	connect(ui.back, &QPushButton::clicked, [=]() {
		emit this->backToMainscence();
		ui.attack->setEnabled(true);
		day++;
		if (day>7)
		{
			day = 1;
		}
	});
//	//monster *m1;
//	connect(this, &fight::backToMainscence, [=] {
//
//	});
}


//int fight::count = 0;

fight::~fight()
{

}

//void fight::myclose()
//{
//	this->close();
//	delete this;
//
//}

//void fight::enemychange(monster *)
//{
//}

/*void fight::attack(monster *m1,maincharc *man)
{

	if (man->ATK - m1->DEF>=ui.mon_hp->value())																			//判断HP=0，如是则退出窗口。
	{
		ui.mon_hp->setValue(0);
		int n = qrand() % 6;
		switch (n)
		{
		case 0: m1 = new monster(30, 5, 0, u8"懒惰恶灵", 001); break;
		case 1: m1 = new monster(20, 15, 0, u8"抑郁恶灵", 002); break;
		case 2: m1 = new monster(40, 10, 10, u8"不学无术恶灵", 003); break;
		case 3: m1 = new monster(10, 5, 13, u8"恶灵三号", 004); break;
		case 4: m1 = new monster(25, 8, 10, u8"恶灵四号", 005); break;
		case 5: m1 = new monster(40, 15, 10, u8"恶灵五号", 006); break;
		default:
			break;
		}
		this->close();
		ui.mon_hp->setValue(m1->HP);
		ui.mon_name->setText(m1->name);
	}
	else
	{
		ui.mon_hp->setValue(ui.mon_hp->value() -(man->ATK -m1->DEF));
		 attack_mon(m1,man);
	}
}
*/
/*
void fight::attack_mon(monster *m1, maincharc *man)
{
	man->HP -= (m1->ATK - man->DEF);
	ui.char_hp->setValue(man->HP);
	

}*/


