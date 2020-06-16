#include "shopWidgetsClass.h"
#include<QPushButton>
#include<QColor>
#include"shop.h"
#include"maincharc.h"
#include<QMessageBox>
#include<QIcon>

shopWidgetsClass::shopWidgetsClass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
    //初始化对象
    maincharc me(100, 100, 3, 100, 100);//初始化人物属性
    maincharc* me1 = &me;
    shop gaoji(10, 0, 0, 0, 100);//"高级语言程序设计"
    shop shuzi(10, 0, 0, 0, 150);//"数字电路设计及Verilog"
    shop lisan(0, 0, 0, 10, 100);//"离散数学"
    shop ruhe(0, 20, 0, 0, 150);//"如何与异性相处"
    shop lanqiu(0, 0, 1, 0, 70);//"篮球与人生"
    shop gaodeng(12, 0, 0, 0, 120);//"高等数学"
    shop dianzi(0, 5, 0, 0, 100);//"电子竞技概论"
    shop ruyu(0, 0, 0, 20, 80);//"日语入门"
    shop* goods1 = &gaoji;
    shop* goods2 = &shuzi;
    shop* goods3 = &lisan;
    shop* goods4 = &ruhe;
    shop* goods5 = &lanqiu;
    shop* goods6 = &gaodeng;
    shop* goods7 = &dianzi;
    shop* goods8 = &ruyu;
    //设置窗口大小
    resize(800, 800);
    //设置窗口名字
    setWindowTitle("淘多多");
    //设置关闭按钮
    QPushButton* btn0 = new QPushButton;
    btn0->show();
    btn0->setParent(this);
    btn0->setText("离开商店");
    btn0->resize(100, 50);
    btn0->move(700, 600);
    connect(btn0, QPushButton::clicked, this, QWidget::close);
    //创建第一件商品购买按钮：高级语言程序设计
    QPushButton* btn1 = new QPushButton;
    btn1->show();
    btn1->setParent(this);
    btn1->setText("高级语言程序设计\n属性：智慧+10\n价格：100");
    btn1->resize(200, 100);
    btn1->move(100, 0);
    //创建第二件商品购买按钮：数字电路设计及Verilog
    QPushButton* btn2 = new QPushButton;
    btn2->show();
    btn2->setParent(this);
    btn2->setText("数字电路设计及Verilog\n属性：智慧+10\n价格：150");
    btn2->resize(200, 100);
    btn2->move(450, 0);
    //创建第三件商品购买按钮；离散数学
    QPushButton* btn3 = new QPushButton;
    btn3->show();
    btn3->setParent(this);
    btn3->setText("离散数学\n属性：记忆力+10\n价格：100");
    btn3->resize(200, 100);
    btn3->move(100, 150);
    //创建第四件商品购买按钮：如何和异性相处
    QPushButton* btn4 = new QPushButton;
    btn4->show();
    btn4->setParent(this);
    btn4->setText("如何和异性相处\n属性：魅力+20\n价格：150");
    btn4->resize(200, 100);
    btn4->move(450, 150);
    //创建第五件商品购买按钮：篮球与人生
    QPushButton* btn5 = new QPushButton;
    btn5->show();
    btn5->setParent(this);
    btn5->setText("篮球与人生\n属性：行动力+1\n价格：70");
    btn5->resize(200, 100);
    btn5->move(100, 300);
    //创建第六件商品购买按钮：高等数学
    QPushButton* btn6 = new QPushButton;
    btn6->show();
    btn6->setParent(this);
    btn6->setText("高等数学\n属性：智慧+12\n价格：120");
    btn6->resize(200, 100);
    btn6->move(450, 300);
    //创建第七件商品购买按钮：电子竞技概论
    QPushButton* btn7 = new QPushButton;
    btn7->show();
    btn7->setParent(this);
    btn7->setText("电子竞技概论\n属性：魅力+5\n价格：100");
    btn7->resize(200, 100);
    btn7->move(100, 450);
    //创建第八件商品购买按钮：日语入门
    QPushButton* btn8 = new QPushButton;
    btn8->show();
    btn8->setParent(this);
    btn8->setText("日语入门\ns属性：记忆力+20\n价格：80");
    btn8->resize(200, 100);
    btn8->move(450, 450);
    //创建弹出对话框显示购买结果
    QMessageBox* box = new QMessageBox;
    //创建第一个结果lambda表达式即位购买函数
    connect(btn1, QPushButton::clicked, box, [=]() {
        if (goods1->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods1->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods1->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods1->getwalk();//加行动力属性
            me1->remember = me1->remember + goods1->getremember();//加记忆力属性
            me1->money = me1->money - goods1->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");


        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第二个结果
    connect(btn2, QPushButton::clicked, box, [=]() {
        if (goods2->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods2->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods2->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods2->getwalk();//加行动力属性
            me1->remember = me1->remember + goods2->getremember();//加记忆力属性
            me1->money = me1->money - goods2->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");
        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第三个购买
    connect(btn3, QPushButton::clicked, box, [=]() {
        if (goods3->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods3->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods3->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods3->getwalk();//加行动力属性
            me1->remember = me1->remember + goods3->getremember();//加记忆力属性
            me1->money = me1->money - goods3->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第四个结果
    connect(btn4, QPushButton::clicked, box, [=]() {
        if (goods4->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods4->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods4->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods4->getwalk();//加行动力属性
            me1->remember = me1->remember + goods4->getremember();//加记忆力属性
            me1->money = me1->money - goods4->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第五个结果
    connect(btn5, QPushButton::clicked, box, [=]() {
        if (goods5->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods5->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods5->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods5->getwalk();//加行动力属性
            me1->remember = me1->remember + goods5->getremember();//加记忆力属性
            me1->money = me1->money - goods5->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第六个结果
    connect(btn6, QPushButton::clicked, box, [=]() {
        if (goods6->getmoney() < me1->money)
        {
            me1->zhiLI= me1->zhiLI + goods6->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods6->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods6->getwalk();//加行动力属性
            me1->remember = me1->remember + goods6->getremember();//加记忆力属性
            me1->money = me1->money - goods6->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "critcal", "您的余额不足");
        });
    //创建第七个结果
    connect(btn7, QPushButton::clicked, box, [=]() {
        if (goods7->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods7->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods7->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods7->getwalk();//加行动力属性
            me1->remember = me1->remember + goods7->getremember();//加记忆力属性
            me1->money = me1->money - goods7->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });
    //创建第八个结果
    connect(btn8, QPushButton::clicked, box, [=]() {
        if (goods8->getmoney() < me1->money)
        {
            me1->zhiLI = me1->zhiLI + goods8->getknowledge();//加智慧属性
            me1->meiLi = me1->meiLi + goods8->getcharm();//加魅力属性
            me1->movepoint = me1->movepoint + goods8->getwalk();//加行动力属性
            me1->remember = me1->remember + goods8->getremember();//加记忆力属性
            me1->money = me1->money - goods8->getmoney();//扣除相应金钱
            box->information(this, "购买结果", "购买成功");

        }
        else
            box->critical(this, "购买结果", "您的余额不足");
        });

}

shopWidgetsClass::~shopWidgetsClass()
{
}
