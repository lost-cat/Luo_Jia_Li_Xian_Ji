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
  //设置窗口名字
  setWindowTitle("淘多多");
  //设置关闭按钮
  
  connect(ui.exit, &QPushButton::clicked, [=]() {
      emit backtomain();
      });
  //创建第一件商品购买按钮：高级语言程序设计
 /* QPushButton* btn1 = new QPushButton;
  btn1->setParent(this);
  btn1->show();
  btn1->setText("高级语言程序设计\n属性：智慧+200等\n价格：300");
  btn1->resize(200, 100);
  btn1->move(100, 0);*/
  //创建第二件商品购买按钮：数字电路设计及Verilog
 /* QPushButton* btn2 = new QPushButton;
  btn2->setParent(this);
  btn2->show();
  btn2->setText("数字电路设计及Verilog\n属性：智慧和想象力+150\n价格：400");
  btn2->resize(200, 100);
  btn2->move(450, 0);*/
  //创建第三件商品购买按钮；离散数学
 /* QPushButton* btn3 = new QPushButton;
  btn3->setParent(this);
  btn3->show();
  btn3->setText("离散数学\n属性：智力加250\n价格：250");
  btn3->resize(200, 100);
  btn3->move(100, 150);*/
  //创建第四件商品购买按钮：如何和异性相处
 /* QPushButton* btn4 = new QPushButton;
  btn4->setParent(this);
  btn4->show();
  btn4->setText("如何和异性相处\n属性：魅力+25,情商+200\n价格：600");
  btn4->resize(200, 100);
  btn4->move(450, 150);*/
  //创建第五件商品购买按钮：篮球与人生
 /* QPushButton* btn5 = new QPushButton;
  btn5->setParent(this);
  btn5->show();
  btn5->setText("篮球与人生\n属性：最大行动力+50\n价格：400");
  btn5->resize(200, 100);
  btn5->move(100, 300);*/
  //创建第六件商品购买按钮：高等数学
 /* QPushButton* btn6 = new QPushButton;
  btn6->setParent(this);
  btn6->show();
  btn6->setText("高等数学\n属性：智慧+300\n价格：500");
  btn6->resize(200, 100);
  btn6->move(450, 300);*/
  //创建第七件商品购买按钮：电子竞技概论
 /* QPushButton* btn7 = new QPushButton;
  btn7->setParent(this);
  btn7->show();
  btn7->setText("电子竞技概论\n属性：魅力+5\n价格：100");
  btn7->resize(200, 100);
  btn7->move(100, 450);*/
  //创建第八件商品购买按钮：日语入门
 /* QPushButton* btn8 = new QPushButton;
  btn8->setParent(this);
  btn8->show();
  btn8->setText("日语入门\ns属性：魅力+2\n价格：150");
  btn8->resize(200, 100);
  btn8->move(450, 450);*/
  //创建弹出对话框显示购买结果
  QMessageBox* box = new QMessageBox;
  //创建第一个结果lambda表达式即位购买函数
  connect(ui.buy1, &QPushButton::clicked, box, [=]() {
      if (goods1->money<= mm->money)
      {
          goods1->plus(mm); 
          box->information(this, "购买结果", "购买成功");
          ui.buy1->setText("已购买");
          ui.buy1->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第二个结果
  connect(ui.buy2, &QPushButton::clicked, box, [=]() {
      if (goods2->money <= mm->money)
      {
          goods2->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy2->setText("已购买");
          ui.buy2->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第三个购买
  connect(ui.buy3, &QPushButton::clicked, box, [=]() {
      if (goods3->money <= mm->money)
      {
          goods3->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy3->setText("已购买");
          ui.buy3->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第四个结果
  connect(ui.buy4, &QPushButton::clicked, box, [=]() {
      if (goods4->money<=mm->money)
      {
          goods4->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy4->setText("已购买");
          ui.buy4->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第五个结果
  connect(ui.buy5, &QPushButton::clicked, box, [=]() {
      if (goods5->money<=mm->money)
      {
          goods5->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy5->setText("已购买");
          ui.buy5->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第六个结果
  connect(ui.buy6, &QPushButton::clicked, box, [=]() {
      if (goods6->money <= mm->money)
      {
          goods6->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy6->setText("已购买");
          ui.buy6->setEnabled(false);
      }
      else
          box->critical(this, "critcal", "您的余额不足");
      });
  //创建第七个结果
  connect(ui.buy7, &QPushButton::clicked, box, [=]() {
      if (goods7->money<=mm->money)
      {
          goods7->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy7->setText("已购买");
          ui.buy7->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
  //创建第八个结果
  connect(ui.buy8, &QPushButton::clicked, box, [=]() {
      if (goods8->money<= mm->money)
      {
          goods8->plus(mm);
          box->information(this, "购买结果", "购买成功");
          ui.buy8->setText("已购买");
          ui.buy8->setEnabled(false);
      }
      else
          box->critical(this, "购买结果", "您的余额不足");
      });
}

shop::~shop()
{
}

