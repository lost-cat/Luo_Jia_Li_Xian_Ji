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
	// ��ʼ������
	mm = new maincharc(this, 150, 100, 0, 50, 50, 100000,50);
	//������ڵĳ�ʼ����
	c = new Choose(mm);
	sk = new skill(mm);
	f = new fight(mm);
	sh = new shop(mm);
	sh->setWindowTitle("�Զ��");
	//�̵갴ť������
	

	
	
	


	//ÿ0.1sˢ������
	QTimer *t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		ui.week->setText(QString("�� %1��").arg(this->week));
		ui.day->setText(QString("����%1").arg(this->day));
		ui.money->setText(QString::number(mm->money));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		ui.ima->setText(QString::number(mm->img));
		c->day = this->day;
		c->week = this->week;
	});

	//�趨����
	setWindowTitle("�������ռ�");
	//�趨�̶���С
	setFixedSize(645, 716);
	sh->resize(this->size());
	//�̵갴ť��ʵ��
	connect(ui.tao, &QPushButton::clicked, [=]()           //�����̵갴ť
	{

		QTimer::singleShot(500, this, [=]() {
			this->hide();
			sh->setGeometry(this->geometry());
			sh->show();
		});
		
	});
	//f�������ڵĳ�Ա��
	
	f->setFixedSize(581, 672);
	connect(ui.leaarn, &QPushButton::clicked, [=]()          //����ѧϰ�ð�ť
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
		//�����ť��ʵ��
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
			ui.textEdit->append("�µ�һ�쵽�ˣ�����ҲҪԪ������Ŷ��");
			if (this->day>7)
			{
				this->week += 1;
				this->day = 1;
				mm->money += 1000;
				ui.textEdit->append("�����������1000Ԫ");
			}
		}


