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
	setWindowTitle(QStringLiteral("��ѧ�������"));

	//���ٵ��Ｊ����
	connect(ui.toolButton, &QPushButton::clicked, [=]() {
		if (mm->movepoint>30)
		{
	ui.textEdit_2->setText(QStringLiteral("���ٵ�����\n ����һ��ʱ����٣����鶼����ˣ�\n  ����+2!!"));
		mm->meiLi += 2;
		mm->movepoint -= 30;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
	
		});

	//�����˶�
	connect(ui.toolButton_2, &QPushButton::clicked, [=]() {
		if (mm->movepoint>40)
		{
ui.textEdit_2->setText(QStringLiteral("�����˶���\n �ոյ��������ü���ѽ����������Ӯ����\n ����+2!!"));
		mm->HP += 2;
		mm->movepoint -= 40;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		
		});

	//��������ѵ
	connect(ui.toolButton_4, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit_2->setText(QStringLiteral("��������ѵ\n ����ͬѧ�Ǽ����������Ӣ��ˮƽ��\n �ǻ�+30����"));
			mm->zhiLI += 30;
			mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		});

	//ӣ����
	connect(ui.toolButton_3, &QPushButton::clicked, [=]() {
		if (mm->movepoint > 20)
		{
			ui.textEdit_2->setText(QStringLiteral("ӣ����\n ǰ�����ο����˹�����ӣ���꣬������ȥ���ѣ��ο���æ��Ǹ����ʾ���������������ˣ���\n ����+2����"));
			mm->qinShang += 30;
			mm->movepoint -= 20;
		}
		else
		{
			ui.textEdit_2->append("No Enough Movepoint");
		}
		});

	//�뿪
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		emit back();
		ui.textEdit_2->clear();
		});

	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		/*ui.week->setText(QString("�� %1��").arg(this->week));
		ui.day->setText(QString("����%1").arg(this->day));*/
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
	//			ui.textEdit_2->setText(QStringLiteral(" ���� +2"));
		//		b->meili += 2;
		//		});
		//}
	//	else if (*a == 1)
	//	{
	//		connect(ui.toolButton, &QPushButton::clicked, [=]() {
				//ui.secondChoice->close();
				//ui.teachingBuildingWords->close();
	//			ui.textEdit_2->setText(QStringLiteral("  ���� +1"));
	//			b->meili += 1;
	//			});
	//	}
	//}






