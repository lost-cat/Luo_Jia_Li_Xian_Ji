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
	ui.skilltable->hide();
	//将人物属性显示在战斗窗口上。并实时更新数据
	connect(t1,&QTimer::timeout,[=]()		
	{
		ui.movepoint->setText(QString::number(man->movepoint));
		ui.zili->setText(QString::number(man->zhiLI));
		ui.qinshang->setText(QString::number(man->qinShang));
		ui.jiankang->setText(QString::number(man->HP));
		ui.img->setText(QString::number(man->img));
		ui.rec->setText((m1 + day - 1)->getWeakPoint());
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
			switch ((m1+day-1)->getNum())
			{
				case 1:
				if ((m1 + day - 1)->getREC()<=man->qinShang)
				{
					times +=4;
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
				}
				else if (man->qinShang< (m1 + day - 1)->getREC()&& man->qinShang>=200)
				{
					times +=2;
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
				}
				else if (man->qinShang < 200 && man->qinShang >= 100)
				{
					times +=1;
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
				}
				else
				{
					ui.textEdit->append("你对这门课完全没有办法，还是先去图书馆学习吧");
				}
				break;
				case 2:if (man->zhiLI>400)
				{
					times += 4; 
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
				}
					  else if (man->zhiLI >= 300)
				{
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
					times +=3;

				}
					  else if (man->zhiLI>=200 )
				{
					times +=2; 
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
				}
					  else
				{
					ui.textEdit->append("你对这门课完全没有办法，还是先去图书馆学习吧");
					
				}
					break;
				case 3:if (man->img > 400)
				{
					times += 4;
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
				}
					  else if (man->img < 400 && man->img >= 300)
				{
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
					times +=3;
				}
					  else if (man->img< 300 && man->img>= 200)
				{
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
					times +=2;
				}
					  else
				{
					ui.textEdit->append("你对这门课完全没有办法，还是先去图书馆学习吧");

				}break;
				case 4:if (man->img > 200&& man->zhiLI>=400)
				{
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
					times += 4;
				}
					  else if (man->img > 100 && man->zhiLI >= 200)
				{
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
					times +=2;
				}
					  else if ( man->zhiLI >= 200)
				{
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
					times += 1;
				}
					  else
				{
					ui.textEdit->append("你对这门课完全没有办法，还是先去图书馆学习吧");

				}break;
				case 5:if (man->zhiLI >=500)
				{
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
					times +=4;
				}
					  else if (man->zhiLI> 400)
				{
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
					times +=3;
				}
					  else if (man->zhiLI >= 300)
				{
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
					times+= 2;
				}
					  else
				{
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");

				}
					  break;
				case 6:if (man->qinShang >= 500&& man->zhiLI>=300)
				{
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
					times += 4;
				}
					  else if (man->zhiLI > 200&& man->qinShang>=300)
				{
					ui.textEdit->append("这门课对你有点难，但是你还是完成了任务");
					times +=2;
				}
					  else if (man->zhiLI >= 100&& man->qinShang>=150)
				{
					ui.textEdit->append("这门课似乎对你来说有点困难，你最好去提升一下自己的属性");
					times += 1;
				}
					  else
				{
					ui.textEdit->append("这么课对你很轻松，你很快就完成了学习任务");
				}
					  break;
			default:
				break;
			}


			(m1 + day - 1)->addPro(times, per);










	

			man->movepoint -= 30;
			ui.attack->setEnabled(false);
	});
//	//发送信号表明返回主界面
	
	connect(ui.skill, &QPushButton::clicked, [=]() {
		if (ui.skilltable->isHidden())
		{
			ui.skilltable->show();

		}else{ui.skilltable->hide();}
		

		});
	connect(ui.skill1, &QPushButton::clicked, [=]() {
		if (man->movepoint>=20)
		{
			per += 0.2;
			man->movepoint -= 20;
			ui.skilltable->hide();
			ui.textEdit->append("你整理好书桌，打算专心致志的学习（你的学习效率提高）");
			ui.skill1->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要30行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}
		
		});
	connect(ui.skill2, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 50)
		{
			per += 0.6;
			man->movepoint -= 50;
			ui.skilltable->hide();
			ui.textEdit->append("你将周围的所有电子设备全部关闭，隔绝一切干扰，全身心的投入到学习（你的学习效率大幅提高）");
			ui.skill2->setEnabled(false);
			man->zhiLI += 15;
			man->img += 10;
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要50行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}

		});
	connect(ui.skill3, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 40)
		{
			per += 0.3;
			man->movepoint -= 40;
			ui.skilltable->hide();
			ui.textEdit->append("你充分发挥你的想象力 此时你更容易解决一些难题（你的想象力略微提升）");
			man->img += 30;
			ui.skill3->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要40行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}

		});
	connect(ui.skill4, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 70)
		{
			per += 0.6;
			man->movepoint -= 70;
			ui.skilltable->hide();
			ui.textEdit->append("THE DDL 会迫使你不得不完成学习，即便是熬夜的情况（你的健康数值下降）");
			man->img -=20;
			man->HP -= 5;
			ui.skill4->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要70行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}

		});
	connect(ui.skill5, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 60)
		{
			times += 2;
			per -= 0.2;
			man->movepoint -= 60;
			ui.skilltable->hide();
			ui.textEdit->append("你为了学习竟然忘记了吃饭，可真是刻苦啊（笑）");
			man->img -= 20;
			man->HP -= 10;
			ui.skill5->setEnabled(false);
			man->recverPer -= 0.2;
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要60行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}
		});
	connect(ui.skill6, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 20)
		{
			times +=3;
			man->movepoint -= 20;
			ui.skilltable->hide();
			ui.textEdit->append("这招乃是到万不得已才为之，没想到你尽然在此处使用（无奈），你的各个属性都会下降的哦");
			man->img -=50;
			man->zhiLI -= 50;
			man->qinShang -= 60;
			man->meiLi -= 1;
			ui.skill6->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要20行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}
		});
	connect(ui.skill7, &QPushButton::clicked, [=]() {
		if (man->movepoint >=0)
		{
			man->movepoint +=(man->movepointMax-man->movepoint)*0.7;
			ui.skilltable->hide();
			ui.textEdit->append("你已经是强弩之末了，为什么还要硬撑呢（━━(￣ー￣*|||━━）");
			man->img -=30;
			man->zhiLI -= 20;
			man->qinShang -= 30;
			man->HP -= 10;
			ui.skill7->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("行动力不足（你需要20行动力），今天要不就休息吧。");
			ui.skilltable->hide();
		}
		});
	connect(ui.back, &QPushButton::clicked, [=]() {
		emit this->backToMainscence();
		
		ui.attack->setEnabled(true);
		day++;
		
		if (day>7)
		{
			day = 1;
		}
		per = man->per;
		times = man->times;
		ui.textEdit->clear();
		ui.skill1->setEnabled(true); 
		ui.skill2->setEnabled(true);
		ui.skill3->setEnabled(true);
		ui.skill4->setEnabled(true);
		ui.skill5->setEnabled(true);
		ui.skill6->setEnabled(true);

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


