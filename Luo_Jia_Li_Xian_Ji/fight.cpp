#include "fight.h"
#include "maincharc.h"
#include"Select_course.h"
#include"qtimer.h"
#if _MSC_VER >=1600 //VS2010�汾����1600��ǿ��MSVC����������UTF-8�������ɿ�ִ���ļ�
#pragma execution_character_set("utf-8")
#endif
fight::fight(maincharc *man,QWidget *parent)
	: QWidget(parent)
{
		
	
	ui.setupUi(this);
	//���ñ���
	this->setWindowTitle("ս������");		
	//	
	m1 =man->selctedCourse;
	//�趨��ʱ��
	QTimer *t1 = new QTimer();			
	//ÿ0.1s����һ���ź�
	t1->start(100);
	//������������ʾ��ս�������ϡ���ʵʱ��������
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
	//ѧϰ��ť��ʵ��
	connect(ui.attack, &QPushButton::clicked, [=]()												
	{	
			
			
			(m1 + day - 1)->addPro(1, 1);





			ui.attack->setEnabled(false);






	});
//	//�����źű�������������
	
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

	if (man->ATK - m1->DEF>=ui.mon_hp->value())																			//�ж�HP=0���������˳����ڡ�
	{
		ui.mon_hp->setValue(0);
		int n = qrand() % 6;
		switch (n)
		{
		case 0: m1 = new monster(30, 5, 0, u8"�������", 001); break;
		case 1: m1 = new monster(20, 15, 0, u8"��������", 002); break;
		case 2: m1 = new monster(40, 10, 10, u8"��ѧ��������", 003); break;
		case 3: m1 = new monster(10, 5, 13, u8"��������", 004); break;
		case 4: m1 = new monster(25, 8, 10, u8"�����ĺ�", 005); break;
		case 5: m1 = new monster(40, 15, 10, u8"�������", 006); break;
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


