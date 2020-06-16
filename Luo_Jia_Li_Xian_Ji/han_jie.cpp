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
	setWindowTitle(QStringLiteral("����"));

	//��������
	QMovie* canting = new QMovie(":/plotphoto/hanjie2.gif");
	ui.label_4->setMovie(canting);
	canting->start();
	ui.label_4->hide();
	ui.pushButton_2->hide();
	//ӰԺ����
	QMovie* yingyuan = new QMovie(":/plotphoto/hanjie3.gif");
	ui.label_5->setMovie(yingyuan);
	yingyuan->start();
	ui.label_5->hide();
	ui.pushButton_3->hide();

	ui.textEdit->hide();

	//���
	connect(ui.toolButton, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit->show();
			ui.textEdit->setText(QStringLiteral("���\n ż����ͬѧ��һ����ĺܿ��ģ�\n  ����+20����"));
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

	//����
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
			ui.textEdit->setText(QStringLiteral("����\n Ǯ������Ŷ�����ǻ�ȥ��ʳ�ðɣ�\n "));
		}


		});
	connect(ui.pushButton_2, &QPushButton::clicked, [=]() {
		ui.label_4->hide();
		ui.pushButton_2->hide();
		ui.textEdit->show();
		ui.textEdit->setText(QStringLiteral("����\n �Ա��˲����������ʣ��Ժ�Ҫ������\n ��Ǯ-100���� ����+2����"));

		//connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
			//ui.textEdit->hide();
			//ui.label_4->hide();
			//ui.pushButton_2->hide();
			//});
		});
	//ӰԺ
	connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
		if (mm->money >= 50) {
			ui.label_5->show();
			ui.pushButton_3->show();
			mm->meiLi += 1;
			mm->qinShang += 30;
			mm->money -= 50;
		}
		else {
			ui.textEdit->setText(QStringLiteral("��ӰԺ\n Ǯ������Ŷ����ȥ��ְ׬Ǯ�ɣ�\n "));
		}
		
		});
connect(ui.pushButton_3, &QPushButton::clicked, [=]() {
			ui.label_5->hide();
			ui.pushButton_3->hide();
			ui.textEdit->show();
			ui.textEdit->setText(QStringLiteral("��ӰԺ\n �ⲿ���ٵ�����ÿ���������У���\n ����+1����  ����+30���� ��Ǯ-100"));
			
			//connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
				//ui.textEdit->hide();
				//ui.label_5->hide();
				//ui.pushButton_3->hide();
				//});
			});
	//�뿪
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		emit back();
		});
}






































