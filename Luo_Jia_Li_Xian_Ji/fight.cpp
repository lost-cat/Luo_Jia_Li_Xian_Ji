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
	ui.skilltable->hide();
	//������������ʾ��ս�������ϡ���ʵʱ��������
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
	//ѧϰ��ť��ʵ��
	connect(ui.attack, &QPushButton::clicked, [=]()												
	{	
			switch ((m1+day-1)->getNum())
			{
				case 1:
				if ((m1 + day - 1)->getREC()<=man->qinShang)
				{
					times +=4;
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
				}
				else if (man->qinShang< (m1 + day - 1)->getREC()&& man->qinShang>=200)
				{
					times +=2;
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
				}
				else if (man->qinShang < 200 && man->qinShang >= 100)
				{
					times +=1;
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
				}
				else
				{
					ui.textEdit->append("������ſ���ȫû�а취��������ȥͼ���ѧϰ��");
				}
				break;
				case 2:if (man->zhiLI>400)
				{
					times += 4; 
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
				}
					  else if (man->zhiLI >= 300)
				{
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
					times +=3;

				}
					  else if (man->zhiLI>=200 )
				{
					times +=2; 
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
				}
					  else
				{
					ui.textEdit->append("������ſ���ȫû�а취��������ȥͼ���ѧϰ��");
					
				}
					break;
				case 3:if (man->img > 400)
				{
					times += 4;
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
				}
					  else if (man->img < 400 && man->img >= 300)
				{
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
					times +=3;
				}
					  else if (man->img< 300 && man->img>= 200)
				{
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
					times +=2;
				}
					  else
				{
					ui.textEdit->append("������ſ���ȫû�а취��������ȥͼ���ѧϰ��");

				}break;
				case 4:if (man->img > 200&& man->zhiLI>=400)
				{
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
					times += 4;
				}
					  else if (man->img > 100 && man->zhiLI >= 200)
				{
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
					times +=2;
				}
					  else if ( man->zhiLI >= 200)
				{
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
					times += 1;
				}
					  else
				{
					ui.textEdit->append("������ſ���ȫû�а취��������ȥͼ���ѧϰ��");

				}break;
				case 5:if (man->zhiLI >=500)
				{
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
					times +=4;
				}
					  else if (man->zhiLI> 400)
				{
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
					times +=3;
				}
					  else if (man->zhiLI >= 300)
				{
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
					times+= 2;
				}
					  else
				{
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");

				}
					  break;
				case 6:if (man->qinShang >= 500&& man->zhiLI>=300)
				{
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
					times += 4;
				}
					  else if (man->zhiLI > 200&& man->qinShang>=300)
				{
					ui.textEdit->append("���ſζ����е��ѣ������㻹�����������");
					times +=2;
				}
					  else if (man->zhiLI >= 100&& man->qinShang>=150)
				{
					ui.textEdit->append("���ſ��ƺ�������˵�е����ѣ������ȥ����һ���Լ�������");
					times += 1;
				}
					  else
				{
					ui.textEdit->append("��ô�ζ�������ɣ���ܿ�������ѧϰ����");
				}
					  break;
			default:
				break;
			}


			(m1 + day - 1)->addPro(times, per);










	

			man->movepoint -= 30;
			ui.attack->setEnabled(false);
	});
//	//�����źű�������������
	
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
			ui.textEdit->append("�����������������ר����־��ѧϰ�����ѧϰЧ����ߣ�");
			ui.skill1->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ30�ж�����������Ҫ������Ϣ�ɡ�");
			ui.skilltable->hide();
		}
		
		});
	connect(ui.skill2, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 50)
		{
			per += 0.6;
			man->movepoint -= 50;
			ui.skilltable->hide();
			ui.textEdit->append("�㽫��Χ�����е����豸ȫ���رգ�����һ�и��ţ�ȫ���ĵ�Ͷ�뵽ѧϰ�����ѧϰЧ�ʴ����ߣ�");
			ui.skill2->setEnabled(false);
			man->zhiLI += 15;
			man->img += 10;
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ50�ж�����������Ҫ������Ϣ�ɡ�");
			ui.skilltable->hide();
		}

		});
	connect(ui.skill3, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 40)
		{
			per += 0.3;
			man->movepoint -= 40;
			ui.skilltable->hide();
			ui.textEdit->append("���ַ������������ ��ʱ������׽��һЩ���⣨�����������΢������");
			man->img += 30;
			ui.skill3->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ40�ж�����������Ҫ������Ϣ�ɡ�");
			ui.skilltable->hide();
		}

		});
	connect(ui.skill4, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 70)
		{
			per += 0.6;
			man->movepoint -= 70;
			ui.skilltable->hide();
			ui.textEdit->append("THE DDL ����ʹ�㲻�ò����ѧϰ�������ǰ�ҹ���������Ľ�����ֵ�½���");
			man->img -=20;
			man->HP -= 5;
			ui.skill4->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ70�ж�����������Ҫ������Ϣ�ɡ�");
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
			ui.textEdit->append("��Ϊ��ѧϰ��Ȼ�����˳Է��������ǿ̿డ��Ц��");
			man->img -= 20;
			man->HP -= 10;
			ui.skill5->setEnabled(false);
			man->recverPer -= 0.2;
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ60�ж�����������Ҫ������Ϣ�ɡ�");
			ui.skilltable->hide();
		}
		});
	connect(ui.skill6, &QPushButton::clicked, [=]() {
		if (man->movepoint >= 20)
		{
			times +=3;
			man->movepoint -= 20;
			ui.skilltable->hide();
			ui.textEdit->append("�������ǵ��򲻵��Ѳ�Ϊ֮��û�뵽�㾡Ȼ�ڴ˴�ʹ�ã����Σ�����ĸ������Զ����½���Ŷ");
			man->img -=50;
			man->zhiLI -= 50;
			man->qinShang -= 60;
			man->meiLi -= 1;
			ui.skill6->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ20�ж�����������Ҫ������Ϣ�ɡ�");
			ui.skilltable->hide();
		}
		});
	connect(ui.skill7, &QPushButton::clicked, [=]() {
		if (man->movepoint >=0)
		{
			man->movepoint +=(man->movepointMax-man->movepoint)*0.7;
			ui.skilltable->hide();
			ui.textEdit->append("���Ѿ���ǿ��֮ĩ�ˣ�Ϊʲô��ҪӲ���أ�����(���`��*|||������");
			man->img -=30;
			man->zhiLI -= 20;
			man->qinShang -= 30;
			man->HP -= 10;
			ui.skill7->setEnabled(false);
		}
		else
		{
			ui.textEdit->append("�ж������㣨����Ҫ20�ж�����������Ҫ������Ϣ�ɡ�");
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


