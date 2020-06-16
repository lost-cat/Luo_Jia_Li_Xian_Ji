#include "shop.h"
#include<qpushbutton.h>
#include<qtimer.h>
#if _MSC_VER >=1600 
#pragma execution_character_set("utf-8")
#endif
shop::shop(maincharc*mm, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
   Items* goods1 = new Items(200, 0, 100, 0, 300, 50);
  Items* goods2 = new Items(150, 0, 150, 0, 300, 50);
  Items* goods3 = new Items(250, 0, 150, 0, 350, 50);
  Items* goods4 = new Items(0, 25, 200, 0, 400, 200);
  Items* goods5 = new Items(0, 5, 0, 50, 250, 0);
  Items* goods6 = new Items(300, 0, 200, 0, 500, 150);
  Items* goods7 = new Items(100, 15, 200, 0, 250, 100);
  Items* goods8 = new Items(0, 5, 150, 0, 200, 150);
  QTimer* t = new QTimer(this);
  t->start(100);
  connect(t, &QTimer::timeout, [=]() {
      ui.money->setText(QString::number(mm->money));
      });
  resize(800, 800);
  //���ô�������
  setWindowTitle("�Զ��");
  //���ùرհ�ť
  
  connect(ui.exit, &QPushButton::clicked, [=]() {
      emit backtomain();
      });
  //������һ����Ʒ����ť���߼����Գ������
 /* QPushButton* btn1 = new QPushButton;
  btn1->setParent(this);
  btn1->show();
  btn1->setText("�߼����Գ������\n���ԣ��ǻ�+200��\n�۸�300");
  btn1->resize(200, 100);
  btn1->move(100, 0);*/
  //�����ڶ�����Ʒ����ť�����ֵ�·��Ƽ�Verilog
 /* QPushButton* btn2 = new QPushButton;
  btn2->setParent(this);
  btn2->show();
  btn2->setText("���ֵ�·��Ƽ�Verilog\n���ԣ��ǻۺ�������+150\n�۸�400");
  btn2->resize(200, 100);
  btn2->move(450, 0);*/
  //������������Ʒ����ť����ɢ��ѧ
 /* QPushButton* btn3 = new QPushButton;
  btn3->setParent(this);
  btn3->show();
  btn3->setText("��ɢ��ѧ\n���ԣ�������250\n�۸�250");
  btn3->resize(200, 100);
  btn3->move(100, 150);*/
  //�������ļ���Ʒ����ť����κ������ദ
 /* QPushButton* btn4 = new QPushButton;
  btn4->setParent(this);
  btn4->show();
  btn4->setText("��κ������ദ\n���ԣ�����+25,����+200\n�۸�600");
  btn4->resize(200, 100);
  btn4->move(450, 150);*/
  //�����������Ʒ����ť������������
 /* QPushButton* btn5 = new QPushButton;
  btn5->setParent(this);
  btn5->show();
  btn5->setText("����������\n���ԣ�����ж���+50\n�۸�400");
  btn5->resize(200, 100);
  btn5->move(100, 300);*/
  //������������Ʒ����ť���ߵ���ѧ
 /* QPushButton* btn6 = new QPushButton;
  btn6->setParent(this);
  btn6->show();
  btn6->setText("�ߵ���ѧ\n���ԣ��ǻ�+300\n�۸�500");
  btn6->resize(200, 100);
  btn6->move(450, 300);*/
  //�������߼���Ʒ����ť�����Ӿ�������
 /* QPushButton* btn7 = new QPushButton;
  btn7->setParent(this);
  btn7->show();
  btn7->setText("���Ӿ�������\n���ԣ�����+5\n�۸�100");
  btn7->resize(200, 100);
  btn7->move(100, 450);*/
  //�����ڰ˼���Ʒ����ť����������
 /* QPushButton* btn8 = new QPushButton;
  btn8->setParent(this);
  btn8->show();
  btn8->setText("��������\ns���ԣ�����+2\n�۸�150");
  btn8->resize(200, 100);
  btn8->move(450, 450);*/
  //���������Ի�����ʾ������
  QMessageBox* box = new QMessageBox;
  //������һ�����lambda���ʽ��λ������
  connect(ui.buy1, &QPushButton::clicked, box, [=]() {
      if (goods1->money<= mm->money)
      {
          goods1->plus(mm); 
          box->information(this, "������", "����ɹ�");
          ui.buy1->setText("�ѹ���");
          ui.buy1->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //�����ڶ������
  connect(ui.buy2, &QPushButton::clicked, box, [=]() {
      if (goods2->money <= mm->money)
      {
          goods2->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy2->setText("�ѹ���");
          ui.buy2->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //��������������
  connect(ui.buy3, &QPushButton::clicked, box, [=]() {
      if (goods3->money <= mm->money)
      {
          goods3->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy3->setText("�ѹ���");
          ui.buy3->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //�������ĸ����
  connect(ui.buy4, &QPushButton::clicked, box, [=]() {
      if (goods4->money<=mm->money)
      {
          goods4->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy4->setText("�ѹ���");
          ui.buy4->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //������������
  connect(ui.buy5, &QPushButton::clicked, box, [=]() {
      if (goods5->money<=mm->money)
      {
          goods5->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy5->setText("�ѹ���");
          ui.buy5->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //�������������
  connect(ui.buy6, &QPushButton::clicked, box, [=]() {
      if (goods6->money <= mm->money)
      {
          goods6->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy6->setText("�ѹ���");
          ui.buy6->setEnabled(false);
      }
      else
          box->critical(this, "critcal", "��������");
      });
  //�������߸����
  connect(ui.buy7, &QPushButton::clicked, box, [=]() {
      if (goods7->money<=mm->money)
      {
          goods7->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy7->setText("�ѹ���");
          ui.buy7->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
  //�����ڰ˸����
  connect(ui.buy8, &QPushButton::clicked, box, [=]() {
      if (goods8->money<= mm->money)
      {
          goods8->plus(mm);
          box->information(this, "������", "����ɹ�");
          ui.buy8->setText("�ѹ���");
          ui.buy8->setEnabled(false);
      }
      else
          box->critical(this, "������", "��������");
      });
}

shop::~shop()
{
}

