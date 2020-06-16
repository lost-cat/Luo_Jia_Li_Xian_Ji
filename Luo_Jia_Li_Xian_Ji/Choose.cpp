#include "Choose.h"
#include<qtimer.h>
#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
Choose::Choose(maincharc*mm,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setFixedSize(648, 612);
	carteen = new BigAssignmentPP(mm);
	teachingBuilding = new TeachingBuilding(mm);
	san = new luo_jia_shan(mm);
	huo = new huo_dong_zhong_xin(mm);
	tu = new tu_shu_guan(mm);
	han = new han_jie(mm);
	QTimer* t = new QTimer(this);
	t->start(100);
	connect(t, &QTimer::timeout, [=]() {
		ui.move->setText(QString::number(mm->movepoint));
		ui.hp->setText(QString::number(mm->HP));
		ui.week->setText(QString("µÚ %1ÖÜ").arg(this->week));
		ui.day->setText(QString("ÐÇÆÚ%1").arg(this->day));
		ui.money->setText(QString::number(mm->money));
		ui.zi->setText(QString::number(mm->zhiLI));
		ui.qin->setText(QString::number(mm->qinShang));
		ui.mei->setText(QString::number(mm->meiLi));
		ui.ing->setText(QString::number(mm->img));		
		});
	connect(ui.shuse, &QPushButton::clicked, [=]() {
		emit this->backToHome();

		});
	connect(ui.shitang, &QPushButton::clicked, [=]() {
		this->hide();
		carteen->setGeometry(this->geometry());
		carteen->show();
		});
	connect(carteen, &BigAssignmentPP::backToChoose, [=]() {
		carteen->hide();
		this->setGeometry(carteen->geometry());
		this->show();

		});
	connect(ui.jiaosi, &QPushButton::clicked, [=]() {
		this->hide();
		teachingBuilding->setGeometry(this->geometry());
		teachingBuilding->show();
		});
	connect(teachingBuilding, &TeachingBuilding::backToChoose, [=]() {
		teachingBuilding->hide();
		this->setGeometry(teachingBuilding->geometry());
		this->show();

		});
	connect(ui.tushuguan, &QPushButton::clicked, [=]() {
		this->hide();
		tu->setGeometry(this->geometry());
		tu->show();
		});
	connect(tu, &tu_shu_guan::backTochoose, [=]() {
		tu->hide();
		this->setGeometry(tu->geometry());
		this->show();

		});
	connect(ui.san, &QPushButton::clicked, [=]() {
		this->hide();
		san->setGeometry(this->geometry());
		san->show();
		});
	connect(san, &luo_jia_shan::back, [=]() {
		san->hide();
		this->setGeometry(san->geometry());
		this->show();

		});
	connect(ui.huodon, &QPushButton::clicked, [=]() {
		this->hide();
		huo->setGeometry(this->geometry());
		huo->show();
		});
	connect(huo, &huo_dong_zhong_xin::back, [=]() {
		huo->hide();
		this->setGeometry(huo->geometry());
		this->show();

		});
	connect(ui.hanjie, &QPushButton::clicked, [=]() {
		this->hide();
		han->setGeometry(this->geometry());
		han->show();
		});
	connect(han, &han_jie::back, [=]() {
		han->hide();
		this->setGeometry(han->geometry());
		this->show();
		});;
}

Choose::~Choose()
{
}
